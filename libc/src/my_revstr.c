/*
** my_revstr.c for my_revstr in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 12:04:01 2011 nicolas klarman
** Last update Tue Oct 11 19:44:08 2011 nicolas klarman
*/

int     my_revstr_strlen(char *str);

char    *my_revstr(char *str)
{
  char  strc;
  int   i;
  int   j;

  i = 0;
  j = my_revstr_strlen(str) - 1;
  while (i < j)
    {
      strc = str[j];
      str[j] = str[i];
      str[i] = strc;
      i = i + 1;
      j = j - 1;
    }
  return str;
}

int     my_revstr_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return i;
}
