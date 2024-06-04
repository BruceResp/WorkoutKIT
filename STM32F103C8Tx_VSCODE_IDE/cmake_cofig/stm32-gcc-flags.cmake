#编译选项文件
#从用户变量生成标志位   NDEBUG宏会使assert宏被去除掉（assert宏主要是在调试时使用）
if(CMAKE_BUILD_TYPE MATCHES Debug)
        set(DBG_FLAGS "-g3 -gdwarf-2 -O0")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
        set(DEG_FLAGS "-O3 -DNDEBUG")
endif()

# stm32 gcc common flags
message(STATUS "MCU_FLAGS: ${MCU_FLAGS}")
message(STATUS "DBG_FLAGS: ${DBG_FLAGS}")

#这些选项通常与链接器的优化选项一起使用，例如--gc-sections（对于GNU ld链接器），它可以根据目标文件中的数据和函数段是否真正被引用，来消除未使用的段。这在嵌入式系统或资源受限的环境中特别有用，因为它可以显著减少最终生成的可执行文件的大小。
set(CMAKE_C_FLAGS "${MCU_FLAGS} -std=gnu99 -Wall -fdata-sections -ffunction-sections ${DBG_FLAGS} " CACHE INTERNAL "C compiler flags")
set(CMAKE_C_FLAGS_DEBUG "" CACHE INTERNAL "C compiler flags: Debug")
set(CMAKE_C_FLAGS_RELEASE "" CACHE INTERNAL "C compiler flags: Release")

set(CMAKE_CXX_FLAGS "${MCU_FLAGS} -fno-rtti -fno-exceptions -fno-builtin -Wall -fdata-sections -ffunction-sections ${DBG_FLAGS} " CACHE INTERNAL "Cxx compiler flags")
set(CMAKE_CXX_FLAGS_DEBUG "" CACHE INTERNAL "Cxx compiler flags: Debug")
set(CMAKE_CXX_FLAGS_RELEASE "" CACHE INTERNAL "Cxx compiler flags: Release")

set(CMAKE_ASM_FLAGS "${MCU_FLAGS} -x assembler-with-cpp ${DBG_FLAGS} " CACHE INTERNAL "ASM compiler flags")
set(CMAKE_ASM_FLAGS_DEBUG "" CACHE INTERNAL "ASM compiler flags: Debug")
set(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "ASM compiler flags: Release")
#设置链接器的编译标志位
set(CMAKE_EXE_LINKER_FLAGS "${LINK_FLAGS}" CACHE INTERNAL "Exe linker flags")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "" CACHE INTERNAL "Shared linker flags")