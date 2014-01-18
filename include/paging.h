#ifndef _PAGING_H
#define _PAGING_H

#include <stddef.h>
#include <stdint.h>
#include "kernel.h"

/*
 * http://wiki.osdev.org/Paging
 */

#define PAGE_SIZE	(4096)



struct s_kernel_page_directory
{
  uint32_t	dwFlags:12;
  uint32_t	pAddr:20;
} __attribute__((packed));
typedef struct s_kernel_page_directory t_kernel_page_directory;

#define PAGETABLE_GLOBAL		(1 << 8)
#define PAGETABLE_DIRTY			(1 << 6)
#define PAGETABLE_ACCESSED		(1 << 5)
#define PAGETABLE_CACHE_DISABLED	(1 << 4)
#define PAGETABLE_WRITE_THROUGH		(1 << 3)
#define PAGETABLE_USER			(1 << 2)
#define PAGETABLE_RDWR			(1 << 1)
#define PAGETABLE_PRESENT		(1 << 0)

struct s_kernel_page_table
{
  uint32_t	dwFlags:12;
  uint32_t	pAddr:20;
} __attribute__ ((packed));
typedef struct s_kernel_page_table t_kernel_page_table;

void InitializePaging(void);

#endif 
