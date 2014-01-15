#include "paging.h"

extern void FASTCALL EnablePaging(uint32_t *pageDir); // cf kernel.asm
/*
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
  uint32_t      *puiKernelPageDirPtr;
  uint32_t	*puiKernelPageTable = GetKernelPageTable();
  uint32_t      *puiKernelPageTablePtr;
  uint32_t	i, j;

  puiKernelPageDirPtr = (char *)puiKernelPageDir + 0x40000000; 
  puiKernelPageTablePtr = (char *)puiKernelPageTable + 0x40000000;

  
  i = SIZEOFARRAY(puiKernelPageTable);
  j = 0;
  while (i--)
    {
      puiKernelPageTable[i] = j | 0x03;
      j += PAGE_SIZE;
      puiKernelPageDir[i] = 0;
    }

  puiKernelPageDir[0] = ((uint32_t) puiKernelPageTablePtr | 0x03);
  puiKernelPageDir[768] = ((uint32_t) puiKernelPageTablePtr | 0x03);

  EnablePaging(puiKernelPageDirPtr);
}
*/

unsigned long kernelpagedir[1024] __attribute__ ((aligned (4096)));
unsigned long lowpagetable[1024] __attribute__ ((aligned (4096)));

void  InitializePaging(void)
{
  void *kernelpagedirPtr = 0;
  void *lowpagetablePtr = 0;
  int k = 0;

  kernelpagedirPtr = (char *)kernelpagedir + 0x40000000;
  lowpagetablePtr = (char *)lowpagetable + 0x40000000;
  for (k = 0; k < 1024; k++)
    {
      lowpagetable[k] = (k * 4096) | 0x3;
      kernelpagedir[k] = 0;
    }

  kernelpagedir[0] = (unsigned long)lowpagetablePtr | 0x3;
  kernelpagedir[768] = (unsigned long)lowpagetablePtr | 0x3;

  EnablePaging(kernelpagedirPtr);
}

