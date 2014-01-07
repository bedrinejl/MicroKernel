/*
** my_showstr.c for my_showstr in /home/klarma_n//progc/lib/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 24 10:58:03 2011 nicolas klarman
** Last update Mon Oct 24 10:58:27 2011 nicolas klarman
*/

void	_print_unprintable_char(char c);

/*
**
*/
int	my_showstr(char *str)
{
  int	i;

  if (!str)
    return 0;
  i = 0;
  while (str[i])
    {
      if (!my_char_isprintable(str[i]))
	{
	  _print_unprintable_char(str[i]);
	}
      else
	my_putchar(str[i]);
      i++;
    }
  return 0;
}

void	_print_unprintable_char(char c)
{
  my_putchar('\\');
  if (c < 16)
    my_putchar('0');
  my_putnbr_base(c, "0123456789abcdef");
}
