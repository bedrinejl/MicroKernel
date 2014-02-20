#include "klibc.h"
#include "vga.h"

#define TOLOWER(c)  ((c) >= 'A' && (c) <= 'Z') ? ((c) - 32) : (c)

typedef int (*proc_t) (vga_terminal*, va_list*);

typedef struct	s_print
{
  uint32_t	c;
  proc_t	pfn;
} t_print;

static int	print_s(vga_terminal *pterm, va_list *pva)
{
  char *psz = va_arg(*pva, char*);

  if (!psz)
    return  terminal_putstr(pterm, "(null)");

  return terminal_putstr(pterm, psz);
}

static int	print_c(vga_terminal *pterm, va_list *pva)
{
  int	i = va_arg(*pva, int);

  return terminal_putchar(pterm, (char) (i & 0xFF));
}

static int	print_d(vga_terminal *pterm, va_list *pva)
{
  char		szDec[10 + 1];
  int		i = va_arg(*pva, int);

  kultoa(i, szDec, 10);
  return terminal_putstr(pterm, szDec);
}

static int	print_b(vga_terminal *pterm, va_list *pva)
{
  char		szBinary[32 + 1];
  uint32_t	ui = va_arg(*pva, int);

  kultoa(ui, szBinary, 2);
  return terminal_putstr(pterm, szBinary);
}

static int	print_x(vga_terminal *pterm, va_list *pva)
{
  char		szHexa[16 + 1];
  uint32_t	ui = va_arg(*pva, uint32_t);

  kultoa(ui, szHexa, 16);
  return terminal_putstr(pterm, szHexa);
}

static int	print_p(vga_terminal *pterm, va_list *pva)
{
  // 32bits ptr only
  terminal_putstr(pterm, "0x");
  return print_x(pterm, pva);
}

static int	print_percent(vga_terminal *pterm, va_list *pva)
{
  UNUSED(pva);
  return terminal_putchar(pterm, '%');
}

static int	print_as(uint32_t type, vga_terminal *pterm, va_list *pargs)
{
  static const	t_print pPrintProc[] = {
    {'%', &print_percent},
    {'b', &print_b},
    {'p', &print_p},
    {'x', &print_x},
    {'c', &print_c},
    {'d', &print_d},
    {'i', &print_d},
    {'s', &print_s}
  };
  int		idx = SIZEOFARRAY(pPrintProc);

  while (idx--)
    {
      if (pPrintProc[idx].c == type)
	return pPrintProc[idx].pfn(pterm, pargs);
    }
  return 0;
}

int		kprintf(const char *format, ...)
{
  vga_terminal	*pterm;
  char		*psz;
  va_list      	args;
  int		iBytesWritten = 0;
  int		i;
  char		c;

  pterm = get_terminal_instance();
  va_start(args, format);
  psz = (char*) format;
  while (*psz)
    {
      if (*psz == '%' && *(psz + 1))
	{
	  c = *(++psz);
	  i = print_as(TOLOWER(c), pterm, &args);
	  if (!i)
	    terminal_putstrn(pterm, psz - 1, 2);
	  else
	    iBytesWritten += i;
	}
      else
	iBytesWritten += terminal_putchar(pterm, *psz);
      psz++;
    }
  va_end(args);
  return iBytesWritten;
}
