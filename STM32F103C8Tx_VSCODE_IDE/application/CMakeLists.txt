include(../cmake_cofig/target-def.cmake)

set(MCU_FLAGS "${CPU} -mthumb ${FPU} ${FLOAT_ABI}")
set(LINK_FLAGS "${MCU_FLAGS} -Wl,--gc-sections")                              #使用microlib
set(EXTRA_LINK_FLAGS "-Wl,-Map=${PROJECT_NAME}.map,--cref,--no-warn-mismatch -specs=nano.specs -specs=nosys.specs")
include(../cmake_cofig/stm32-gcc-flags.cmake)

# print summary of configurations
message(STATUS "MCU_FAMILY: ${MCU_FAMILY}")
message(STATUS "MCU_NAME: ${MCU_NAME}")
message(STATUS "Specified C compiler: ${CMAKE_C_COMPILER}")
message(STATUS "Linker script: ${LINKER_SCRIPT}")
message(STATUS "Use LL library: ${USE_LL_LIB}")
message(STATUS "Use HAL library: ${USE_HAL_LIB}")
message(STATUS "Use STD library: ${USE_SPL_LIB}")
message(STATUS "${PROJECT_SOURCE_DIR}")
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")

## version information
set(VERSION_MAJOR 0 CACHE STRING "Project major version number.")
set(VERSION_MINOR 1 CACHE STRING "Project minor version number.")
set(VERSION_PATCH 0 CACHE STRING "Project patch version number.")

set(ELF_TARGET ${PROJECT_NAME}.elf)

#注意  用在编译时寻找头文件
include_directories(
  ../product
  ../drivers/inc
  ../devices/inc
  ./bsp/inc
  ./core/application/inc 
  ./c_unity/inc
  ./core/gui/inc 
  ./core/key/inc
  ./core/system/inc
  ./core/flash/inc
)

set_property(SOURCE STARTUP PROPERTY LANGUAGE C)

set(PROJ_SRC
    ./core/application/main.c
    ./c_unity/unity.c
    ./core/application/stm32f10x_it.c
    ./core/gui/gui.c
    ./core/key/key.c
    ./core/system/system.c
    ./core/flash/flash.c
    ../devices/core_cm3.c
    ../devices/system_stm32f10x.c
    
)
#标准库文件
file(GLOB_RECURSE SOURCES ../drivers/*.c)
add_library(STD_LIB STATIC ${SOURCES})
target_include_directories(STD_LIB PUBLIC ../drivers/inc)
target_compile_definitions(STD_LIB INTERFACE "")

#bsp库文件
file(GLOB_RECURSE BSP_SOURCES ./bsp/*.c)
add_library(BSP_LIB STATIC ${BSP_SOURCES})
target_include_directories(BSP_LIB PUBLIC ./bsp/inc)
target_compile_definitions(BSP_LIB INTERFACE "")
#添加可执行文件
add_executable(${ELF_TARGET} ${PROJ_SRC} ${STARTUP})
set_target_properties(${ELF_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/application/bin")
target_compile_definitions(${ELF_TARGET} PUBLIC -D${MCU_FAMILY})
target_link_libraries(${ELF_TARGET} PUBLIC BSP_LIB STD_LIB -lc -lm -lnosys )
target_link_libraries(${ELF_TARGET} PRIVATE -T${LINKER_SCRIPT} ${EXTRA_LINK_FLAGS})

target_include_directories(${ELF_TARGET} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/application/core/application/inc>)

#项目名称

include(../cmake_cofig/stm32-gcc-postbuild.cmake)

message("project's name : " "${PROJECT_NAME}")
