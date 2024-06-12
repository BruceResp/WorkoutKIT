#include "flash.h"
#include "bsp.h"
#define FLASH_SELECTED()          GPIO_ResetBits(FLASH_SPI_CS_PORT,FLASH_SPI_CS_PIN)
#define FLASH_DISELECTED()        GPIO_SetBits(FLASH_SPI_CS_PORT,FLASH_SPI_CS_PIN)

void FLASH_Read_ID(uint8_t *MID, uint16_t *DID)
{
	FLASH_SELECTED();
	Bsp_Flash_SPI_TransmitReceive(0x9F);
	*MID = Bsp_Flash_SPI_TransmitReceive(0xff);
	*DID = Bsp_Flash_SPI_TransmitReceive(0xff);
	*DID <<= 8;
	*DID |= Bsp_Flash_SPI_TransmitReceive(0xff);
	FLASH_DISELECTED();
}

void FLASH_Write_Enable()
{
    FLASH_SELECTED();
    Bsp_Flash_SPI_TransmitReceive(0x06);
    FLASH_DISELECTED();  
}

void FLASH_Write_Disable()
{
    Bsp_Flash_SPI_TransmitReceive(0x04);
}

/*-----------------------------------------------------------------------------------------
*函数名称:'FLASH_Read_Data'
*函数功能:''
*参    数:''
*返 回 值:''
*说    明: '
            addr[0]: BLOCK: 00-7F'
            addr[1]: Sector: 0-F  F个 Sector组成一个Block
            addr[2]: 1个sector 内部 0 / 00-f / ff(Page)
            F个page组成一个sector，
            Length:要读取的字节个数 (u8 最多255个数据)
*作    者: Danny
*----------------------------------------------------------------------------------------*/
void FLASH_Read_Data(u8 addr, u8 *Rxdata, u8 Length)
{
    FLASH_SELECTED();
    Bsp_Flash_SPI_TransmitReceive(0x03);

    // for (u8 i = 0; i < 3; i++)
    // {
    //     Bsp_Flash_SPI_TransmitReceive(addr[i])
    // }
    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    for (u8 i = 0; i < Length; i++)
    {
        Rxdata[i] = Bsp_Flash_SPI_TransmitReceive(0xfc); // 传输一个无效字符来接收有效的数据
    }
    FLASH_DISELECTED();  
}

void FLASH_Sector_Erase(u8 addr){
    FLASH_Write_Enable();
    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(0x02);

    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    FLASH_DISELECTED();  
    Flash_Read_Status(1);

}

/*-----------------------------------------------------------------------------------------
 *函数名称:'Flash_Read_Status'
 *函数功能:''
 *参    数:''
 *返 回 值:''
 *说    明: ''
 *作    者: Danny
 *----------------------------------------------------------------------------------------*/
void Flash_Read_Status(u8 Stat_reg_f)
{

    u8 stat_ins;
    switch (Stat_reg_f)
    {
    case 1:
        stat_ins = 0x05;
        break;
    case 2:
        stat_ins = 0x35;
        break;
    case 3:
        stat_ins = 0x15;
        break;
    default:
        break;
    }
    FLASH_SELECTED();
    Bsp_Flash_SPI_TransmitReceive(stat_ins);
    u32 Timeout = 1000;
    while ( (Bsp_Flash_SPI_TransmitReceive(0xFF) & FLASH_BUSY_MASK) == FLASH_BUSY_MASK){
        Timeout --;
		if (Timeout == 0)
		{
			break;
		}
    };
    FLASH_DISELECTED();  
    
}

/*-----------------------------------------------------------------------------------------
*函数名称:'FLASH_Write_Data'
*函数功能:''
*参    数:''
*返 回 值:''
*说    明: '写之前必须使能，写完之后自动写失能，写之前要先检查busy位，如果要写一个已经写入的数据要先清理所有的数据'
            一次最多写1Page（256字节）
*作    者: Danny
*----------------------------------------------------------------------------------------*/
void FLASH_Write_Data(u8 addr, u8 *Data, u8 Length)
{
    // 检查busy位
    
    FLASH_Write_Enable();
    FLASH_SELECTED();
    Bsp_Flash_SPI_TransmitReceive(0x02);
    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);
    for (u8 i = 0; i < Length; i++)
    {
        Bsp_Flash_SPI_TransmitReceive(Data[i]);
    }
    FLASH_DISELECTED();  
    Flash_Read_Status(1);
}
