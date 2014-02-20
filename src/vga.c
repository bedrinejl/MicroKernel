#include "vga.h"
#include "keyboard.h"
#include "klibc.h"

vga_terminal *get_terminal_instance()
{
  static vga_terminal vga;

  return &vga;
}

void terminal_setcolor(vga_terminal *pterm, vga_color fg, vga_color bg)
{
  pterm->terminal_color = MAKE_COLOR(fg, bg);
}

void terminal_initialize(vga_terminal *pterm)
{
  terminal_initialize_with_color(pterm, fg_default_color, bg_default_color);
}

void terminal_clear_buffer(vga_terminal *pterm)
{
  uint32_t i;
  uint16_t c;

  i = (VGA_HEIGHT * VGA_WIDTH);
  c = MAKE_VGAENTRY(0, pterm->terminal_color);
  while (i--)
    pterm->terminal_buffer[i] = c;
}

void terminal_initialize_with_color(vga_terminal *pterm, vga_color fg, vga_color bg)
{
  pterm->terminal_buffer = (uint16_t*) VGA_BUFFER_MODE;
  pterm->terminal_row = 0;
  pterm->terminal_column = 0;
  terminal_setcolor(pterm, fg, bg);
  terminal_clear_buffer(pterm);
}

int	terminal_put_vgaentry_at(vga_terminal *pterm, uint32_t c, vga_color color, size_t x, size_t y)
{
  if (c == MICRO_CHAR)
    c = 0xE6;

  pterm->terminal_buffer[y * VGA_WIDTH + x] = MAKE_VGAENTRY(c, color);
  return 1;
}

int terminal_putchar(vga_terminal *pterm, uint32_t c)
{
  return terminal_putchar_with_color(pterm, c);
}

int terminal_putchar_with_color(vga_terminal *pterm, uint32_t c)
{
  switch (c)
    {
    case VK_RETURN:
      pterm->terminal_row++;
      pterm->terminal_column = 0;
      break;

    case VK_BACKSPACE:
      if (pterm->terminal_column)
	pterm->terminal_column--;
      else if (pterm->terminal_row)
	{
	  pterm->terminal_row--;
	  pterm->terminal_column = VGA_WIDTH;
	}
      terminal_put_vgaentry_at(pterm, 0, pterm->terminal_color, pterm->terminal_column, pterm->terminal_row);
      break;

    case VK_DEL:
      break;

    case VK_RIGHT:
    case VK_LEFT:

      //break;

    default:
      terminal_put_vgaentry_at(pterm, c, pterm->terminal_color, pterm->terminal_column++, pterm->terminal_row);

      if (pterm->terminal_column == VGA_WIDTH)
	{
	  pterm->terminal_column = 0;
	  pterm->terminal_row++;
	}
    }
  if (pterm->terminal_row == VGA_HEIGHT)
    scrollup(pterm, 1);

  terminal_show_cursor(pterm);
  return 1;
}

void terminal_show_cursor(vga_terminal *pterm)
{
  SetCursorPos(pterm->terminal_column, pterm->terminal_row + 1);
}

int terminal_putstr_with_color(vga_terminal *pterm, const char* data)
{
  size_t datalen = kstrlen(data);

  for (size_t i = 0; i < datalen; i++)
    terminal_putchar_with_color(pterm, data[i]);
  return datalen;
}

int terminal_putstr(vga_terminal *pterm, const char* data)
{
  return terminal_putstr_with_color(pterm, data);
}

int terminal_putstrn(vga_terminal *pterm, const char* data, int n)
{
  char	*psz = (char*) data;

  while (*psz && n--)
    terminal_putchar_with_color(pterm, *psz++);
  return (--psz - data);
}

void printkc(int color, char c) {
  vga_terminal *pterm = get_terminal_instance();
  int lastColor = pterm->terminal_color;

  pterm->terminal_color = color;

  terminal_putchar_with_color(pterm, c);
  pterm->terminal_color = lastColor;
}

void printk(int color, char *str) {
  vga_terminal *pterm = get_terminal_instance();
  int lastColor = pterm->terminal_color;

  pterm->terminal_color = color;

  terminal_putstr_with_color(pterm, str);
  pterm->terminal_color = lastColor;
}

void scrollup(vga_terminal *pterm, uint8_t n)
{
  uint8_t *video;
  uint8_t *tmp;
  uint8_t *maxAddr = (uint8_t *)(VGA_BUFFER_MODE + (VGA_WIDTH * VGA_HEIGHT * 2));

  for (video = (uint8_t *) pterm->terminal_buffer; video < maxAddr; video += 2)
    {
      tmp = (uint8_t *) (video + n * 160);

      if (tmp < maxAddr)
	{
	  *video = *tmp;
	  *(video + 1) = *(tmp + 1);
	}
      else
	{
	  *video = 0;
	  *(video + 1) = 0x07;
	}
    }
  pterm->terminal_row -= n;
}

void printTaskBar(vga_terminal *pterm)
{
  uint16_t *initial_buffer = pterm->terminal_buffer;
  size_t initial_column = pterm->terminal_column;
  size_t initial_row = pterm->terminal_row;
  char title[] = "Kernel";
  vga_color title_color = MAKE_COLOR(COLOR_BLACK, COLOR_GREEN);
  vga_color bar_color_a = MAKE_COLOR(COLOR_GREEN, COLOR_BLACK);
  vga_color bar_color_b = MAKE_COLOR(COLOR_LIGHT_GREEN,COLOR_BLACK);

  pterm->terminal_buffer = (uint16_t*) VGA_BUFFER_BASE_MODE;
  pterm->terminal_column = 0;
  pterm->terminal_row = 0;

  printkc(title_color, 6);
  printk(title_color, title);
  printkc(bar_color_b, '[');
  for(int i = 0; i < (int) (VGA_WIDTH - (kstrlen(title) + 3)); i += 2) {
    printkc(bar_color_a, '=');
    if ((i + 1) < (int) (VGA_WIDTH - (kstrlen(title) + 3)))
      printkc(bar_color_b, '=');
  }
  printkc(bar_color_b, ']');

  pterm->terminal_buffer = initial_buffer;
  pterm->terminal_column = initial_column;
  pterm->terminal_row = initial_row;

}
