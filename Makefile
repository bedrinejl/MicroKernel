#Kernel name
NAME = ukernel.bin
ISO = $(NAME:.bin=.iso)

#Source Assembler
A_SRC =								\
	src/kernel.asm						\
	src/asmISR.asm						\
	src/asmIRQ.asm						\

#Source C
C_SRC =								\
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

#Object
A_OBJ = $(A_SRC:.asm=.o)
C_OBJ = $(C_SRC:.c=.o)
OBJ = $(A_OBJ) $(C_OBJ)

#Compiler
CA	=	nasm
CC	=	i586-elf-gcc
LD	=	$(CC)
RM	=	rm -f

#Include
INCLUDE = -I include -I libc/include -I klibc/include

#Linker file
LDFILE = linker.ld

#C Options
NOLIBC = -nostdinc -fno-builtin
NOINSTR = -mno-mmx -mno-3dnow -mno-sse -mno-sse2 -mno-sse3
OPTI = -fno-stack-protector -O2
NAZI = -Wall -Wextra
STD = -masm=intel -std=gnu99
OTHER = -ffreestanding -nostartfiles -m32

LIBC = ./klibc/klibc.a

#Flags
AFLAGS	=	-f elf32
CFLAGS	=	$(NOLIBC) $(NOINSTR) $(OPTI) $(NAZI) $(STD) $(OTHER) $(INCLUDE)
LDFLAGS	=	-T $(LDFILE) -nostdlib #-nodefaultlib -lgcc

#Rules
all: $(NAME)

$(NAME): $(OBJ) linker.ld
	make -C libc
	make -C klibc
	$(LD) $(LDFLAGS) $(OBJ) $(LIBC) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.asm
	$(CA) $(AFLAGS) -o $@ $<

clean:
	rm -rf isodir
	rm -f /tmp/qemu.log
	rm -f /tmp/bochs.log
	rm -f $(NAME) $(ISO) $(OBJ)
	make -C libc clean
	make -C klibc clean

iso: $(ISO)

isodir isodir/boot isodir/boot/grub:
	mkdir -p $@

isodir/boot/$(NAME): $(NAME) isodir/boot
	cp $< $@

isodir/boot/grub/grub.cfg: grub.cfg isodir/boot/grub
	cp $< $@

$(ISO): isodir/boot/$(NAME) isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir

run-bochs: $(ISO)
	bochs -q -f ./bochs.cfg

run-qemu: $(ISO)
	qemu-system-i386 -cdrom $(ISO) -monitor stdio -d cpu_reset

show:
	echo $(OBJ) > /dev/null

.PHONEY: all clean iso run-qemu
