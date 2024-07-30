#目标单片机 架构 单片机 名字等信息
set(MCU_ARCH ARMCM3)
set(MCU_FAMILY STM32F103xB)
set(MCU_NAME STM32F103CB)

set(CPU "-mcpu=cortex-m3")
set(FPU "")
set(FLOAT_ABI "")
#这个很重要
set(LINKER_SCRIPT E:/Projects/Own/WorkoutKIT/STM32F103C8Tx_VSCODE_IDE/application/STM32F103C8Tx_FLASH.ld)
set(STARTUP ./startup/startup_stm32f103xb.s)
option(USE_LL_LIB "Enable LL library" OFF)
option(USE_HAL_LIB "Enable HAL library" OFF)
option(USE_SPL_LIB "Enable Standard Peripheral Libraries" ON)

#option(USE_SYSTEM_VIEW "Enable Segger SystemView library" OFF)