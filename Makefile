AS:=nasm
CC:=i586-elf-gcc

CFLAGS:=-ffreestanding -O0 -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
CPPFLAGS:=
LIBS:=-lgcc

OBJS:=			\
./src/kernel.o		\
./src/kmain.o		\
./src/gdt.o		\
./src/paging.o		\
./src/vga.o		\
./src/libc.o

all: myos.bin

.PHONEY: all clean iso run-qemu

myos.bin: $(OBJS) linker.ld
	$(CC) -T linker.ld -o $@ $(CFLAGS) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ -I ./include -std=gnu99 $(CFLAGS) $(CPPFLAGS)

%.o: %.asm
	$(AS) -f elf $< -o $@

clean:
	rm -rf isodir
	rm -f myos.bin myos.iso $(OBJS)
	rm -f /tmp/qemu.log
	rm -f /tmp/bochs.log

iso: myos.iso

isodir isodir/boot isodir/boot/grub:
	mkdir -p $@

isodir/boot/myos.bin: myos.bin isodir/boot
	cp $< $@

isodir/boot/grub/grub.cfg: grub.cfg isodir/boot/grub
	cp $< $@

myos.iso: isodir/boot/myos.bin isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir

run-qemu: myos.iso
	qemu-system-i386 -cdrom myos.iso -monitor stdio -d cpu_reset

run-bochs: myos.bin
	bochs -q -f ./bochs.cfg