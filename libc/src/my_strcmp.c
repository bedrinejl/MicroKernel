/*
** my_strcmp.c for my_strcmp in /home/klarma_n//progc/Jour_06
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 10 15:26:57 2011 nicolas klarman
** Last update Mon Oct 10 19:29:49 2011 nicolas klarman
*/

int	my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i = i + 1;
  return s1[i] - s2[i];
}
