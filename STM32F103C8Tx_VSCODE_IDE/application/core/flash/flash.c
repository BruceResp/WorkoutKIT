#include "flash.h"
#include "bsp.h"

void FLASH_Write_Enable()
{
    Bsp_Flash_SPI_TransmitReceive(0x06);
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
void FLASH_Read_Data(u8 *addr, u8 *Rxdata, u8 Length)
{

    Bsp_Flash_SPI_TransmitReceive(0x03);

    for (u8 i = 0; i < 3; i++)
    {
        Bsp_Flash_SPI_TransmitReceive(addr[i]);
    }

    for (u8 i = 0; i < Length; i++)
    {
        Rxdata[i] = Bsp_Flash_SPI_TransmitReceive(0xff); // 传输一个无效字符来接收有效的数据
    }
}
/*-----------------------------------------------------------------------------------------
 *函数名称:'Flash_Read_Status'
 *函数功能:''
 *参    数:''
 *返 回 值:''
 *说    明: ''
 *作    者: Danny
 *----------------------------------------------------------------------------------------*/
u8 Flash_Read_Status(u8 Stat_reg_f)
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
    Bsp_Flash_SPI_TransmitReceive(stat_ins);
    return Bsp_Flash_SPI_TransmitReceive(0xFF);
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
void FLASH_Write_Data(u8 *addr, u8 *Data, u8 Length)
{
    // 检查busy位
    while ( (Flash_Read_Status(1) & FLASH_BUSY_MASK) != FLASH_BUSY_MASK);
    
    FLASH_Write_Enable();
    Bsp_Flash_SPI_TransmitReceive(0x02);
    for (u8 i = 0; i < 3; i++)
    {
        Bsp_Flash_SPI_TransmitReceive(addr[i]);
    }
    for (u8 i = 0; i < Length; i++)
    {
        Bsp_Flash_SPI_TransmitReceive(Data[i]);
    }
}
