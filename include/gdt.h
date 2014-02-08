#ifndef _GDT_H
#define _GDT_H

#include <sys/types.h>
#include <stddef.h>

#include "kernel.h"

#define GDT_BASE_ADDR	(0xC0000800)
#define GDT_ENTRY_COUNT	(255)

#define SEG_DESCTYPE(x)  ((x) << 0x04) // Descriptor type (0 for system, 1 for code/data)
#define SEG_PRES(x)      ((x) << 0x07) // Present
#define SEG_SAVL(x)      ((x) << 0x0C) // Available for system use
#define SEG_LONG(x)      ((x) << 0x0D) // Long mode
#define SEG_SIZE(x)      ((x) << 0x0E) // Size (0 for 16-bit, 1 for 32)
#define SEG_GRAN(x)      ((x) << 0x0F) // Granularity (0 for 1B - 1MB, 1 for 4KB - 4GB)
#define SEG_PRIV(x)     (((x) &  0x03) << 0x05)   // Set privilege level (0 - 3)

#define SEG_DATA_RD        0x00 // Read-Only
#define SEG_DATA_RDA       0x01 // Read-Only, accessed
#define SEG_DATA_RDWR      0x02 // Read/Write
#define SEG_DATA_RDWRA     0x03 // Read/Write, accessed
#define SEG_DATA_RDEXPD    0x04 // Read-Only, expand-down
#define SEG_DATA_RDEXPDA   0x05 // Read-Only, expand-down, accessed
#define SEG_DATA_RDWREXPD  0x06 // Read/Write, expand-down
#define SEG_DATA_RDWREXPDA 0x07 // Read/Write, expand-down, accessed
#define SEG_CODE_EX        0x08 // Execute-Only
#define SEG_CODE_EXA       0x09 // Execute-Only, accessed
#define SEG_CODE_EXRD      0x0A // Execute/Read
#define SEG_CODE_EXRDA     0x0B // Execute/Read, accessed
#define SEG_CODE_EXC       0x0C // Execute-Only, conforming
#define SEG_CODE_EXCA      0x0D // Execute-Only, conforming, accessed
#define SEG_CODE_EXRDC     0x0E // Execute/Read, conforming
#define SEG_CODE_EXRDCA    0x0F // Execute/Read, conforming, accessed

#define GDT_CODE_PL0 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(0)     | SEG_CODE_EXRD

#define GDT_DATA_PL0 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(0)     | SEG_DATA_RDWR

#define GDT_STACK_PL0 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                      SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                      SEG_PRIV(0)     | SEG_DATA_RDWREXPDA

#define GDT_CODE_PL3 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(3)     | SEG_CODE_EXRD

#define GDT_DATA_PL3 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                     SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                     SEG_PRIV(3)     | SEG_DATA_RDWR

#define GDT_STACK_PL3 SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
                      SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
                      SEG_PRIV(3)     | SEG_DATA_RDWREXPDA

#define GDT_TSS	SEG_PRES(1) | SEG_CODE_EXA

struct	s_gdtentry
{
  uint16_t	limit_low;	// 0 .. 15
  uint16_t	base_low;	// 0 .. 15
  uint8_t	base_middle;	// 16 .. 23
  uint8_t	access;
  uint8_t	limit_high:4;	// 16 .. 19
  uint8_t	flags:4;	//
  uint8_t	base_high;	// 24 .. 31
}__attribute__((packed));
typedef struct s_gdtentry t_gdtentry;

struct	s_gdtdesc
{
  uint16_t	limit;
  uint32_t	base;
}__attribute__((packed));
typedef struct s_gdtdesc t_gdtdesc;

struct s_tss
{
  uint16_t    previous_task, __previous_task_unused;
  uint32_t    esp0;
  uint16_t    ss0, __ss0_unused;
  uint32_t    esp1;
  uint16_t    ss1, __ss1_unused;
  uint32_t    esp2;
  uint16_t    ss2, __ss2_unused;
  uint32_t    cr3;
  uint32_t    eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi;
  uint16_t    es, __es_unused;
  uint16_t    cs, __cs_unused;
  uint16_t    ss, __ss_unused;
  uint16_t    ds, __ds_unused;
  uint16_t    fs, __fs_unused;
  uint16_t    gs, __gs_unused;
  uint16_t    ldt_selector, __ldt_sel_unused;
  uint16_t    Debug_flag, io_map;
}__attribute__((packed));
typedef struct s_tss t_tss;

t_gdtentry	*gdtGetEntries(void);
void		gdtInitialize(void);
void		gdtSetEntry(t_gdtentry *pgdtEntry, uint32_t base, uint32_t limit, uint16_t flags);

#endif
