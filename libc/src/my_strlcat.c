/*
** my_strlcat.c for my_strlcat in /home/klarma_n//progc/Jour_07
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Tue Oct 11 14:38:30 2011 nicolas klarman
** Last update Tue Oct 11 15:35:56 2011 nicolas klarman
*/

char	*my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	j;

  i = 0;
  while (dest[i] != '\0'&& size != 0)
    i = i + 1;
  size = size - i;
  j = 0;
  while (src[j] != '\0' && size > 0)
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
      size = size - 1;
    }
  dest[i - 1] = '\0';
  return dest;
}
