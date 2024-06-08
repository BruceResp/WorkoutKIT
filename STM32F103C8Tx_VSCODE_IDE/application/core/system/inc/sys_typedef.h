
#ifndef _SYS_TYPEDEF_
#define _SYS_TYPEDEF_
#include <stm32f10x.h>

typedef struct train_action
{
    char * name;
    u8     num;
    u8     time;
}MoveProperty_t;

typedef struct MENU
{
    char *Menu_name;
    MoveProperty_t Actions[0];
}Menu_t;

Menu_t Menu_list[];

#endif