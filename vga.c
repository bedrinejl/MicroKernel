#include "vga.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

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

void terminal_setcolor(vga_color fg, vga_color bg)
{
  terminal_color = make_color(fg, bg);
}

void terminal_initialize()
{
  terminal_initialize_with_color(fg_default_color, bg_default_color);
}

void terminal_clear_buffer()
{
  terminal_buffer = (uint16_t*) VGA_BUFFER_MODE;
  for(size_t y = 0; y < VGA_HEIGHT; y++)
    for(size_t x = 0; x < VGA_WIDTH; x++)
      {
        const size_t index = y * VGA_WIDTH + x;
        terminal_buffer[index] = make_vgaentry(' ', terminal_color);
      }
}

void terminal_initialize_with_color(vga_color fg, vga_color bg)
{
  terminal_row = 0;
  terminal_column = 0;
  terminal_setcolor(fg, bg);
  terminal_clear_buffer();
}

void terminal_put_vgaentry_at(char c, vga_color color, size_t x, size_t y)
{
  const size_t index = y * VGA_WIDTH + x;
  terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(char c)
{
  terminal_put_vgaentry_at(c, terminal_color, terminal_column, terminal_row);
  if (++terminal_column == VGA_WIDTH)
    {
      terminal_column = 0;
      if (++terminal_row == VGA_HEIGHT)
        {
          terminal_row = 0;
        }
    }
}

void terminal_putstr(const char* data)
{
  size_t datalen = strlen(data);
  for (size_t i = 0; i < datalen; i++)
    terminal_putchar(data[i]);
}
