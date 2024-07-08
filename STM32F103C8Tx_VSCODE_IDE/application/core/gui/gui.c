/**
 * @file gui.c
 * @author Danny (xxx@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "gui.h"
#include "guifont.h"
#include "guicon.h"
#include "system.h"
#include "math.h"
/*			内部调用		*/

#define S6X8 0
#define S8X16 1
extern Sys_Rowitem_t Sys_Rowitem;

extern uint8_t GUI_DISPLAY_BUF[8][128];
extern SystemCtrl_t SystemCtrl;

float kp = 0.80f;			//动画

/********************************I2C****************************************/

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Dispaly_ON' 
*函数功能:'显示 开启'  
*说    明:'只是开灯 关灯，并不影响GDRAM中存储的内容，可以作为功耗开关来使用' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Display_ON(void){
	Bsp_I2C_SET(0x8D);    //SET DCDC命令
	Bsp_I2C_SET(0X14);	  //DCDC ON
	Bsp_I2C_SET(0XAF);	  //DISPLAY ON
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Display_OFF' 
*函数功能:'显示 关闭' 
*说    明: '只是开灯 关灯，并不影响GDRAM中存储的内容，可以作为功耗开关来使用' 
*作    者:Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Display_OFF(void)
{
	Bsp_I2C_SET(0X8D);		//SET DCDC命令
	Bsp_I2C_SET(0X10);		//DCDC OFF
	Bsp_I2C_SET(0XAE);		//DISPLAY OFF
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Update_Screen' 
*函数功能:' ' 
*说    明: '更新单片机显存缓存矩阵到SSD1306上,如果方法中使用了GUI_DISPLAY_BUF缓存，则必须在最后调用
			这个方法来更新显示' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Update_Screen(void){
	
	for (uint32_t j = 0; j < 8; j++)
	{	
		GUI_Set_Cursor(j,0);
		Bsp_I2C_Write_Bytes(GUI_DISPLAY_BUF[0],0); // 左移7为相当于 *2^7
		
	}
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Draw_Point' 
*函数功能:'画 点' 
*参    数:'0<x<64,0<y<128' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Draw_Point(int x,int y){
	if (x>=0 && x<=127 && y>=0 &&y <= 63)
	{
		GUI_DISPLAY_BUF[y/8][x] |= 0x01 << (y%8);
	}
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_CLEAR_SCREEN' 
*函数功能:'清理 屏幕' 
*参    数:'' 
*返 回 值:'' 
*说    明: '缓存所有像素点值设为0，达到清屏的效果，' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_CLEAR_SCREEN(){
	uint8_t i,j;
	for(j=0;j<8;j++){
		//GUI_Set_Cursor(j,0);
		for(i = 0;i<=128;i++){
			GUI_DISPLAY_BUF[j][i] = 0x00;	//将显存数组数据全部清零
		}
	}
}

/*-----------------------------------------------------------------------------------------
 *函数名称：GUI_Set_Cursor
 *函数功能：设置 光标 位置
 *参    数：
 *返 回 值：
 *说    明：0 < x < 8 , 0 < Y < 128,直接操作SSD1306 和 非全尺寸指令配合使用
 *作    者：Danny
 *修改记录：
 *----------------------------------------------------------------------------------------*/
void GUI_Set_Cursor(uint8_t Y,uint8_t X){

	Bsp_I2C_SET(0xB0 | Y);
	Bsp_I2C_SET(0x10 | ((X & 0xF0) >> 4));
	Bsp_I2C_SET(0x00 | (X & 0x0F));  //低位
}

/*----------------------------------------------------------------------------------------- 
@name:'GUI_Init' 
@param ''
@brief:'初始化 GUI' 
@author Danny
*----------------------------------------------------------------------------------------*/ 
void GUI_Init(void) {
	
 	Bsp_DelayMS(200);
	/**************初始化SSD1306*****************/
	Bsp_I2C_SET(0xAE); //--turn off oled panel
	Bsp_I2C_SET(0x00); //---set low column address
	Bsp_I2C_SET(0x10); //---set high column address
	Bsp_I2C_SET(0x40 ); //--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	Bsp_I2C_SET(0x81 ); //--set contrast control register
	Bsp_I2C_SET(0xCF ); // Set SEG Output Current Brightness
	Bsp_I2C_SET(0xA1 ); //--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	Bsp_I2C_SET(0xC8 ); //Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	Bsp_I2C_SET(0xA6 ); //--set normal display
	Bsp_I2C_SET(0xA8 ); //--set multiplex ratio(1 to 64)
	Bsp_I2C_SET(0x3f ); //--1/64 duty
	Bsp_I2C_SET(0xD3 ); //-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	Bsp_I2C_SET(0x00 ); //-not offset
	Bsp_I2C_SET(0xd5 ); //--set display clock divide ratio/oscillator frequency
	Bsp_I2C_SET(0x80 ); //--set divide ratio, Set Clock as 100 Frames/Sec
	Bsp_I2C_SET(0xD9 ); //--set pre-charge period
	Bsp_I2C_SET(0xF1 ); //Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	Bsp_I2C_SET(0xDA ); //--set com pins hardware configuration
	Bsp_I2C_SET(0x12 );
	Bsp_I2C_SET(0xDB ); //--set vcomh
	Bsp_I2C_SET(0x40 ); //Set VCOM Deselect Level
	Bsp_I2C_SET(0x20 ); //-Set Page Addressing Mode (0x00/0x01/0x02)
	//OLED_WR_Byte(0x02, OLED_CMD); //
	Bsp_I2C_SET(0x00); //在这里修改位行扫描方式
	Bsp_I2C_SET(0x8D); //--set Charge Pump enable/disable
	Bsp_I2C_SET(0x14); //--set(0x10) disable
	Bsp_I2C_SET(0xA4); // Disable Entire Display On (0xa4/0xa5)
	Bsp_I2C_SET(0xA6); // Disable Inverse Display On (0xa6/a7)
	Bsp_I2C_SET(0xAF);
	
	// Bsp_I2C_SET(0xAE);	//关闭显示
	
	// Bsp_I2C_SET(OLED_CLK);	//设置显示时钟分频比/振荡器频率
	// Bsp_I2C_SET(0x1f);
	
	// Bsp_I2C_SET(0xA8);	//设置多路复用率
	// Bsp_I2C_SET(0x3F);
	
	// Bsp_I2C_SET(0xD3);	//设置显示偏移
	// Bsp_I2C_SET(0x00);

	// Bsp_I2C_SET(0x20);//设置模式
	// Bsp_I2C_SET(0x01);//设置为水平地址模式
    // Bsp_I2C_SET(0x21);//设置列地址的起始和结束的位置
    // Bsp_I2C_SET(0x00);//0
    // Bsp_I2C_SET(0x7f);//127   
    // Bsp_I2C_SET(0x22);//设置页地址的起始和结束的位置
    // Bsp_I2C_SET(0x00);//0
    // Bsp_I2C_SET(0x07);//7

	// Bsp_I2C_SET(0x40);	//设置显示开始行
	
	// Bsp_I2C_SET(0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	// Bsp_I2C_SET(0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	// Bsp_I2C_SET(0xDA);	//设置COM引脚硬件配置
	// Bsp_I2C_SET(0x12);
	
	// Bsp_I2C_SET(0x81);	//设置对比度控制
	// Bsp_I2C_SET(0xCF);

	// Bsp_I2C_SET(0xD9);	//设置预充电周期
	// Bsp_I2C_SET(0xF1);

	// Bsp_I2C_SET(0xDB);	//设置VCOMH取消选择级别
	// Bsp_I2C_SET(0x30);

	// Bsp_I2C_SET(0xA4);	//设置整个显示打开/关闭

	// Bsp_I2C_SET(0xA6);	//设置正常/倒转显示

	// Bsp_I2C_SET(0x8D);	//设置充电泵
	// Bsp_I2C_SET(0x14);

	// Bsp_I2C_SET(0xAF);	//开启显示
	// //while (!I2C_CheckEvent(GUI_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	Bsp_I2C_DMA_Init();
	//GUI_CLEAR_SCREEN();				//复位OLED
	//GUI_Update_Screen();				//更新显示，清屏，防止初始化后未显示内容时花屏
}

/*               外部调用               */
/*-----------------------------------------------------------------------------------------
 *函数名称：GUI_Show_Char
 *函数功能：显示 ASCII 字符
 *参    数：
 *返 回 值：
 *说    明：
 *作    者：Danny
 *修改记录：
 *----------------------------------------------------------------------------------------*/
void GUI_Show_Char(uint8_t Line,uint8_t Column,char Char){
	
	GUI_Set_Cursor((Line - 1) * 2, (Column - 1) * 8+1);
	Bsp_I2C_Write_Bytes(&OLED_F8x16[Char - ' '][0],8);
	
	GUI_Set_Cursor((Line - 1) * 2+1, (Column - 1) * 8);
	Bsp_I2C_Write_Bytes(&OLED_F8x16[Char - ' '][8],8);
	
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Show_String' 
*函数功能:'显示 字符' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Show_String(uint8_t Line,uint8_t Column,char *string){
	while ((*string) != '\0')
	{
		GUI_Show_Char(Line,Column++,*string);
		string++;
	}	
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_ShowChar_FulCoord' 
*函数功能:'' 
*参    数:'Line 在0-64范围之内，Column 在0-128之内，Char必须在OLED_F8x16内' 
*返 回 值:'' 
*说    明:'' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_ShowChar_FulCoord(uint8_t Line, uint8_t Column,char Char){
	u8 shift = Line / 8;
	u8 shift_1 = shift +1 ;
	u8 shift_2 = shift +2 ;
	u8 Index = Line%8 ;
	for (uint8_t i = 0; i < 8; i++)
	{
		GUI_DISPLAY_BUF[shift][Column+i] |= OLED_F8x16[Char - ' '][i]<<Index;
		GUI_DISPLAY_BUF[shift_1][Column+i] |= OLED_F8x16[Char - ' '][i]>>(8-Index);
	
		GUI_DISPLAY_BUF[shift_1][Column+i] |= OLED_F8x16[Char - ' '][8+i]<<Index;
		GUI_DISPLAY_BUF[shift_2][Column+i] |= OLED_F8x16[Char - ' '][8+i]>>(8-Index);
	}
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_ShowString_FulCoord' 
*函数功能:'显示 字符' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_ShowString_FulCoord(uint8_t Line,uint8_t Column,char *string){
	while ((*string) != '\0')
	{
		GUI_ShowChar_FulCoord(Line,Column,*string);
		Column+=8;
		string++;
	}
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'' 
*函数功能:'' 
*参    数:'0 < x <64 , 0 < y < 128  
			Height: 输出图像高度 单位 像素' 
			Width: 输出图像宽度 单位 像素
			Image: 图像单位列的值集合的最开始部分 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Show_Image(int16_t X, int16_t Y,uint8_t Height,uint8_t Width, const uint8_t *Image){
	uint8_t	across_line = (Height-1) / 8 + 1 ; 			//先看占几行
	int16_t Page, shift;
	for (uint8_t j = 0; j < across_line; j++)
	{	
		for (uint8_t i = 0; i < Width ; i++)
		{	
			if ((X + i) > 127 || (X + i) < 0)
			{
				continue;
			}
			shift = Y % 8;
			Page = Y / 8;

			if (Y < 0)   // Y<-8 的情况可以保证 Page+j<0(j ==0 ) 但是 -8<Y<0的情况会进去像素赋值，而j<0导致i+width出现不准确的情况，我们只需要需要的部分就好了
			{
				Page -= 1;
				shift += 8;
			}
			if ((Page + j) >= 0 && (Page + j) < 8)
			{
				GUI_DISPLAY_BUF[Page + j][X + i] |= Image[i + Width*j] << (shift);
			}
			if ((Page + j + 1) >= 0 && (Page + j + 1) < 8)
			{
				GUI_DISPLAY_BUF[Page + j + 1][X + i] |= Image[i + Width*j] >> (8-(shift));
			}
		}
	}

}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Reverse_Y' 
*函数功能:'反转 行' 
*参    数:'y:要反转的y轴坐标 0<y<64 height：反转行的高度' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Reverse_Y(uint8_t y,uint8_t height){
	u8 across_page = y + height;
	for (uint8_t j = y; j < across_page; j++)
	{
		u8 Page = j / 8;
		u8 shift = j % 8;
		for (uint8_t i = 0; i < 128; i++)
		{
			GUI_DISPLAY_BUF[Page][i] ^= 0x01 << shift; //对行取反
		}
	}

}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Show_Chinese' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: 'Chinese 指定要显示的汉字串，范围：必须全部为汉字或者全角字符，不要加入任何半角字符
*           显示的汉字需要在OLED_Data.c里的OLED_CF16x16数组定义
*           未找到指定汉字时，会显示默认图形（一个方框，内部一个问号）' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Show_Chinese(uint8_t Line, uint8_t Column,char *Chinese){
	
	// char Ch_char;
	// for (uint8_t i = 0; *Chinese !='\n'; i++)
	// {
		// Ch_char = *Chinese;
		// for (uint8_t j = 0; (OLED_Test[j].Index != "空") && (*Chinese !='\n'); j++)
		// {
		// 	if (OLED_Test[j].Index == *Chinese)
		// 	{
		// 		/* code 打印*/
		// 		Chinese++;
		// 	}
				
		// }
		// if (*Chinese =='\n')
		// {
		// 	/* code */
		// }else
		// {
		// 	/* code */
		// }
		
		
		
	// }
	
}

void GUI_Draw_Line(int X1, int Y1,int X2, int Y2){
	u8 flag = 0 ;
	if (Y2-Y1 > X2 - X1)
	{
		int temp;
		temp = Y1 ; Y1 = X1; X1 = temp;
		temp = Y2 ; Y2 = X2; X2 = temp;
		flag = 1;
	}
	else if (Y2 - Y1 < 0)
	{
		Y1 = -Y1; Y2 = -Y2;
		if (Y2-Y1 > X2 - X1)
		{
			int temp;
			temp = Y1 ; Y1 = X1; X1 = temp;  //根据象限来变化而不是 坐标点（x1，y1）
			temp = Y2 ; Y2 = X2; X2 = temp;
			flag = 3;
		}
		else{
			flag = 2;
		}
	}

	int dx = X2 - X1,dy = Y2 -Y1;	//
	int base_part = 2 * dy - dx;
	int inc = 2 * dy;
	int inc_dbl = 2 * (dy -dx);
	
	int y = Y1;
	switch (flag)
	{
	case 1:GUI_Draw_Point(Y1,X1);break;
	case 2:GUI_Draw_Point(X1,-Y1);break;
	case 3:GUI_Draw_Point(Y1,-X1);break;
	default:GUI_Draw_Point(X1,Y1);
		break;
	}
	//GUI_Draw_Point(X1,Y1);

	for (int x = X1+1; x < X2; x++)
	{
		if (base_part < 0)
		{
			base_part += inc;
		}else{
			base_part += inc_dbl;
			y += 1;
		}
		switch (flag)
		{
		case 1:GUI_Draw_Point(y,x);break;
		case 2:GUI_Draw_Point(x,-y);break;
		case 3:GUI_Draw_Point(y,-x);break;
		default:GUI_Draw_Point(x,y);
			break;
		}		
	}
	
}


/********************************I2C****************************************/

/********************************SPI****************************************/

// /*******************************************************************
//  * @name       :void OLED_Reset(void)
//  * @date       :2022-06-22
//  * @function   :重置OLED屏幕显示
//  * @parameters :dat:0-显示全黑
//                     1-显示全白
//  * @retvalue   :无
// ********************************************************************/ 
// void GUI_Reset(void)
// {
// 	GPIO_SetBits(GUI_RST_PORT,GUI_RST_PIN);
// 	Bsp_DelayMS(100);
// 	GPIO_ResetBits(GUI_RST_PORT,GUI_RST_PIN);
// 	Bsp_DelayMS(100);
// 	GPIO_SetBits(GUI_RST_PORT,GUI_RST_PIN);
// }

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_SPI_Init' 
*函数功能:'GUI SPI 初始化' 
*说    明: '发送指令初始化ssd1306' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_SPI_Init(void)
{
	Bsp_DelayMS(1000); //1000

	Bsp_SPI_RES_LOW();
	Bsp_DelayMS(100);  //100
	Bsp_SPI_RES_HIGH();
	Bsp_SPI_Send_CMD(0xae);//关闭显示
	Bsp_SPI_Send_CMD(0xd5);//设置时钟分频因子,震荡频率
	Bsp_SPI_Send_CMD(0xf0);//[3:0],分频因子;[7:4],震荡频率
	
	Bsp_SPI_Send_CMD(0xd9);//设置时钟分频因子,震荡频率
	Bsp_SPI_Send_CMD(0x11);//[3:0],分频因子;[7:4],震荡频率

	Bsp_SPI_Send_CMD(0x81);//设置对比度
	Bsp_SPI_Send_CMD(0x7f);//128
	Bsp_SPI_Send_CMD(0x8d);//设置电荷泵开关
	Bsp_SPI_Send_CMD(0x14);//开

	Bsp_SPI_Send_CMD(0x20);//设置模式
	Bsp_SPI_Send_CMD(0x00);//设置为水平地址模式
    Bsp_SPI_Send_CMD(0x21);//设置列地址的起始和结束的位置
    Bsp_SPI_Send_CMD(0x00);//0
    Bsp_SPI_Send_CMD(0x7f);//127   
    Bsp_SPI_Send_CMD(0x22);//设置页地址的起始和结束的位置
    Bsp_SPI_Send_CMD(0x00);//0
    Bsp_SPI_Send_CMD(0x07);//7
	Bsp_SPI_Send_CMD(0xc9);//0xc9上下反置 0xc8正常
    Bsp_SPI_Send_CMD(0xa1);//0xa0左右反置 0xa1正常
	
	Bsp_SPI_Send_CMD(0xa4);//全局显示开启;0xa4正常,0xa5无视命令点亮全屏
	Bsp_SPI_Send_CMD(0xa6);//设置显示方式;bit0:1,反相显示;0,正常显示	
	Bsp_SPI_Send_CMD(0xaf);//开启显示

   Bsp_SPI_Send_CMD(0x56);
   Bsp_DelayMS(100);
   Bsp_SPI_DMA_Init();//DMA初始化
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Display_Char_ASCII' 
*函数功能:'GUI 显示 字符 ASCII格式' 
*参    数:''  
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_SPI_Display_Char_ASCII(u8 Y,u8 X,char ascii,u8 size)
{
	u8 i=0,j=0,c=ascii;
	if (size==S6X8)
	{
		for (i=0;i<6;i++)
		{
			GUI_DISPLAY_BUF[Y][X+i]=F6X8[(c-32)*6+1+i];
		}
	}
	else if(size==S8X16)
	{
		for (j=0;j<2;j++)
		{
			for (i=0;i<8;i++)
			{
				GUI_DISPLAY_BUF[Y+j][X+i]=OLED_F8x16[(c-32)*8+1+i][j*8];
			}
		}
	}


}

/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_SPI_Display_Graph' 
*函数功能:'' 
*参    数:'0 < x <64 , 0 < y < 128  
			Height: 输出图像高度 单位 像素' 
			Width: 输出图像宽度 单位 像素
			Graph: 图像单位列的值集合的最开始部分 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_SPI_Display_Graph(int16_t X,int16_t Y,u8 height,u8 width,const u8 *Graph){
	// u8 across = ( height-1 ) / 8 + 1;		//得出占据行的最大可能值
	// u8 page = Y/8 ;
	// u8 shift = Y%8;
	// for (u8 j = 0; j < across; j++)
	// {
	// 	for (u8 i = 0; i < width; i++)
	// 	{
	// 		if ((X + i) > 127 && (X + i) < 0)
	// 		{
	// 			continue;
	// 		}
	// 		if (Y < 0 )
	// 		{
	// 			page -=1;
	// 			shift +=8;
	// 		}
	// 		if ((page + j) >= 0 && (page + j) < 8)
	// 		{
	// 			GUI_DISPLAY_BUF[page+j][X+i] |= Graph[i+width*j] << shift;
	// 		}
	// 		if ((page + j + 1) >= 0 && (page + j + 1) < 8)
	// 		{
	// 			GUI_DISPLAY_BUF[page+j+1][X+i] |= Graph[i+width*j] >>(8 - shift) ;
	// 		}
	// 	}
	// }

	uint8_t i = 0, j = 0;
	int16_t Page, Shift;
	
	/*将图像所在区域清空*/
	//OLED_ClearArea(X, Y, Width, Height);
	
	/*遍历指定图像涉及的相关页*/
	/*(Height - 1) / 8 + 1的目的是Height / 8并向上取整*/
	for (j = 0; j < (height - 1) / 8 + 1; j ++)
	{
		/*遍历指定图像涉及的相关列*/
		for (i = 0; i < width; i ++)
		{
			if (X + i >= 0 && X + i <= 127)		//超出屏幕的内容不显示
			{
				/*负数坐标在计算页地址和移位时需要加一个偏移*/
				Page = Y / 8;
				Shift = Y % 8;
				if (Y < 0)
				{
					Page -= 1;
					Shift += 8;
				}
				
				if (Page + j >= 0 && Page + j <= 7)		//超出屏幕的内容不显示
				{
					/*显示图像在当前页的内容*/
					GUI_DISPLAY_BUF[Page + j][X + i] |= Graph[j * width + i] << (Shift);
				}
				
				if (Page + j + 1 >= 0 && Page + j + 1 <= 7)		//超出屏幕的内容不显示
				{					
					/*显示图像在下一页的内容*/
					GUI_DISPLAY_BUF[Page + j + 1][X + i] |= Graph[j * width + i] >> (8 - Shift);
				}
			}
		}
	}
}

void GUI_SPI_Reverse_Y(uint8_t y,uint8_t height){

	for (uint8_t j = y; j < y+height; j++)
	{
		for (uint8_t i = 0; i < 128; i++)
		{
			GUI_DISPLAY_BUF[j / 8][i] ^= 0x01 << (j % 8); //对行取反
		}
	}
}


/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_SPI_CLEAR_SCREEN' 
*函数功能:'清理 屏幕' 
*参    数:'' 
*返 回 值:'' 
*说    明: '缓存所有像素点值设为0，达到清屏的效果，' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_SPI_CLEAR_SCREEN(){
	uint8_t i,j;
	for(j=0;j<8;j++){
		//GUI_Set_Cursor(j,0);
		for(i = 0;i<=128;i++){
			GUI_DISPLAY_BUF[j][i] = 0x00;	//将显存数组数据全部清零
		}
	}
}

void GUI_Test(void){
	
	//Bsp_DelayS(5);
	//GUI_Show_Image(0,10,44,44,train_Icon);
	GUI_SPI_Display_Graph(44,10,44,44,config_Icon);
	//GUI_Show_Image(88,10,44,44,Set_Icon);

	GUI_Show_Image(0,0,16,16,OLED_Test[0].CellMatrix);
		GUI_Show_Image(0,0+16,16,16,OLED_Test[1].CellMatrix);
		GUI_Show_Image(0,0+32,16,16,OLED_Test[2].CellMatrix);
		GUI_Show_Image(0,0+48,16,16,OLED_Test[3].CellMatrix);
		
	//GUI_SPI_Display_Graph(5,5,16,16,OLED_Test[0].CellMatrix);
	//GUI_Display_OFF();
	//Bsp_DelayS(5);
	//GUI_Display_ON();
}
/*----------------------------------------------------------------------------------------- 
*函数名称:'GUI_Show_Frame' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Show_Frame(void){
	
	GUI_CLEAR_SCREEN();
	
	GUI_Show_Image(Sys_MainPage.right_icon.current_x,Sys_MainPage.right_icon.current_y,44,44,Set_Icon);
	
	GUI_Show_Image(Sys_MainPage.mid_icon.current_x,Sys_MainPage.mid_icon.current_y,44,44,train_Icon);
	
	GUI_Show_Image(Sys_MainPage.left_icon.current_x,Sys_MainPage.left_icon.current_y,44,44,config_Icon);
	

}

float GUI_easeOutCubic(float time,float timeScale){
	time = (time / timeScale) - 1;
	return powf(time,3);
}


void GUI_Animation_move2(void){
	static uint32_t tick = 0 ;
	if (round(Sys_MainPage.mid_icon.current_x) != round(Sys_MainPage.mid_icon.target_x) )
	{
		tick++;
		GUI_CLEAR_SCREEN();
		// midicon = (Sys_MainPage.mid_icon.target_x-Sys_MainPage.mid_icon.current_x);			//为什么这样的就会出现撕裂，乘到下面就没有事
		// lefticon = (Sys_MainPage.left_icon.target_x-Sys_MainPage.left_icon.current_x);
		// righticon = (Sys_MainPage.right_icon.target_x-Sys_MainPage.right_icon.current_x);
	}else{
		tick = 0;
	}
	Sys_MainPage.mid_icon.current_x = Sys_MainPage.mid_icon.current_x + (Sys_MainPage.mid_icon.target_x-Sys_MainPage.mid_icon.current_x)*(GUI_easeOutCubic(tick,100)+1);
	Sys_MainPage.left_icon.current_x = Sys_MainPage.left_icon.current_x + (Sys_MainPage.left_icon.target_x-Sys_MainPage.left_icon.current_x)*(GUI_easeOutCubic(tick,100)+1);
	Sys_MainPage.right_icon.current_x = Sys_MainPage.right_icon.current_x + (Sys_MainPage.right_icon.target_x-Sys_MainPage.right_icon.current_x)*(GUI_easeOutCubic(tick,100)+1);
	
	// Sys_MainPage.mid_icon.current_y = kp*Sys_MainPage.mid_font.current_y + (1-kp)*Sys_MainPage.mid_icon.target_y;
	// Sys_MainPage.left_icon.current_y = kp*Sys_MainPage.left_icon.current_y + (1-kp)*Sys_MainPage.left_icon.target_y;
	// Sys_MainPage.right_icon.current_y = kp*Sys_MainPage.right_icon.current_y + (1-kp)*Sys_MainPage.right_icon.target_y;

	Sys_MainPage.mid_icon.current_y = Sys_MainPage.mid_icon.target_y;
	Sys_MainPage.left_icon.current_y = Sys_MainPage.left_icon.target_y;
	Sys_MainPage.right_icon.current_y = Sys_MainPage.right_icon.target_y;
	// GUI_Show_Frame();

	GUI_Show_Image(Sys_MainPage.right_icon.current_x,Sys_MainPage.right_icon.current_y,44,44,Set_Icon);
	GUI_Show_Image(Sys_MainPage.mid_icon.current_x,Sys_MainPage.mid_icon.current_y,44,44,train_Icon);
	GUI_Show_Image(Sys_MainPage.left_icon.current_x,Sys_MainPage.left_icon.current_y,44,44,config_Icon);
	
	return;
}

void GUI_Animation_move(void){
	
	if (SystemCtrl.currentPage == SYSTEM_MAIN_PAGE )
	{
		Sys_MainPage.mid_icon.current_x = kp*Sys_MainPage.mid_icon.current_x + (1-kp)*(Sys_MainPage.mid_icon.target_x);
		Sys_MainPage.left_icon.current_x = kp*Sys_MainPage.left_icon.current_x + (1-kp)*(Sys_MainPage.left_icon.target_x);
		Sys_MainPage.right_icon.current_x = kp*Sys_MainPage.right_icon.current_x + (1-kp)*(Sys_MainPage.right_icon.target_x);

		// Sys_MainPage.mid_icon.current_y = kp*Sys_MainPage.mid_font.current_y + (1-kp)*Sys_MainPage.mid_icon.target_y;
		// Sys_MainPage.left_icon.current_y = kp*Sys_MainPage.left_icon.current_y + (1-kp)*Sys_MainPage.left_icon.target_y;
		// Sys_MainPage.right_icon.current_y = kp*Sys_MainPage.right_icon.current_y + (1-kp)*Sys_MainPage.right_icon.target_y;

		Sys_MainPage.mid_icon.current_y = Sys_MainPage.mid_icon.target_y;
		Sys_MainPage.left_icon.current_y = Sys_MainPage.left_icon.target_y;
		Sys_MainPage.right_icon.current_y = Sys_MainPage.right_icon.target_y;
		// GUI_Show_Frame();
		if (round(Sys_MainPage.right_icon.current_x) != round(Sys_MainPage.right_icon.target_x) )
		{
			GUI_CLEAR_SCREEN();
		}

		GUI_Show_Image(Sys_MainPage.right_icon.current_x,Sys_MainPage.right_icon.current_y,44,44,Set_Icon);
		GUI_Show_Image(Sys_MainPage.mid_icon.current_x,Sys_MainPage.mid_icon.current_y,44,44,train_Icon);
		GUI_Show_Image(Sys_MainPage.left_icon.current_x,Sys_MainPage.left_icon.current_y,44,44,config_Icon);
		
		//Bsp_DelayMS(2);
		return;
	}
	if (SystemCtrl.currentPage == SYSTEM_TRAIN_MENU_SELECET_PAGE)
	{
		
		SystemCtrl.Sys_InverseBox.current_y =kp*SystemCtrl.Sys_InverseBox.current_y + (1-kp)*(SystemCtrl.Sys_InverseBox.target_y);
        Sys_Rowitem.current_y = kp*Sys_Rowitem.current_y + (1-kp)*(Sys_Rowitem.target_y);
		
		// SystemCtrl.Sys_InverseBox.current_y = Sys_MainPage.left_icon.target_y;
		// Sys_MainPage.right_icon.current_y = Sys_MainPage.right_icon.target_y;
		if ((round(Sys_Rowitem.current_y) != Sys_Rowitem.target_y) || (round(SystemCtrl.Sys_InverseBox.current_y) != round(SystemCtrl.Sys_InverseBox.target_y)))
		{
			GUI_CLEAR_SCREEN();
		}
		
		if ((round(Sys_Rowitem.current_y) != Sys_Rowitem.target_y) || (round(SystemCtrl.Sys_InverseBox.current_y) != round(SystemCtrl.Sys_InverseBox.target_y)))
		{
			GUI_Show_Image(0,Sys_Rowitem.current_y,16,16,OLED_Test[0].CellMatrix);
			GUI_Show_Image(0,Sys_Rowitem.current_y+16,16,16,OLED_Test[1].CellMatrix);
			GUI_Show_Image(0,Sys_Rowitem.current_y+32,16,16,OLED_Test[2].CellMatrix);
			GUI_Show_Image(0,Sys_Rowitem.current_y+48,16,16,OLED_Test[3].CellMatrix);
		
			GUI_Reverse_Y(SystemCtrl.Sys_InverseBox.current_y,16);
		}	
	}
/* 
	// if (System_Status_Read() == SYSTEM_TARIN_MENU_SELECET_PAGE)	//菜单选择界面动画
	// {
	// 	Sys_MainPage.mid_icon.current_x = kp*Sys_MainPage.mid_icon.current_x + (1-kp)*(Sys_MainPage.mid_icon.target_x);
	// 	Sys_MainPage.left_icon.current_x = kp*Sys_MainPage.left_icon.current_x + (1-kp)*(Sys_MainPage.left_icon.target_x);
	// 	Sys_MainPage.right_icon.current_x = kp*Sys_MainPage.right_icon.current_x + (1-kp)*(Sys_MainPage.right_icon.target_x);

	// 	// Sys_MainPage.mid_icon.current_y = kp*Sys_MainPage.mid_font.current_y + (1-kp)*Sys_MainPage.mid_icon.target_y;
	// 	// Sys_MainPage.left_icon.current_y = kp*Sys_MainPage.left_icon.current_y + (1-kp)*Sys_MainPage.left_icon.target_y;
	// 	// Sys_MainPage.right_icon.current_y = kp*Sys_MainPage.right_icon.current_y + (1-kp)*Sys_MainPage.right_icon.target_y;

	// 	Sys_MainPage.mid_icon.current_y = Sys_MainPage.mid_icon.target_y;
	// 	Sys_MainPage.left_icon.current_y = Sys_MainPage.left_icon.target_y;
	// 	Sys_MainPage.right_icon.current_y = Sys_MainPage.right_icon.target_y;
	// 	// GUI_Show_Frame();
	// 	if (Sys_MainPage.right_icon.current_x != Sys_MainPage.right_icon.target_x )
	// 	{
	// 		GUI_CLEAR_SCREEN();
	// 	}

	// 	GUI_Show_Image(Sys_MainPage.right_icon.current_x,Sys_MainPage.right_icon.current_y,44,44,Set_Icon);
	// 	GUI_Show_Image(Sys_MainPage.mid_icon.current_x,Sys_MainPage.mid_icon.current_y,44,44,train_Icon);
	// 	GUI_Show_Image(Sys_MainPage.left_icon.current_x,Sys_MainPage.left_icon.current_y,44,44,config_Icon);
		
	// 	Bsp_DelayMS(2);
	// 	return;
	// }
	 */
}

/*----------------------------------------------------------------------------------------- 
*函数名称:'' 
*函数功能:'' 
*参    数:'' 
*返 回 值:'' 
*说    明: '每次按键按完才能调用一次，不能频繁调用' 
*作    者: Danny 
*----------------------------------------------------------------------------------------*/ 
void GUI_Shift_Menu(uint8_t currentPage,uint8_t targetPage){
	u8 base_x = 42,	Delta_x = 44;
	u8 base_y = 18; //Delta_y = 7
	if (currentPage == SYSTEM_MAIN_PAGE)//处于ready状态
	{
		switch (targetPage)
		{
			case SYSTEM_MAIN_PAGE:;
			case SYSTEM_TRAIN_MENU_SELECET_PAGE:
				Sys_MainPage.mid_icon.target_x =  base_x;
				Sys_MainPage.left_icon.target_x = base_x - Delta_x ;
				Sys_MainPage.right_icon.target_x = base_x + Delta_x ;

				Sys_MainPage.mid_icon.target_y = base_y; 
				Sys_MainPage.left_icon.target_y = base_y ;
				Sys_MainPage.right_icon.target_y = base_y ;
				break;
			case SYSTEM_EDIT_MENU_SELECT_PAGE:
				Sys_MainPage.mid_icon.target_x =  base_x + Delta_x;
				Sys_MainPage.left_icon.target_x = base_x - Delta_x + Delta_x;
				Sys_MainPage.right_icon.target_x = base_x + Delta_x + Delta_x;

				Sys_MainPage.mid_icon.target_y = base_y; 
				Sys_MainPage.left_icon.target_y = base_y ;
				Sys_MainPage.right_icon.target_y = base_y ;break;
			case SYSTEM_CONFIG_PAGE:
				Sys_MainPage.mid_icon.target_x =  base_x - Delta_x;
				Sys_MainPage.left_icon.target_x = base_x - Delta_x - Delta_x ;
				Sys_MainPage.right_icon.target_x = base_x + Delta_x - Delta_x;

				Sys_MainPage.mid_icon.target_y = base_y; 
				Sys_MainPage.left_icon.target_y = base_y ;
				Sys_MainPage.right_icon.target_y = base_y ;break;
			default:
				break;
		}
	}else if (currentPage == SYSTEM_TRAIN_MENU_SELECET_PAGE)
	{
		switch (targetPage)
		{
			case SYSTEM_TRAIN_MENU_SELECET_PAGE:
			case SYSTEM_START_TRAIN_PAGE:
				SystemCtrl.Sys_InverseBox.target_y = SystemCtrl.GUIpagePoint *16;
				break;
		}
	}else if (currentPage == SYSTEM_EDIT_MENU_SELECT_PAGE)
	{
		switch (targetPage)
		{
			case SYSTEM_EDIT_MOVES_SELECT_PAGE:
				/* code */
				break;
			
			default:
				break;
		}
	}
	
	
	// else if(currentPage == SYSTEM_TRAIN_MENU_SELECET_PAGE){
	// 	switch (targetPage)
	// 	{
	// 		// case SYSTEM_MAIN_PAGE_TARIN_MENU_SELECET_ALREADY:
	// 		// 	Sys_MainPage.mid_icon.target_x =  base_x + Delta_x;
	// 		// 	Sys_MainPage.left_icon.target_x = base_x - Delta_x -Delta_x;
	// 		// 	Sys_MainPage.right_icon.target_x = base_x + Delta_x +Delta_x;

	// 		// 	Sys_MainPage.mid_icon.target_y = base_y + Delta_y; 
	// 		// 	// Sys_MainPage.left_icon.target_y = base_y ;
	// 		// 	// Sys_MainPage.right_icon.target_y = base_y ;
	// 		// 	break;
	// 		// case SYSTEM_MAIN_PAGE_EDIT_TRAIN_MENU_ALREADY:
	// 		// 	break;
	// 		// case SYSTEM_MAIN_PAGE_CONFIG_ALREADY:
	// 		// 	break;
	// 		default:
	// 		break;
	// 	}	
	
}