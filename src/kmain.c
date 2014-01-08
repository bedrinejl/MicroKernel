#include "vga.h"
#include "paging.h"
#include "gdt.h"
#include "stdlib.h"

void kmain()
{
  vga_terminal *pterm;

  //InitializePaging();
  gdtInitialize();
  pterm = get_terminal_instance(); 
  terminal_initialize(pterm);

  //  terminalBlueScreenOfDeath(pterm);
  printTaskBar(pterm);
  for(int i = 0; i < 200; i++)
      printf("%i\n", i);
  while(1);
}
