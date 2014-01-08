#ifndef _ISR_H
#define _ISR_H

#include <stdint.h>
#include "kernel.h"

typedef struct s_context
{
  uint32_t	ds;
  uint32_t	edi;
  uint32_t	esi;
  uint32_t	ebp;
  uint32_t	esp;
  uint32_t	ebx;
  uint32_t	edx;
  uint32_t	ecx;
  uint32_t	eax;
  uint32_t	uiNumber;
  uint32_t	uiErrCode;
  uint32_t	eip;
  uint32_t	cs;
  uint32_t	eflags;
  uint32_t	useresp;
  uint32_t	ss;
}		t_context;

typedef uint32_t (*handler_t) (t_context *pContext);

void InterruptServiceRoutineCHandler(t_context ctx);

extern void _isr0(void);
extern void _isr1(void);
extern void _isr2(void);
extern void _isr3(void);
extern void _isr4(void);
extern void _isr5(void);
extern void _isr6(void);
extern void _isr7(void);
extern void _isr8(void);
extern void _isr9(void);
extern void _isr10(void);
extern void _isr11(void);
extern void _isr12(void);
extern void _isr13(void);
extern void _isr14(void);
extern void _isr15(void);
extern void _isr16(void);
extern void _isr17(void);
extern void _isr18(void);
extern void _isr19(void);
extern void _isr20(void);
extern void _isr21(void);
extern void _isr22(void);
extern void _isr23(void);
extern void _isr24(void);
extern void _isr25(void);
extern void _isr26(void);
extern void _isr27(void);
extern void _isr28(void);
extern void _isr29(void);
extern void _isr30(void);
extern void _isr31(void);

#endif
