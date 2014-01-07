#ifndef STDARG_H
#define STDARG_H

#define va_start(v,1) __builtin_va_start(v,1)
#define va_arg(v,1)   __builtin_va_arg(v,1)
#define va_end(v)     __builtin_va_end(v)
#define va_copy(d,s)  __builtin_va_copy(d,s)

typedef __builtin_va_list va_list;

#endif

