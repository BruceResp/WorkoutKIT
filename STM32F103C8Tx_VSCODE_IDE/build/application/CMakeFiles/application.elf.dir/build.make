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
CMAKE_SOURCE_DIR = D:/Projects/STM32F103C8Tx_VSCODE_IDE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/Projects/STM32F103C8Tx_VSCODE_IDE/build

# Include any dependencies generated for this target.
include application/CMakeFiles/application.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include application/CMakeFiles/application.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include application/CMakeFiles/application.elf.dir/progress.make

# Include the compile flags for this target's objects.
include application/CMakeFiles/application.elf.dir/flags.make

application/CMakeFiles/application.elf.dir/core/application/main.c.obj: application/CMakeFiles/application.elf.dir/flags.make
application/CMakeFiles/application.elf.dir/core/application/main.c.obj: D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/application/main.c
application/CMakeFiles/application.elf.dir/core/application/main.c.obj: application/CMakeFiles/application.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object application/CMakeFiles/application.elf.dir/core/application/main.c.obj"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/application.elf.dir/core/application/main.c.obj -MF CMakeFiles/application.elf.dir/core/application/main.c.obj.d -o CMakeFiles/application.elf.dir/core/application/main.c.obj -c D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/application/main.c

application/CMakeFiles/application.elf.dir/core/application/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/application.elf.dir/core/application/main.c.i"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/application/main.c > CMakeFiles/application.elf.dir/core/application/main.c.i

application/CMakeFiles/application.elf.dir/core/application/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/application.elf.dir/core/application/main.c.s"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/application/main.c -o CMakeFiles/application.elf.dir/core/application/main.c.s

application/CMakeFiles/application.elf.dir/c_unity/unity.c.obj: application/CMakeFiles/application.elf.dir/flags.make
application/CMakeFiles/application.elf.dir/c_unity/unity.c.obj: D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/c_unity/unity.c
application/CMakeFiles/application.elf.dir/c_unity/unity.c.obj: application/CMakeFiles/application.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object application/CMakeFiles/application.elf.dir/c_unity/unity.c.obj"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/application.elf.dir/c_unity/unity.c.obj -MF CMakeFiles/application.elf.dir/c_unity/unity.c.obj.d -o CMakeFiles/application.elf.dir/c_unity/unity.c.obj -c D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/c_unity/unity.c

application/CMakeFiles/application.elf.dir/c_unity/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/application.elf.dir/c_unity/unity.c.i"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/c_unity/unity.c > CMakeFiles/application.elf.dir/c_unity/unity.c.i

application/CMakeFiles/application.elf.dir/c_unity/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/application.elf.dir/c_unity/unity.c.s"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/c_unity/unity.c -o CMakeFiles/application.elf.dir/c_unity/unity.c.s

application/CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj: application/CMakeFiles/application.elf.dir/flags.make
application/CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj: D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/application/stm32f10x_it.c
application/CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj: application/CMakeFiles/application.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object application/CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj -MF CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj.d -o CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj -c D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/application/stm32f10x_it.c

application/CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.i"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/application/stm32f10x_it.c > CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.i

application/CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.s"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/application/stm32f10x_it.c -o CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.s

application/CMakeFiles/application.elf.dir/core/gui/gui.c.obj: application/CMakeFiles/application.elf.dir/flags.make
application/CMakeFiles/application.elf.dir/core/gui/gui.c.obj: D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/gui/gui.c
application/CMakeFiles/application.elf.dir/core/gui/gui.c.obj: application/CMakeFiles/application.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object application/CMakeFiles/application.elf.dir/core/gui/gui.c.obj"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/application.elf.dir/core/gui/gui.c.obj -MF CMakeFiles/application.elf.dir/core/gui/gui.c.obj.d -o CMakeFiles/application.elf.dir/core/gui/gui.c.obj -c D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/gui/gui.c

application/CMakeFiles/application.elf.dir/core/gui/gui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/application.elf.dir/core/gui/gui.c.i"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/gui/gui.c > CMakeFiles/application.elf.dir/core/gui/gui.c.i

application/CMakeFiles/application.elf.dir/core/gui/gui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/application.elf.dir/core/gui/gui.c.s"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/core/gui/gui.c -o CMakeFiles/application.elf.dir/core/gui/gui.c.s

application/CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj: application/CMakeFiles/application.elf.dir/flags.make
application/CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj: D:/Projects/STM32F103C8Tx_VSCODE_IDE/devices/core_cm3.c
application/CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj: application/CMakeFiles/application.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object application/CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj -MF CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj.d -o CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj -c D:/Projects/STM32F103C8Tx_VSCODE_IDE/devices/core_cm3.c

