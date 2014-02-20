#ifndef _PAGING_H
#define _PAGING_H

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
/*
#define MEM_COMMIT		(0x1000)
#define MEM_RESERVE		(0x2000)
#define MEM_DECOMMIT		(0x4000)
#define MEM_RELEASE		(0x8000)

#define PAGE_NOACCESS		(0x01)
#define PAGE_READONLY		(0x02)
#define PAGE_READWRITE		(0x04)
#define PAGE_WRITECOPY		(0x08)
#define PAGE_EXECUTE		(0x10)
#define PAGE_EXECUTE_READ	(0x20)
#define PAGE_EXECUTE_READWRITE	(0x40)


void	*MmVirtualAlloc(t_process *pProcess, void *lpAddress, uint32_t dwSize, uint32_t flAllocationType, uint32_t flProtect);
bool	MmVirtualFree(t_process *pProcess, void *lpAddress, uint32_t dwSize, uint32_t dwFreeType);
*/

#endif
