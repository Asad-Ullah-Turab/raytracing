# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mrlmao/workstuff/projects/raytracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrlmao/workstuff/projects/raytracing/build

# Include any dependencies generated for this target.
include CMakeFiles/raytracing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/raytracing.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracing.dir/flags.make

CMakeFiles/raytracing.dir/codegen:
.PHONY : CMakeFiles/raytracing.dir/codegen

CMakeFiles/raytracing.dir/src/main.cpp.o: CMakeFiles/raytracing.dir/flags.make
CMakeFiles/raytracing.dir/src/main.cpp.o: /home/mrlmao/workstuff/projects/raytracing/src/main.cpp
CMakeFiles/raytracing.dir/src/main.cpp.o: CMakeFiles/raytracing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mrlmao/workstuff/projects/raytracing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracing.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raytracing.dir/src/main.cpp.o -MF CMakeFiles/raytracing.dir/src/main.cpp.o.d -o CMakeFiles/raytracing.dir/src/main.cpp.o -c /home/mrlmao/workstuff/projects/raytracing/src/main.cpp

CMakeFiles/raytracing.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrlmao/workstuff/projects/raytracing/src/main.cpp > CMakeFiles/raytracing.dir/src/main.cpp.i

CMakeFiles/raytracing.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrlmao/workstuff/projects/raytracing/src/main.cpp -o CMakeFiles/raytracing.dir/src/main.cpp.s

# Object files for target raytracing
raytracing_OBJECTS = \
"CMakeFiles/raytracing.dir/src/main.cpp.o"

# External object files for target raytracing
raytracing_EXTERNAL_OBJECTS =

bin/raytracing: CMakeFiles/raytracing.dir/src/main.cpp.o
bin/raytracing: CMakeFiles/raytracing.dir/build.make
bin/raytracing: CMakeFiles/raytracing.dir/compiler_depend.ts
bin/raytracing: /usr/lib/libSDL2main.a
bin/raytracing: /usr/lib/libSDL2-2.0.so.0.3000.52
bin/raytracing: CMakeFiles/raytracing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mrlmao/workstuff/projects/raytracing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/raytracing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracing.dir/build: bin/raytracing
.PHONY : CMakeFiles/raytracing.dir/build

CMakeFiles/raytracing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracing.dir/clean

CMakeFiles/raytracing.dir/depend:
	cd /home/mrlmao/workstuff/projects/raytracing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrlmao/workstuff/projects/raytracing /home/mrlmao/workstuff/projects/raytracing /home/mrlmao/workstuff/projects/raytracing/build /home/mrlmao/workstuff/projects/raytracing/build /home/mrlmao/workstuff/projects/raytracing/build/CMakeFiles/raytracing.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/raytracing.dir/depend

