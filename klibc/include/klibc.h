#ifndef _KLIBC_H
#define _KLIBC_H

#include "kernel.h"

int	kprintf(const char *format, ...);

void	*kmemset(void *s, int c, size_t n);
void	*kmemcpy(void *dest, const void *src, size_t n);
char   	*kultoa(uint32_t value, char *lpszout, int radix);

size_t	kstrlen(const char *s);
char	*kstrcpy(char *dest, const char *src);

#endif
