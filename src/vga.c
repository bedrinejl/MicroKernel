#include "vga.h"

vga_terminal *get_terminal_instance()
{
  static vga_terminal vga;

  return &vga;
}

uint8_t make_color(uint8_t fg, uint8_t bg)
{
  return fg | bg << 4;
}

uint16_t make_vgaentry(char c, uint8_t color)
{
  uint16_t c16 = c;
  uint16_t color16 = color;
  return c16 | color16 << 8;
}

void terminal_setcolor(vga_terminal *pterm, vga_color fg, vga_color bg)
{
  pterm->terminal_color = make_color(fg, bg);
}

void terminal_initialize(vga_terminal *pterm)
{
  terminal_initialize_with_color(pterm, fg_default_color, bg_default_color);
}

void terminal_clear_buffer(vga_terminal *pterm)
{
  uint32_t idx;
  uint16_t c;

  c = make_vgaentry(' ', 0);
  idx = (VGA_HEIGHT * VGA_WIDTH) - 1;
  while (idx--)
    {
      pterm->terminal_buffer[idx] = c;
    }
}

void terminal_initialize_with_color(vga_terminal *pterm, vga_color fg, vga_color bg)
{
  pterm->terminal_buffer = (uint16_t*) VGA_BUFFER_MODE;
  pterm->terminal_row = 0;
  pterm->terminal_column = 0;
  terminal_setcolor(pterm, fg, bg);
  terminal_clear_buffer(pterm);
}

void terminal_put_vgaentry_at(vga_terminal *pterm, char c, vga_color color, size_t x, size_t y)
{
  const size_t index = y * VGA_WIDTH + x;
  pterm->terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(vga_terminal *pterm, char c)
{
  terminal_putchar_with_color(pterm, c);
}

void terminal_putchar_with_color(vga_terminal *pterm, char c)
{
  if (c == '\n')
    {
      pterm->terminal_row++;
      pterm->terminal_column = 0;
    }
  else
    {
      terminal_put_vgaentry_at(pterm, c, pterm->terminal_color, pterm->terminal_column, pterm->terminal_row);
      pterm->terminal_column++;
    }

  if (pterm->terminal_column == VGA_WIDTH)
    {
      pterm->terminal_column = 0;
      pterm->terminal_row++;
    }

  if (pterm->terminal_row == VGA_HEIGHT)
    {
      // memcpy(pterm->terminal_buffer, pterm->terminal_buffer + VGA_WIDTH, (VGA_WIDTH * (VGA_HEIGHT-1)));
      pterm->terminal_row = 0;
    }
}

void terminal_putstr_with_color(vga_terminal *pterm, const char* data)
{
  size_t datalen = strlen(data);
  for (size_t i = 0; i < datalen; i++)
    terminal_putchar_with_color(pterm, data[i]);
}

void terminal_putstr(vga_terminal *pterm, const char* data)
{
  terminal_putstr_with_color(pterm, data);
}

void printk(int color, char *str) {
  vga_terminal *pterm = get_terminal_instance();
  int lastColor = pterm->terminal_color;

  pterm->terminal_color = color;
  //TODO call printf of mylib
  terminal_putstr_with_color(pterm, str);
  pterm->terminal_color = lastColor;
}
