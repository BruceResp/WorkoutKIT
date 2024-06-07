#ifndef _KEY_H_
#define _KET_H

#include "bsp.h"

#define KEY_DEBOUNCE_TIME               20u

enum {
    KEY_UP                  = 0u,
    KEY_DOWN,
    KEY_SET,
    KEY_COMFIRM,
    KEYS_NUM,
};

typedef struct KeyCtrl_t{
    u8 cache;   //存储变化更新之前的值
    u8 value;   //存储当前的值，
    u8 trg;     //触发的几个按键
    u8 realse;   //释放的几个按键

} KeyCtrl_t;      //四个键的状态


extern void Key_Process(void);
#endif