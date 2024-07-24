#include "bsp.h"

GPIO_InitTypeDef GPIO_InitStruct_AF_PP;
GPIO_InitTypeDef GPIO_InitStruct_OUT_PP;
GPIO_InitTypeDef GPIO_InitStruct_AF_OD;
GPIO_InitTypeDef GPIO_InitStruct_IN_UP;  //输入下拉
GPIO_InitTypeDef GPIO_InitStructure;

void Bsp_GPIO_Init(){

    /*------------中断优先级--------------*/
    
    /*------------*/


    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOB , ENABLE);
    
    #if defined(GUI_SPI_MODE_SUPPORT)
        GPIO_InitStruct_AF_PP.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStruct_AF_PP.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_AF_PP.GPIO_Pin = GUI_MOSI_PIN | GUI_SCK_PIN;
        
        GPIO_InitStruct_OUT_PP.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStruct_OUT_PP.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_OUT_PP.GPIO_Pin = GUI_RST_PIN | GUI_DC_PIN;

        GPIO_Init(GPIOA, &GPIO_InitStruct_AF_PP);
        GPIO_Init(GPIOA, &GPIO_InitStruct_OUT_PP);

    #elif defined(GUI_I2C_MODE_SUPPORT)
        GPIO_InitStruct_AF_OD.GPIO_Mode = GPIO_Mode_AF_OD;
        GPIO_InitStruct_AF_OD.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_AF_OD.GPIO_Pin = GUI_SCL_PIN | GUI_SDA_PIN ;
        GPIO_Init(GPIOB,&GPIO_InitStruct_AF_OD);

    #endif
    #ifdef KEY_Marix
        GPIO_InitStruct_IN_UP.GPIO_Mode = GPIO_Mode_IPU;
        GPIO_InitStruct_IN_UP.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_IN_UP.GPIO_Pin = KEY_UP_PIN | KEY_DOWN_PIN | KEY_SET_PIN;

        GPIO_Init(GPIOA,&GPIO_InitStruct_IN_UP);
        GPIO_InitStruct_IN_UP.GPIO_Pin = KEY_COMFIRM_PIN;
        GPIO_Init(GPIOB,&GPIO_InitStruct_IN_UP);
    #endif

    #ifdef FLASH_SPI_SUPPORT
        GPIO_InitStruct_AF_PP.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStruct_AF_PP.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_AF_PP.GPIO_Pin = FLASH_SPI_DI_PIN | FLASH_SPI_CLK_PIN ;
        
        GPIO_InitStruct_IN_UP.GPIO_Mode = GPIO_Mode_IPU;
        GPIO_InitStruct_IN_UP.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_IN_UP.GPIO_Pin = FLASH_SPI_DO_PIN;

        GPIO_InitStruct_OUT_PP.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStruct_OUT_PP.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStruct_OUT_PP.GPIO_Pin = FLASH_SPI_CS_PIN;
        
        GPIO_Init(GPIOB, &GPIO_InitStruct_OUT_PP);
        GPIO_Init(GPIOB, &GPIO_InitStruct_AF_PP);
        GPIO_Init(GPIOB, &GPIO_InitStruct_IN_UP);
    #endif

    #ifdef BSP_USART_SUPPORT

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
        GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
        
        //USART1_RX	  GPIOA.10初始化
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
        GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10 
        

    #endif

}





