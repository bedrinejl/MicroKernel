/*
** my_strncpy.c for my_strncpy in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 11:17:16 2011 nicolas klarman
** Last update Mon Oct 10 12:24:10 2011 nicolas klarman
*/

char    *my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (i < n)
    dest[i] = '\0';
  return dest;
}
