#ifndef _KEY_H_
#define _KET_H

#include "bsp.h"

enum {
    KEY_UP                  = 0u,
    KEY_DOWN,
    KEY_SET,
    KEY_CONFIRM,
    KEYS_NUM,
};

typedef enum{
    HOLD_NONE,
    HOLD_START_3SEC,
    HOLD_ALREADY_3SEC,
}Key_status_t;


typedef struct KeyCtrl_t{
    u8 cache              :4;   //存储变化更新之前的值
    u8 value              :4;   //存储当前的值，
    u8 trg                :4;     //触发的几个按键
    u8 release            :4;   //释放的几个按键

    uint16_t up_holding_timeout;
    uint16_t down_holding_timeout;
    uint16_t set_holding_timeout;
    uint16_t confirm_holding_timeout;

    uint8_t up_hold_status;
    uint8_t down_hold_status;
    uint8_t set_hold_status;
    uint8_t confirm_hold_status;
} KeyCtrl_t;      //四个键的状态

#define HOLDING_3_SECOND                    3000u
#define KEY_DEBOUNCE_TIME                   20u

#define KEY_UP_MASK                         (1 << KEY_UP)
#define KEY_DOWN_MASK                       (1 << KEY_DOWN)
#define KEY_SET_MASK                        (1 << KEY_SET)
#define KEY_CONFIRM_MASK                    (1 << KEY_CONFIRM)

#define KEY_IS_UP_PRESS()                   (KeyCtrl.trg & KEY_UP_MASK)
#define KEY_IS_UP_HOLDING()                 (KeyCtrl.value & KEY_UP_MASK)
#define KEY_IS_UP_RELEASE()                 (KeyCtrl.release & KEY_UP_MASK)

#define KEY_IS_DOWN_PRESS()                 (KeyCtrl.trg & KEY_DOWN_MASK)
#define KEY_IS_DOWN_HOLDING()               (KeyCtrl.value & KEY_DOWN_MASK)
#define KEY_IS_DOWN_RELEASE()               (KeyCtrl.release & KEY_DOWN_MASK)


#define KEY_IS_SET_PRESS()                 (KeyCtrl.trg & KEY_SET_MASK)
#define KEY_IS_SET_HOLDING()               (KeyCtrl.value & KEY_SET_MASK)
#define KEY_IS_SET_RELEASE()               (KeyCtrl.release & KEY_SET_MASK)

#define KEY_IS_CONFIRM_PRESS()             (KeyCtrl.trg & KEY_CONFIRM_MASK)
#define KEY_IS_CONFIRM_HOLDING()           (KeyCtrl.value & KEY_CONFIRM_MASK)
#define KEY_IS_CONFIRM_RELEASE()           (KeyCtrl.release & KEY_CONFIRM_MASK)







extern void Key_Timer(void);
extern void Key_Process(void);

#endif