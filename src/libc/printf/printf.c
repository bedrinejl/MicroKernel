/*
** main.c for my_printf in /home/klarma_n//work/systeme_unix/my_printf/my_printf
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Nov 14 15:35:56 2011 nicolas klarman
** Last update Sat Nov 19 19:13:20 2011 nicolas klarman
*/

#include "stdlib.h"
#include "printf.h"

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

int	        printf(char *str, ...)
{
  int		i;
  va_list	args;
  int		nb;

  va_start(args, str);
  nb = 0;
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '%' && str[i + 1] != '%')
	{
	  nb = nb + find_func(str[i + 1], &args);
	  i++;
	}
      else
	{
	  putchar(str[i]);
	  nb = nb + i;
	  if (str[i] == '%')
	    i++;
	}
    }
  va_end(args);
  return (nb);
}

int	find_func(char format, va_list *args)
{
  int j;

  j = -1;
  while (gl_fp[++j].flag != 0)
    if (format == gl_fp[j].flag)
      return ((*gl_fp[j].funcprint)(args));
  putchar('%');
  putchar(format);
  return (2);
}
