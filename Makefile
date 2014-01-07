AS:=nasm
CC:=i586-elf-gcc

CFLAGS:=-ffreestanding -O2 -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -I ./include -std=gnu99
CPPFLAGS:=
LIBS:=-lgcc

SRC=    src/libc/find_prime_sup.c \
        src/libc/is_prime.c \
        src/libc/put_nbr.c \
        src/libc/strcat.c\
        src/libc/str_isnum.c \
        src/libc/strlcat.c \
        src/libc/strncat.c\
        src/libc/strstr.c\
        src/libc/swap.c \
        src/libc/getnbr.c \
	src/libc/memcpy.c \
        src/libc/power_rec.c \
        src/libc/putstr.c \
        src/libc/square_root.c \
        src/libc/strcmp.c\
        src/libc/str_isalpha.c \
        src/libc/str_isprintable.c \
        src/libc/strlen.c \
        src/libc/strncmp.c\
        src/libc/isneg.c \
        src/libc/putchar.c \
        src/libc/revstr.c \
        src/libc/strcapitalize.c \
        src/libc/strcpy.c \
        src/libc/str_islower.c \
        src/libc/str_isupper.c \
        src/libc/strlowcase.c \
        src/libc/strncpy.c \
        src/libc/strupcase.c \
        src/libc/printf/printf.c \
        src/libc/printf/print/put_nbr_base.c \
        src/libc/printf/print/put_nbr_base_u.c \
        src/libc/printf/print/putstr_o.c \
        src/libc/printf/print/print_b.c \
        src/libc/printf/print/print_c.c \
        src/libc/printf/print/print_d.c \
        src/libc/printf/print/print_o.c \
        src/libc/printf/print/print_p.c \
        src/libc/printf/print/print_s.c \
        src/libc/printf/print/print_u.c \
        src/libc/printf/print/print_X.c \
	src/kernel.o \
	src/kmain.c \
	src/gdt.c     \
	src/vga.c 


OBJ=    $(SRC:.c=.o)

all: myos.bin

.PHONEY: all clean iso run-qemu

myos.bin: $(OBJ) linker.ld
	$(CC) -T linker.ld -o $@ $(CFLAGS) $(OBJ) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

%.o: %.asm
	$(AS) -f elf $< -o $@

clean:
	rm -rf isodir
	rm -f myos.bin myos.iso $(OBJ)

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