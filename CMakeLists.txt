cmake_minimum_required(VERSION 2.8.9)
project(n_body_simulation)

find_package(OpenMP)

#Bring the headers, such as Student.h into the project
include_directories(include)

set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

#Can manually add the sources using the set command as follows:
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
add_executable(nbody ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(nbody PUBLIC OpenMP::OpenMP_CXX)
endif()

