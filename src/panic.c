#include "vga.h"
#include "stdlib.h"


void setBackground(vga_terminal *pterm)
{
  uint32_t idx;
  uint16_t c;
  
  pterm->terminal_color = make_color(COLOR_WHITE, COLOR_BLUE);
  c = make_vgaentry(' ', make_color(COLOR_BLUE, COLOR_BLUE));
  idx = (VGA_HEIGHT * VGA_WIDTH);
  while (idx--)
    {
      pterm->terminal_buffer[idx] = c;
    }
}

void printTitle(vga_terminal *pterm, char *str)
{
  int x = (VGA_WIDTH / 2) - (strlen(str) / 2);
  int y = (VGA_HEIGHT / 4);

  pterm->terminal_column = x;
  pterm->terminal_row = y;
  
  printk(make_color(COLOR_BLUE, COLOR_WHITE), str);
  printk(0, "\n");
}

void printMessage(vga_terminal *pterm, int idt)
{
  int x = (VGA_WIDTH / 7);

  pterm->terminal_column = x;
  printf("A fatal exception %i has occured at _____________\n", idt);
  pterm->terminal_column = x;
  printf("the current application will be terminated.\n\n");
  pterm->terminal_column = x;
  printf("* Press any key to terminate the current application.\n");
  pterm->terminal_column = x;
  printf("* Press CTRL+ALT+DEL to restart your computer.\n");
  pterm->terminal_column = x;
  printf("  You will lose all unsaved information in all applications.\n");
}

void printPressAnyKey(vga_terminal *pterm)
{
  int x= (VGA_WIDTH / 2) - (strlen("Press any key to continue") / 2);

  printf("\n");
  pterm->terminal_column = x;
  printf("Press any key to continue\n");

}


void     terminalBlueScreenOfDeath(vga_terminal *pterm)
{
  setBackground(pterm);
  printTitle(pterm, "WINDOWS");
  printMessage(pterm, 10);
  printPressAnyKey(pterm);
}
