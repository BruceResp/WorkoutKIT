#ifndef _BSP_H_
#define _BSP_H_
// Include--------------------------------------------------------------------
#include "stm32f10x.h"
#include "system_stm32f10x.h"  
#include "stdio.h"
#include "WK1000.h"


#define Flase                         0
#define True                          1

#define Bsp_Flash_SELECTED()          GPIO_ResetBits(FLASH_SPI_CS_PORT,FLASH_SPI_CS_PIN)
#define Bsp_Flash_DISELECTED()        GPIO_SetBits(FLASH_SPI_CS_PORT,FLASH_SPI_CS_PIN)

extern int Bsp_fputc(int Character);
extern void Bsp_printf(const char *format,...);

extern void Bsp_GPIO_Init(void);
extern void Bsp_Init(void);

extern void Bsp_DelayUS(uint32_t us);
extern void Bsp_DelayMS(uint32_t ms);
extern void Bsp_DelayS(uint32_t s);

extern void Bsp_SPI_RES_LOW(void);
extern void Bsp_SPI_RES_HIGH(void);
extern void Bsp_SPI_Init(void);
extern void Bsp_SPI_Send_CMD(uint8_t TxData);


extern void Bsp_I2C_Init(void);
extern void Bsp_I2C_SET(const uint8_t CMD);
extern void Bsp_I2C_Multi_SET(const uint8_t *CMD,uint8_t count);
extern void Bsp_I2C_Write_Byte(const uint8_t dat);
extern void Bsp_I2C_Write_Bytes(const uint8_t *dat,uint8_t count);


extern void Bsp_SPI_DMA_Init(void);
extern void Bsp_I2C_DMA_Init(void);

extern void Bsp_I2C_DMA_Ctrl(FunctionalState ctrl);

extern uint8_t Bsp_KEY_Probe(uint8_t key);

extern void Bsp_Flash_Init(void);
extern uint8_t Bsp_Flash_SPI_TransmitReceive(uint8_t TxData);
extern void Bsp_Flash_Write_Enable(void);
extern void Bsp_Flash_Write_Volatile_StatReg_EN(void);
extern void Bsp_Flash_Write_Disable(void);

#endif
