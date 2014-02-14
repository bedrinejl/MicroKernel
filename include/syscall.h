#ifndef _SYSCALL_H
#define _SYSCALL_H

#include "kernel.h"

#define SYSCALL_INTERRUPT_NUMBER	(0x80)
#define SYSCALL_CREATE_PROCESS		(0)
#define SYSCALL_RUN_PROCESS		(1)
#define SYSCALL_KILL			(2)
#define SYSCALL_WAIT			(3)
#define SYSCALL_SLEEP			(4)
#define SYSCALL_SEND			(5)
#define SYSCALL_RECV			(6)
#define SYSCALL_INVLPG			(7)

/*
#0: int create_process(u64 *user_pid);!
#1: int run_process(void *task_struct, void *entry, void *stack, void *root_pt);!
#2: int kill(u64 pid);!
#3: int wait(u64 pid);!
#4: void sleep(u32 milli);!
#5: int send(u64 to, void *msg, u32 size);!
#6: int recv(void *pool, u32 pool_size);!
#7: void invlpg(void *vaddr);
 */

typedef int32_t (*syscall_t) (void);

void STDCALL KiSysCallHandler(t_context *pCtx);

#endif
