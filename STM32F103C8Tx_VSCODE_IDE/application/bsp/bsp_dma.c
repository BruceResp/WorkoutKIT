#include "bsp.h"

uint8_t GUI_DISPLAY_BUF[8][128];

void Bsp_SPI_DMA_Init(){
    
    DMA_InitTypeDef DMA_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); 					//使能 DMA 时钟
	DMA_DeInit(DMA1_Channel3);

	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&SPI1->DR; 			//DMA 外设 ADC 基地址
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&GUI_DISPLAY_BUF; 		//DMA 内存基地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST; 					//从储存器读取发送到外设
	DMA_InitStructure.DMA_BufferSize = 1024; 							//DMA 通道的 DMA 缓存的大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;	//外设地址不变
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; 			//内存地址递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //8 位
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; 	// 8 位
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; 					//工作在循环传输模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 				//DMA 通道 x 拥有中优先级
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 						//非内存到内存传输

	DMA_Init(DMA1_Channel3, &DMA_InitStructure); //根据指定的参数初始化

	DMA_Cmd(DMA1_Channel3, ENABLE); //使能DMA1 CH3所指示的通道
}


void Bsp_I2C_DMA_Init(){
    Bsp_I2C_DMA_Ctrl(ENABLE);
    
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); 					//使能 DMA 时钟
	DMA_DeInit(DMA1_Channel6);

	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&GUI_I2C->DR; 			//DMA 外设 ADC 基地址
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&GUI_DISPLAY_BUF; 		//DMA 内存基地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST; 					//从储存器读取发送到外设
	DMA_InitStructure.DMA_BufferSize = 128; 							//DMA 通道的 DMA 缓存的大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;	//外设地址不变
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; 			//内存地址递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //8 位
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; 	// 8 位
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; 					//工作在循环传输模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 				//DMA 通道 x 拥有中优先级
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 						//非内存到内存传输

	DMA_Init(DMA1_Channel6, &DMA_InitStructure); //根据指定的参数初始化

	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = DMA1_Channel6_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);

	DMA_Cmd(DMA1_Channel6, ENABLE); //使能DMA1 CH3所指示的通道
	DMA_Cmd(DMA1_Channel6, DISABLE); 
	DMA_ITConfig(DMA1_Channel6,DMA_IT_TC,ENABLE);
}

void DMA1_Channel6_IRQHandler(void){
	if (DMA_GetFlagStatus(DMA1_FLAG_TC6))
	{
		DMA_ClearFlag(DMA1_FLAG_TC6);
		Bsp_DelayUS(10);
		I2C_GenerateSTOP(GUI_I2C,ENABLE);
		I2C_AcknowledgeConfig(GUI_I2C,ENABLE);
		DMA_Cmd(DMA1_Channel6, DISABLE);
	}
}	

