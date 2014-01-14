#include "gdt.h"
#include "stdlib.h"

extern void FASTCALL gdtFlush(t_gdtdesc *pdesc);

t_gdtentry	*gdtGetEntries(void)
{
  static t_gdtentry	gdtEntries[GDT_ENTRY_COUNT];

  return gdtEntries;
}

t_gdtdesc	*gdtGetDescriptor(void)
{
  static t_gdtdesc	desc;

  return &desc;
}

void		gdtInitialize(void)
{
  t_gdtdesc	*pDesc = gdtGetDescriptor();
  t_gdtentry	*pEntries = gdtGetEntries();

  gdtSetEntry(&pEntries[0], 0, 0, 0);

  gdtSetEntry(&pEntries[1], 0, 0x000FFFFF, GDT_CODE_PL0); // kernel code
  gdtSetEntry(&pEntries[2], 0, 0x000FFFFF, GDT_DATA_PL0); // kernel data
  gdtSetEntry(&pEntries[3], 0, 0, GDT_STACK_PL0); // kernel stack

  gdtSetEntry(&pEntries[4], 0, 0x000FFFFF, GDT_CODE_PL3); // user code
  gdtSetEntry(&pEntries[5], 0, 0x000FFFFF, GDT_DATA_PL3); // user data
  gdtSetEntry(&pEntries[6], 0, 0, GDT_STACK_PL3); // user stack

  pDesc->limit = GDT_ENTRY_COUNT * sizeof(t_gdtentry);
  pDesc->base = (uint32_t) GDT_BASE_ADDR;

  memcpy((void*) pDesc->base, pEntries, pDesc->limit);

  gdtFlush(pDesc);
}

void		gdtSetEntry(t_gdtentry *pentry, uint32_t base, uint32_t limit, uint16_t flags)
{
  pentry->limit_low = limit & 0x0000FFFF;
  pentry->base_low = base & 0x0000FFFF;
  pentry->base_middle = (base & 0x00FF0000) >> 16;
  pentry->access = flags & 0x00FF;
  pentry->flags = (flags & 0xF000) >> 12;
  pentry->limit_high = (limit & 0xF0000) >> 16;
  pentry->base_high = (base & 0xFF000000) >> 24;
}
