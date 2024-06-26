#include "system.h"
#include "gui.h"
#include "flash.h"
#include "key.h"
#include "sys_typedef.h"
extern KeyCtrl_t KeyCtrl;
SystemCtrl_t SystemCtrl;
Sys_MainPage_t Sys_MainPage;
Flash_Addr_t FlashAddr ;
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
*函数名称:'System_MainPage_Operation' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_MainPage_Operation(void){

    if (SystemCtrl.GUIpagePoint > MainPage_EndIndex)
    {
        SystemCtrl.GUIpagePoint = MainPage_BeginIndex;
    }
    if (SystemCtrl.GUIpagePoint < MainPage_BeginIndex)
    {
        SystemCtrl.GUIpagePoint = MainPage_EndIndex;
    }
    
    SystemCtrl.targetPage = SystemCtrl.GUIpagePoint * MainPage_MultiPower;
    
    if (KEY_IS_SET_RELEASE()){
        SystemCtrl.currentPage = SystemCtrl.targetPage;
    }

    GUI_Shift_Menu(SystemCtrl.currentPage,SystemCtrl.targetPage);
    
}

void System_TrainMenuSelPage_Operation(void){
    MenuList_t *MenuList;
    FlashAddr.addr = MENU_NUM_START_ADDRESS;
    FLASH_Read_Dataes(FlashAddr,MenuList,1);
    
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
            System_MainPage_Operation();break;
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
    
    GUI_Animation_move();

}

