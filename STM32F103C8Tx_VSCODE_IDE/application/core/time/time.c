#include "systime.h"
#include "key.h"

__IO uint32_t uwTick;

uint32_t Time_GetTick(void) {

    return uwTick;
}

void Time_1ms_IT(void){
    uwTick++;
}
void Time_1ms_Polling(void){
    static uint32_t OldTick;
    uint32_t CurTick = uwTick;

    if (OldTick == CurTick)
        return;
    
    OldTick = CurTick;

    Key_Timer();
    
}