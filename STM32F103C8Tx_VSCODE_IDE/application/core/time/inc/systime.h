#ifndef _SYSTIME_H_
#define _SYSTIME_H_

#include "bsp.h"

extern uint32_t Time_GetTick(void);
extern void Time_1ms_IT(void);
extern void Time_1ms_Polling(void);
#endif