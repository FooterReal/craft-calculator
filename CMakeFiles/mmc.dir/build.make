# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:/ELTE/Projects/MMC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:/ELTE/Projects/MMC

# Include any dependencies generated for this target.
include CMakeFiles/mmc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mmc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mmc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mmc.dir/flags.make

CMakeFiles/mmc.dir/main.c.obj: CMakeFiles/mmc.dir/flags.make
CMakeFiles/mmc.dir/main.c.obj: main.c
CMakeFiles/mmc.dir/main.c.obj: CMakeFiles/mmc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/ELTE/Projects/MMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mmc.dir/main.c.obj"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mmc.dir/main.c.obj -MF CMakeFiles/mmc.dir/main.c.obj.d -o CMakeFiles/mmc.dir/main.c.obj -c F:/ELTE/Projects/MMC/main.c

CMakeFiles/mmc.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mmc.dir/main.c.i"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:/ELTE/Projects/MMC/main.c > CMakeFiles/mmc.dir/main.c.i

CMakeFiles/mmc.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mmc.dir/main.c.s"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:/ELTE/Projects/MMC/main.c -o CMakeFiles/mmc.dir/main.c.s

CMakeFiles/mmc.dir/material.c.obj: CMakeFiles/mmc.dir/flags.make
CMakeFiles/mmc.dir/material.c.obj: material.c
CMakeFiles/mmc.dir/material.c.obj: CMakeFiles/mmc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/ELTE/Projects/MMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mmc.dir/material.c.obj"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mmc.dir/material.c.obj -MF CMakeFiles/mmc.dir/material.c.obj.d -o CMakeFiles/mmc.dir/material.c.obj -c F:/ELTE/Projects/MMC/material.c

CMakeFiles/mmc.dir/material.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mmc.dir/material.c.i"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:/ELTE/Projects/MMC/material.c > CMakeFiles/mmc.dir/material.c.i

CMakeFiles/mmc.dir/material.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mmc.dir/material.c.s"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:/ELTE/Projects/MMC/material.c -o CMakeFiles/mmc.dir/material.c.s

CMakeFiles/mmc.dir/recipe.c.obj: CMakeFiles/mmc.dir/flags.make
CMakeFiles/mmc.dir/recipe.c.obj: recipe.c
CMakeFiles/mmc.dir/recipe.c.obj: CMakeFiles/mmc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/ELTE/Projects/MMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mmc.dir/recipe.c.obj"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mmc.dir/recipe.c.obj -MF CMakeFiles/mmc.dir/recipe.c.obj.d -o CMakeFiles/mmc.dir/recipe.c.obj -c F:/ELTE/Projects/MMC/recipe.c

CMakeFiles/mmc.dir/recipe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mmc.dir/recipe.c.i"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:/ELTE/Projects/MMC/recipe.c > CMakeFiles/mmc.dir/recipe.c.i

CMakeFiles/mmc.dir/recipe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mmc.dir/recipe.c.s"
	C:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:/ELTE/Projects/MMC/recipe.c -o CMakeFiles/mmc.dir/recipe.c.s

# Object files for target mmc
mmc_OBJECTS = \
"CMakeFiles/mmc.dir/main.c.obj" \
"CMakeFiles/mmc.dir/material.c.obj" \
"CMakeFiles/mmc.dir/recipe.c.obj"

# External object files for target mmc
mmc_EXTERNAL_OBJECTS =

mmc.exe: CMakeFiles/mmc.dir/main.c.obj
mmc.exe: CMakeFiles/mmc.dir/material.c.obj
mmc.exe: CMakeFiles/mmc.dir/recipe.c.obj
mmc.exe: CMakeFiles/mmc.dir/build.make
mmc.exe: CMakeFiles/mmc.dir/linklibs.rsp
mmc.exe: CMakeFiles/mmc.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:/ELTE/Projects/MMC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable mmc.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/mmc.dir/objects.a
	C:/MinGW/bin/ar.exe qc CMakeFiles/mmc.dir/objects.a @CMakeFiles/mmc.dir/objects1.rsp
	C:/MinGW/bin/gcc.exe -Wl,--whole-archive CMakeFiles/mmc.dir/objects.a -Wl,--no-whole-archive -o mmc.exe -Wl,--out-implib,libmmc.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/mmc.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/mmc.dir/build: mmc.exe
.PHONY : CMakeFiles/mmc.dir/build

CMakeFiles/mmc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mmc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mmc.dir/clean

CMakeFiles/mmc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" F:/ELTE/Projects/MMC F:/ELTE/Projects/MMC F:/ELTE/Projects/MMC F:/ELTE/Projects/MMC F:/ELTE/Projects/MMC/CMakeFiles/mmc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mmc.dir/depend
