#include "vga.h"
#include "paging.h"
#include "gdt.h"
#include "idt.h"
#include "stdlib.h"

extern void FASTCALL outb(uint8_t val, uint16_t port);

void kmain()
{
  vga_terminal *pterm;

  int i;

  InitializePaging();
  gdtInitialize();
  idtInitialize();
  pterm = get_terminal_instance(); 
  terminal_initialize(pterm);


  //outb(0xfd, 0x21);
  //outb(0xff, 0xa1);
  asm("sti");
  //printf("%i\n", 5 /0);
  
  while(1);
}
