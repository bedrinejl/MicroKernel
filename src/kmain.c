#include "vga.h"
#include "gdt.h"
#include "stdlib.h"

void kmain()
{
  vga_terminal *pterm = get_terminal_instance();
  terminal_initialize(pterm);

   gdtInitialize();
   asm("mov ax, 0x0FE6");
   asm("mov word [0xB8000], ax");
}
