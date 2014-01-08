#include "vga.h"
#include "paging.h"
#include "gdt.h"
#include "idt.h"
#include "stdlib.h"

void kmain()
{
  vga_terminal *pterm;

  //InitializePaging();
  gdtInitialize();
  idtInitialize();
  pterm = get_terminal_instance(); 
  terminal_initialize(pterm);
  
  printf("%i\n", 5 /0);
  //printTaskBar(pterm);
  //for(int i = 0; i < 200; i++)
  //    printf("%i\n", i);
  while(1);
}
