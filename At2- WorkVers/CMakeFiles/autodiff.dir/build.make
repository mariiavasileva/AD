# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mariia/Desktop/At2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariia/Desktop/At2

# Include any dependencies generated for this target.
include CMakeFiles/autodiff.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/autodiff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/autodiff.dir/flags.make

parser/lexer.c: parser/lexer.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating /home/mariia/Desktop/At2/parser/lexer.c"
	/usr/bin/flex -o /home/mariia/Desktop/At2/parser/lexer.c /home/mariia/Desktop/At2/parser/lexer.l

parser/parser.c: parser/lexer.c
parser/parser.c: parser/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating /home/mariia/Desktop/At2/parser/parser.c"
	/usr/bin/bison -d -y /home/mariia/Desktop/At2/parser/parser.y -o /home/mariia/Desktop/At2/parser/parser.c

CMakeFiles/autodiff.dir/main.cpp.o: CMakeFiles/autodiff.dir/flags.make
CMakeFiles/autodiff.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/autodiff.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autodiff.dir/main.cpp.o -c /home/mariia/Desktop/At2/main.cpp

CMakeFiles/autodiff.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autodiff.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariia/Desktop/At2/main.cpp > CMakeFiles/autodiff.dir/main.cpp.i

CMakeFiles/autodiff.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autodiff.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariia/Desktop/At2/main.cpp -o CMakeFiles/autodiff.dir/main.cpp.s

CMakeFiles/autodiff.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/autodiff.dir/main.cpp.o.requires

CMakeFiles/autodiff.dir/main.cpp.o.provides: CMakeFiles/autodiff.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/autodiff.dir/build.make CMakeFiles/autodiff.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/autodiff.dir/main.cpp.o.provides

CMakeFiles/autodiff.dir/main.cpp.o.provides.build: CMakeFiles/autodiff.dir/main.cpp.o


CMakeFiles/autodiff.dir/model.cpp.o: CMakeFiles/autodiff.dir/flags.make
CMakeFiles/autodiff.dir/model.cpp.o: model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/autodiff.dir/model.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autodiff.dir/model.cpp.o -c /home/mariia/Desktop/At2/model.cpp

CMakeFiles/autodiff.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autodiff.dir/model.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariia/Desktop/At2/model.cpp > CMakeFiles/autodiff.dir/model.cpp.i

CMakeFiles/autodiff.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autodiff.dir/model.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariia/Desktop/At2/model.cpp -o CMakeFiles/autodiff.dir/model.cpp.s

CMakeFiles/autodiff.dir/model.cpp.o.requires:

.PHONY : CMakeFiles/autodiff.dir/model.cpp.o.requires

CMakeFiles/autodiff.dir/model.cpp.o.provides: CMakeFiles/autodiff.dir/model.cpp.o.requires
	$(MAKE) -f CMakeFiles/autodiff.dir/build.make CMakeFiles/autodiff.dir/model.cpp.o.provides.build
.PHONY : CMakeFiles/autodiff.dir/model.cpp.o.provides

CMakeFiles/autodiff.dir/model.cpp.o.provides.build: CMakeFiles/autodiff.dir/model.cpp.o


CMakeFiles/autodiff.dir/parser/lexer.c.o: CMakeFiles/autodiff.dir/flags.make
CMakeFiles/autodiff.dir/parser/lexer.c.o: parser/lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/autodiff.dir/parser/lexer.c.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autodiff.dir/parser/lexer.c.o -c /home/mariia/Desktop/At2/parser/lexer.c

CMakeFiles/autodiff.dir/parser/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autodiff.dir/parser/lexer.c.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariia/Desktop/At2/parser/lexer.c > CMakeFiles/autodiff.dir/parser/lexer.c.i

CMakeFiles/autodiff.dir/parser/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autodiff.dir/parser/lexer.c.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariia/Desktop/At2/parser/lexer.c -o CMakeFiles/autodiff.dir/parser/lexer.c.s

CMakeFiles/autodiff.dir/parser/lexer.c.o.requires:

.PHONY : CMakeFiles/autodiff.dir/parser/lexer.c.o.requires

CMakeFiles/autodiff.dir/parser/lexer.c.o.provides: CMakeFiles/autodiff.dir/parser/lexer.c.o.requires
	$(MAKE) -f CMakeFiles/autodiff.dir/build.make CMakeFiles/autodiff.dir/parser/lexer.c.o.provides.build
