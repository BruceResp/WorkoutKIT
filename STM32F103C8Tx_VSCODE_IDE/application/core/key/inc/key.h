#ifndef _KEY_H_
#define _KET_H

#include "bsp.h"

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
    u8 release;   //释放的几个按键

} KeyCtrl_t;      //四个键的状态


#define KEY_DEBOUNCE_TIME                   20u

#define KEY_UP_MASK                         (1 << KEY_UP)
#define KEY_DOWN_MASK                       (1 << KEY_DOWN)
#define KEY_SET_MASK                        (1 << KEY_SET)
#define KEY_COMFIRM_MASK                    (1 << KEY_COMFIRM)

#define KEY_IS_UP_PRESS()                   (KeyCtrl.trg & KEY_UP_MASK)
#define KEY_IS_UP_HOLDING()                 (KeyCtrl.value & KEY_UP_MASK)
#define KEY_IS_UP_RELEASE()                 (KeyCtrl.release & KEY_UP_MASK)

#define KEY_IS_DOWN_PRESS()                 (KeyCtrl.trg & KEY_DOWN_MASK)
#define KEY_IS_DOWN_HOLDING()               (KeyCtrl.value & KEY_DOWN_MASK)
#define KEY_IS_DOWN_RELEASE()               (KeyCtrl.release & KEY_DOWN_MASK)


#define KEY_IS_SET_PRESS()                 (KeyCtrl.trg & KEY_SET_MASK)
#define KEY_IS_SET_HOLDING()               (KeyCtrl.value & KEY_SET_MASK)
#define KEY_IS_SET_RELEASE()               (KeyCtrl.release & KEY_SET_MASK)

#define KEY_IS_COMFIRM_PRESS()             (KeyCtrl.trg & KEY_COMFIRM_MASK)
#define KEY_IS_COMFIRM_HOLDING()           (KeyCtrl.value & KEY_COMFIRM_MASK)
#define KEY_IS_COMFIRM_RELEASE()           (KeyCtrl.release & KEY_COMFIRM_MASK)








extern void Key_Process(void);
#endif