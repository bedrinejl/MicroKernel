#ifndef _SYSCALL_H
#define _SYSCALL_H

#define SYSCALL_INTERRUPT_NUMBER	(0x80)

typedef int32_t (*syscall_t) (void);

void STDCALL KiSysCallHandler(t_context *pCtx);

#endif
