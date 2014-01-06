#include "libc.h"

size_t strlen(const char* str)
{
  size_t ret = 0;
  while (str[ret] != '\0')
    ret++;
  return ret;
}

void		*memcpy(void *dest, const void *src, size_t n)
{
  uint8_t *pdst = (uint8_t*) dest;
  uint8_t *psrc = (uint8_t*) src;

  while (n--)
    *pdst++ = *psrc++;

  return dest;
}
