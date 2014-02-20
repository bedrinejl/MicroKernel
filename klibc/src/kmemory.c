#include "klibc.h"

void	*kmemset(void *s, int c, size_t n)
{
  char	*psz = (char*) s;

  while (n--)
    {
      *psz++ = (char) (c & 0xFF);
    }
  return s;
}

void	*kmemcpy(void *dest, const void *src, size_t n)
{
  char	*pout = (char*) dest;
  char	*pin = (char*) src;

  while (n--)
    {
      *pout++ = *pin++;
    }
  return dest;
}
