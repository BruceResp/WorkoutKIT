#include "stm32f10x.h" 
#include "bsp.h"
#include <stdio.h> 
#include <stdarg.h>
#include <stdlib.h>


int _write(int handle, char *data, int size ) 
{
    int count ;

    handle = handle ; // unused

    for( count = 0; count < size; count++) 
    {
        ITM_SendChar( data[count] ) ;  // Your low-level output function here.
    }

    return count;
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_DelayUS' 
*函数功能:'硬件 延时' 
*参    数:'' 
*返 回 值:'' 
*说    明: '采用阻塞方式的延时' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_DelayUS(uint32_t xus)
{
	// SysTick->LOAD = 72 * xus;				//设置定时器重装值
	// SysTick->VAL = 0x00;					//清空当前计数值
	// SysTick->CTRL = 0x00000005;				//设置时钟源为HCLK，启动定时器
	// while(!(SysTick->CTRL & 0x00010000));	//等待计数到0
	// SysTick->CTRL = 0x00000004;				//关闭定时器
    __IO uint32_t us= xus * 2;
    while (us > 0)
    {
        us--;
        __NOP();
        __NOP();
    }
    
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_DelayMS' 
*函数功能:'硬件 延时' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_DelayMS(uint32_t xms)
{
	while(xms--)
	{
		Bsp_DelayUS(1000);
	}
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_DelayS' 
*函数功能:'硬件 延时' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_DelayS(uint32_t xs)
{
	while(xs--)
	{
		Bsp_DelayMS(1000);
	}
} 

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_Init' 
*函数功能:'系统 初始化' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_Init(void){
	Bsp_GPIO_Init();
	//Bsp_SPI_Init();	
    //Bsp_Flash_Init();
	Bsp_USART_Init();
	//Bsp_I2C_Init();
    
}


/* 
// /*----------------------------------------------------------------------------------------- 
// *函数名称:'fputc' 
// *函数功能:'输出单个字符 用于调试，输出到swo 0端口' 
// *参    数:'Character' 
// *返 回 值:'' 
// *说    明: '' 
// *作    者:Danny 
// *----------------------------------------------------------------------------------------*/ 
// /*int Bsp_fputc(int Character)
// {	
// 	ITM_SendChar(Character);
// 	return Character;
// }
// /*----------------------------------------------------------------------------------------- 
// *函数名称:'Bsp_fputs' 
// *函数功能:'输出字符串' 
// *参    数:'' 
// *返 回 值:'' 
// *说    明: '' 
// *作    者: Danny 
// *----------------------------------------------------------------------------------------*/ 
// void Bsp_fputs(const char *str){
// 	while (*str)
// 	{
// 		Bsp_fputc(*str++);
// 	}
	
// }
// /*----------------------------------------------------------------------------------------- 
// *函数名称:'printf' 
// *函数功能:'输出调试参数到swo口' 
// *参    数:'format （字符数组）' 
// *返 回 值:'' 
// *说    明: '临时使用，后续需改进增加可用性' 
// *作    者:Danny 
// *----------------------------------------------------------------------------------------*/ 
// void Bsp_printf(const char *format,...){ 
// 	va_list args;  
//     va_start(args, format); 

// 	while (*format) {
// 		if (*format == '%') {  
//             format++;  
//             switch (*format) {  
//                 case 's': {  
//                     const char *s = va_arg(args, const char *);  
//                     Bsp_fputs(s);  
//                     break;  
//                 }  
//                 case 'd': {  
//                     int i = va_arg(args, int);  
//                     // 这里可以添加代码将整数转换为字符串并输出  
//                     // 为了简单起见，我们直接调用标准库函数  
//                     char buffer[32]; // 假设整数转换后的字符串长度不会超过31个字符（包括\0）  
//                     snprintf(buffer, sizeof(buffer), "%d", i);  
//                     Bsp_fputs(buffer);  
//                     break;  
//                 }  
//                 case 'c': {  
//                     char c = (char)va_arg(args, int); // va_arg返回的是int类型，需要转换为char  
//                     Bsp_fputc(c);  
//                     break;  
//                 }  
//                 // 可以添加更多格式说明符的处理...  
//                 default:  
//                     // 未知的格式说明符，可以输出一个错误消息或忽略它  
//                     //my_putchar('%');  
//                     //my_putchar(*format);  
//                     break;  
//             }
// 		}  
// 		else
//         {
//             Bsp_fputc(*format); // 调用自定义的my_fputc  
//         }
        
        
//         format++; 
    
//     } 
// 	va_end(args);
// } */