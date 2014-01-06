#ifndef _LIBC__H
#define _LIBC_H

#include <stddef.h>
#include <stdint.h>

size_t strlen(const char* str);
void *memcpy(void *dest, const void *src, size_t n);

#endif
