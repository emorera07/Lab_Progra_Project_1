cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Voronoi VERSION 1.0)

set(CMAKE_BUILD_TYPE Release)

# specify the C++ standard

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the executable
add_executable(Voronoi "./src/main.cpp")
target_link_libraries(Voronoi PRIVATE libreria)



############ SOURCES FOR EXECUTABLE #############
# Add sources for shared library
add_library( libreria SHARED "./include/voronoi.h")
target_link_libraries(libreria)
set_target_properties(libreria PROPERTIES LINKER_LANGUAGE CXX)
