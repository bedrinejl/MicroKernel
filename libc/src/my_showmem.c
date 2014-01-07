/*
** my_showmem.c for my_showmem in /home/klarma_n//progc/lib/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 24 10:59:07 2011 nicolas klarman
** Last update Tue Nov 15 14:43:30 2011 nicolas klarman
*/

#include "include/my.h"

void	my_showmem_print_adress(int adress, int pos, int size);
void	my_showmem_print_hexa(char *hexa);
void	my_showmem_print_str(char *str);

int	my_showmem(char *str, int size)
{
  int	length;
  int	i;

  length = 0;
  while (str[length])
    length++;
  i = 0;
  while (length > 0)
    {
      my_showmem_print_adress(i * 16, 0, 8);
      my_putchar(':');
      my_showmem_print_hexa(str + i * 16);
      my_putchar(' ');
      my_showmem_print_str(str + i * 16);
      my_putchar('\n');
      i++;
      length -= 16;
    }
  return 0;
}

void	my_showmem_print_adress(int adress, int pos, int size)
{
  char	*base;

  base = "0123456789ABCDEF";
  if (pos < (size - 1))
    my_showmem_print_adress(adress / 16, pos + 1, size);
  my_putchar(base[adress % 16]);
}

void	my_showmem_print_hexa(char *hexa)
{
  int	valid;
  int	value;
  int	i;

  valid = 1;
  i = 0;
  while (i < 16)
    {
      if (valid && hexa[i])
	value = hexa[i];
      else
	{
	  value = 0;
	  valid = 0;
	}
      if (!(i % 2))
	my_putchar(' ');
      if (valid)
	my_showmem_print_adress(value, 0, 2);
      else
	my_putstr('  ');
      i++;
    }
}

void	my_showmem_print_str(char *str)
{
  int	i;

  i = 0;
  while (i < 16 && str[i])
    {
      if (str[i] < 32 || str[i] == 127)
	my_putchar('.');
      else
	my_putchar(str[i]);
      i++;
    }
}
