AS:=nasm
CC:=i586-elf-gcc

CFLAGS:=-ffreestanding -O2 -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel -I ./include -std=gnu99
CPPFLAGS:=
LIBS:=-lgcc

SRC=    src/libc/find_prime_sup.c				\
        src/libc/is_prime.c					\
        src/libc/put_nbr.c					\
        src/libc/strcat.c					\
        src/libc/str_isnum.c					\
        src/libc/strlcat.c					\
        src/libc/strncat.c					\
        src/libc/strstr.c					\
        src/libc/swap.c						\
        src/libc/getnbr.c					\
	src/libc/memcpy.c					\
	src/libc/memset.c					\
        src/libc/power_rec.c					\
        src/libc/putstr.c					\
        src/libc/square_root.c					\
        src/libc/strcmp.c					\
        src/libc/str_isalpha.c					\
        src/libc/str_isprintable.c				\
        src/libc/strlen.c					\
        src/libc/strncmp.c					\
        src/libc/isneg.c					\
        src/libc/putchar.c					\
        src/libc/revstr.c					\
        src/libc/strcapitalize.c				\
        src/libc/strcpy.c					\
        src/libc/str_islower.c					\
        src/libc/str_isupper.c					\
        src/libc/strlowcase.c					\
        src/libc/strncpy.c					\
        src/libc/strupcase.c					\
        src/libc/printf/printf.c				\
        src/libc/printf/print/put_nbr_base.c			\
        src/libc/printf/print/put_nbr_base_u.c			\
        src/libc/printf/print/putstr_o.c			\
        src/libc/printf/print/print_b.c				\
        src/libc/printf/print/print_c.c				\
        src/libc/printf/print/print_d.c				\
        src/libc/printf/print/print_o.c				\
        src/libc/printf/print/print_p.c				\
        src/libc/printf/print/print_s.c				\
        src/libc/printf/print/print_u.c				\
        src/libc/printf/print/print_X.c				\
	src/kernel.o						\
	src/asmISR.o						\
	src/asmIRQ.o						\
	src/kmain.c						\
	src/paging.c						\
	src/idt.c						\
	src/isr.c						\
	src/irq.c						\
	src/gdt.c						\
	src/syscall.c						\
	src/vga.c						\
	src/keyboard.c						\
	src/panic.c

OBJ=    $(SRC:.c=.o)

all: ukernel.bin

.PHONEY: all clean iso run-qemu

ukernel.bin: $(OBJ) linker.ld
	$(CC) -T linker.ld -o $@ $(CFLAGS) $(OBJ) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

%.o: %.asm
	$(AS) -f elf $< -o $@

clean:
	rm -rf isodir
	rm -f /tmp/qemu.log
	rm -f /tmp/bochs.log
	rm -f ukernel.bin ukernel.iso $(OBJ)

iso: ukernel.iso

isodir isodir/boot isodir/boot/grub:
	mkdir -p $@

isodir/boot/ukernel.bin: ukernel.bin isodir/boot
	cp $< $@

isodir/boot/grub/grub.cfg: grub.cfg isodir/boot/grub
	cp $< $@

ukernel.iso: isodir/boot/ukernel.bin isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir

run-bochs: ukernel.bin
	bochs -q -f ./bochs.cfg

run-qemu: ukernel.iso
	qemu-system-i386 -cdrom ukernel.iso -monitor stdio -d cpu_reset
