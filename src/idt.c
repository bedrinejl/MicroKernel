#include "idt.h"
#include "stdlib.h"
#include "asmISR.h"

extern void FASTCALL idtFlush(t_idtdesc *pDesc);
extern void FASTCALL RemapPIC(uint8_t btOffset1, uint8_t btOffset2);


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
  t_idtdesc *pDesc = idtGetDescriptor();
  t_idtentry *pEntries = idtGetEntries();

  RemapPIC(0x20, 0x28);
  /*
  for (int i = 0; i < IDT_ENTRY_COUNT; i++)
    {
      idtSetEntry(&pEntries[i], (uint32_t) &InterruptServiceRoutineDefaultHandler, 0x08, IDT_INT_GATE);
    }
  */
  //idtSetEntry(&pEntries[32], (uint32_t)_asm_irq_0, 0x08, IDT_INT_GATE); /* horlog */
  //idtSetEntry(&pEntries[33], (uint32_t)_asm_irq_1, 0x08, IDT_INT_GATE); /* calvier */


  idtSetEntry(&pEntries[0], (uint32_t) &_isr0, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[1], (uint32_t) &_isr1, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[2], (uint32_t) &_isr2, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[3], (uint32_t) &_isr3, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[4], (uint32_t) &_isr4, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[5], (uint32_t) &_isr5, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[6], (uint32_t) &_isr6, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[7], (uint32_t) &_isr7, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[8], (uint32_t) &_isr8, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[9], (uint32_t) &_isr9, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[10], (uint32_t) &_isr10, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[11], (uint32_t) &_isr11, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[12], (uint32_t) &_isr12, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[13], (uint32_t) &_isr13, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[14], (uint32_t) &_isr14, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[15], (uint32_t) &_isr15, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[16], (uint32_t) &_isr16, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[17], (uint32_t) &_isr17, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[18], (uint32_t) &_isr18, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[19], (uint32_t) &_isr19, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[20], (uint32_t) &_isr20, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[21], (uint32_t) &_isr21, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[22], (uint32_t) &_isr22, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[23], (uint32_t) &_isr23, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[24], (uint32_t) &_isr24, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[25], (uint32_t) &_isr25, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[26], (uint32_t) &_isr26, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[27], (uint32_t) &_isr27, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[28], (uint32_t) &_isr28, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[29], (uint32_t) &_isr29, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[30], (uint32_t) &_isr30, 0x08, IDT_INT_GATE);
  idtSetEntry(&pEntries[31], (uint32_t) &_isr31, 0x08, IDT_INT_GATE);
  
  pDesc->limit = IDT_ENTRY_COUNT * sizeof(t_idtentry);
  pDesc->base = (uint32_t)  pEntries;//IDT_BASE_ADDR;

  //memcpy((void*) pDesc->base, pEntries, pDesc->limit);

  idtFlush(pDesc);
}


void         idtSetEntry(t_idtentry *pidtEntry, uint32_t offset, uint16_t select, uint8_t type_attr)
{
  pidtEntry->offset_low = (offset & 0xffff);
  pidtEntry->select = select;
  pidtEntry->zero = 0;
  pidtEntry->type_attr = type_attr;
  pidtEntry->offset_high = (offset & 0xffff0000) >> 16;
}
