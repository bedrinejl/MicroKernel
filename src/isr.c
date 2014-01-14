#include "isr.h"
#include "panic.h"

static char	*pszCpuInt[] = {
  "Division by zero exception",
  "Debug exception",
  "Non maskable interrupt",
  "Breakpoint exception",
  "Into detected overflow",
  "Out of bounds exception",
  "Invalid opcode exception",
  "No coprocessor exception",
  "Double fault",
  "Coprocessor segment overrun",
  "Bad TSS",
  "Segment not present",
  "Stack fault",
  "General protection fault",
  "Page fault",
  "Unknown interrupt exception",
  "Coprocessor fault",
  "Alignment check exception",
  "Machine check exception",
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
      asm("hlt");
      while (1);
      //SendEndOfInterrupt(ctx.uiNumber);
    }
}
