/*
** my_putchar.c for my_putchar in /home/klarma_n//progc/lib/my
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Mon Oct 24 11:01:03 2011 nicolas klarman
** Last update Mon Oct 24 11:02:16 2011 nicolas klarman
*/

#include "vga.h"

void	putchar(char c)
{
  vga_terminal *pterm = get_terminal_instance();
  terminal_putchar(pterm, c);
}
