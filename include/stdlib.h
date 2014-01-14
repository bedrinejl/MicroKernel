#ifndef _LIBC_H
#define _LIBC_H

#include <stddef.h>
#include <stdint.h>
#include "stdarg.h"

void    putchar(char c);
void    *memcpy(void *dest, const void *src, size_t n);
void	*memset(void *s, int c, size_t n);
int     isneg(int nb);
int     put_nbr(int nb);
int     swap(int *a, int *b);
void    putstr(char *str);
int     strlen(const char *str);
int     getnbr(char *str);
void    sort_int_tab(int *tab, int size);
int     power_rec(int nb, int power);
int     square_root(int nb);
int     is_prime(int nombre);
int     find_prime_sup(int nb);
char    *strcpy(char *dest, char *src);
char    *strncpy(char *dest, char *src, int nb);
char    *revstr(char *str);
char    *strstr(char *str, char *to_find);
int     strcmp(char *s1, char *s2);
int     strncmp(char *s1, char *s2, int nb);
char    *strupcase(char *str);
char    *strlowcase(char *str);
char    *strcapitalize(char *str);
int     str_isalpha(char *str);
int     str_isnum(char *str);
int     str_islower(char *str);
int     str_isupper(char *str);
int     str_isprintable(char *str);
char    *strcat(char *dest, char *src);
char    *strncat(char *dest, char *src, int nb);
int     strlcat(char *dest, char *src, int size);
int     printf(char *str, ...);


#endif
