# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lw/RedBlackBST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lw/RedBlackBST

# Include any dependencies generated for this target.
include lib/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include lib/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include lib/gtest/CMakeFiles/gtest.dir/flags.make

lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: lib/gtest/CMakeFiles/gtest.dir/flags.make
lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: lib/gtest/src/gtest-all.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lw/RedBlackBST/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/lw/RedBlackBST/lib/gtest && /usr/bin/g++-4.9   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/lw/RedBlackBST/lib/gtest/src/gtest-all.cc

lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/lw/RedBlackBST/lib/gtest && /usr/bin/g++-4.9  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lw/RedBlackBST/lib/gtest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/lw/RedBlackBST/lib/gtest && /usr/bin/g++-4.9  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lw/RedBlackBST/lib/gtest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:
.PHONY : lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f lib/gtest/CMakeFiles/gtest.dir/build.make lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/gtest/libgtest.a: lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/gtest/libgtest.a: lib/gtest/CMakeFiles/gtest.dir/build.make
lib/gtest/libgtest.a: lib/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgtest.a"
	cd /home/lw/RedBlackBST/lib/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/lw/RedBlackBST/lib/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/gtest/CMakeFiles/gtest.dir/build: lib/gtest/libgtest.a
.PHONY : lib/gtest/CMakeFiles/gtest.dir/build

lib/gtest/CMakeFiles/gtest.dir/requires: lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
.PHONY : lib/gtest/CMakeFiles/gtest.dir/requires

lib/gtest/CMakeFiles/gtest.dir/clean:
	cd /home/lw/RedBlackBST/lib/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : lib/gtest/CMakeFiles/gtest.dir/clean

lib/gtest/CMakeFiles/gtest.dir/depend:
	cd /home/lw/RedBlackBST && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lw/RedBlackBST /home/lw/RedBlackBST/lib/gtest /home/lw/RedBlackBST /home/lw/RedBlackBST/lib/gtest /home/lw/RedBlackBST/lib/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/gtest/CMakeFiles/gtest.dir/depend

