# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chan/ClionProjects/MarsServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chan/ClionProjects/MarsServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MarsServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MarsServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarsServer.dir/flags.make

CMakeFiles/MarsServer.dir/main.cpp.o: CMakeFiles/MarsServer.dir/flags.make
CMakeFiles/MarsServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chan/ClionProjects/MarsServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MarsServer.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MarsServer.dir/main.cpp.o -c /Users/chan/ClionProjects/MarsServer/main.cpp

CMakeFiles/MarsServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarsServer.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/ClionProjects/MarsServer/main.cpp > CMakeFiles/MarsServer.dir/main.cpp.i

CMakeFiles/MarsServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarsServer.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/ClionProjects/MarsServer/main.cpp -o CMakeFiles/MarsServer.dir/main.cpp.s

CMakeFiles/MarsServer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MarsServer.dir/main.cpp.o.requires

CMakeFiles/MarsServer.dir/main.cpp.o.provides: CMakeFiles/MarsServer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarsServer.dir/build.make CMakeFiles/MarsServer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MarsServer.dir/main.cpp.o.provides

CMakeFiles/MarsServer.dir/main.cpp.o.provides.build: CMakeFiles/MarsServer.dir/main.cpp.o


CMakeFiles/MarsServer.dir/MarsServer.cpp.o: CMakeFiles/MarsServer.dir/flags.make
CMakeFiles/MarsServer.dir/MarsServer.cpp.o: ../MarsServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chan/ClionProjects/MarsServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MarsServer.dir/MarsServer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MarsServer.dir/MarsServer.cpp.o -c /Users/chan/ClionProjects/MarsServer/MarsServer.cpp

CMakeFiles/MarsServer.dir/MarsServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarsServer.dir/MarsServer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/ClionProjects/MarsServer/MarsServer.cpp > CMakeFiles/MarsServer.dir/MarsServer.cpp.i

CMakeFiles/MarsServer.dir/MarsServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarsServer.dir/MarsServer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/ClionProjects/MarsServer/MarsServer.cpp -o CMakeFiles/MarsServer.dir/MarsServer.cpp.s

CMakeFiles/MarsServer.dir/MarsServer.cpp.o.requires:

.PHONY : CMakeFiles/MarsServer.dir/MarsServer.cpp.o.requires

CMakeFiles/MarsServer.dir/MarsServer.cpp.o.provides: CMakeFiles/MarsServer.dir/MarsServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarsServer.dir/build.make CMakeFiles/MarsServer.dir/MarsServer.cpp.o.provides.build
.PHONY : CMakeFiles/MarsServer.dir/MarsServer.cpp.o.provides

CMakeFiles/MarsServer.dir/MarsServer.cpp.o.provides.build: CMakeFiles/MarsServer.dir/MarsServer.cpp.o


# Object files for target MarsServer
MarsServer_OBJECTS = \
"CMakeFiles/MarsServer.dir/main.cpp.o" \
"CMakeFiles/MarsServer.dir/MarsServer.cpp.o"

# External object files for target MarsServer
MarsServer_EXTERNAL_OBJECTS =

MarsServer: CMakeFiles/MarsServer.dir/main.cpp.o
MarsServer: CMakeFiles/MarsServer.dir/MarsServer.cpp.o
MarsServer: CMakeFiles/MarsServer.dir/build.make
MarsServer: /usr/local/lib/libopencv_videostab.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_superres.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_stitching.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_shape.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_photo.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_objdetect.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_hal.a
MarsServer: /usr/local/lib/libopencv_calib3d.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_features2d.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_ml.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_highgui.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_videoio.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_imgcodecs.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_flann.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_video.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_imgproc.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_core.3.0.0.dylib
MarsServer: /usr/local/lib/libopencv_hal.a
MarsServer: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
MarsServer: CMakeFiles/MarsServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chan/ClionProjects/MarsServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MarsServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MarsServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarsServer.dir/build: MarsServer

.PHONY : CMakeFiles/MarsServer.dir/build

CMakeFiles/MarsServer.dir/requires: CMakeFiles/MarsServer.dir/main.cpp.o.requires
CMakeFiles/MarsServer.dir/requires: CMakeFiles/MarsServer.dir/MarsServer.cpp.o.requires

.PHONY : CMakeFiles/MarsServer.dir/requires

CMakeFiles/MarsServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MarsServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MarsServer.dir/clean

CMakeFiles/MarsServer.dir/depend:
	cd /Users/chan/ClionProjects/MarsServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chan/ClionProjects/MarsServer /Users/chan/ClionProjects/MarsServer /Users/chan/ClionProjects/MarsServer/cmake-build-debug /Users/chan/ClionProjects/MarsServer/cmake-build-debug /Users/chan/ClionProjects/MarsServer/cmake-build-debug/CMakeFiles/MarsServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MarsServer.dir/depend

