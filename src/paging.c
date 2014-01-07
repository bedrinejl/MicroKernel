#include "paging.h"

extern void FASTCALL EnablePaging(void); // cf kernel.asm

uint32_t	*GetKernelPageDirectory(void)
{
  static uint32_t	puiKernelPageDir[1024] __attribute__((aligned (4096)));

  return puiKernelPageDir;
}

uint32_t	*GetKernelPageTable(void)
{
  static uint32_t	puiKernelPageTable[1024] __attribute__((aligned (4096)));

  return puiKernelPageTable;
}
//static uint32_t	puiKernelPageDir[1024] __attribute__((aligned (4096)));
// static uint32_t	puiKernelPageTable[1024] __attribute__((aligned (4096)));
void  InitializePaging(void)
{
  uint32_t	*puiKernelPageDir = GetKernelPageDirectory();
  uint32_t	*puiKernelPageTable = GetKernelPageTable();
  uint32_t	i, j;

  //puiKernelPageDir += (0x40000000 / sizeof(uint32_t));	// translate virtual address to physical address
  // puiKernelPageTable += (0x40000000 / sizeof(uint32_t));

  i = SIZEOFARRAY(puiKernelPageTable);
  j = 0;
  while (i--)
    {
      puiKernelPageTable[i] = j | 0x03;
      j += PAGE_SIZE;
      puiKernelPageDir[i] = 0;
    }

  puiKernelPageDir[0] = (uint32_t) ((char*) puiKernelPageTable + 0x40000000) | 0x03;
  puiKernelPageDir[768] = (uint32_t) ((char*) puiKernelPageTable + 0x40000000) | 0x03;
  asm("xor		eax, eax");
  asm("mov		cr3, eax");
  asm("mov		eax, cr0");
  asm("or		eax, 0x80000000");
  asm("mov		cr0, eax");
  //EnablePaging();
}
