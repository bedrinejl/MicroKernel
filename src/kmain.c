#include "vga.h"
#include "gdt.h"
#include "stdlib.h"

void kmain()
{
  vga_terminal *pterm = get_terminal_instance();
  terminal_initialize(pterm);

  gdtInitialize();

  /*  printk(2,"Mikro\n");
  printk(3,"     is\n");
  printk(4,"       the\n");
  printk(5,"          best\n");
  printk(6,"              kernel\n");*/

  char t1[] = "salut";
  char t2[] = "ca marche";

  printf("%X, %i\n", t1, t2);


}
