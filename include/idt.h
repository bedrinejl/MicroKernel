#ifndef _IDT_H
#define _IDT_H

#include <sys/types.h>
#include <stddef.h>

#include "kernel.h"

#define IDT_BASE_ADDR   (0x00000000)
#define IDT_ENTRY_COUNT (255)

#define IDT_INT_GATE  (0x8E) /* interrupts P=1, DPL=00b, S=0, type=1110b => type_attr=1000_1110b=0x8E*/

struct s_idtentry {
  uint16_t offset_low;   // 0 .. 15
  uint16_t select;       // a code segment selector in GDT or LDT
  uint8_t zero;          // unused, set to 0
  uint8_t type_attr;     // type and attributes
  uint16_t offset_high;  // 0 .. 16
} __attribute__ ((packed));
typedef struct s_idtentry t_idtentry;


struct s_idtdesc {
  uint16_t limit;
  uint32_t base;
} __attribute__ ((packed));

typedef struct s_idtdesc t_idtdesc;

t_idtentry  *idtGetEntries(void);
void         idtInitialize(void);
void         idtSetEntry(t_idtentry *pidtEntry, uint32_t offset, uint16_t select, uint8_t type_attr);

#endif
