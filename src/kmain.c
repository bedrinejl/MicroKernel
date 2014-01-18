#include "vga.h"
#include "paging.h"
#include "gdt.h"
#include "idt.h"
#include "stdlib.h"

extern void FASTCALL outb(uint8_t val, uint16_t port);

void userTask(void)
{
  //asm volatile ("int	0x80");
  while (1);
}
void __end() {}

void kmain()
{
  vga_terminal *pterm;

  int i;

  InitializePaging();
  gdtInitialize();
  idtInitialize();
  pterm = get_terminal_instance(); 
  terminal_initialize(pterm);
  /*
    memcpy(0x13000, &userTask, 100);
    asm volatile ("cli");
    asm volatile ("push		0x3B"); // SS
    asm volatile ("push		0x30000"); // ESP
    asm volatile ("pushf");
    asm volatile ("pop		eax");
    asm volatile ("or		eax, 0x200");
    asm volatile ("and		eax, 0xFFFFBFFF");
    asm volatile ("push		eax"); // EFLAGS
    asm volatile ("push		0x2B"); // CS
    asm volatile ("push		0x13000"); // EIP
    asm volatile ("mov		ax, 0x33");
    asm volatile ("mov		ds, ax");

    asm volatile ("iret");

    printf("OK1\n");
    while (1);
  */

  asm volatile ("sti");
  
  //printf("%i\n", 5 /0);

  //  asm volatile ("int 5");

  while(1);
}
