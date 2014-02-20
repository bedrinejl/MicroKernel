#include "klibc.h"

size_t	kstrlen(const char *s)
{
  char	*psz;

  psz = (char*) s;
  while (*psz)
    psz++;
  return (size_t) (psz - s);
}

char	*kstrcpy(char *dest, const char *src)
{
  while ((*dest++ = *src++));
  return --dest;
}
