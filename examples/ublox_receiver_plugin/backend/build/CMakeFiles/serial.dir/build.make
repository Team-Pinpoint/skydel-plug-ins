# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build

# Include any dependencies generated for this target.
include CMakeFiles/serial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/serial.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/serial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serial.dir/flags.make

CMakeFiles/serial.dir/src/impl/unix.o: CMakeFiles/serial.dir/flags.make
CMakeFiles/serial.dir/src/impl/unix.o: ../src/impl/unix.cc
CMakeFiles/serial.dir/src/impl/unix.o: CMakeFiles/serial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serial.dir/src/impl/unix.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serial.dir/src/impl/unix.o -MF CMakeFiles/serial.dir/src/impl/unix.o.d -o CMakeFiles/serial.dir/src/impl/unix.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/impl/unix.cc

CMakeFiles/serial.dir/src/impl/unix.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial.dir/src/impl/unix.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/impl/unix.cc > CMakeFiles/serial.dir/src/impl/unix.i

CMakeFiles/serial.dir/src/impl/unix.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial.dir/src/impl/unix.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/impl/unix.cc -o CMakeFiles/serial.dir/src/impl/unix.s

CMakeFiles/serial.dir/src/impl/win.o: CMakeFiles/serial.dir/flags.make
CMakeFiles/serial.dir/src/impl/win.o: ../src/impl/win.cc
CMakeFiles/serial.dir/src/impl/win.o: CMakeFiles/serial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serial.dir/src/impl/win.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serial.dir/src/impl/win.o -MF CMakeFiles/serial.dir/src/impl/win.o.d -o CMakeFiles/serial.dir/src/impl/win.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/impl/win.cc

CMakeFiles/serial.dir/src/impl/win.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial.dir/src/impl/win.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/impl/win.cc > CMakeFiles/serial.dir/src/impl/win.i

CMakeFiles/serial.dir/src/impl/win.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial.dir/src/impl/win.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/impl/win.cc -o CMakeFiles/serial.dir/src/impl/win.s

CMakeFiles/serial.dir/src/serial.o: CMakeFiles/serial.dir/flags.make
CMakeFiles/serial.dir/src/serial.o: ../src/serial.cc
CMakeFiles/serial.dir/src/serial.o: CMakeFiles/serial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/serial.dir/src/serial.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serial.dir/src/serial.o -MF CMakeFiles/serial.dir/src/serial.o.d -o CMakeFiles/serial.dir/src/serial.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/serial.cc

CMakeFiles/serial.dir/src/serial.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial.dir/src/serial.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/serial.cc > CMakeFiles/serial.dir/src/serial.i

CMakeFiles/serial.dir/src/serial.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial.dir/src/serial.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/serial.cc -o CMakeFiles/serial.dir/src/serial.s

# Object files for target serial
serial_OBJECTS = \
"CMakeFiles/serial.dir/src/impl/unix.o" \
"CMakeFiles/serial.dir/src/impl/win.o" \
"CMakeFiles/serial.dir/src/serial.o"

# External object files for target serial
serial_EXTERNAL_OBJECTS =

libserial.a: CMakeFiles/serial.dir/src/impl/unix.o
libserial.a: CMakeFiles/serial.dir/src/impl/win.o
libserial.a: CMakeFiles/serial.dir/src/serial.o
libserial.a: CMakeFiles/serial.dir/build.make
libserial.a: CMakeFiles/serial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libserial.a"
	$(CMAKE_COMMAND) -P CMakeFiles/serial.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serial.dir/build: libserial.a
.PHONY : CMakeFiles/serial.dir/build

CMakeFiles/serial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serial.dir/clean

CMakeFiles/serial.dir/depend:
	cd /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles/serial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serial.dir/depend

