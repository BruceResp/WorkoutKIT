#ifndef _FLASH_H_
#define _FLASH_H_

#include "stm32f10x.h"

// typedef struct 
// {
//     uint32_t Block_Addr                        :8;
//     uint32_t Sector_Addr                       :4;
//     uint32_t Page_Addr                         :4;
//     uint32_t Base_Addr                         :8;
// }Flash_Addr_t;

typedef union 
{
    uint32_t addr;
    struct 
    {
        uint8_t Block_Addr                        ;
        uint8_t Sector_Addr                      : 4;
        uint8_t Page_Addr                        : 4;
        uint8_t Base_Addr                         ;
    };
}Flash_Addr_t;

//STATUS REG1
#define FLASH_BUSY_MASK                             (1 << 0u)
#define FLASH_WEL_MASK                              (1 << 1u)
#define FLASH_BP0_MASK                              (1 << 2u)
#define FLASH_BP1_MASK                              (1 << 3U)
#define FLASH_BP2_MASK                              (1 << 4U)   //BLOCK PROTECT BITS
#define FLASH_TB_MASK                               (1 << 5U)   //TOP/BOTTOM PROTECT
#define FLASH_SEC_MASK                              (1 << 6U)   //SECTOR PROTECT
#define FLASH_SRP_MASK                              (1 << 7U)   //STATUS REGISTER PROTECT

//STATUS REG 2
#define FLASH_SRL_MASK                              (1 << 0u)   //STATUS REG LOCK
#define FLASH_QUAD_EN_MASK                          (1 << 1u)
#define FLASH_LB1_MASK                              (1 << 3U)   //SECURITY REGISTER LOCK BITS
#define FLASH_LB2_MASK                              (1 << 4u)   
#define FLASH_LB3_MASK                              (1 << 5u)
#define FLASH_CMP_MASK                              (1 << 6u)   //COMPLEMENT PROTECT
#define FLASH_SUS_MASK                              (1 << 7u)   //SUSPEND STATUS


//STATUS REG3
#define FLASH_WPS_MASK                              (1 << 2U)   //WRITE PROTECT SELECTION
#define FLASH_DRV0_MASK                             (1 << 5U)
#define FLASH_DRV1_MASK                             (1 << 6U)   //OUTPUT DRIVER STRENGTH

#define FLASH_VOLATILE_BIT_MASK                     (FLASH_SRL_MASK | FLASH_LB1_MASK | FLASH_LB2_MASK | FLASH_LB3_MASK)

#define FLASH_WRITE_ENABLE							0x06
#define FLASH_WRITE_VOLATILE_STATUS_REGISTER        0x50
#define FLASH_WRITE_DISABLE						    0x04
#define FLASH_READ_STATUS_REGISTER_1				0x05
#define FLASH_READ_STATUS_REGISTER_2				0x35
#define FLASH_READ_STATUS_REGISTER_3				0x15
#define FLASH_WRITE_STATUS_REGISTER_1				0x01
#define FLASH_WRITE_STATUS_REGISTER_2				0x31
#define FLASH_WRITE_STATUS_REGISTER_3				0x11
#define FLASH_PAGE_PROGRAM							0x02
#define FLASH_QUAD_PAGE_PROGRAM					    0x32
#define FLASH_BLOCK_ERASE_64KB						0xD8
#define FLASH_BLOCK_ERASE_32KB						0x52
#define FLASH_SECTOR_ERASE_4KB						0x20
#define FLASH_CHIP_ERASE							0x60
#define FLASH_ERASE_SUSPEND						    0x75
#define FLASH_ERASE_RESUME							0x7A
#define FLASH_POWER_DOWN							0xB9
#define FLASH_HIGH_PERFORMANCE_MODE				    0xA3
#define FLASH_CONTINUOUS_READ_MODE_RESET			0xFF
#define FLASH_RELEASE_POWER_DOWN_HPM_DEVICE_ID		0xAB
#define FLASH_MANUFACTURER_DEVICE_ID				0x90
#define FLASH_READ_UNIQUE_ID						0x4B
#define FLASH_JEDEC_ID								0x9F
#define FLASH_READ_DATA							    0x03
#define FLASH_FAST_READ							    0x0B
#define FLASH_FAST_READ_DUAL_OUTPUT				    0x3B
#define FLASH_FAST_READ_DUAL_IO					    0xBB
#define FLASH_FAST_READ_QUAD_OUTPUT				    0x6B
#define FLASH_FAST_READ_QUAD_IO					    0xEB
#define FLASH_OCTAL_WORD_READ_QUAD_IO				0xE3
#define FLASH_ENABLE_RESET                          0x66
#define FLASH_RESET_Device                          0x99


#define FLASH_DUMMY_BYTE							0xFF

#define FLASH_BLOCK_INDEX                           0x10        //描述了一个Block的起始地址倍频偏移   最大7f*它
#define FLASH_SECTOR_INDEX                          0x08        //Sector的偏移量  最大F*它
#define FLASH_PAGE_INDEX                            0x04        //Page 的起始地址偏移



extern void FLASH_Read_Data(Flash_Addr_t addr, void *Rxdata, uint16_t Length);
extern uint8_t FLASH_Read_StatusReg(uint8_t stat_ins,uint8_t statMask);
extern void FLASH_Reset_device(void);
extern void FLASH_Write_StatusReg(uint8_t Reg,uint8_t RegBitMask);
extern void FLASH_Sector_Erase(Flash_Addr_t addr);
extern void FLASH_Unlock_All(void);
extern void FLASH_Chip_Erase(void);
extern void FLASH_Read_ID(uint8_t *MID, uint16_t *DID);
extern void FLASH_Write_Data(Flash_Addr_t addr, void *Data, uint16_t Length);

extern uint8_t FLASH_Read_Dataes(Flash_Addr_t StartAddr,void * DataArray, uint32_t size);
extern uint8_t FLASH_Write_Dataes(Flash_Addr_t StartAddr,void * DataArray, uint32_t size);

#endif