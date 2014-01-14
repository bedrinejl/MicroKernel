#ifndef _IRQ_H
#define _IRQ_H

#include "isr.h"

#define MAX_IRQ_HANDLERS	(16)

#define IRQ_CLOCK	(0)
#define IRQ_KEYBOARD	(1)

void		irqInitialize(void);
handler_t	irqRegisterHandler(uint32_t dwIRQ, handler_t pHandler);
handler_t	irqUnregisterHandler(uint32_t dwIRQ);
void		STDCALL InterruptRequestCHandler(t_context *pctx);

extern void _irq0(void);
extern void _irq1(void);
extern void _irq2(void);
extern void _irq3(void);
extern void _irq4(void);
extern void _irq5(void);
extern void _irq6(void);
extern void _irq7(void);
extern void _irq8(void);
extern void _irq9(void);
extern void _irq10(void);
extern void _irq11(void);
extern void _irq12(void);
extern void _irq13(void);
extern void _irq14(void);
extern void _irq15(void);

#endif
