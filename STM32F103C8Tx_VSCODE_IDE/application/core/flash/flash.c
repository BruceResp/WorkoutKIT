#include "flash.h"
#include "bsp.h"
#include "sys_typedef.h"

MenuList_t Menu_list;
u8 Menu_List_Addr = 0x000000;   //存储菜单的FLASH地址
/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Read_ID' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '读取设备ID' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Read_ID(uint8_t *MID, uint16_t *DID)
{
	Bsp_Flash_SELECTED();
	Bsp_Flash_SPI_TransmitReceive(FLASH_JEDEC_ID);
	*MID = Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE);
	*DID = Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE);
	*DID <<= 8;
	*DID |= Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE);
	Bsp_Flash_DISELECTED();
}

/*  --------------------------------完成时序组装的工作------------------------------------- */

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
void FLASH_Read_Data(Flash_Addr_t addr, void *Rxdata, uint16_t Length)
{
    if (Length == 0)
    {
        return;
    }
    
    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_READ_DATA);

    Bsp_Flash_SPI_TransmitReceive(addr.addr >> 16);
    Bsp_Flash_SPI_TransmitReceive(addr.addr >> 8);
    Bsp_Flash_SPI_TransmitReceive(addr.addr);

    for (uint8_t i = 0; i < Length; i++)
    {
        *(uint8_t *)Rxdata = Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE); // 传输一个无效字符来接收有效的数据
        Rxdata += 1;
    }

    Bsp_Flash_DISELECTED();  
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
void FLASH_Write_Data(Flash_Addr_t addr, void *Data, uint16_t Length)
{
    // 检查busy位
    Bsp_Flash_Write_Enable();

    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_PAGE_PROGRAM);

    Bsp_Flash_SPI_TransmitReceive(addr.addr >> 16);
    Bsp_Flash_SPI_TransmitReceive(addr.addr >> 8);
    Bsp_Flash_SPI_TransmitReceive(addr.addr);

    for (; 0 < Length;Length-- ){
        Bsp_Flash_SPI_TransmitReceive(*(uint8_t *)(Data) );
        Data += 1;
    }

    Bsp_Flash_DISELECTED();  
    
    FLASH_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Sector_Erase' 
*函数功能:'FLASH 扇区 擦除' 
*参    数:'' 
*返 回 值:'' 
*说    明: '在写扇区之前 如果flash该区域已经有数据 必须先擦除才能写 擦除4KB' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Sector_Erase(Flash_Addr_t addr){

    Bsp_Flash_Write_Enable();

    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_SECTOR_ERASE_4KB);

    Bsp_Flash_SPI_TransmitReceive(addr.addr >> 16);
    Bsp_Flash_SPI_TransmitReceive(addr.addr >> 8);
    Bsp_Flash_SPI_TransmitReceive(addr.addr);

    Bsp_Flash_DISELECTED(); 
    
    FLASH_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
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
    Bsp_Flash_Write_Enable();

    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_BLOCK_ERASE_32KB);

    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    Bsp_Flash_DISELECTED(); 
    
    FLASH_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
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
    Bsp_Flash_Write_Enable();

    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_BLOCK_ERASE_64KB);

    Bsp_Flash_SPI_TransmitReceive(addr>>16);
    Bsp_Flash_SPI_TransmitReceive(addr>>8);
    Bsp_Flash_SPI_TransmitReceive(addr);

    Bsp_Flash_DISELECTED(); 
    
    FLASH_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
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
    Bsp_Flash_Write_Enable();

    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_CHIP_ERASE);

    Bsp_Flash_DISELECTED(); 
    
    FLASH_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
}


