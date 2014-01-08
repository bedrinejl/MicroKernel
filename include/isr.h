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

#endif
