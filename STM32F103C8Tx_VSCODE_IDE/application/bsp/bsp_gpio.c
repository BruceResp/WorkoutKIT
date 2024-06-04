#include "bsp.h"

GPIO_InitTypeDef GPIO_InitStruct_AF_PP;
GPIO_InitTypeDef GPIO_InitStruct_OUT_PP;
GPIO_InitTypeDef GPIO_InitStruct_AF_OD;



void Bsp_GPIO_Init(){

    /*------------中断优先级--------------*/
    
    /*------------*/


    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOB , ENABLE);
    
    #if defined(GUI_SPI_MODE_SUPPORT)
        GPIO_InitStruct_AF_PP.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStruct_AF_PP.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_AF_PP.GPIO_Pin = GUI_MOSI_PIN | GUI_SCK_PIN;
        
        GPIO_InitStruct_OUT_PP.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStruct_OUT_PP.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_OUT_PP.GPIO_Pin = GUI_RST_PIN | GUI_DC_PIN;

        GPIO_Init(GPIOA, &GPIO_InitStruct_AF_PP);
        GPIO_Init(GPIOA,&GPIO_InitStruct_OUT_PP);
      
    #elif defined(GUI_I2C_MODE_SUPPORT)
        GPIO_InitStruct_AF_OD.GPIO_Mode = GPIO_Mode_AF_OD;
        GPIO_InitStruct_AF_OD.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_AF_OD.GPIO_Pin = GUI_SCL_PIN | GUI_SDA_PIN ;
        GPIO_Init(GPIOB,&GPIO_InitStruct_AF_OD);

    #endif
}
 
 
 
 




