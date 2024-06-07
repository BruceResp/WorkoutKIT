#include "main.h"
#include "gui.h"
#include "key.h"
#include "unity.h"

// void setUp(void) { }    统一放到uint_test文件夹
// void tearDown(void) { }
// int add(int a,int b){
// 	return a + b;
// }
// void testZeroAdd(void){
// 	int temp;
// 	temp = add(1,1);
// 	TEST_ASSERT_EQUAL(2,temp);
// }

int main(void)
{
	
	// UNITY_BEGIN();
	// RUN_TEST(testZeroAdd);
	// UNITY_END();  //在方法里才需要加 return
  	Bsp_Init();
	//GUI_Init();
 	GUI_SPI_Init(); //初始化函数

	//GUI_Show_Image(1,1);
	// GUI_Draw_Point(3,3);
	// GUI_Draw_Point(10,8);
	// GUI_Draw_Point(50,15);
	//GUI_Show_Char_SPI(5,5,'A');
	// uint8_t y = 0;
	// u8 page_Y = 50;
	//GUI_Test();
	while (1)
	{
		//GUI_CLEAR_SCREEN();
		Key_Process();
		//Bsp_DelayS(10);
	// OLED_Write(2,1,"B",0);
	// OLED_Write(3,50,"C",0);
	// 	Bsp_DelayMS(5000);
	// 	GUI_Show_String(1,1,a);
		
		// for (uint8_t i = 0; i < 63; i++)
		// {
			//GUI_ShowString_FulCoord(i,i,"abcd");
		 	// GUI_SPI_Display_Char_ASCII(5,1,"D",0);
			// GUI_SPI_Display_Char_ASCII(3,50,"B",0);
			// GUI_Test();
			// GUI_SPI_Reverse_Y(i,10);
			// Bsp_DelayMS(1000);
			// GUI_SPI_CLEAR_SCREEN();
			
			//GUI_ShowString_FulCoord(i,i,"abcd");
			//GUI_Draw_Line(-2,-10,110,50);
			//GUI_Draw_Line(2,50,110,50);
			//OLED_DrawLine(-2,5,50,9);
		 	//GUI_SPI_CLEAR_SCREEN();
			//Bsp_DelayMS(10);
			
	// }	
		
	}
}

