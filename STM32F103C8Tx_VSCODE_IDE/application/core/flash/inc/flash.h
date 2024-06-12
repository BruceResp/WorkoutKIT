#ifndef _FLASH_H_
#define _FLASH_H_

#include "stm32f10x.h"

#define FLASH_BUSY_MASK                     (1 << 0)
#define FLASH_WEL_MASK                      (1 << 1)
#define FLASH_BP0_MASK                      (1 << 2)

extern void FLASH_Read_Data(u8 addr, u8 *Rxdata, u8 Length);
extern void Flash_Read_Status(u8 Stat_reg_f);
extern void FLASH_Sector_Erase(u8 addr);
extern void FLASH_Read_ID(uint8_t *MID, uint16_t *DID);
extern void FLASH_Write_Data(u8 addr, u8 *Data, u8 Length);

#endif