/*
** my_printf.h for my_printf in /home/klarma_n//work/systeme_unix/my_printf/my_printf
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Nov 14 17:38:48 2011 nicolas klarman
** Last update Sun Nov 20 13:05:43 2011 nicolas klarman
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include "stdarg.h"

typedef int (*funcprint)(va_list *pa);

typedef struct s_fp
{
  char flag;
  funcprint funcprint;
} t_fp;

int     printf(char *str, ...);
int     find_func(char format, va_list *args);
int     put_nbr_base(int n, char *base);
int	put_nbr_base_u(unsigned int n, char *base);
int	print_s(va_list *pa);
int	print_c(va_list *pa);
int     print_d(va_list *pa);
int	print_p(va_list *pa);
int	print_u(va_list *pa);
int     print_o(va_list *pa);
int     print_X(va_list *pa);
int	print_b(va_list *pa);

/*
static t_fp gl_fp[] =
  {
    {'s', &print_s},
    {'c', &print_c},
    {'d', &print_d},
    {'b', &print_b},
    {'i', &print_d},
    {'o', &print_o},
    {'u', &print_u},
    {'X', &print_X},
    {'p', &print_p},
    {0, NULL}
  };
*/
#endif
