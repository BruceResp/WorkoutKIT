#注意：set() 是一个局部变量 只在当前文件中有用，不可以在别的文件声明以后又用到当前文件
# 但是 如果添加了子目录就可以使用
cmake_minimum_required(VERSION 3.10)
#set(CMAKE_MYPROJECT_DIR "D:/Projects/STM32F103C8Tx_VSCODE_IDE")

#包含需要的cmake配置文件 编译器和有关工具  目标单片机内核等信息文件
include(cmake_cofig/gcc-arm-none-eabi.cmake)

project(application C ASM)
set(STM32_PROJ_FOLDER application)

#添加宏定义
add_definitions(
  -DUSE_STDPERIPH_DRIVER
  -DSTM32F103xB
  -DSTM32F10X_MD
)


message(STATUS "Building project: ${PROJECT_NAME}")

if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_BUILD_TYPE MATCHES Debug)
  message(STATUS "Build type: Debug")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
  message(STATUS "Build type: Release")
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/application)