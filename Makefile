AS:=nasm
CC:=i586-elf-gcc

CFLAGS:=-ffreestanding -O2 -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -I ./include -std=gnu99
CPPFLAGS:=
LIBS:=-lgcc

OBJS:=\
./src/kernel.o \
./src/kmain.o \
./src/gdt.o	\
./src/vga.o \
./src/libc.o

all: myos.bin

.PHONEY: all clean iso run-qemu

myos.bin: $(OBJS) linker.ld
	$(CC) -T linker.ld -o $@ $(CFLAGS) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

%.o: %.asm
	$(AS) -f elf $< -o $@

clean:
	rm -rf isodir
	rm -f myos.bin myos.iso $(OBJS)

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
	qemu-system-i386 -cdrom myos.iso -monitor vc