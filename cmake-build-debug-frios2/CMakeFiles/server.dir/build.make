# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /tmp/tmp.3R9LwTKRK6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/server.cpp.o -c /tmp/tmp.3R9LwTKRK6/server.cpp

CMakeFiles/server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.3R9LwTKRK6/server.cpp > CMakeFiles/server.dir/server.cpp.i

CMakeFiles/server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.3R9LwTKRK6/server.cpp -o CMakeFiles/server.dir/server.cpp.s

CMakeFiles/server.dir/main_server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/main_server.cpp.o: ../main_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/main_server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/main_server.cpp.o -c /tmp/tmp.3R9LwTKRK6/main_server.cpp

CMakeFiles/server.dir/main_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/main_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.3R9LwTKRK6/main_server.cpp > CMakeFiles/server.dir/main_server.cpp.i

CMakeFiles/server.dir/main_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/main_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.3R9LwTKRK6/main_server.cpp -o CMakeFiles/server.dir/main_server.cpp.s

CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.o: ../QuestionManager/QuestionsManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.o -c /tmp/tmp.3R9LwTKRK6/QuestionManager/QuestionsManager.cpp

CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.3R9LwTKRK6/QuestionManager/QuestionsManager.cpp > CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.i

CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.3R9LwTKRK6/QuestionManager/QuestionsManager.cpp -o CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.s

CMakeFiles/server.dir/QuestionManager/Question.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/QuestionManager/Question.cpp.o: ../QuestionManager/Question.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/QuestionManager/Question.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/QuestionManager/Question.cpp.o -c /tmp/tmp.3R9LwTKRK6/QuestionManager/Question.cpp

CMakeFiles/server.dir/QuestionManager/Question.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/QuestionManager/Question.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.3R9LwTKRK6/QuestionManager/Question.cpp > CMakeFiles/server.dir/QuestionManager/Question.cpp.i

CMakeFiles/server.dir/QuestionManager/Question.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/QuestionManager/Question.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.3R9LwTKRK6/QuestionManager/Question.cpp -o CMakeFiles/server.dir/QuestionManager/Question.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/server.cpp.o" \
"CMakeFiles/server.dir/main_server.cpp.o" \
"CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.o" \
"CMakeFiles/server.dir/QuestionManager/Question.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/server.cpp.o
server: CMakeFiles/server.dir/main_server.cpp.o
server: CMakeFiles/server.dir/QuestionManager/QuestionsManager.cpp.o
server: CMakeFiles/server.dir/QuestionManager/Question.cpp.o
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.3R9LwTKRK6 /tmp/tmp.3R9LwTKRK6 /tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2 /tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2 /tmp/tmp.3R9LwTKRK6/cmake-build-debug-frios2/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

