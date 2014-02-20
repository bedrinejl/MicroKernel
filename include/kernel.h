#ifndef _KERNEL_H
#define _KERNEL_H

#define FASTCALL __attribute__((fastcall))
#define STDCALL __attribute__((stdcall))

#define KERNEL extern

#define SIZEOFARRAY(x) (sizeof(x) / sizeof(*(x)))

typedef int bool;
#define FALSE   ((bool) 0)
#define TRUE	(!FALSE)

#define UNUSED(x) ((void) (x))

typedef unsigned char u8;
typedef signed char i8;

typedef unsigned short u16;
typedef unsigned short le16;
typedef unsigned short be16;
typedef short i16;

typedef unsigned int u32;
typedef unsigned int le32;
typedef unsigned int be32;
typedef int i32;

#if __x86_64__
typedef unsigned long u64;
typedef unsigned long le64;
typedef unsigned long be64;
typedef long i64;
#else
typedef unsigned long long u64;
typedef unsigned long long le64;
typedef unsigned long long be64;
typedef long long i64;
#endif

typedef u8 uint8_t;
typedef i8 int8_t;

typedef u16 uint16_t;
typedef i16 int16_t;

typedef u32 uint32_t;
typedef i32 int32_t;

typedef u64 uint64_t;
typedef i64 int64_t;

typedef unsigned int pid_t;

typedef unsigned int size_t;


# define va_start(v,l) __builtin_va_start(v,l)
# define va_end(v) __builtin_va_end(v)
# define va_arg(v,l) __builtin_va_arg(v,l)
# define va_copy(d,s) __builtin_va_copy(d,s)

typedef __builtin_va_list va_list;

#endif
