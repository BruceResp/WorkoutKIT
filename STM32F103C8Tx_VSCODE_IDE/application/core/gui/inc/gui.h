#ifndef _GUI_H_
#define _GUI_H_

#define GUI_CMD_MODE        0x80  //命令模式

#include "bsp.h"


typedef struct
{
    float current_x; //描述当前的横纵坐标
    float current_y; 

    float target_x; //描述目标的横纵坐标
    float target_y; 
}GUI_Base_Obj_t;    //主界面显示的字的属性

typedef struct
{
    //GUI_Base_Obj_t font;
    GUI_Base_Obj_t left_icon;
    GUI_Base_Obj_t mid_icon;
    GUI_Base_Obj_t right_icon;
    
    GUI_Base_Obj_t left_font;
    GUI_Base_Obj_t mid_font;
    GUI_Base_Obj_t right_font;
}GUI_MainPage_t;


typedef struct 
{
    GUI_Base_Obj_t chosen_obj;
    GUI_Base_Obj_t datalist_crood;
}GUI_TrainMenuSelectPage_t;     //可以作为一个模板 动态生成？




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
extern void GUI_SPI_Display_Char_ASCII(u8 ye,u8 lie,char ascii,u8 size);
extern void GUI_SPI_Display_Graph(int16_t X,int16_t Y,u8 height,u8 width,const u8 *Graph);
extern void GUI_SPI_Reverse_Y(uint8_t y,uint8_t height);
extern void GUI_SPI_CLEAR_SCREEN(void);

extern void GUI_MenuselectPage_Init(void);
extern void GUI_List_shift(uint8_t shiftup);
extern void GUI_Animation_move(uint8_t currentpage);
extern void GUI_Animation_move2(void);
extern void GUI_Shift_Menu(uint8_t currentPage,uint8_t targetPage);

#endif