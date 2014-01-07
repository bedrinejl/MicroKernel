#include "stdlib.h"

void                *memcpy(void *dest, const void *src, size_t n)
{
  uint8_t *pdst = (uint8_t*) dest;
  uint8_t *psrc = (uint8_t*) src;

  while (n--)
    *pdst++ = *psrc++;

  return dest;
}
