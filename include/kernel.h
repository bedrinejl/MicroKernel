#ifndef _KERNEL_H
#define _KERNEL_H

#include <sys/types.h>
#include <stddef.h>

#define FASTCALL __attribute__((fastcall))
#define STDCALL __attribute__((stdcall))

#define KERNEL extern

#define SIZEOFARRAY(x) (sizeof(x) / sizeof(*(x)))

typedef int bool;
#define TRUE	(!FALSE)
#define FALSE	((bool) 0)

#define UNUSED(x) ((void) (x))

#endif
