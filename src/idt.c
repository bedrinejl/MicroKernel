#include "idt.h"
#include "stdlib.h"

void _asm_default_int(void) {}; //REMOVE {} when asm function exist
void _asm_irq_0(void) {};
void _asm_irq_1(void) {};

t_idtentry      *idtGetEntries(void)
{
  static t_idtentry     idtEntries[IDT_ENTRY_COUNT];

  return idtEntries;
}

t_idtdesc       *idtGetDescriptor(void)
{
  static t_idtdesc      desc;

  return &desc;
}

void          idtInitialize(void)
{
  //t_idtdesc *pDesc = idtGetDescriptor();
    t_idtentry *pEntries = idtGetEntries();

    for (int i = 0; i < IDT_ENTRY_COUNT; i++)
      {
	idtSetEntry(&pEntries[i], (uint32_t) _asm_default_int, 0x08, IDT_INT_GATE);
      }
    
    idtSetEntry(&pEntries[32], (uint32_t)_asm_irq_0, 0x08, IDT_INT_GATE); /* horlog */
    idtSetEntry(&pEntries[33], (uint32_t)_asm_irq_1, 0x08, IDT_INT_GATE); /* calvier */
    
}


void         idtSetEntry(t_idtentry *pidtEntry, uint32_t offset, uint16_t select, uint8_t type_attr)
{
  pidtEntry->offset_low = (offset & 0xffff);
  pidtEntry->select = select;
  pidtEntry->zero = 0;
  pidtEntry->type_attr = type_attr;
  pidtEntry->offset_high = (offset & 0xffff0000) >> 16;
}
