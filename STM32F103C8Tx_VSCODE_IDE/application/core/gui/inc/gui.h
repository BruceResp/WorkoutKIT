#ifndef _GUI_H_
#define _GUI_H_

#define GUI_CMD_MODE        0x80  //命令模式

#include "bsp.h"



void GUI_Display_ON(void);
void GUI_Display_OFF(void);

extern void GUI_Set_Cursor(uint8_t Y,uint8_t X);
extern void GUI_CLEAR_SCREEN(void);
extern void GUI_Update_Screen(void);

extern void GUI_Init(void);
extern void GUI_Show_Char(uint8_t Line,uint8_t Column,char Char);
extern void GUI_Show_String(uint8_t Line,uint8_t Column,char *string);

extern void GUI_ShowChar_FulCoord(uint8_t Line, uint8_t Column,char Char);
extern void GUI_ShowString_FulCoord(uint8_t Line,uint8_t Column,char *string);

extern void GUI_Draw_Point(int x,int y);
extern void GUI_Draw_Line(int X1, int Y1,int X2, int Y2);
extern void GUI_Show_Image(int16_t x, int16_t y,uint8_t Height,uint8_t Width, const uint8_t *image);
extern void GUI_Reverse_Y(uint8_t y,uint8_t height);
extern void GUI_Test(void);

// extern void GUI_Reset(void);
extern void GUI_SPI_Init(void);
extern void GUI_SPI_Display_Char_ASCII(u8 ye,u8 lie,char* ascii,u8 size);
extern void GUI_SPI_Display_Graph(int16_t X,int16_t Y,u8 height,u8 width,const u8 *Graph);
extern void GUI_SPI_Reverse_Y(uint8_t y,uint8_t height);
extern void GUI_SPI_CLEAR_SCREEN(void);
#endif