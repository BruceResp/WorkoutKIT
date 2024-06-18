#include "main.h"
#include "gui.h"
#include "key.h"
#include "unity.h"
#include "flash.h"
#include "system.h"

// 全部完成后的优化目标 1 flash访问使用qual 的方式 加快访问速度

uint8_t MID;
uint16_t DID;
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
 	GUI_SPI_Init(); //初始化测试下来要4s钟有点长
	System_Init();
	
	// for (int64_t i = 0; i < 10000; i++)
	// {
	// 	GUI_Test();
	// 	GUI_CLEAR_SCREEN();
	// }
	u32 i =0,sum=0;
	while (1)
	{	
		GUI_Test();
		i++;
		u32 j = 10;
		u8 a = 1;
		while (i%j != i)//先确定最大值
		{
			j *= 10;
		}
		sum = i;
		while (j >=10)
		{
			a += 8;
			j /= 10;
			GUI_SPI_Display_Char_ASCII(0,80+a,sum/j+48,0);
			sum = sum%j;//去掉最高位
		}
		//GUI_SPI_Display_Char_ASCII(1,2,12,0);
		// GUI_SPI_Display_Char_ASCII(1,7,'9',0);
		// GUI_SPI_Display_Char_ASCII(1,7,'8',0);


		//GUI_Test();
		
		// Key_Process();
		// System_Poll();
		
	}
}

void SysTick_handler(void){

}

