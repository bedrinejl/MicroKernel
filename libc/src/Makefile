##
## Makefile for Makefile in /home/klarma_n//progc/lib/my
##
## Made by nicolas klarman
## Login   <klarma_n@epitech.net>
##
## Started on  Mon Oct 24 10:21:43 2011 nicolas klarman
## Last update Sun Nov 20 15:24:27 2011 nicolas klarman
##

NAME=	../libc.a

SRC=	my_find_prime_sup.c \
	my_is_prime.c \
	my_put_nbr.c \
	my_showmem.c \
	my_sort_int_tab.c \
	my_strcat.c\
	my_strdup.c \
	my_str_isnum.c \
	my_strlcat.c \
	my_strncat.c\
	my_strstr.c\
	my_swap.c \
	my_getnbr.c \
	my_power_rec.c \
	my_putstr.c \
	my_showstr.c \
	my_square_root.c \
	my_strcmp.c\
	my_str_isalpha.c \
	my_str_isprintable.c \
	my_strlen.c \
	my_strncmp.c\
	my_isneg.c \
	my_putchar.c \
	my_revstr.c \
	my_strcapitalize.c \
	my_strcpy.c \
	my_str_islower.c \
	my_str_isupper.c \
	my_strlowcase.c \
	my_strncpy.c \
	my_strupcase.c \
	my_printf/my_printf.c \
	my_printf/print/my_put_nbr_base.c \
	my_printf/print/my_put_nbr_base_u.c \
	my_printf/print/my_putstr_o.c \
	my_printf/print/print_b.c \
	my_printf/print/print_c.c \
	my_printf/print/print_d.c \
	my_printf/print/print_o.c \
	my_printf/print/print_p.c \
	my_printf/print/print_s.c \
	my_printf/print/print_S.c \
	my_printf/print/print_u.c \
	my_printf/print/print_X.c

OBJ=    $(SRC:.c=.o)

all :	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
