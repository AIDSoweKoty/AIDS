# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Program.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Program.dir/flags.make

CMakeFiles/Program.dir/main.cpp.obj: CMakeFiles/Program.dir/flags.make
CMakeFiles/Program.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Program.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Program.dir\main.cpp.obj -c C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\main.cpp

CMakeFiles/Program.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Program.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\main.cpp > CMakeFiles\Program.dir\main.cpp.i

CMakeFiles/Program.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Program.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\main.cpp -o CMakeFiles\Program.dir\main.cpp.s

CMakeFiles/Program.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Program.dir/main.cpp.obj.requires

CMakeFiles/Program.dir/main.cpp.obj.provides: CMakeFiles/Program.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Program.dir\build.make CMakeFiles/Program.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Program.dir/main.cpp.obj.provides

CMakeFiles/Program.dir/main.cpp.obj.provides.build: CMakeFiles/Program.dir/main.cpp.obj


CMakeFiles/Program.dir/plecak.cpp.obj: CMakeFiles/Program.dir/flags.make
CMakeFiles/Program.dir/plecak.cpp.obj: plecak.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Program.dir/plecak.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Program.dir\plecak.cpp.obj -c C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug\plecak.cpp

CMakeFiles/Program.dir/plecak.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Program.dir/plecak.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug\plecak.cpp > CMakeFiles\Program.dir\plecak.cpp.i

CMakeFiles/Program.dir/plecak.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Program.dir/plecak.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug\plecak.cpp -o CMakeFiles\Program.dir\plecak.cpp.s

CMakeFiles/Program.dir/plecak.cpp.obj.requires:

.PHONY : CMakeFiles/Program.dir/plecak.cpp.obj.requires

CMakeFiles/Program.dir/plecak.cpp.obj.provides: CMakeFiles/Program.dir/plecak.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Program.dir\build.make CMakeFiles/Program.dir/plecak.cpp.obj.provides.build
.PHONY : CMakeFiles/Program.dir/plecak.cpp.obj.provides

CMakeFiles/Program.dir/plecak.cpp.obj.provides.build: CMakeFiles/Program.dir/plecak.cpp.obj


# Object files for target Program
Program_OBJECTS = \
"CMakeFiles/Program.dir/main.cpp.obj" \
"CMakeFiles/Program.dir/plecak.cpp.obj"

# External object files for target Program
Program_EXTERNAL_OBJECTS =

Program.exe: CMakeFiles/Program.dir/main.cpp.obj
Program.exe: CMakeFiles/Program.dir/plecak.cpp.obj
Program.exe: CMakeFiles/Program.dir/build.make
Program.exe: CMakeFiles/Program.dir/linklibs.rsp
Program.exe: CMakeFiles/Program.dir/objects1.rsp
Program.exe: CMakeFiles/Program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Program.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Program.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Program.dir/build: Program.exe

.PHONY : CMakeFiles/Program.dir/build

CMakeFiles/Program.dir/requires: CMakeFiles/Program.dir/main.cpp.obj.requires
CMakeFiles/Program.dir/requires: CMakeFiles/Program.dir/plecak.cpp.obj.requires

.PHONY : CMakeFiles/Program.dir/requires

CMakeFiles/Program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Program.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Program.dir/clean

CMakeFiles/Program.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug C:\Users\Piotr\Documents\GitHub\AIDS\Plecak\Program\cmake-build-debug\CMakeFiles\Program.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Program.dir/depend

