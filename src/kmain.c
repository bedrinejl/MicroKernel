#include "vga.h"
#include "gdt.h"
#include "stdlib.h"

void kmain()
{
  vga_terminal *pterm = get_terminal_instance();
  terminal_initialize(pterm);

  gdtInitialize();
  terminalBlueScreenOfDeath(pterm);


}
