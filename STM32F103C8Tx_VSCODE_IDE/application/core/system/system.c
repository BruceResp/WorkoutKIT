#include "system.h"
#include "gui.h"
#include "flash.h"
#include "key.h"
#include "sys_typedef.h"
#include <stdlib.h>

extern GUI_TrainMenuSelectPage_t GUI_TrainMenuSelectPage;
SystemCtrl_t SystemCtrl;
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
    SystemCtrl.currentpage = SYSTEM_MAIN_PAGE;
    SystemCtrl.targetpage = SYSTEM_MAIN_PAGE;
    SystemCtrl.gui_focus_coord = 1; 
    GUI_CLEAR_SCREEN();
    GUI_Shift_Menu( SystemCtrl.currentpage,SystemCtrl.targetpage);
};

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_MenuselectPage_Init' 
*函数功能:'菜单选择界面 初始化' 
*参    数:'' 
*返 回 值:'' 
*说    明: '在结束主菜单工作以后调用，初始化 动画的坐标等信息' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_MenuselectPage_Init(void (*gui_init)(void)){
    
    SystemCtrl.currentpage = SystemCtrl.targetpage;
    SystemCtrl.gui_focus_coord = 0;
    SystemCtrl.datasource_index = 0;
    gui_init();

}

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_GUIPagepointer_Sub' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '供外部调用' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_GUIFocus_Coord_Sub(void){
    SystemCtrl.gui_focus_coord--;
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_GUIPagepointer_Add' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '供外部调用' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_GUIFocus_Coord_Add(void){
    SystemCtrl.gui_focus_coord++;
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Turn_Page' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '当set 释放以后，设置该位，并在判断完以后，调用System_Clear_turnPage
            供外部调用' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Turn_Page(int8_t turnToNext){

    if (turnToNext)     //True ++
    {
        SystemCtrl.is_turn_page++;
        return;
    }
    SystemCtrl.is_turn_page--;
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
    SystemCtrl.is_turn_page = 0;
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
    if(SystemCtrl.gui_focus_coord > MainPage_EndIndex)
    {
        SystemCtrl.gui_focus_coord = MainPage_BeginIndex;
    }
    if(SystemCtrl.gui_focus_coord < MainPage_BeginIndex)
    {
        SystemCtrl.gui_focus_coord = MainPage_EndIndex;
    }
    
    SystemCtrl.targetpage = SystemCtrl.gui_focus_coord * MainPage_MultiPower;
    
    if(SystemCtrl.is_turn_page == 1){
        System_MenuselectPage_Init(GUI_MenuselectPage_Init);
        System_Clear_turnPage();
    }
    
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Datasource_Index_Overflow_Detect' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '控制索引不越界' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Datasource_Index_Overflow_Detect(SystemCtrl_t* SystemCtrlPoint,uint8_t menuNum,uint8_t uplimit){
    switch (uplimit)
    {
        case 1:
            if (SystemCtrlPoint->datasource_index >= menuNum){
                SystemCtrlPoint->datasource_index = menuNum - 1;
            }
            break;
        case 0:
            if(SystemCtrlPoint->datasource_index < GUI_ROWS_DOWN_LIMIT){
                SystemCtrlPoint->datasource_index = GUI_ROWS_DOWN_LIMIT;
            }
            break;
        default:
            #ifdef Debug_mode
                if ((uplimit != 1) && (uplimit != 0) )
                {
                    printf("\r\n error code 20: System_Datasource_Index_Overflow_Detect() fail to execute ,uplimit isn't clear \r\n");
                }
            #endif
            break;
    }
}

