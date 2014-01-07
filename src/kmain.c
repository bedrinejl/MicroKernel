#include "vga.h"
#include "paging.h"
#include "gdt.h"
#include "stdlib.h"

void kmain()
{
  vga_terminal *pterm;

  InitializePaging();
  gdtInitialize();
  pterm = get_terminal_instance(); 
  terminal_initialize(pterm);

  asm("mov ax, 0x0FE6");
  asm("mov word [0xB8000], ax");

  printk(2,"Mikro\n");
  printk(3,"     is\n");
  printk(4,"       the\n");
  printk(5,"          best\n");
  printk(6,"              kernel\n");

  while(1);
}
