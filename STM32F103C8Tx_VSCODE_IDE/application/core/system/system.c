#include "system.h"
#include "gui.h"
SystemCtrl_t SystemCtrl;
Sys_MainPage_t Sys_MainPage;

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Page_Status_Read' 
*函数功能:'页面 状态 读取' 
*参    数:'' 
*返 回 值:'' 
*说    明: '返回当前所处页面' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
uint8_t System_Page_Status_Read(void){

    return (uint8_t)SystemCtrl.page_index;
    
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Page_Status_Write' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Page_Status_Write(uint8_t page_index){

    SystemCtrl.page_index = page_index ;

}
/*----------------------------------------------------------------------------------------- 
*函数名称:'' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '页面初始化 设置默认页面' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Init(void){
    SystemCtrl.page_index = SYSTEM_MAIN_PAGE_START_TRAIN_READY;

    GUI_CLEAR_SCREEN();
    GUI_Shift_Menu(SystemCtrl.page_index);
};

/*----------------------------------------------------------------------------------------- 
*函数名称:'System_Poll' 
*函数功能:'系统 轮询' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void System_Poll(void){

    switch (SystemCtrl.status)
    {
        case SYSTEM_MAIN_PAGE:
            if (SystemCtrl.page_index % 2 == 1){
                SystemCtrl.status = SystemCtrl.page_index / 2 +1;  //更新页面指针到下一页
                                                                    //更新坐标
                
            };
            break;
        case SYSTEM_TARIN_MENU_SELECET_PAGE:
            if (/* 临时变量为空 */1)
            {
                //read_flash 加载菜单 保存在临时变量中 每次从flash中读一次 
            }
            // 菜单开始运行处理函数
            break;
        case SYSTEM_EDIT_MENU_PAGE:
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

