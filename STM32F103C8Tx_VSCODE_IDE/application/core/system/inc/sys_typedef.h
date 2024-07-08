
#ifndef _SYS_TYPEDEF_
#define _SYS_TYPEDEF_
#include <stm32f10x.h>

#define MEN_LIST_START_ADDRESS              0x010001
#define ACTIONS_SIZE                         0x3

// typedef struct train_action
// {
//     u8     name_num;  //指向名称列表的具体数字 1
//     u8     num;         //1
//     u8     time;        //1
// }MoveProperty_t;

// typedef struct MENU
// {
//     u8 Actions_num;             //将要存储的个数
//     u8 Menu_name;               //菜单名称列表
//     MoveProperty_t Actions[];      //3*N   N最多设置15个   可以设置最后一个数组为分割的黑色数据
// }Menu_t;                            //单个菜单

// typedef struct MENU_List
// {
//     u8 Menu_num;                    //菜单个数  1 B
//     Menu_t menu[];
// }MenuList_t;



#endif