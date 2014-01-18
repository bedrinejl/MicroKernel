#include "isr.h"
#include "panic.h"
#include "syscall.h"

static char	*pszCpuInt[] = {
  "Division by Zero Exception",
  "Debug Exception",
  "Non Maskable Interrupt",
  "Breakpoint Exception",
  "Overflow Exception",
  "Out of bounds Exception",
  "Invalid Opcode Exception",
  "No Coprocessor Exception",
  "Double Fault Exception",
  "Coprocessor Segment Overrun",
  "Invalid TSS Exception",
  "Segment Not Present",
  "Stack Fault Exception",
  "General Protection Fault",
  "Page-Fault Exception",
  "Unknown interrupt exception",
  "x87 FPU Error",
  "Align Check Exception",
  "Machine Check Exception",
  "SIMD FPU Exception",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved"
};

#define CPU_INT		31

handler_t	pHandlers[] = {

};

void		STDCALL InterruptServiceRoutineCHandler(t_context *pctx)
{
  //if (ctx.uiNumber <= CPU_INT)
  //ctx.uiErrCode = cpuIntHandler(&ctx);
  //else
  // ctx.uiErrCode = pHandlers[ctx.uiNumber - CPU_INT](&ctx);
 
  if (pctx->uiNumber <= CPU_INT)
    {
      terminalBlueScreenOfDeath(pctx->uiNumber, pszCpuInt[pctx->uiNumber], pctx->eip);
      //printf("ds: %p\n", ctx.ds);
      //printf("edi: %p\n", ctx.edi);
      //printf("esi: %p\n", ctx.esi);
      //printf("ebp: %p\n", ctx.ebp);
      //printf("esp: %p\n", ctx.esp);
      //printf("ebx: %p\n", ctx.ebx);
      //printf("edx: %p\n", ctx.edx);
      //printf("ecx: %p\n", ctx.ecx);
      //printf("eax: %p\n", ctx.eax);
      //printf("uiNumber: %i\n", ctx.uiNumber);
      //printf("uiErrCode: %i\n", ctx.uiErrCode);
      //printf("eip: %p\n", ctx.eip);
      //printf("cs: %p\n", ctx.cs);
      //printf("eflags: %p\n", ctx.eflags);
      //printf("useresp: %p\n", ctx.useresp);
      //printf("ss: %p\n", ctx.ss);
    }
  else if (pctx->uiNumber == SYSCALL_INTERRUPT_NUMBER)
    KiSysCallHandler(pctx);
}
