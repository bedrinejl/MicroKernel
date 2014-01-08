#ifndef _PANIC_H
#define _PANIC_H

#include <stdint.h>

void     terminalBlueScreenOfDeath(uint32_t uiNumber, char *pszError, uint32_t uiAddr);

#endif
