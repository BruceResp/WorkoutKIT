#include "bsp.h"
#include "systime.h"
void Bsp_clcok_init(void){
    SysTick->LOAD = 72 * 1000;				//1 ms 定时
	SysTick->VAL = 0x00;					//清空当前计数值
	SysTick->CTRL = 0x00000005;				//设置时钟源为HCLK，启动定时器
	//while(!(SysTick->CTRL & 0x00010000));	//等待计数到0
	//SysTick->CTRL = 0x00000004;				//关闭定时器
}

void SysTick_Handler(void){
    Time_1ms_IT();//备用
}