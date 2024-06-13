#include "flash.h"
#include "bsp.h"

#define FLASH_SELECTED()          GPIO_ResetBits(FLASH_SPI_CS_PORT,FLASH_SPI_CS_PIN)
#define FLASH_DISELECTED()        GPIO_SetBits(FLASH_SPI_CS_PORT,FLASH_SPI_CS_PIN)

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Read_ID' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Read_ID(uint8_t *MID, uint16_t *DID)
{
	FLASH_SELECTED();
	Bsp_Flash_SPI_TransmitReceive(FLASH_JEDEC_ID);
	*MID = Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE);
	*DID = Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE);
	*DID <<= 8;
	*DID |= Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE);
	FLASH_DISELECTED();
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Write_Enable' 
*函数功能:'FLASH 写 使能' 
*参    数:'' 
*返 回 值:'' 
*说    明: '在写/擦除Flash之前必须使能' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Write_Enable()
{
    FLASH_SELECTED();
    Bsp_Flash_SPI_TransmitReceive(FLASH_WRITE_ENABLE);
    FLASH_DISELECTED();  
}

void FLASH_Write_Volatile_StatReg_EN(){
    FLASH_SELECTED();
    Bsp_Flash_SPI_TransmitReceive(FLASH_WRITE_ENABLE);
    FLASH_DISELECTED();
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Write_Disable' 
*函数功能:'FLASH 写 失能' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Write_Disable()
{
    FLASH_SELECTED();
    Bsp_Flash_SPI_TransmitReceive(FLASH_WRITE_DISABLE);
    FLASH_DISELECTED();
}

/*-----------------------------------------------------------------------------------------
*函数名称:'FLASH_Read_Data'
*函数功能:'Flash 读 数据'
*参    数:''
*返 回 值:''
*说    明: '
            addr[0]: BLOCK: 00-7F'
            addr[1]: Sector: 0-F  F个 Sector组成一个Block
            addr[2]: 1个sector 内部 0 / 00-f / ff(Page)
            F个page组成一个sector，
            Length:要读取的字节个数 (uint8_t 最多255个数据)
*作    者: Danny
*----------------------------------------------------------------------------------------*/
void FLASH_Read_Data(uint8_t addr, uint8_t *Rxdata, uint8_t Length)
{
    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_READ_DATA);

    // for (uint8_t i = 0; i < 3; i++)
    // {
    //     Bsp_Flash_SPI_TransmitReceive(addr[i])
    // }
    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    for (uint8_t i = 0; i < Length; i++)
    {
        Rxdata[i] = Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE); // 传输一个无效字符来接收有效的数据
    }

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
void FLASH_Write_Data(uint8_t addr, uint8_t *Data, uint8_t Length)
{
    // 检查busy位
    FLASH_Write_Enable();

    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_PAGE_PROGRAM);

    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    for (uint8_t i = 0; i < Length; i++){
        Bsp_Flash_SPI_TransmitReceive(Data[i]);
    }

    FLASH_DISELECTED();  

    Flash_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Sector_Erase' 
*函数功能:'FLASH 扇区 擦除' 
*参    数:'' 
*返 回 值:'' 
*说    明: '在写扇区之前 如果flash该区域已经有数据 必须先擦除才能写 擦除4KB' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Sector_Erase(uint8_t addr){

    FLASH_Write_Enable();

    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_SECTOR_ERASE_4KB);

    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    FLASH_DISELECTED(); 

    Flash_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Block_Erase' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '如果操作的flash区域被锁住了，则不能操作' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Block_Erase(uint8_t addr){
    FLASH_Write_Enable();

    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_BLOCK_ERASE_32KB);

    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    FLASH_DISELECTED(); 

    Flash_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Block_Erase_64KB' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '如果操作的flash区域被锁住了，则不能操作' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Block_Erase_64KB(uint8_t addr){
    FLASH_Write_Enable();

    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_BLOCK_ERASE_64KB);

    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    FLASH_DISELECTED(); 

    Flash_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Chip_Erase' 
*函数功能:'FLASH 芯片 擦除' 
*参    数:'' 
*返 回 值:'' 
*说    明: '如果操作的flash区域被锁住了，则不能操作' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Chip_Erase(void){
    FLASH_Write_Enable();

    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_CHIP_ERASE);

    FLASH_DISELECTED(); 

    Flash_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
}

/*-----------------------------------------------------------------------------------------
 *函数名称:'Flash_Read_StatusReg'
 *函数功能:''
 *参    数:'accessedReg:FLASH_READ_STATUS_REGISTER_1
                        FLASH_READ_STATUS_REGISTER_2
                        FLASH_READ_STATUS_REGISTER_3
            statMask:   FLASH_BUSY_MASK
                        FLASH_WEL_MASK
                        FLASH_BP0_MASK'
 *返 回 值:''
 *说    明: ''
 *作    者: Danny
 *----------------------------------------------------------------------------------------*/
void Flash_Read_StatusReg(uint8_t accessedReg,uint8_t statMask)
{

    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(accessedReg);
    u32 Timeout = 1000;
    while ( (Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE) & statMask) == FLASH_BUSY_MASK){
		if (--Timeout == 0)
		{
			break;
		}
    };
    
    FLASH_DISELECTED();  
    
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Write_StatusReg' 
*函数功能:'' 
*参    数:' Reg :FLASH_WRITE_STATUS_REGISTER_1
                FLASH_WRITE_STATUS_REGISTER_2
                FLASH_WRITE_STATUS_REGISTER_3
                
            RegBitMask:FLASH_XXX_MASK|FLASH_XXX_MASK|...
                        ' 
*返 回 值:'' 
*说    明:  reg1: SEC TB BP[0:2] 可以写
            reg2: CMP QE SRL 可以写，LB[3:1] non-volatile 只能修改一次
            reg3 DRV1 DRV0 WPS 可以写
            All other Status Register bit locations are read-only and will not be affected 
            by the Write Status Register instruction.'
            ' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Write_StatusReg(uint8_t Reg,uint8_t RegBitMask){    
    
    if ((Reg == FLASH_WRITE_STATUS_REGISTER_2) && (RegBitMask & FLASH_VOLATILE_BIT_MASK)){
        FLASH_Write_Volatile_StatReg_EN();
    }else{
        FLASH_Write_Enable();
    }
    
    FLASH_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(Reg);
    Bsp_Flash_SPI_TransmitReceive(RegBitMask);  
    
    FLASH_DISELECTED(); 
}