#include "bsp.h"

// 发送之前的缓存

void ERROR_DECT(uint16_t OVER_NUM,const char *WARNING){
    
    
    if (OVER_NUM--<=0)
    {
        //Bsp_printf(WARNING); 
    }
};

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_I2C_DMA_Enable' 
*函数功能:'I2C DMA 使能' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_I2C_DMA_Ctrl(FunctionalState ctrl){
    I2C_DMACmd(GUI_I2C,ctrl);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_I2C_Init' 
*函数功能:'硬件 I2C 初始化' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_I2C_Init(void){

    if (GUI_I2C == I2C1){
        RCC_APB1PeriphClockCmd(RCC_APB1ENR_I2C1EN , ENABLE);
    }
    else{
        RCC_APB2PeriphClockCmd(RCC_APB1ENR_I2C2EN , ENABLE);
    }

    I2C_DeInit(GUI_I2C);

    GUI_I2C->CR1 |= 0x8000;  // 手动清除清BUSY 避免出现硬件错误
	GUI_I2C->CR1 &= ~0x8000;
    
    I2C_InitTypeDef I2C_InitStruct;
    //cutome mode : common mode
    I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
    // I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
    // I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
    // I2C_InitStruct.I2C_OwnAddress1 = 0x30;
    // I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    // I2C_InitStruct.I2C_ClockSpeed = 400000;

    I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStruct.I2C_DutyCycle = 0;
    I2C_InitStruct.I2C_OwnAddress1 = 0;
    I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_InitStruct.I2C_ClockSpeed = 10000;
    I2C_Cmd(GUI_I2C,ENABLE);
    I2C_Init(GUI_I2C,&I2C_InitStruct);

    
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); 	
    // DMA_InitTypeDef DMA_InitStruct = {
    //     DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)&GUI_I2C->DR,
    //     DMA_InitStruct.DMA_PeripheralDataSize =DMA_PeripheralDataSize_Byte,
    //     DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable ,

    //     //DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)&OLED_Test,
    //     DMA_InitStruct.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte,
    //     DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable,

    //     DMA_InitStruct.DMA_BufferSize = 128,
    //     DMA_InitStruct.DMA_Priority = DMA_Priority_VeryHigh
    // };
    // DMA_Init(DMA1_Channel6,&DMA_InitStruct);
    // NVIC_InitTypeDef NVIC_InitStructure;
	// //中断优先级NVIC设置
	// NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel6_IRQn;  //DMA中断
	// NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	// NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  //从优先级1级
	// NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	// NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器

    // DMA_ITConfig(DMA1_Channel6, DMA_IT_TC, ENABLE);	
    // DMA_Cmd(DMA1_Channel6,ENABLE);
    
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_I2C_Write_Byte' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void I2C_Write_DATA(const uint8_t dat){
    // int error =0;
    while (!I2C_CheckEvent(GUI_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING)){
        //ERROR_DECT(*OVER_NUM ,"const char *WARNING");
        //return;    
    };
    
    I2C_SendData(GUI_I2C,dat);

}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_I2C_Write_Byte' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void I2C_Write_Ins(const uint8_t Ins){
    // int error =0;
    while (!I2C_CheckEvent(GUI_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING)){
        // error++;
        // if (error>1000)
        // {
        //     printf("\r\n I2C 写 指令 超时 \r\n");
        //     return ;
        // }        
    };
    
    I2C_SendData(GUI_I2C,Ins);

}

/*----------------------------------------------------------------------------------------- 
*函数名称:'I2C_Write_Addr' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void I2C_Write_Addr(const uint8_t addr){
//    uint16_t error =0;
   while (!I2C_CheckEvent(GUI_I2C,I2C_EVENT_MASTER_MODE_SELECT)){}
   I2C_Send7bitAddress(GUI_I2C,addr,I2C_Direction_Transmitter);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'I2C_START' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void I2C_START(void){
    while (I2C_GetFlagStatus(GUI_I2C, I2C_FLAG_BUSY)){};
    
	I2C_GenerateSTART(GUI_I2C,ENABLE);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'I2C_STOP' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void I2C_STOP(void){
    while(!I2C_CheckEvent(GUI_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED)){};
	
    I2C_GenerateSTOP(GUI_I2C,ENABLE);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_I2C_SET' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_I2C_SET(const uint8_t CMD){
	I2C_START();

	I2C_Write_Addr(OLED_ADDRESS);
    I2C_Write_Ins(OLED_SSD1306_SEND_CMD);
    I2C_Write_DATA(CMD);

	I2C_STOP();
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_I2C_Multi_SET' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_I2C_Multi_SET(const uint8_t *CMD,uint8_t count){
	I2C_START();

	I2C_Write_Addr(OLED_ADDRESS);
    I2C_Write_Ins(OLED_SSD1306_SEND_CMD);
    for (uint8_t i = 0; i < count; i++)
    {
        I2C_Write_DATA(CMD[i]);
    }
	I2C_STOP();
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_I2C_Write_Byte' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_I2C_Write_Byte(const uint8_t dat){
	I2C_START();

	I2C_Write_Addr(OLED_ADDRESS);
    I2C_Write_Ins(OLED_SSD1306_SEND_DATA);

    I2C_Write_DATA(dat);

	I2C_STOP();
}
/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_I2C_Write_Bytes' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_I2C_Write_Bytes(const uint32_t dat,uint8_t count){

    I2C_START();
	I2C_Write_Addr(OLED_ADDRESS);
    I2C_Write_Ins(OLED_SSD1306_SEND_DATA);
    while (!I2C_CheckEvent(GUI_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING))
    DMA_Cmd(DMA1_Channel6,DISABLE);
    //DMA_SetCurrDataCounter(DMA1_Channel6, 1024);
    DMA1_Channel6->CMAR = (uint32_t)dat;
    DMA_Cmd(DMA1_Channel6,ENABLE);

    // for (uint8_t i = 0; i < count; i++)
    // {
        
    //     I2C_Write_DATA(dat[i]);
    //     //Bsp_printf("\r\n %d \r\n",DMA_GetCurrDataCounter(DMA1_Channel6));
    // }
	//I2C_STOP();
}

