# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/krystian/development/study/algorytmy/project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/krystian/development/study/algorytmy/project1/cmake-build-debug

# Include any dependencies generated for this target.
include GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/depend.make
# Include the progress variables for this target.
include GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/progress.make

# Include the compile flags for this target's objects.
include GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/flags.make

GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.o: GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/flags.make
GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.o: ../GraphProperties_lib/DataReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krystian/development/study/algorytmy/project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.o"
	cd /home/krystian/development/study/algorytmy/project1/cmake-build-debug/GraphProperties_lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.o -c /home/krystian/development/study/algorytmy/project1/GraphProperties_lib/DataReader.cpp

GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.i"
	cd /home/krystian/development/study/algorytmy/project1/cmake-build-debug/GraphProperties_lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krystian/development/study/algorytmy/project1/GraphProperties_lib/DataReader.cpp > CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.i

GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.s"
	cd /home/krystian/development/study/algorytmy/project1/cmake-build-debug/GraphProperties_lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krystian/development/study/algorytmy/project1/GraphProperties_lib/DataReader.cpp -o CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.s

# Object files for target GraphProperties_lib
GraphProperties_lib_OBJECTS = \
"CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.o"

# External object files for target GraphProperties_lib
GraphProperties_lib_EXTERNAL_OBJECTS =

GraphProperties_lib/libGraphProperties_lib.a: GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/DataReader.cpp.o
GraphProperties_lib/libGraphProperties_lib.a: GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/build.make
GraphProperties_lib/libGraphProperties_lib.a: GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krystian/development/study/algorytmy/project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libGraphProperties_lib.a"
	cd /home/krystian/development/study/algorytmy/project1/cmake-build-debug/GraphProperties_lib && $(CMAKE_COMMAND) -P CMakeFiles/GraphProperties_lib.dir/cmake_clean_target.cmake
	cd /home/krystian/development/study/algorytmy/project1/cmake-build-debug/GraphProperties_lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GraphProperties_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/build: GraphProperties_lib/libGraphProperties_lib.a
.PHONY : GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/build

GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/clean:
	cd /home/krystian/development/study/algorytmy/project1/cmake-build-debug/GraphProperties_lib && $(CMAKE_COMMAND) -P CMakeFiles/GraphProperties_lib.dir/cmake_clean.cmake
.PHONY : GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/clean

GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/depend:
	cd /home/krystian/development/study/algorytmy/project1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krystian/development/study/algorytmy/project1 /home/krystian/development/study/algorytmy/project1/GraphProperties_lib /home/krystian/development/study/algorytmy/project1/cmake-build-debug /home/krystian/development/study/algorytmy/project1/cmake-build-debug/GraphProperties_lib /home/krystian/development/study/algorytmy/project1/cmake-build-debug/GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : GraphProperties_lib/CMakeFiles/GraphProperties_lib.dir/depend

