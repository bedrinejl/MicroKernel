/*
** my_strcapitalize.c for my_strcapitalize in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 17:31:47 2011 nicolas klarman
** Last update Mon Oct 10 20:41:18 2011 nicolas klarman
*/

char    *my_strcapitalize_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return str;
}

char	*my_strcapitalize(char *str)
{
  int	i;
  int	flag;

  i = 0;
  flag = 1;
  my_strcapitalize_strlowcase(str);
  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
	{
	  if (flag == 1)
	    str[i] = str[i] - 32;
	  flag = 0;
	}
      else if (str[i] > 47 && str[i] < 58)
	flag = 0;
      else
	flag = 1;
      i = i + 1;
    }
  return str;
}
