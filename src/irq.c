#include "irq.h"

extern void FASTCALL SendEndOfInterrupt(uint32_t dwIRQ);

static handler_t pirqHandlers[MAX_IRQ_HANDLERS] = {0};

handler_t	irqRegisterHandler(uint32_t dwIRQ, handler_t pHandler)
{
  handler_t	prevHandler = (handler_t) -1;

  if (dwIRQ < MAX_IRQ_HANDLERS)
    {
      prevHandler = pirqHandlers[dwIRQ];
      pirqHandlers[dwIRQ] = pHandler;
    }
  return prevHandler;
}

handler_t	irqUnregisterHandler(uint32_t dwIRQ)
{
  handler_t	prevHandler = (handler_t) -1;

  if (dwIRQ < MAX_IRQ_HANDLERS)
    {
      prevHandler = pirqHandlers[dwIRQ];
      pirqHandlers[dwIRQ] = (handler_t) 0;
    }
  return prevHandler;
}

void		STDCALL InterruptRequestCHandler(t_context *pctx)
{
  if (pctx->uiNumber >= 32
      && pctx->uiNumber <= 47
      && pirqHandlers[pctx->uiNumber - 32])
    pirqHandlers[pctx->uiNumber - 32](pctx);

  //printf("SendEndOfInterrupr(%i)\n", pctx->uiNumber);
  SendEndOfInterrupt(pctx->uiNumber);
}

static void    	irqClockHandler(t_context *pctx)
{
  printf("clock\n");
}

static void    	irqKeyboardHandler(t_context *pctx)
{
  printf("keyboard\n");
}

void		irqInitialize(void)
{
  //irqRegisterHandler(IRQ_CLOCK, &irqClockHandler);
  irqRegisterHandler(IRQ_KEYBOARD, &irqKeyboardHandler);
}
