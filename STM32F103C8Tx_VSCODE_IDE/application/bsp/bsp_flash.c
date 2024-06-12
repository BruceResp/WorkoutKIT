#include "bsp.h"


/*----------------------------------------------------------------------------------------- 
*函数名称:'Flash_Init' 
*函数功能:'flash 初始化' 
*参    数:'' 
*返 回 值:'' 
*说    明: '初始化flash' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_Flash_Init(void){
    
    SPI_InitTypeDef FLASH_SPI_InitStruct;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2 , ENABLE);
    
    SPI_I2S_DeInit(FLASH_SPI);
    FLASH_SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    FLASH_SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
    FLASH_SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
    FLASH_SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;                    //空闲 低
    FLASH_SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;                  //奇数边沿
    FLASH_SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
    FLASH_SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
    FLASH_SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;            //大端
    FLASH_SPI_InitStruct.SPI_CRCPolynomial = 7;

    SPI_Init(FLASH_SPI,&FLASH_SPI_InitStruct);
    
    SPI_Cmd(FLASH_SPI,ENABLE);
    
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_Flash_SPI_TransmitReceive' 
*函数功能:' FLASH 标准spi 传输接收 ' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
u8 Bsp_Flash_SPI_TransmitReceive(u8 TxData){
    
    //FLASH_SELECTED();
	while (SPI_I2S_GetFlagStatus(FLASH_SPI, SPI_I2S_FLAG_TXE) != SET); //检查指定的 SPI标志位设置与否:发送缓存空标志位	
    
    FLASH_SPI->DR = TxData;
    
    while (SPI_I2S_GetFlagStatus(FLASH_SPI,SPI_I2S_FLAG_RXNE) != SET);

    return SPI_I2S_ReceiveData(FLASH_SPI);
    
}

