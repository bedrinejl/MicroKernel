#include "kernel.h"
#include "isr.h"
#include "syscall.h"

syscall_t pSysCall[] = {

};

void STDCALL KiSysCallHandler(t_context *pCtx)
{
  if (pCtx->uiNumber != SYSCALL_INTERRUPT_NUMBER)
    /*
      pCtx struct corrupted
    */
    return;
  pCtx->uiErrCode = pSysCall[pCtx->eax]();
}

void TestSyscall(int iParam1, char *pParam2)
{
	(void) iParam1;
	(void) pParam2;
 /*
  if (pCtx->eax < SIZEOFARRAY(pSysCall))
    pCtx->uiErrCode = pSysCall[pCtx->eax]();
    else
    ERROR !!
  */
}
