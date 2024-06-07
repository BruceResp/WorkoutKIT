#ifndef _NODE_WK1000_
#define _NODE_WK1000_



/*------------------FUNCTION DEFINE AREAR-------------------------------*/
#define GUI_SPI_MODE_SUPPORT 

//#define GUI_I2C_MODE_SUPPORT
// #define GUI_I2C_MODE_SUPPORT
/*------------------PORT / PIN DEFINE AREAR-------------------------------*/
/*                  SPI                 */
#define GUI_SPI              SPI1

// #define GUI_RST_PIN         GPIO_Pin_2
#define GUI_RST_PIN         GPIO_Pin_4
#define GUI_RST_PORT        GPIOA

// #define GUI_DC_PIN          GPIO_Pin_3
#define GUI_DC_PIN          GPIO_Pin_6
#define GUI_DC_PORT         GPIOA

// #define GUI_NSS_PIN          GPIO_Pin_3
// #define GUI_NSS_PORT         GPIOA

#define GUI_SCK_PIN          GPIO_Pin_5
#define GUI_SCK_PORT         GPIOA

// #define GUI_MISO_PIN         GPIO_Pin_6
// #define GUI_MISO_PORT        GPIOA

#define GUI_MOSI_PIN         GPIO_Pin_7
#define GUI_MOSI_PORT        GPIOA


/*                 i2c                      */
#define GUI_I2C             I2C1

#define GUI_SCL_PIN         GPIO_Pin_6
#define GUI_SCL_PORT        GPIOB

#define GUI_SDA_PIN         GPIO_Pin_7
#define GUI_SCL_PORT        GPIOB

#define OLED_ADDRESS      		((uint8_t)0x78)       /* oled 的设备地址 */
#define OLED_CLK                ((uint8_t)0xD5)       /* oled 的时钟频率指令 */

#define OLED_SSD1306_SEND_CMD        ((uint8_t)0x00)
#define OLED_SSD1306_SEND_DATA        ((uint8_t)0x40)

/**********************KEYS RESOURCES******************************/
#define KEY_Marix               

#define KEY_UP_PIN                   GPIO_Pin_8
#define KEY_UP_PORT                  GPIOA

#define KEY_DOWN_PIN                GPIO_Pin_9
#define KEY_DOWN_PORT                GPIOA

#define KEY_SET_PIN                 GPIO_Pin_10
#define KEY_SET_PORT                GPIOA

#define KEY_COMFIRM_PIN             GPIO_Pin_5
#define KEY_COMFIRM_PORT            GPIOB


#endif