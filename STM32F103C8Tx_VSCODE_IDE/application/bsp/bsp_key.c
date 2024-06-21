// 实现对应按键抬起按下检测 四个按键 抬起触发事件 按下触发事件 按键按下时间
#include "bsp.h"
#include "key.h"
/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_KEY_Probe' 
*函数功能:'按键 检测' 
*参    数:'void' 
*返 回 值:'none' 
*说    明: '返回 0 表示按键按下 返回 1 表示按键释放' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
uint8_t Bsp_KEY_Probe(uint8_t key){
    switch (key)
    {
        case KEY_UP: return (GPIO_ReadInputDataBit(KEY_UP_PORT,KEY_UP_PIN) == 0); break;   //这里用 == 0 而不直接读取值，有两个好处 向上层屏蔽了按下和没按下的底层逻辑，上层只需要知道 按下为1 未按下0，如果后续出现改动比如 电平0为释放 1为按下 不用对上层做对应的变化，符合分层 对上层屏蔽细节的作用，便于维护 与阅读 （告诉读者 当前针对 0）
        case KEY_DOWN:return (GPIO_ReadInputDataBit(KEY_DOWN_PORT,KEY_DOWN_PIN) == 0); break;
        case KEY_SET:return (GPIO_ReadInputDataBit(KEY_SET_PORT,KEY_SET_PIN) == 0);  break;
        case KEY_COMFIRM: return (GPIO_ReadInputDataBit(KEY_COMFIRM_PORT,KEY_COMFIRM_PIN) == 0); break;
    }
    return 0;
}
