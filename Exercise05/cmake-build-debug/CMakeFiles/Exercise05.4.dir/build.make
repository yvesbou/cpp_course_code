# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yvesboutellier/CLionProjects/Exercise05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yvesboutellier/CLionProjects/Exercise05/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Exercise05.4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exercise05.4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exercise05.4.dir/flags.make

CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.o: CMakeFiles/Exercise05.4.dir/flags.make
CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.o: ../Task04/Source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yvesboutellier/CLionProjects/Exercise05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.o -c /Users/yvesboutellier/CLionProjects/Exercise05/Task04/Source.cpp

CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yvesboutellier/CLionProjects/Exercise05/Task04/Source.cpp > CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.i

CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yvesboutellier/CLionProjects/Exercise05/Task04/Source.cpp -o CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.s

# Object files for target Exercise05.4
Exercise05_4_OBJECTS = \
"CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.o"

# External object files for target Exercise05.4
Exercise05_4_EXTERNAL_OBJECTS =

Exercise05.4: CMakeFiles/Exercise05.4.dir/Task04/Source.cpp.o
Exercise05.4: CMakeFiles/Exercise05.4.dir/build.make
Exercise05.4: CMakeFiles/Exercise05.4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yvesboutellier/CLionProjects/Exercise05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Exercise05.4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exercise05.4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exercise05.4.dir/build: Exercise05.4

.PHONY : CMakeFiles/Exercise05.4.dir/build

CMakeFiles/Exercise05.4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Exercise05.4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Exercise05.4.dir/clean

CMakeFiles/Exercise05.4.dir/depend:
	cd /Users/yvesboutellier/CLionProjects/Exercise05/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yvesboutellier/CLionProjects/Exercise05 /Users/yvesboutellier/CLionProjects/Exercise05 /Users/yvesboutellier/CLionProjects/Exercise05/cmake-build-debug /Users/yvesboutellier/CLionProjects/Exercise05/cmake-build-debug /Users/yvesboutellier/CLionProjects/Exercise05/cmake-build-debug/CMakeFiles/Exercise05.4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exercise05.4.dir/depend

