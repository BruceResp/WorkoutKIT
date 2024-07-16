#ifndef _SYSTEM_H_
#define _SYSTEM_H

#include "bsp.h"

typedef enum {
    SYSTEM_MAIN_PAGE                                       =0u,
        SYSTEM_TRAIN_MENU_SELECET_PAGE                     =3u,
            SYSTEM_START_TRAIN_PAGE,
        SYSTEM_EDIT_MENU_SELECT_PAGE                       =6u,
            SYSTEM_EDIT_MOVES_SELECT_PAGE,
                SYSTEM_MOVES_COFIG_PAGE,
        SYSTEM_CONFIG_PAGE                                 =9u, 
}Sys_PageStatus_List_t;

// char *GUI_Display_Name[] ={
//     "主菜单",
//     "训练菜单选择",
//         "开始训练",
//     "选择菜单编辑",
//         "动作选择编辑",
//             "动作配置",
//     "系统配置",
// };

typedef struct 
{
    float current_x;
    float current_y;

    float target_x;
    float target_y;
}Sys_Rowitem_t;

typedef struct 
{
    Sys_PageStatus_List_t targetpage;
    Sys_PageStatus_List_t currentpage;
    int8_t is_turn_page;                  //翻页 正 : 向后索引，负 :向前索引

    int8_t gui_focus_coord;               //选中焦点坐标
    int8_t datasource_index;              //数据源索引值

}SystemCtrl_t;


#define MainPage_EndIndex                  3
#define MainPage_BeginIndex                1
#define MainPage_MultiPower                3




extern void System_Init(void);
extern void System_Poll(void);
extern void System_GUIFocus_Coord_Sub(void);
extern void System_GUIFocus_Coord_Add(void);
extern void System_Turn_Page(int8_t turnToNext);

#endif