#include <sys/types.h>
#include <stddef.h>

#include "paging.h"

extern void __attribute__((fastcall)) EnablePaging(uint32_t *pageDir); // cf kernel.asm

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

void  InitializePaging(void)
{
  void *kernelpagedirPtr = 0;
  void *kernelpagetablePtr = 0;
  uint32_t *kernelpagedir = GetKernelPageDirectory();
  uint32_t *kernelpagetable = GetKernelPageTable();
  int k = 0;

  kernelpagedirPtr = (char *)kernelpagedir + 0x40000000;
  kernelpagetablePtr = (char *)kernelpagetable + 0x40000000;

  for (k = 0; k < 1024; k++)
    {
      kernelpagetable[k] = (k * 4096) | 0x3;
      kernelpagedir[k] = 0;
    }

  kernelpagedir[0] = (uint32_t)kernelpagetablePtr | 0x3;
  kernelpagedir[768] = (uint32_t)kernelpagetablePtr | 0x3;

  EnablePaging(kernelpagedirPtr);
}

