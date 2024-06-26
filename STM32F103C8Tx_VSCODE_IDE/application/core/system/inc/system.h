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
}Sys_pagePointer_t;

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
    Sys_pagePointer_t targetPage;
    Sys_pagePointer_t currentPage;

    uint8_t GUIpagePoint;               //config by up / down key
}SystemCtrl_t;


typedef struct
{
    int current_x; //描述当前的横纵坐标
    int current_y; 

    int target_x; //描述目标的横纵坐标
    int target_y; 
}Sys_MainPage_module_t;    //主界面显示的字的属性

typedef struct
{
    //Sys_MainPage_module_t font;
    Sys_MainPage_module_t left_icon;
    Sys_MainPage_module_t mid_icon;
    Sys_MainPage_module_t right_icon;
    
    Sys_MainPage_module_t left_font;
    Sys_MainPage_module_t mid_font;
    Sys_MainPage_module_t right_font;
}Sys_MainPage_t;

#define MainPage_EndIndex                  3
#define MainPage_BeginIndex                1
#define MainPage_MultiPower                3


extern Sys_MainPage_t Sys_MainPage;

extern void System_Init(void);
extern void System_Poll(void);
extern void System_GUIPagepointer_Sub(void);
extern void System_GUIPagepointer_Add(void);


#endif