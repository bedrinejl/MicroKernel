#ifndef _KERNEL_H
#define _KERNEL_H

#include <stdint.h>

#define FASTCALL __attribute__((fastcall)) 
#define STDCALL __attribute__((stdcall)) 

#define KERNEL extern 

#define SIZEOFARRAY(x) (sizeof(x) / sizeof(*(x)))

#endif
