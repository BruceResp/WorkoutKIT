# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = D:/TOOL/CMake/bin/cmake.exe

# The command to remove a file.
RM = D:/TOOL/CMake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build

# Include any dependencies generated for this target.
include application/CMakeFiles/BSP_LIB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include application/CMakeFiles/BSP_LIB.dir/compiler_depend.make

# Include the progress variables for this target.
include application/CMakeFiles/BSP_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include application/CMakeFiles/BSP_LIB.dir/flags.make

application/CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj: application/CMakeFiles/BSP_LIB.dir/flags.make
application/CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj: D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp.c
application/CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj: application/CMakeFiles/BSP_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object application/CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj -MF CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj.d -o CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj -c D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp.c

application/CMakeFiles/BSP_LIB.dir/bsp/bsp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BSP_LIB.dir/bsp/bsp.c.i"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp.c > CMakeFiles/BSP_LIB.dir/bsp/bsp.c.i

application/CMakeFiles/BSP_LIB.dir/bsp/bsp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BSP_LIB.dir/bsp/bsp.c.s"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp.c -o CMakeFiles/BSP_LIB.dir/bsp/bsp.c.s

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj: application/CMakeFiles/BSP_LIB.dir/flags.make
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj: D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_dma.c
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj: application/CMakeFiles/BSP_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object application/CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj -MF CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj.d -o CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj -c D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_dma.c

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.i"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_dma.c > CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.i

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.s"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_dma.c -o CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.s

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj: application/CMakeFiles/BSP_LIB.dir/flags.make
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj: D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_gpio.c
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj: application/CMakeFiles/BSP_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object application/CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj -MF CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj.d -o CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj -c D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_gpio.c

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.i"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_gpio.c > CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.i

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.s"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_gpio.c -o CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.s

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj: application/CMakeFiles/BSP_LIB.dir/flags.make
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj: D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_i2c.c
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj: application/CMakeFiles/BSP_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object application/CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj -MF CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj.d -o CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj -c D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_i2c.c

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.i"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_i2c.c > CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.i

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.s"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_i2c.c -o CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.s

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj: application/CMakeFiles/BSP_LIB.dir/flags.make
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj: D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_key.c
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj: application/CMakeFiles/BSP_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object application/CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj -MF CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj.d -o CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj -c D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_key.c

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.i"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_key.c > CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.i

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.s"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_key.c -o CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.s

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj: application/CMakeFiles/BSP_LIB.dir/flags.make
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj: D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_spi.c
application/CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj: application/CMakeFiles/BSP_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object application/CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj -MF CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj.d -o CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj -c D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_spi.c

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.i"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_spi.c > CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.i

application/CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.s"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application/bsp/bsp_spi.c -o CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.s

# Object files for target BSP_LIB
BSP_LIB_OBJECTS = \
"CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj" \
"CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj" \
"CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj" \
"CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj" \
"CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj" \
"CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj"

# External object files for target BSP_LIB
BSP_LIB_EXTERNAL_OBJECTS =

application/libBSP_LIB.a: application/CMakeFiles/BSP_LIB.dir/bsp/bsp.c.obj
application/libBSP_LIB.a: application/CMakeFiles/BSP_LIB.dir/bsp/bsp_dma.c.obj
application/libBSP_LIB.a: application/CMakeFiles/BSP_LIB.dir/bsp/bsp_gpio.c.obj
application/libBSP_LIB.a: application/CMakeFiles/BSP_LIB.dir/bsp/bsp_i2c.c.obj
application/libBSP_LIB.a: application/CMakeFiles/BSP_LIB.dir/bsp/bsp_key.c.obj
application/libBSP_LIB.a: application/CMakeFiles/BSP_LIB.dir/bsp/bsp_spi.c.obj
application/libBSP_LIB.a: application/CMakeFiles/BSP_LIB.dir/build.make
application/libBSP_LIB.a: application/CMakeFiles/BSP_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libBSP_LIB.a"
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && $(CMAKE_COMMAND) -P CMakeFiles/BSP_LIB.dir/cmake_clean_target.cmake
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BSP_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/CMakeFiles/BSP_LIB.dir/build: application/libBSP_LIB.a
.PHONY : application/CMakeFiles/BSP_LIB.dir/build

application/CMakeFiles/BSP_LIB.dir/clean:
	cd D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application && $(CMAKE_COMMAND) -P CMakeFiles/BSP_LIB.dir/cmake_clean.cmake
.PHONY : application/CMakeFiles/BSP_LIB.dir/clean

application/CMakeFiles/BSP_LIB.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/application D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application D:/Git_Repository/STM32F103C8Tx_VSCODE_IDE/build/application/CMakeFiles/BSP_LIB.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : application/CMakeFiles/BSP_LIB.dir/depend

