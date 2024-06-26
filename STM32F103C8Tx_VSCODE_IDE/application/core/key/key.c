#include "key.h"
#include "gui.h"
#include "system.h"
struct keys {
    uint8_t Tmr1ms;
} Key[KEYS_NUM];

KeyCtrl_t KeyCtrl;


extern SystemCtrl_t SystemCtrl;


/*----------------------------------------------------------------------------------------- 
*函数名称:'Key_Trig_Handler' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Key_Trig_Handler(void){

    if (KEY_IS_CONFIRM_PRESS()){
        KeyCtrl.confirm_holding_timeout = HOLDING_3_SECOND;   //
        KeyCtrl.confirm_hold_status = HOLD_START_3SEC;
    }
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Key_Mainpage_Process' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
/* // void Key_Mainpage_Process(void){

//     int8_t Page_Index = System_Page_Status_Read();

//     if (KEY_IS_UP_RELEASE())
//     {
//         Page_Index += 2;
//         if (Page_Index > SYSTEM_MAIN_PAGE_CONFIG_READY ) //超出
//         {
//             Page_Index = 0;
//         }
        
//     }

//     if (KEY_IS_DOWN_RELEASE())
//     {
//         Page_Index -= 2;

//         if (Page_Index+2 <= SYSTEM_MAIN_PAGE_TARIN_MENU_SELECET_READY )
//         {
//             Page_Index = SYSTEM_MAIN_PAGE_CONFIG_READY;
//         }
        
//     }

//     if (KEY_IS_SET_RELEASE())
//     {
//         if (Page_Index % 2 == 0)    //选中图标 处于ready状态
//         {
//             Page_Index += 1;        //系统轮询检测到为奇数 自动跳转
//         }
//     }
    
//     System_Page_Status_Write((uint8_t)Page_Index);

//     //GUI_Shift_Menu(Page_Index);
    
    
// } */

/*----------------------------------------------------------------------------------------- 
*函数名称:'Key_release_Handler' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Key_release_Handler(void){
    if (KEY_IS_UP_RELEASE()){
        System_GUIPagepointer_Add();
    }
    if (KEY_IS_DOWN_RELEASE()){
        System_GUIPagepointer_Sub();
    }
    if (KEY_IS_SET_RELEASE())
    {
        KeyCtrl.set_hold_status = HOLD_NONE;
    }
    if (KEY_IS_CONFIRM_RELEASE())
    {
        KeyCtrl.set_hold_status = HOLD_NONE;
    }
    

}

Key_status_t Key_Read_SetStatus(){
    return KeyCtrl.set_hold_status;
}

void Key_Hold_Handler(void){
    switch (KeyCtrl.confirm_hold_status)
    {
        case HOLD_ALREADY_3SEC:
            //做额外操作
            break;
    
        default:
            break;
    }
    

}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Key_Timer' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '按键定时处理' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Key_Timer(void){

    switch (KeyCtrl.confirm_hold_status)
    {
        case HOLD_NONE:break;
        case HOLD_START_3SEC:
        if ( --KeyCtrl.confirm_holding_timeout == 0)
        {
            KeyCtrl.confirm_hold_status +=  1;
        }
        
            break;
    }
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Key_Process' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Key_Process(void){
    u8 i = 0;
    u8 key_mask = 1;
    
    for ( i = 0; i < KEYS_NUM; i++)
    {
        /***              去抖           ***/
        if(Bsp_KEY_Probe(i))
        {
            if (Key[i].Tmr1ms <= KEY_DEBOUNCE_TIME)          //这种方式可以避免阻塞系统
            {
                if ( ++Key[i].Tmr1ms > KEY_DEBOUNCE_TIME)
                {
                    KeyCtrl.cache |= key_mask ;
                }
            }
        }else{
            if (Key[i].Tmr1ms)
            {
                if (--Key[i].Tmr1ms == 0)
                {
                    KeyCtrl.cache &= ~key_mask ;
                }
            }
        }
        key_mask <<= 1;
    }

    if (KeyCtrl.cache != KeyCtrl.value)
    {
        KeyCtrl.trg = KeyCtrl.cache & (~KeyCtrl.value);      //只能检测新按下的  存储被按下的按键
        KeyCtrl.release = (~KeyCtrl.cache) & KeyCtrl.value;
        KeyCtrl.value = KeyCtrl.cache;
    }
    
    if (KeyCtrl.trg)
    {
        /* 进入按键按下处理程序 */
        // switch (KeyCtrl.trg)
        // {
        //     case 0x08: GUI_SPI_Display_Char_ASCII(1,2,"A",0);break;
        //     case 0x04: GUI_SPI_Display_Char_ASCII(1,4,"B",0);break;
        //     case 0x02: GUI_SPI_Display_Char_ASCII(1,6,"C",0);break;
        //     case 0x01: GUI_CLEAR_SCREEN();break;
        //     default:
        //     break;
        // }
        Key_Trig_Handler();
        KeyCtrl.trg = 0;
    }

    if (KeyCtrl.release)
    {
        /* 进入按键释放处理程序 */
        // switch (KeyCtrl.release)
        // {
        //     case 0x08: GUI_SPI_Display_Char_ASCII(5,2,"E",0);break;
        //     case 0x04: GUI_SPI_Display_Char_ASCII(5,3,"F",0);break;
        //     case 0x02: GUI_SPI_Display_Char_ASCII(5,4,"G",0);break;
        //     case 0x01: GUI_SPI_Display_Char_ASCII(5,5,"H",0);break;
        //     default:
        //     break;
        // }
        Key_release_Handler();
        KeyCtrl.release = 0;
    }

    Key_Hold_Handler();
}