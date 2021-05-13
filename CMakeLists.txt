cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Voronoi VERSION 1.0)

# Add headers
include_directories(include)
set(CMAKE_BUILD_TYPE Release)

############ SOURCES FOR EXECUTABLE #############
# Add sources for EXECUTABLE
set(SOURCES_EXE test/main.cxx src/main.cxx)
file(GLOB SOURCES_EXE "src/*.cxx" "test/*.cxx")

# add the executable
add_executable(Voronoi_exe "${SOURCES_EXE}")
set_target_properties(Voronoi_exe PROPERTIES LINKER_LANGUAGE CXX)

############ SOURCES FOR EXECUTABLE #############
# Add sources for shared library
file(GLOB SOURCES_LIB "src/*.cxx")

# Create library (.so)
# Change SHARED for STATIC to create static library (.a)
add_library(Voronoi SHARED "${SOURCES_LIB}")
set_target_properties(Voronoi PROPERTIES LINKER_LANGUAGE CXX)


# Install library (.so)
install(TARGETS Voronoi DESTINATION /usr/lib/)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
