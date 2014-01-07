#include "idt.h"
#include "stdlib.h"

/*void _asm_default_int(void);
void _asm_irq_0(void);
void _asm_irq_1(void);*/

t_idtentry      *idtGetEntries(void)
{
  static t_idtentry     idtEntries[GDT_ENTRY_COUNT];

  return gdtEntries;
}

t_idtdesc       *idtGetDescriptor(void)
{
  static t_idtdesc      desc;

  return &desc;
}

void          idtInitialize(void)
{
    t_idtdesc *pDesc = idtGetDescriptor();
    t_idtentry *pEntries = gdtGetEntries();

  /*for (int i = 0; i < IDT_ENTRY_COUNT; i++)
    {
      idtSetEntry(&pEntries[i], _asm_default_int, );
    }
  */

}


void         idtSetEntry(t_idtentry *pidtEntry, uint32_t offset, uint16_t select, uint8_t type_attr)
{
  pidtEntry->offset_low = (offset & 0xffff);
  pidtEntry->select = select;
  pidEntry->zero = 0;
  pidtEntry->type_attr = type_attr;
  pidtEntry->offset_high = (offset & 0xffff0000) >> 16;
}
