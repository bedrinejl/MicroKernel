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

  terminalBlueScreenOfDeath(pterm);

  while(1);
}
