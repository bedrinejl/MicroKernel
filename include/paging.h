#ifndef _PAGING_H
#define _PAGING_H

#include <stddef.h>
#include <stdint.h>
#include "kernel.h"

#define PAGE_SIZE	(4096)

void InitializePaging(void);

#endif 
