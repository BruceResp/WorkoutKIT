#include "bsp.h"
#include "stm32f10x.h"

u8 TestPort[50],i = 0;
/*----------------------------------------------------------------------------------------- 
*函数名称:'Bsp_USART_Init' 
*函数功能:''初始化串口 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void Bsp_USART_Init(void){
    USART_InitTypeDef USART_InitStructure;

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1; 
    USART_InitStructure.USART_Parity = USART_Parity_No; 
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; 
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; 
    USART_Init(BSP_USART, &USART_InitStructure);

    //USART_DeInit(BSP_USART);
    USART_ITConfig(BSP_USART, USART_IT_RXNE, ENABLE);//开启串口接受中断

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
    
    USART_Cmd(BSP_USART, ENABLE); 
}

void Bsp_USART_Send_Byte(uint8_t Byte){
    USART_SendData(USART1, Byte);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void Bsp_USART_Send_Array(uint8_t *Array, uint16_t Length){
	uint16_t i;
	for (i = 0; i < Length; i ++)
	{
		Bsp_USART_Send_Byte(Array[i]);
	}
}

void Bsp_USART_Send_String(uint8_t *String){
	uint8_t i;
	for (i = 0; String[i] != '\0'; i ++)
	{
		Bsp_USART_Send_Byte(String[i]);
	}
}

void USART1_IRQHandler(void){
	u8 Res;

    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
    {
        
        Res =USART_ReceiveData(USART1);	//读取接收到的数据
        TestPort[i] = Res;
        i++;
        if (i == 49)
        {
            i = 0;
        }
        
        //USART_ClearITPendingBit(USART1, USART_IT_RXNE);
        Bsp_USART_Send_Byte(Res);
        //printf("Res");
    } 
} 