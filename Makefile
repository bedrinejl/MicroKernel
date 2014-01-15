NAME	=	kernel

ASM_SRC	=	src/asmIRQ.asm	\
		src/asmISR.asm	\
		src/kernel.asm

ASM_OBJ =	$(ASM_SRC:.asm=.o)

C_SRC	= src/libc/find_prime_sup.c                                \
        src/libc/is_prime.c                                        \
        src/libc/put_nbr.c                                        \
        src/libc/strcat.c                                        \
        src/libc/str_isnum.c                                        \
        src/libc/strlcat.c                                        \
        src/libc/strncat.c                                        \
        src/libc/strstr.c                                        \
        src/libc/swap.c                                                \
        src/libc/getnbr.c                                        \
        src/libc/memcpy.c                                        \
        src/libc/memset.c                                        \
        src/libc/power_rec.c                                        \
        src/libc/putstr.c                                        \
        src/libc/square_root.c                                        \
        src/libc/strcmp.c                                        \
        src/libc/str_isalpha.c                                        \
        src/libc/str_isprintable.c                                \
        src/libc/strlen.c                                        \
        src/libc/strncmp.c                                        \
        src/libc/isneg.c                                        \
        src/libc/putchar.c                                        \
        src/libc/revstr.c                                        \
        src/libc/strcapitalize.c                                \
        src/libc/strcpy.c                                        \
        src/libc/str_islower.c                                        \
        src/libc/str_isupper.c                                        \
        src/libc/strlowcase.c                                        \
        src/libc/strncpy.c                                        \
        src/libc/strupcase.c                                        \
        src/libc/printf/printf.c                                \
        src/libc/printf/print/put_nbr_base.c                        \
        src/libc/printf/print/put_nbr_base_u.c                        \
        src/libc/printf/print/putstr_o.c                        \
        src/libc/printf/print/print_b.c                                \
        src/libc/printf/print/print_c.c                                \
        src/libc/printf/print/print_d.c                                \
        src/libc/printf/print/print_o.c                                \
        src/libc/printf/print/print_p.c                                \
        src/libc/printf/print/print_s.c                                \
        src/libc/printf/print/print_u.c                                \
        src/libc/printf/print/print_X.c                                \
        src/kernel.o                                                \
        src/asmISR.o                                                \
        src/asmIRQ.o                                                \
        src/kmain.c                                                \
        src/paging.c                                                \
        src/idt.c                                                \
        src/isr.c                                                \
        src/irq.c                                                \
        src/gdt.c                                                \
        src/vga.c                                                \
        src/panic.c

C_OBJ	=	$(C_SRC:.c=.o)

OBJ	=	$(ASM_OBJ) \
		$(C_OBJ)

CA	=	nasm
CC	=	gcc
LD	=	ld
RM	=	rm -f

AFLAGS	=	-f elf32
CFLAGS	=	-m32 -nostdlib -nostartfiles -nostdlib -fno-builtin -fno-stack-protector -mno-mmx -mno-3dnow -mno-sse -mno-sse2 -mno-sse3 -I ./include -std=gnu99 -masm=intel
LDFLAGS	=	-T linker.ld -nostdlib -nodefaultlib

$(NAME)	: $(ASM_OBJ) $(C_OBJ)
	$(LD) $(LDFLAGS) -o $(NAME) $(C_OBJ) $(ASM_OBJ)

all	: $(NAME)

clean	:
	$(RM) $(OBJ) *~ #*#

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

%.o: %.asm
	$(CA) $(AFLAGS) -o $@ $<
