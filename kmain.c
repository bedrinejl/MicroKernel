#include "vga.h"
#include "mylib.h"

void kmain()
{
  terminal_initialize();
  terminal_putstr("Hello, kernel World\n");
}
