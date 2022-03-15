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
include CMakeFiles/ublox_commands.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ublox_commands.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ublox_commands.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ublox_commands.dir/flags.make

CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o: CMakeFiles/ublox_commands.dir/flags.make
CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o: ../src/commands/StartCommand.cpp
CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o: CMakeFiles/ublox_commands.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o -MF CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o.d -o CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/StartCommand.cpp

CMakeFiles/ublox_commands.dir/src/commands/StartCommand.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ublox_commands.dir/src/commands/StartCommand.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/StartCommand.cpp > CMakeFiles/ublox_commands.dir/src/commands/StartCommand.i

CMakeFiles/ublox_commands.dir/src/commands/StartCommand.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ublox_commands.dir/src/commands/StartCommand.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/StartCommand.cpp -o CMakeFiles/ublox_commands.dir/src/commands/StartCommand.s

CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o: CMakeFiles/ublox_commands.dir/flags.make
CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o: ../src/commands/CreateUbloxReceiver.cpp
CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o: CMakeFiles/ublox_commands.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o -MF CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o.d -o CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/CreateUbloxReceiver.cpp

CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/CreateUbloxReceiver.cpp > CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.i

CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/CreateUbloxReceiver.cpp -o CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.s

CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o: CMakeFiles/ublox_commands.dir/flags.make
CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o: ../src/commands/currentFixCommand.cpp
CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o: CMakeFiles/ublox_commands.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o -MF CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o.d -o CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/currentFixCommand.cpp

CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/currentFixCommand.cpp > CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.i

CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/currentFixCommand.cpp -o CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.s

CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o: CMakeFiles/ublox_commands.dir/flags.make
CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o: ../src/commands/getTimeCommand.cpp
CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o: CMakeFiles/ublox_commands.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o -MF CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o.d -o CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getTimeCommand.cpp

CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getTimeCommand.cpp > CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.i

CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getTimeCommand.cpp -o CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.s

CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o: CMakeFiles/ublox_commands.dir/flags.make
CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o: ../src/commands/getConfigurationCommand.cpp
CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o: CMakeFiles/ublox_commands.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o -MF CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o.d -o CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getConfigurationCommand.cpp

CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getConfigurationCommand.cpp > CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.i

CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getConfigurationCommand.cpp -o CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.s

CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o: CMakeFiles/ublox_commands.dir/flags.make
CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o: ../src/commands/getPositionCommand.cpp
CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o: CMakeFiles/ublox_commands.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o -MF CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o.d -o CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o -c /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getPositionCommand.cpp

CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getPositionCommand.cpp > CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.i

CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/src/commands/getPositionCommand.cpp -o CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.s

# Object files for target ublox_commands
ublox_commands_OBJECTS = \
"CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o" \
"CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o" \
"CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o" \
"CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o" \
"CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o" \
"CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o"

# External object files for target ublox_commands
ublox_commands_EXTERNAL_OBJECTS =

libublox_commands.a: CMakeFiles/ublox_commands.dir/src/commands/StartCommand.o
libublox_commands.a: CMakeFiles/ublox_commands.dir/src/commands/CreateUbloxReceiver.o
libublox_commands.a: CMakeFiles/ublox_commands.dir/src/commands/currentFixCommand.o
libublox_commands.a: CMakeFiles/ublox_commands.dir/src/commands/getTimeCommand.o
libublox_commands.a: CMakeFiles/ublox_commands.dir/src/commands/getConfigurationCommand.o
libublox_commands.a: CMakeFiles/ublox_commands.dir/src/commands/getPositionCommand.o
libublox_commands.a: CMakeFiles/ublox_commands.dir/build.make
libublox_commands.a: CMakeFiles/ublox_commands.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libublox_commands.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ublox_commands.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ublox_commands.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ublox_commands.dir/build: libublox_commands.a
.PHONY : CMakeFiles/ublox_commands.dir/build

CMakeFiles/ublox_commands.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ublox_commands.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ublox_commands.dir/clean

CMakeFiles/ublox_commands.dir/depend:
	cd /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build /Users/taylorgrant/RIT_Assignments/SeniorProject/skydel-plug-ins/examples/ublox_receiver_plugin/backend/build/CMakeFiles/ublox_commands.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ublox_commands.dir/depend

