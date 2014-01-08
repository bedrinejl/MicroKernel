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

uint32_t	cpuIntHandler(t_context *pContext)
{
  terminalBlueScreenOfDeath(pContext->uiNumber, pszCpuInt[pContext->uiNumber], pContext->eip);
  return 0;
}

void		InterruptServiceRoutineCHandler(t_context ctx)
{
  if (ctx.uiNumber <= CPU_INT)
    ctx.uiErrCode = cpuIntHandler(&ctx);
  //else
  // ctx.uiErrCode = pHandlers[ctx.uiNumber - CPU_INT](&ctx);
}