.PHONY : CMakeFiles/autodiff.dir/parser/lexer.c.o.provides

CMakeFiles/autodiff.dir/parser/lexer.c.o.provides.build: CMakeFiles/autodiff.dir/parser/lexer.c.o


CMakeFiles/autodiff.dir/parser/parser.c.o: CMakeFiles/autodiff.dir/flags.make
CMakeFiles/autodiff.dir/parser/parser.c.o: parser/parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/autodiff.dir/parser/parser.c.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autodiff.dir/parser/parser.c.o -c /home/mariia/Desktop/At2/parser/parser.c

CMakeFiles/autodiff.dir/parser/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autodiff.dir/parser/parser.c.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariia/Desktop/At2/parser/parser.c > CMakeFiles/autodiff.dir/parser/parser.c.i

CMakeFiles/autodiff.dir/parser/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autodiff.dir/parser/parser.c.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariia/Desktop/At2/parser/parser.c -o CMakeFiles/autodiff.dir/parser/parser.c.s

CMakeFiles/autodiff.dir/parser/parser.c.o.requires:

.PHONY : CMakeFiles/autodiff.dir/parser/parser.c.o.requires

CMakeFiles/autodiff.dir/parser/parser.c.o.provides: CMakeFiles/autodiff.dir/parser/parser.c.o.requires
	$(MAKE) -f CMakeFiles/autodiff.dir/build.make CMakeFiles/autodiff.dir/parser/parser.c.o.provides.build
.PHONY : CMakeFiles/autodiff.dir/parser/parser.c.o.provides

CMakeFiles/autodiff.dir/parser/parser.c.o.provides.build: CMakeFiles/autodiff.dir/parser/parser.c.o


CMakeFiles/autodiff.dir/input.cpp.o: CMakeFiles/autodiff.dir/flags.make
CMakeFiles/autodiff.dir/input.cpp.o: input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/autodiff.dir/input.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autodiff.dir/input.cpp.o -c /home/mariia/Desktop/At2/input.cpp

CMakeFiles/autodiff.dir/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autodiff.dir/input.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariia/Desktop/At2/input.cpp > CMakeFiles/autodiff.dir/input.cpp.i

CMakeFiles/autodiff.dir/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autodiff.dir/input.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariia/Desktop/At2/input.cpp -o CMakeFiles/autodiff.dir/input.cpp.s

CMakeFiles/autodiff.dir/input.cpp.o.requires:

.PHONY : CMakeFiles/autodiff.dir/input.cpp.o.requires

CMakeFiles/autodiff.dir/input.cpp.o.provides: CMakeFiles/autodiff.dir/input.cpp.o.requires
	$(MAKE) -f CMakeFiles/autodiff.dir/build.make CMakeFiles/autodiff.dir/input.cpp.o.provides.build
.PHONY : CMakeFiles/autodiff.dir/input.cpp.o.provides

CMakeFiles/autodiff.dir/input.cpp.o.provides.build: CMakeFiles/autodiff.dir/input.cpp.o


CMakeFiles/autodiff.dir/a13x.cpp.o: CMakeFiles/autodiff.dir/flags.make
CMakeFiles/autodiff.dir/a13x.cpp.o: a13x.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/autodiff.dir/a13x.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autodiff.dir/a13x.cpp.o -c /home/mariia/Desktop/At2/a13x.cpp

CMakeFiles/autodiff.dir/a13x.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autodiff.dir/a13x.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariia/Desktop/At2/a13x.cpp > CMakeFiles/autodiff.dir/a13x.cpp.i

CMakeFiles/autodiff.dir/a13x.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autodiff.dir/a13x.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariia/Desktop/At2/a13x.cpp -o CMakeFiles/autodiff.dir/a13x.cpp.s

CMakeFiles/autodiff.dir/a13x.cpp.o.requires:

.PHONY : CMakeFiles/autodiff.dir/a13x.cpp.o.requires

CMakeFiles/autodiff.dir/a13x.cpp.o.provides: CMakeFiles/autodiff.dir/a13x.cpp.o.requires
	$(MAKE) -f CMakeFiles/autodiff.dir/build.make CMakeFiles/autodiff.dir/a13x.cpp.o.provides.build
.PHONY : CMakeFiles/autodiff.dir/a13x.cpp.o.provides

CMakeFiles/autodiff.dir/a13x.cpp.o.provides.build: CMakeFiles/autodiff.dir/a13x.cpp.o


