# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Admin\CLionProjects\bubblesorting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Admin\CLionProjects\bubblesorting\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bubblesorting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bubblesorting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bubblesorting.dir/flags.make

CMakeFiles/bubblesorting.dir/main.c.obj: CMakeFiles/bubblesorting.dir/flags.make
CMakeFiles/bubblesorting.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Admin\CLionProjects\bubblesorting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bubblesorting.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bubblesorting.dir\main.c.obj   -c C:\Users\Admin\CLionProjects\bubblesorting\main.c

CMakeFiles/bubblesorting.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bubblesorting.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Admin\CLionProjects\bubblesorting\main.c > CMakeFiles\bubblesorting.dir\main.c.i

CMakeFiles/bubblesorting.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bubblesorting.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Admin\CLionProjects\bubblesorting\main.c -o CMakeFiles\bubblesorting.dir\main.c.s

# Object files for target bubblesorting
bubblesorting_OBJECTS = \
"CMakeFiles/bubblesorting.dir/main.c.obj"

# External object files for target bubblesorting
bubblesorting_EXTERNAL_OBJECTS =

bubblesorting.exe: CMakeFiles/bubblesorting.dir/main.c.obj
bubblesorting.exe: CMakeFiles/bubblesorting.dir/build.make
bubblesorting.exe: CMakeFiles/bubblesorting.dir/linklibs.rsp
bubblesorting.exe: CMakeFiles/bubblesorting.dir/objects1.rsp
bubblesorting.exe: CMakeFiles/bubblesorting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Admin\CLionProjects\bubblesorting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bubblesorting.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bubblesorting.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bubblesorting.dir/build: bubblesorting.exe

.PHONY : CMakeFiles/bubblesorting.dir/build

CMakeFiles/bubblesorting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bubblesorting.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bubblesorting.dir/clean

CMakeFiles/bubblesorting.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Admin\CLionProjects\bubblesorting C:\Users\Admin\CLionProjects\bubblesorting C:\Users\Admin\CLionProjects\bubblesorting\cmake-build-debug C:\Users\Admin\CLionProjects\bubblesorting\cmake-build-debug C:\Users\Admin\CLionProjects\bubblesorting\cmake-build-debug\CMakeFiles\bubblesorting.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bubblesorting.dir/depend
