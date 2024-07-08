#include "system.h"
#include "gui.h"
#include "flash.h"
#include "key.h"
#include "sys_typedef.h"
#include <stdlib.h>
extern KeyCtrl_t KeyCtrl;
SystemCtrl_t SystemCtrl;
Sys_MainPage_t Sys_MainPage;
Sys_Rowitem_t Sys_Rowitem;
Flash_Addr_t FlashAddr ;

#define GUI_ROWS_UP_LIMIT        3
#define GUI_ROWS_THIRD           2
#define GUI_ROWS_DOWN_LIMIT      0

/*----------------------------------------------------------------------------------------- 
*函数名称:'' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '页面初始化 设置默认页面' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Init(void){
    SystemCtrl.currentPage = SYSTEM_MAIN_PAGE;
    SystemCtrl.targetPage = SYSTEM_MAIN_PAGE;
    SystemCtrl.GUIpagePoint = 1; 
    GUI_CLEAR_SCREEN();
    GUI_Shift_Menu( SystemCtrl.currentPage,SystemCtrl.targetPage);
};
void System_MenuselectPage_Init(void){

    SystemCtrl.Sys_InverseBox.current_x = 0;
    SystemCtrl.Sys_InverseBox.current_y = -16;
    SystemCtrl.Sys_InverseBox.target_x = 0;
    SystemCtrl.Sys_InverseBox.target_y = 0;
    Sys_Rowitem.current_x = 0;
    Sys_Rowitem.current_y = 0;
    Sys_Rowitem.target_x = 0;
    Sys_Rowitem.target_y = 0;
	GUI_CLEAR_SCREEN();

}
/*----------------------------------------------------------------------------------------- 
*函数名称:'System_GUIPagepointer_Sub' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_GUIPagepointer_Sub(void){
    SystemCtrl.GUIpagePoint--;
}
/*----------------------------------------------------------------------------------------- 
*函数名称:'System_GUIPagepointer_Add' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_GUIPagepointer_Add(void){
    SystemCtrl.GUIpagePoint++;
}
/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Turn_Page' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '当set 释放以后，设置该位，并在判断完以后，调用System_Clear_turnPage' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Turn_Page(void){
    SystemCtrl.is_turn_Page++;
}
/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Clear_turnPage' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '调用System_Turn_Page 后需要调用' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Clear_turnPage(){
    SystemCtrl.is_turn_Page = 0;
}
/*----------------------------------------------------------------------------------------- 
*函数名称:'System_MainPage_Operation' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_MainPage_Operation(void){
    if(SystemCtrl.GUIpagePoint > MainPage_EndIndex)
    {
        SystemCtrl.GUIpagePoint = MainPage_BeginIndex;
    }
    if(SystemCtrl.GUIpagePoint < MainPage_BeginIndex)
    {
        SystemCtrl.GUIpagePoint = MainPage_EndIndex;
    }
    
    SystemCtrl.targetPage = SystemCtrl.GUIpagePoint * MainPage_MultiPower;
    
    if(SystemCtrl.is_turn_Page == 1){
        SystemCtrl.currentPage = SystemCtrl.targetPage;
        SystemCtrl.GUIpagePoint = 0;
        SystemCtrl.MenuPoint = 0;
        System_Clear_turnPage();
        System_MenuselectPage_Init();
    }
}

void System_TrainMenuSelPage_Operation(void){
    //Sytem_Load_Menu();
    //uint8_t menuNum = FLASH_Read_MenuNum();
    uint8_t menuNum = 8; //单纯的个数，从1开始
    static int8_t oldGUIpagePoint; 

    if (menuNum == 0)
    {
        return;
    }
    /*              update SystemCtrl.MenuPoint              */
    if (SystemCtrl.GUIpagePoint - oldGUIpagePoint == 1 && (menuNum > 4))
    {
        
        SystemCtrl.MenuPoint++;
        if (SystemCtrl.MenuPoint >= menuNum)
        {
            SystemCtrl.MenuPoint = menuNum - 1;       //如果超过菜单尾部  菜单尾部是menuNum - 1
        }
        if (oldGUIpagePoint >= GUI_ROWS_THIRD){
            if (SystemCtrl.MenuPoint == (menuNum - 1))
            {
                SystemCtrl.GUIpagePoint = GUI_ROWS_UP_LIMIT;
            }       
        }
        if ((oldGUIpagePoint == GUI_ROWS_THIRD) && (SystemCtrl.MenuPoint <= (menuNum - 2)))  //menupoint是指向下一条
        {
            Sys_Rowitem.target_y -= 16;
            SystemCtrl.GUIpagePoint = GUI_ROWS_THIRD;
        }
        
    }else if (SystemCtrl.GUIpagePoint - oldGUIpagePoint == 1 && (menuNum <= 4))
    {
        SystemCtrl.MenuPoint++;
        if (SystemCtrl.MenuPoint >= menuNum)
        {
            SystemCtrl.GUIpagePoint = (menuNum - 1) ;
            SystemCtrl.MenuPoint = (menuNum - 1) ;
        }
        
    }else if (SystemCtrl.GUIpagePoint-oldGUIpagePoint == -1)
    {
        SystemCtrl.MenuPoint--;
        if (SystemCtrl.MenuPoint < GUI_ROWS_DOWN_LIMIT){
            SystemCtrl.MenuPoint = GUI_ROWS_DOWN_LIMIT;
        }
        if (SystemCtrl.GUIpagePoint < GUI_ROWS_DOWN_LIMIT ){
            SystemCtrl.GUIpagePoint = GUI_ROWS_DOWN_LIMIT;
        }
        if (SystemCtrl.GUIpagePoint == GUI_ROWS_DOWN_LIMIT && (SystemCtrl.MenuPoint > 0))
        {
            Sys_Rowitem.target_y += 16;
        }
    }
    /*              update SystemCtrl.MenuPoint              */

    /*              SystemCtrl.MenuPoint under ctrol         */ 
    /*              SystemCtrl.MenuPoint under ctrol         */
    /*                  control inverse box                  */
    

    
    
    oldGUIpagePoint = SystemCtrl.GUIpagePoint;
    
    if(SystemCtrl.is_turn_Page == 1){
        SystemCtrl.targetPage = SystemCtrl.currentPage +1;
        SystemCtrl.currentPage = SystemCtrl.targetPage;
        System_Clear_turnPage();
    }
    
    
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Poll' 
*函数功能:'系统 轮询' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Poll(void){

    switch (SystemCtrl.currentPage)
    {
        case SYSTEM_MAIN_PAGE:
            System_MainPage_Operation();
            break;
        case SYSTEM_TRAIN_MENU_SELECET_PAGE:
            System_TrainMenuSelPage_Operation();
           // uint8_t menu_num = FLASH_Read_Menu_num();
            // if (menu_num != 0) //存在菜单
            // {
            //     //read_flash 加载菜单 保存在临时变量中 每次从flash中读一次 
            // }
            // 菜单开始运行处理函数
            break;
        case SYSTEM_EDIT_MENU_SELECT_PAGE:
            if (/* 临时变量为空 */1)
            {
                //read_flash 加载菜单 保存在临时变量中 每次从flash中读一次 
            }
            else
            {
                /* 加载现有的菜单 */
            }
            
            break;
        case SYSTEM_CONFIG_PAGE:
            
            break;
        default:
            break;
    }
    
    GUI_Shift_Menu(SystemCtrl.currentPage,SystemCtrl.targetPage);
    GUI_Animation_move();

}