CMakeFiles/autodiff.dir/a13xBack.cpp.o: CMakeFiles/autodiff.dir/flags.make
CMakeFiles/autodiff.dir/a13xBack.cpp.o: a13xBack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/autodiff.dir/a13xBack.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autodiff.dir/a13xBack.cpp.o -c /home/mariia/Desktop/At2/a13xBack.cpp

CMakeFiles/autodiff.dir/a13xBack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autodiff.dir/a13xBack.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariia/Desktop/At2/a13xBack.cpp > CMakeFiles/autodiff.dir/a13xBack.cpp.i

CMakeFiles/autodiff.dir/a13xBack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autodiff.dir/a13xBack.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariia/Desktop/At2/a13xBack.cpp -o CMakeFiles/autodiff.dir/a13xBack.cpp.s

CMakeFiles/autodiff.dir/a13xBack.cpp.o.requires:

.PHONY : CMakeFiles/autodiff.dir/a13xBack.cpp.o.requires

CMakeFiles/autodiff.dir/a13xBack.cpp.o.provides: CMakeFiles/autodiff.dir/a13xBack.cpp.o.requires
	$(MAKE) -f CMakeFiles/autodiff.dir/build.make CMakeFiles/autodiff.dir/a13xBack.cpp.o.provides.build
.PHONY : CMakeFiles/autodiff.dir/a13xBack.cpp.o.provides

CMakeFiles/autodiff.dir/a13xBack.cpp.o.provides.build: CMakeFiles/autodiff.dir/a13xBack.cpp.o


# Object files for target autodiff
autodiff_OBJECTS = \
"CMakeFiles/autodiff.dir/main.cpp.o" \
"CMakeFiles/autodiff.dir/model.cpp.o" \
"CMakeFiles/autodiff.dir/parser/lexer.c.o" \
"CMakeFiles/autodiff.dir/parser/parser.c.o" \
"CMakeFiles/autodiff.dir/input.cpp.o" \
"CMakeFiles/autodiff.dir/a13x.cpp.o" \
"CMakeFiles/autodiff.dir/a13xBack.cpp.o"

# External object files for target autodiff
autodiff_EXTERNAL_OBJECTS =

autodiff: CMakeFiles/autodiff.dir/main.cpp.o
autodiff: CMakeFiles/autodiff.dir/model.cpp.o
autodiff: CMakeFiles/autodiff.dir/parser/lexer.c.o
autodiff: CMakeFiles/autodiff.dir/parser/parser.c.o
autodiff: CMakeFiles/autodiff.dir/input.cpp.o
autodiff: CMakeFiles/autodiff.dir/a13x.cpp.o
autodiff: CMakeFiles/autodiff.dir/a13xBack.cpp.o
autodiff: CMakeFiles/autodiff.dir/build.make
autodiff: CMakeFiles/autodiff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mariia/Desktop/At2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable autodiff"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/autodiff.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/autodiff.dir/build: autodiff

.PHONY : CMakeFiles/autodiff.dir/build

CMakeFiles/autodiff.dir/requires: CMakeFiles/autodiff.dir/main.cpp.o.requires
CMakeFiles/autodiff.dir/requires: CMakeFiles/autodiff.dir/model.cpp.o.requires
CMakeFiles/autodiff.dir/requires: CMakeFiles/autodiff.dir/parser/lexer.c.o.requires
CMakeFiles/autodiff.dir/requires: CMakeFiles/autodiff.dir/parser/parser.c.o.requires
CMakeFiles/autodiff.dir/requires: CMakeFiles/autodiff.dir/input.cpp.o.requires
CMakeFiles/autodiff.dir/requires: CMakeFiles/autodiff.dir/a13x.cpp.o.requires
CMakeFiles/autodiff.dir/requires: CMakeFiles/autodiff.dir/a13xBack.cpp.o.requires

.PHONY : CMakeFiles/autodiff.dir/requires

CMakeFiles/autodiff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/autodiff.dir/cmake_clean.cmake
.PHONY : CMakeFiles/autodiff.dir/clean

CMakeFiles/autodiff.dir/depend: parser/lexer.c
CMakeFiles/autodiff.dir/depend: parser/parser.c
	cd /home/mariia/Desktop/At2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariia/Desktop/At2 /home/mariia/Desktop/At2 /home/mariia/Desktop/At2 /home/mariia/Desktop/At2 /home/mariia/Desktop/At2/CMakeFiles/autodiff.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/autodiff.dir/depend