/*-----------------------------------------------------------------------------------------
 *函数名称:'FLASH_Read_StatusReg'
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
uint8_t FLASH_Read_StatusReg(uint8_t accessedReg,uint8_t statMask){

    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(accessedReg);
    u32 Timeout = 1000;
    u8 status = Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE);;
    while ( (Bsp_Flash_SPI_TransmitReceive(FLASH_DUMMY_BYTE) & statMask) == statMask){
		if (--Timeout == 0)
		{
			break;
		}
    };
    
    Bsp_Flash_DISELECTED();  

    return status;
    
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
        Bsp_Flash_Write_Volatile_StatReg_EN();
    }else{
        Bsp_Flash_Write_Enable();
    }
    
    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(Reg);
    Bsp_Flash_SPI_TransmitReceive(RegBitMask);  
    
    Bsp_Flash_DISELECTED(); 
}


/*                             应用层                            */
/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_lock_All' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '锁存所有扇区' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_lock_All(void){
    Bsp_Flash_Write_Enable();

    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_WRITE_STATUS_REGISTER_1);

    Bsp_Flash_SPI_TransmitReceive(0x00);
    Bsp_Flash_SPI_TransmitReceive(0x40);

    Bsp_Flash_DISELECTED(); 
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'Flash_Write_StatReg' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Unlock_All(void){
    Bsp_Flash_Write_Enable();

    Bsp_Flash_SELECTED();

    Bsp_Flash_SPI_TransmitReceive(FLASH_WRITE_STATUS_REGISTER_1);

    Bsp_Flash_SPI_TransmitReceive(0x00);
    Bsp_Flash_SPI_TransmitReceive(0x00);
    Bsp_Flash_DISELECTED(); 
    
   // FLASH_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK);
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Reset_device' 
*函数功能:'重启 设备' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void FLASH_Reset_device(void){
    Bsp_Flash_SELECTED();
    
    Bsp_Flash_SPI_TransmitReceive(FLASH_ENABLE_RESET);
    Bsp_Flash_DISELECTED();
    FLASH_Read_StatusReg(FLASH_READ_STATUS_REGISTER_1,FLASH_BUSY_MASK|FLASH_SUS_MASK);
    Bsp_Flash_SELECTED();
    Bsp_Flash_SPI_TransmitReceive(FLASH_ENABLE_RESET);
    Bsp_DelayUS(30);

    Bsp_Flash_DISELECTED();
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Write_Data' 
*函数功能:'' 
*参    数:'Block_addr:扇区地址 从 0 到 127（ 0x7f ）128个  一个64KB
            Sector_addr:     从 0 到 15 （0xf） 15个  一个4KB   (可以缺)
            Page_addr:'      从 0 开始 15  （0xf）15个 一个 256B (可以缺)
                            00
            size : 单位字节，描述存入数据组的大小
*返 回 值:'' 
*说    明: '下一步优化，拆分公共部分，节省代码空间降低耦合度' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
uint8_t FLASH_Write_Dataes(Flash_Addr_t StartAddr,void * DataArray, uint32_t size){

    uint8_t Pg1_Data_To_Write = 0xFF-StartAddr.Base_Addr;
    uint16_t across_pages = (size - Pg1_Data_To_Write) / 256 ;                            //跨几页  Base_addr所在页不算进去 不管整除之后有没有余数，都+1，所以最后写入的一页有可能为空，这会导致如果最后一页为空的情况下写入会报code 1 错误，然而实际上是可以写的

    if ( (size - Pg1_Data_To_Write) % 256)
    {
        across_pages += 1;
    }
    
    uint16_t Left_Pages = 0x7fff - (StartAddr.addr >> 8);                                //剩余可编辑页面
    
    if (Pg1_Data_To_Write < size)                                                        //检查是否跨页 当前条件跨页
    {
        if (across_pages > Left_Pages)                                                   //输入数据所跨的页大于可编辑区域
        {
            #ifdef Debug_mode
                Bsp_printf("error code 1 : error in writing Flash \r\n");
            #endif
            return Flase;
        }

        FLASH_Write_Data(StartAddr,DataArray,Pg1_Data_To_Write);                        //先把第一个没存满的页写完，字节数量就是当前页剩余的空间
        DataArray += Pg1_Data_To_Write / sizeof(DataArray[0]);                          //加上要写入的字节个数                              //写数据的地址加1个单位
        StartAddr.addr += Pg1_Data_To_Write;                                            //加上剩余的地址等于下一页开始的地址
        size -= Pg1_Data_To_Write +  (across_pages-1) * 256;
        for (;--across_pages >= 0;)
        {   
            if (across_pages == 0)                                                      //最后一页
            {   
                FLASH_Write_Data(StartAddr,DataArray,size);
                continue;
            }

            FLASH_Write_Data(StartAddr,DataArray,256);
            DataArray += 256 / sizeof(DataArray[0]);                                   //写数据的地址加1个单位
        }
        return True;
    }
    
    FLASH_Write_Data(StartAddr,DataArray,size);
    return True;
    
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'FLASH_Read_Dataes' 
*函数功能:'' 
*参    数:'Block_addr:扇区地址 从 0 到 127（ 0x7f ）128个  一个64KB
            Sector_addr:     从 0 到 15 （0xf） 15个  一个4KB   (可以缺)
            Page_addr:'      从 0 开始 15  （0xf）15个 一个 256B (可以缺)
                            00
            size : 单位字节，描述存入数据组的大小
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
uint8_t FLASH_Read_Dataes(Flash_Addr_t StartAddr,void * DataArray, uint32_t size){

    //uint32_t Start_Addr = Block_addr * FLASH_BLOCK_INDEX + Sector_addr * FLASH_SECTOR_INDEX + Page_addr * FLASH_PAGE_INDEX + Base_addr;
    uint8_t Pg1_Data_To_Write = 0xFF-StartAddr.Base_Addr;
    uint16_t across_pages = (size - Pg1_Data_To_Write) / 256 ;                            //跨几页  Base_addr所在页不算进去 不管整除之后有没有余数，都+1，所以最后写入的一页有可能为空，这会导致如果最后一页为空的情况下写入会报code 1 错误，然而实际上是可以写的

    if ( (size - Pg1_Data_To_Write) % 256)
    {
        across_pages += 1;
    }
    
    uint16_t Left_Pages = 0x7fff - (StartAddr.addr >> 8);    //剩余可编辑页面
    
    if (Pg1_Data_To_Write < size)                                                              //检查是否跨页 当前条件跨页
    {
        if (across_pages > Left_Pages)                                                       //输入数据所跨的页大于可编辑区域
        {
            #ifdef Debug_mode
                Bsp_printf("error code 1 : error in writing Flash \r\n");
            #endif
            return Flase;
        }

        FLASH_Read_Data(StartAddr,DataArray,Pg1_Data_To_Write);  //先把第一个没存满的页写完，字节数量就是当前页剩余的空间
        DataArray += Pg1_Data_To_Write / sizeof(DataArray[0]);                            //加上要写入的字节个数                              //写数据的地址加1个单位
        StartAddr.addr += Pg1_Data_To_Write;                           //加上剩余的地址等于下一页开始的地址
        size -= Pg1_Data_To_Write +  (across_pages-1) * 256;
        for (;--across_pages >= 0;)
        {   
            if (across_pages == 0)                                  //最后一页
            {   
                FLASH_Read_Data(StartAddr,DataArray,size);
                continue;
            }

            FLASH_Read_Data(StartAddr,DataArray,256);
            DataArray += 256 / sizeof(DataArray[0]);                                         //写数据的地址加1个单位
        }
        return True;
    }
    
    FLASH_Read_Data(StartAddr,DataArray,size);
    return True;
    
}
// /*----------------------------------------------------------------------------------------- 
// *函数名称:'FLASH_Read_Menu_num' 
// *函数功能:'' 
// *参    数:'' 
// *返 回 值:'' 
// *说    明: '返回菜单个数' 这里可以再优化
// *作    者: Danny 
// *----------------------------------------------------------------------------------------*/ 
// uint8_t FLASH_Read_Menu_num(void){

//     FLASH_Read_Data(Menu_List_Addr,&Menu_list,1);

//     return Menu_list.Menu_num;
// }
// /*----------------------------------------------------------------------------------------- 
// *函数名称:'Flash_Read_Menu_List' 
// *函数功能:'' 
// *参    数:'Menu_num:菜单数量' 
// *返 回 值:'' 
// *说    明: '' 
// *作    者: Danny 
// *----------------------------------------------------------------------------------------*/ 
// uint8_t Flash_Read_Menu_List(void){

//     FLASH_Read_Data(Menu_List_Addr,&Menu_list,2);
//     if (Menu_list.Menu_num == 0)
//     {
//         return;
//     }
//     u8 baseIndex = 3;           //一个Actions的大小
//     u8 Menunum = Menu_list.Menu_num;
//     u8 Actionum = Menu_list.menu[0].Actions_num;
//     u8 nextAddr = Menu_List_Addr + 3;
//     u8 datalength = 1;
//     u8 menuIndex = 0,actionsIndex = 0;

//     for (; Menunum > 0; Menunum--)
//     {
//         if (Actionum == 0)//如果第一个菜单内的动作为0 说明最后一个为0长数组，不占据空间
//         {
//             datalength = 0;
//         }else
//         {
//             datalength = baseIndex * Actionum;
//         }
        
//         FLASH_Read_Data(nextAddr,&Menu_list.menu[menuIndex].Actions[actionsIndex],datalength);
//         Actionum = Menu_list.menu[menuIndex].Actions_num;
//         nextAddr += baseIndex * Actionum + 2;
//         menuIndex += 1;
//     }

//     for (u8 i = 0; i < Actionum; i++)
//     {
//         /* code */
//     }
// }



//  old version 

/* uint8_t FLASH_Write_Dataes(uint8_t Block_addr,uint8_t Sector_addr,uint8_t Page_addr,uint8_t Base_addr,void * DataArray, uint32_t size){

    uint32_t Start_Addr = Block_addr * FLASH_BLOCK_INDEX + Sector_addr * FLASH_SECTOR_INDEX + Page_addr * FLASH_PAGE_INDEX ;
    uint8_t Pg1_Data_To_Write = 0xFF-Base_addr;
    uint16_t across_pages = (size - Pg1_Data_To_Write) / 256 ;                            //跨几页  Base_addr所在页不算进去 不管整除之后有没有余数，都+1，所以最后写入的一页有可能为空，这会导致如果最后一页为空的情况下写入会报code 1 错误，然而实际上是可以写的

    if ( (size - Pg1_Data_To_Write) % 256)
    {
        across_pages += 1;
    }
    
    uint16_t Left_Pages = 0x7fff - Block_addr * 0x100 + Sector_addr * 0x10 + Page_addr * 0x1;    //剩余可编辑页面
    
    if (Pg1_Data_To_Write < size)                                                              //检查是否跨页 当前条件跨页
    {
        if (across_pages > Left_Pages)                                                       //输入数据所跨的页大于可编辑区域
        {
            #ifdef Debug_mode
                Bsp_printf("error code 1 : error in writing Flash \r\n");
            #endif
            return Flase;
        }

        FLASH_Write_Data(Start_Addr,DataArray,Pg1_Data_To_Write);  //先把第一个没存满的页写完，字节数量就是当前页剩余的空间
        DataArray += Pg1_Data_To_Write / sizeof(DataArray[0]);                            //加上要写入的字节个数                              //写数据的地址加1个单位
        Start_Addr += Pg1_Data_To_Write;                           //加上剩余的地址等于下一页开始的地址
        size -= Pg1_Data_To_Write +  (across_pages-1) * 256;
        for (;--across_pages >= 0;)
        {   
            if (across_pages == 0)                                  //最后一页
            {   
                FLASH_Write_Data(Start_Addr,DataArray,size);
                continue;
            }

            FLASH_Write_Data(Start_Addr,DataArray,256);
            DataArray += 256 / sizeof(DataArray[0]);                                         //写数据的地址加1个单位
        }
        return True;
    }
    
    FLASH_Write_Data(Start_Addr,DataArray,size);
    return True;
    
}*/
