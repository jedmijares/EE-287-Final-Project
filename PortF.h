#ifndef _PortF_h
#define _PortF_h

#include "stdint.h"

void PortF_Init(void);
uint32_t pushbuttons(void);
void redOn(void);
void redOff(void);
void blueOn(void);
void blueOff(void);
void greenOn(void);
void greenOff(void);

#endif