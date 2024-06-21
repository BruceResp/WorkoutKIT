#ifndef _SYSTEM_H_
#define _SYSTEM_H

#include "bsp.h"


// 所处页面Index
typedef enum {
    SYSTEM_MAIN_PAGE                                   =0u,

    SYSTEM_TARIN_MENU_SELECET_PAGE                     =1u,
    SYSTEM_EDIT_MENU_PAGE,
    SYSTEM_CONFIG_PAGE,

    SYSTEM_SELECTED_MENU_CONTENT_PAGE,

    SYSTEM_TRAIN_START_PAGE,
    SYSTEM_MOVEMENTS_LIST_PAGE,
    SYSTEM_MOVEMENT_CONFIG_PAGE,
    
}Sys_status_t;

typedef enum {
    //SYSTEM_MAIN_PAGE_DO_NONE                            =0u,
    SYSTEM_MAIN_PAGE_TARIN_MENU_SELECET_READY=0u,                   
    SYSTEM_MAIN_PAGE_TARIN_MENU_SELECET_ALREADY,//1
    SYSTEM_MAIN_PAGE_EDIT_TRAIN_MENU_READY,//2
    SYSTEM_MAIN_PAGE_EDIT_TRAIN_MENU_ALREADY,//3
    SYSTEM_MAIN_PAGE_CONFIG_READY,//4
    SYSTEM_MAIN_PAGE_CONFIG_ALREADY,//5
}System_page_index_t;

typedef struct 
{
    Sys_status_t status;
    System_page_index_t page_index;  

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

extern Sys_MainPage_t Sys_MainPage;

extern void System_Init(void);
extern void System_Poll(void);
extern uint8_t System_Page_Status_Read(void);
extern uint8_t System_Status_Read(void);
extern void System_Page_Status_Write(uint8_t page_index);

#endif