#include "stdlib.h"

void *memset(void *s, int c, size_t n)
{
  while (n--)
    *(((uint8_t*) s) + n) = (uint8_t) c;
  return s;
}
