#include "klibc.h"

char		*kultoa(uint32_t value, char *lpszout, int radix)
{
  char		buffer[32 + 1];
  char		*ptr;
  int		digit;

  ptr = (buffer + 32);
  *ptr = 0;
  do
    {
      digit = value % radix;
      value = value / radix;
      if (digit < 10)
	*--ptr = ('0' + digit);
      else
	*--ptr = ('a' + digit - 10);
    } while (value);
  while ((*lpszout++ = *ptr++));
  return (--lpszout);
}
