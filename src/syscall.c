#include <stdint.h>
#include "kernel.h"
#include "isr.h"
#include "syscall.h"

syscall_t pSysCall[] = {

};

void STDCALL KiSysCallHandler(t_context *pCtx)
{
  if (pCtx->uiNumber != SYSCALL_INTERRUPT_NUMBER)
    return;
  pCtx->uiErrCode = pSysCall[pCtx->eax]();
}

void TestSyscall(int iParam1, char *pParam2)
{

}
