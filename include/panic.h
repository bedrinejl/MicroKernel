#ifndef _PANIC_H
#define _PANIC_H

#include <sys/types.h>
#include <stddef.h>

void     terminalBlueScreenOfDeath(uint32_t uiNumber, char *pszError, uint32_t uiAddr);

#endif