application/CMakeFiles/application.elf.dir/__/devices/core_cm3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/application.elf.dir/__/devices/core_cm3.c.i"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Projects/STM32F103C8Tx_VSCODE_IDE/devices/core_cm3.c > CMakeFiles/application.elf.dir/__/devices/core_cm3.c.i

application/CMakeFiles/application.elf.dir/__/devices/core_cm3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/application.elf.dir/__/devices/core_cm3.c.s"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Projects/STM32F103C8Tx_VSCODE_IDE/devices/core_cm3.c -o CMakeFiles/application.elf.dir/__/devices/core_cm3.c.s

application/CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj: application/CMakeFiles/application.elf.dir/flags.make
application/CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj: D:/Projects/STM32F103C8Tx_VSCODE_IDE/devices/system_stm32f10x.c
application/CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj: application/CMakeFiles/application.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object application/CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT application/CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj -MF CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj.d -o CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj -c D:/Projects/STM32F103C8Tx_VSCODE_IDE/devices/system_stm32f10x.c

application/CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.i"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:/Projects/STM32F103C8Tx_VSCODE_IDE/devices/system_stm32f10x.c > CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.i

application/CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.s"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:/Projects/STM32F103C8Tx_VSCODE_IDE/devices/system_stm32f10x.c -o CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.s

application/CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.obj: application/CMakeFiles/application.elf.dir/flags.make
application/CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.obj: D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/startup/startup_stm32f103xb.s
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building ASM object application/CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.obj"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.obj -c D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/startup/startup_stm32f103xb.s

application/CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing ASM source to CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.i"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/startup/startup_stm32f103xb.s > CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.i

application/CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling ASM source to assembly CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.s"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/startup/startup_stm32f103xb.s -o CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.s

# Object files for target application.elf
application_elf_OBJECTS = \
"CMakeFiles/application.elf.dir/core/application/main.c.obj" \
"CMakeFiles/application.elf.dir/c_unity/unity.c.obj" \
"CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj" \
"CMakeFiles/application.elf.dir/core/gui/gui.c.obj" \
"CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj" \
"CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj" \
"CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.obj"

# External object files for target application.elf
application_elf_EXTERNAL_OBJECTS =

D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/CMakeFiles/application.elf.dir/core/application/main.c.obj
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/CMakeFiles/application.elf.dir/c_unity/unity.c.obj
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/CMakeFiles/application.elf.dir/core/application/stm32f10x_it.c.obj
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/CMakeFiles/application.elf.dir/core/gui/gui.c.obj
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/CMakeFiles/application.elf.dir/__/devices/core_cm3.c.obj
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/CMakeFiles/application.elf.dir/__/devices/system_stm32f10x.c.obj
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/CMakeFiles/application.elf.dir/startup/startup_stm32f103xb.s.obj
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/CMakeFiles/application.elf.dir/build.make
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/libBSP_LIB.a
D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf: application/libSTD_LIB.a
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && D:/TOOL/Complier_Toolchain/gcc-arm-none-eabi-10-2020-q4-major-win32/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc.exe -mcpu=cortex-m3 -mthumb   -std=gnu99 -Wall -fdata-sections -ffunction-sections -g3 -gdwarf-2 -O0  -mcpu=cortex-m3 -mthumb   -Wl,--gc-sections $(application_elf_OBJECTS) $(application_elf_EXTERNAL_OBJECTS) -o D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf  libBSP_LIB.a libSTD_LIB.a -lc -lm -lnosys -TD:/Projects/STM32F103C8Tx_VSCODE_IDE/application/STM32F103C8Tx_FLASH.ld -Wl,-Map=application.map,--cref,--no-warn-mismatch -specs=nano.specs -specs=nosys.specs
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Generating D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.hex, D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.bin"
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && arm-none-eabi-objcopy -Oihex D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.hex
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && arm-none-eabi-objcopy -Obinary D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.bin
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && arm-none-eabi-objdump -S D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf > D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.lss
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && arm-none-eabi-size -B D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf

# Rule to build all files generated by this target.
application/CMakeFiles/application.elf.dir/build: D:/Projects/STM32F103C8Tx_VSCODE_IDE/application/bin/application.elf
.PHONY : application/CMakeFiles/application.elf.dir/build

application/CMakeFiles/application.elf.dir/clean:
	cd D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application && $(CMAKE_COMMAND) -P CMakeFiles/application.elf.dir/cmake_clean.cmake
.PHONY : application/CMakeFiles/application.elf.dir/clean

application/CMakeFiles/application.elf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Projects/STM32F103C8Tx_VSCODE_IDE D:/Projects/STM32F103C8Tx_VSCODE_IDE/application D:/Projects/STM32F103C8Tx_VSCODE_IDE/build D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application D:/Projects/STM32F103C8Tx_VSCODE_IDE/build/application/CMakeFiles/application.elf.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : application/CMakeFiles/application.elf.dir/depend

