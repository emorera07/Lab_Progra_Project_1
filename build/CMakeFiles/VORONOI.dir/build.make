# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1/build

# Include any dependencies generated for this target.
include CMakeFiles/VORONOI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VORONOI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VORONOI.dir/flags.make

# Object files for target VORONOI
VORONOI_OBJECTS =

# External object files for target VORONOI
VORONOI_EXTERNAL_OBJECTS =

VORONOI: CMakeFiles/VORONOI.dir/build.make
VORONOI: CMakeFiles/VORONOI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX executable VORONOI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VORONOI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VORONOI.dir/build: VORONOI

.PHONY : CMakeFiles/VORONOI.dir/build

CMakeFiles/VORONOI.dir/requires:

.PHONY : CMakeFiles/VORONOI.dir/requires

CMakeFiles/VORONOI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VORONOI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VORONOI.dir/clean

CMakeFiles/VORONOI.dir/depend:
	cd /home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1 /home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1 /home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1/build /home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1/build /home/emmanuel/Documentos/Laboratorio_de_programacion/Proyecto_1/Lab_Progra_Project_1/build/CMakeFiles/VORONOI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VORONOI.dir/depend

