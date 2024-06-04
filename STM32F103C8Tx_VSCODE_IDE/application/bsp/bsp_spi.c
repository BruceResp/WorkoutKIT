#include "bsp.h"

#define Bsp_SPI_DC_CMD()	GPIO_ResetBits(GPIOA,GPIO_Pin_6) //模式 
#define Bsp_SPI_DC_DAT()	GPIO_SetBits(GPIOA,GPIO_Pin_6)

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_SPI_Init' 
*函数功能:'硬件 SPI 初始化' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_SPI_Init(void) {
    
    SPI_InitTypeDef SPI_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 , ENABLE);

    SPI_I2S_DeInit(GUI_SPI);
    SPI_InitStruct.SPI_Direction = SPI_Direction_1Line_Tx;
    SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
    SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;                    //空闲 低
    SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;            //大端
    SPI_InitStruct.SPI_CRCPolynomial = 7;

    SPI_Init(GUI_SPI,&SPI_InitStruct);
    //SPI1->CR1 &=0xfeff;
    SPI1->CR2=1 << 1;                                          //允许DMA往缓冲区内发送
    
    SPI_Cmd(GUI_SPI,ENABLE);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_SPI_Send_CMD' 
*函数功能:'SPI 发送 指令' 
*说    明: '发送完指令以后自动设置成发送数据模式' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_SPI_Send_CMD(u8 TxData)                                   //发送命令
{
	u8 retry=0;
	Bsp_SPI_DC_CMD();                                              //命令模式
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //检查指定的 SPI标志位设置与否:发送缓存空标志位
	{
		retry++;
		if(retry>200) return ;
	}
	
	Bsp_DelayMS(100);
	SPI_I2S_SendData(SPI1, TxData);                                 //通过外设 SPIx 发送一个数据
	retry=0;
	Bsp_SPI_DC_DAT();                                               //数据模式
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_SPI_RES_LOW' 
*函数功能:'SPI RESET引脚 拉低' 
*说    明: '配置或遇到通信问题时，将SPI接口恢复到初始状态或已知状态' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_SPI_RES_LOW(void){
   
    GPIO_ResetBits(GPIOA,GUI_RST_PIN);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_SPI_RES_HIGH' 
*函数功能:'SPI RESET引脚 拉高' 
*说    明: '配置或遇到通信问题时，将SPI接口恢复到初始状态或已知状态' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_SPI_RES_HIGH(void){
    GPIO_SetBits(GPIOA,GUI_RST_PIN);
}





