#选择工具   #被引用在stm32-gcc-postbuild.cmake文件中
set(CMAKE_SYSTEM_NAME Generic)                    #必须在project()之前指定 
set(CMAKE_SYSTEM_PROCESSOR  Arm)                  #必须在project()之前指定 

set(CROSS_COMPILE_PREFIX arm-none-eabi-)          #指定当前使用的交叉编译器的前缀 
set(CMAKE_C_COMPILER ${CROSS_COMPILE_PREFIX}gcc)  #设置使用的交叉编译器
set(CMAKE_CXX_COMPILER ${CROSS_COMPILE_PREFIX}g++)
set(CMAKE_ASM_COMPILER ${CROSS_COMPILE_PREFIX}gcc)

set(CMAKE_C_COMPILER_FORCED ON)                   #不允许系统使用默认编译器
set(CMAKE_CXX_COMPILER_FORCED ON)

#定义了使用的工具 arm-none-eabi-objcopy用于输出bin文件，arm-none-eabi-size用于查看文件占用flash和ram的大小
set(CMAKE_OBJCOPY ${CROSS_COMPILE_PREFIX}objcopy)
set(CMAKE_SIZE ${CROSS_COMPILE_PREFIX}size)
set(CMAKE_OBJDUMP ${CROSS_COMPILE_PREFIX}objdump)
