##
## Makefile for libmy in /u/all/bedrin_j/cu/rendu/piscine/lib/my
## 
## Made by jean-louis bedrine
## Login   <bedrin_j@epitech.net>
## 
## Started on  Wed Dec 16 11:21:36 2009 jean-louis bedrine
## Last update Thu Jan 27 16:44:11 2011 jean-louis bedrine
##

NAME	= "klibc.a"
SRCS	= src/kprintf.c			\
	  src/kultoa.c			\
	  src/kmemory.c			\
	  src/kstring.c

CC	= i586-elf-gcc
OBJS	= $(SRCS:.c=.o)
RM	= rm -rf
CFLAGS	+= -I ./include -I ../include -W -Wall -O2 -nostdinc -fno-builtin -nostartfiles -nodefaultlibs 

all: $(NAME)

$(NAME): $(OBJS)
	ar r $@ $(OBJS)
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

#all	:
#	$(CC) -c $(CFLAGS) $(SRCS) -o $(OBJS)

clean	:
	$(RM) $(OBJS)
	$(RM) *~
	$(RM) \#*
	$(RM) $(NAME)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
