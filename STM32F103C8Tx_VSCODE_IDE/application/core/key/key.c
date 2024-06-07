#include "key.h"
#include "gui.h"
struct keys {
    uint8_t Tmr1ms;
} Key[KEYS_NUM];

KeyCtrl_t KeyCtrl;
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
        if (Bsp_KEY_Probe(i))
        {
            if (Key[i].Tmr1ms <= KEY_DEBOUNCE_TIME)
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
        KeyCtrl.trg = KeyCtrl.cache & (~KeyCtrl.value);      //存储被按下的按键
        KeyCtrl.realse = (~KeyCtrl.cache) & KeyCtrl.value;
        KeyCtrl.value = KeyCtrl.cache;
    }
    
    if (KeyCtrl.trg)
    {
        /* 进入按键按下处理程序 */
        switch (KeyCtrl.trg)
        {
            case 0x08: GUI_SPI_Display_Char_ASCII(1,2,"A",0);break;
            case 0x04: GUI_SPI_Display_Char_ASCII(1,4,"B",0);break;
            case 0x02: GUI_SPI_Display_Char_ASCII(1,6,"C",0);break;
            case 0x01: GUI_CLEAR_SCREEN();break;
            default:
            break;
        }
        KeyCtrl.trg = 0;
    }

    if (KeyCtrl.realse)
    {
        /* 进入按键释放处理程序 */
        switch (KeyCtrl.realse)
        {
            case 0x08: GUI_SPI_Display_Char_ASCII(5,2,"E",0);break;
            case 0x04: GUI_SPI_Display_Char_ASCII(5,3,"F",0);break;
            case 0x02: GUI_SPI_Display_Char_ASCII(5,4,"G",0);break;
            case 0x01: GUI_SPI_Display_Char_ASCII(5,5,"H",0);break;
            default:
            break;
        }
        KeyCtrl.realse = 0;
    }
    
    
    
    
}