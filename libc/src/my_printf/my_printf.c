/*
** main.c for my_printf in /home/klarma_n//work/systeme_unix/my_printf/my_printf
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Nov 14 15:35:56 2011 nicolas klarman
** Last update Sat Nov 19 19:13:20 2011 nicolas klarman
*/

//#include <unistd.h>
#include <stdarg.h>
#include "includes/my.h"
#include "includes/my_printf.h"

int	        my_printf(char *str, ...)
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
	  nb = nb + find_func(str[i + 1], &i, &args);
	  i++;
	}
      else
	{
	  my_putchar(str[i]);
	  nb = nb + i;
	  if (str[i] == '%')
	    i++;
	}
    }
  va_end(args);
  return (nb);
}

int	find_func(char format, int *i, va_list *args)
{
  int j;

  j = -1;
  while (gl_fp[++j].flag != 0)
    if (format == gl_fp[j].flag)
      return ((*gl_fp[j].funcprint)(args));
  my_putchar('%');
  my_putchar(format);
  return (2);
}