void System_GUI_Focus_Coord_Overflow_Detect(SystemCtrl_t* SystemCtrlPoint,int8_t old_gui_focus_coord, uint8_t menuNum,uint8_t uplimit){
    switch (uplimit)
    {
        case 0:
            if (old_gui_focus_coord >= GUI_ROWS_THIRD){
                if (SystemCtrlPoint->datasource_index == (menuNum - 1))
                {
                    SystemCtrlPoint->gui_focus_coord = GUI_ROWS_UP_LIMIT;
                }else{
                    SystemCtrlPoint->gui_focus_coord = GUI_ROWS_THIRD;
                }       
            }
            break;
        case 1:
            if (SystemCtrlPoint->gui_focus_coord < GUI_ROWS_DOWN_LIMIT ){
                SystemCtrlPoint->gui_focus_coord = GUI_ROWS_DOWN_LIMIT;
            }
        default:
            #ifdef Debug_mode
                if ((uplimit != 1) && (uplimit != 0) ){
                    printf("\r\n error code 21: System_Menu_shift_OP() fail to execute \r\n");
                }
            #endif
            break;
    }
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Menu_shift_OP' 
*函数功能:'菜单 移动 操作' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Menu_shift_OP(SystemCtrl_t* SystemCtrlPoint,void (* GUI_shift)(uint8_t),uint8_t menuNum){
    static int8_t old_gui_focus_coord; 
    int8_t coord_diff = SystemCtrlPoint->gui_focus_coord - old_gui_focus_coord ;

    if (menuNum == 0){
        return;
    }
    switch (coord_diff)
    {
        case 1:
            if (menuNum > 4)
            {
                SystemCtrlPoint->datasource_index++;

                System_Datasource_Index_Overflow_Detect(SystemCtrlPoint,menuNum,1);
                System_GUI_Focus_Coord_Overflow_Detect(SystemCtrlPoint,old_gui_focus_coord,menuNum,0);

                if ((old_gui_focus_coord == GUI_ROWS_THIRD) && (SystemCtrlPoint->datasource_index <= (menuNum - 2))){    //datasource_index是指向下一条
                    GUI_shift(1);                                                                                        //页面下移
                }
            }else{
                SystemCtrlPoint->datasource_index++;
                if (SystemCtrlPoint->datasource_index >= menuNum){
                    SystemCtrlPoint->gui_focus_coord = (menuNum - 1) ;
                    SystemCtrlPoint->datasource_index = (menuNum - 1) ;
                }
            }
            break;
        case -1:
            //System_Datasource_Index_Overflow_Detect(SystemCtrlPoint,menuNum,0);
            System_GUI_Focus_Coord_Overflow_Detect(SystemCtrlPoint,old_gui_focus_coord,menuNum,1);

            if (old_gui_focus_coord == GUI_ROWS_DOWN_LIMIT && (SystemCtrlPoint->datasource_index > 0)){
                GUI_shift(0);                                                                                           //页面上移 
            };
            SystemCtrlPoint->datasource_index--;
            System_Datasource_Index_Overflow_Detect(SystemCtrlPoint,menuNum,0);

            break;

        default:
            #ifdef Debug_mode
                if ((coord_diff != 1) && (coord_diff != -1) ){
                    printf("\r\n error code 22: System_Menu_shift_OP() fail to execute \r\n");
                }
            #endif
            break;
    }

/* 
    if (SystemCtrlPoint->gui_focus_coord - old_gui_focus_coord == 1 && (menuNum > 4)){
        
        SystemCtrlPoint->datasource_index++;
        if (SystemCtrlPoint->datasource_index >= menuNum)
        {
            SystemCtrlPoint->datasource_index = menuNum - 1;                                               //如果超过菜单尾部  菜单尾部是menuNum - 1
        }
        if (old_gui_focus_coord >= GUI_ROWS_THIRD){
            if (SystemCtrlPoint->datasource_index == (menuNum - 1))
            {
                SystemCtrlPoint->gui_focus_coord = GUI_ROWS_UP_LIMIT;
            }       
        }
        if ((old_gui_focus_coord == GUI_ROWS_THIRD) && (SystemCtrlPoint->datasource_index <= (menuNum - 2)))  //datasource_index是指向下一条
        {
            GUI_TrainMenuSelectPage.datalist_crood.target_y -= 16;
            SystemCtrlPoint->gui_focus_coord = GUI_ROWS_THIRD;
        }
        
    }else if (SystemCtrlPoint->gui_focus_coord - old_gui_focus_coord == 1 && (menuNum <= 4))
    {
        SystemCtrlPoint->datasource_index++;
        if (SystemCtrlPoint->datasource_index >= menuNum)
        {
            SystemCtrlPoint->gui_focus_coord = (menuNum - 1) ;
            SystemCtrlPoint->datasource_index = (menuNum - 1) ;
        }
        
    }else if (SystemCtrlPoint->gui_focus_coord-old_gui_focus_coord == -1)
    {
        SystemCtrlPoint->datasource_index--;
        if (SystemCtrlPoint->datasource_index < GUI_ROWS_DOWN_LIMIT){
            SystemCtrlPoint->datasource_index = GUI_ROWS_DOWN_LIMIT;
        }
        if (SystemCtrlPoint->gui_focus_coord < GUI_ROWS_DOWN_LIMIT ){
            SystemCtrlPoint->gui_focus_coord = GUI_ROWS_DOWN_LIMIT;
        }
        if (SystemCtrlPoint->gui_focus_coord == GUI_ROWS_DOWN_LIMIT && (SystemCtrlPoint->datasource_index > 0))
        {
            GUI_TrainMenuSelectPage.datalist_crood.target_y += 16;
        }
    }
 */
    old_gui_focus_coord = SystemCtrlPoint->gui_focus_coord;
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_TrainMenuSelPage_Operation' 
*函数功能:'系统 训练菜单选择页面 操作' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_TrainMenuSelPage_Operation(void){
    //Sytem_Load_Menu();
    //uint8_t menuNum = FLASH_Read_MenuNum();
    uint8_t menuNum = 8;                                 //单纯的个数，从1开始

    System_Menu_shift_OP(&SystemCtrl,GUI_List_shift,menuNum);           //直接传是作为变量传递的，是一个副本
    
    if(SystemCtrl.is_turn_page == 1){
        SystemCtrl.targetpage = SystemCtrl.currentpage + 1;
        SystemCtrl.currentpage = SystemCtrl.targetpage;
    }else if (SystemCtrl.is_turn_page == -1)
    {
        SystemCtrl.targetpage = SystemCtrl.currentpage * 0;
        SystemCtrl.currentpage = SystemCtrl.targetpage;
        SystemCtrl.gui_focus_coord = 1;
        GUI_CLEAR_SCREEN();
    }
    System_Clear_turnPage();

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

    switch (SystemCtrl.currentpage)
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
    
    GUI_Shift_Menu(SystemCtrl.currentpage,SystemCtrl.targetpage);

    GUI_Animation_move(SystemCtrl.currentpage);

}

