#include "vga.h"
#include "paging.h"
#include "gdt.h"
#include "idt.h"
#include "klibc.h"

//#include "stdlib.h"
//#include "stddef.h"

extern void FASTCALL outb(uint8_t val, uint16_t port);

void userTask(void)
{
  //asm volatile ("int	0x80");
  return;
}
void __end() {}

void kmain()
{
  vga_terminal *pterm;

  int i;
  (void) i;

  InitializePaging();
  gdtInitialize();
  idtInitialize();
  pterm = get_terminal_instance();
  terminal_initialize(pterm);

  kmemcpy((void*) 0x20000, &userTask, 200);
  /*
    asm volatile ("cli");
    asm volatile ("mov ax,0x23");
    asm volatile ("mov ds,ax");
    asm volatile ("mov es,ax ");
    asm volatile ("mov fs,ax ");
    asm volatile ("mov gs,ax");
 
    asm volatile ("mov eax,esp");
    asm volatile ("push 0x23");
    asm volatile ("push eax");
    asm volatile ("pushf");
    asm volatile ("push 0x1B");
    asm volatile ("push 0x30000");
    //   asm volatile ("push userTask");
    asm volatile ("iret");
  */

  asm volatile ("cli");
  asm volatile ("push		0x33"); // SS
  asm volatile ("push		0x30000"); // ESP

  asm volatile ("pushf");
  asm volatile ("pop		eax");
  asm volatile ("or		eax, 0x200");
  asm volatile ("and		eax, 0xFFFFBFFF");
  asm volatile ("push		eax"); // EFLAGS

  asm volatile ("push		0x23"); // CS
  asm volatile ("push		0x20000"); // kernel stack ptr
  asm volatile ("mov		ax, 0x2B");
  asm volatile ("mov		ds, ax");

  asm volatile ("iret");

  kprintf("OK1\n");
  //while (1);
  

  asm volatile ("sti");

  //printf("%i\n", 5 /0);

  //  asm volatile ("int 5");

  while(1);
}
