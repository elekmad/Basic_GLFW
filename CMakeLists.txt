cmake_minimum_required(VERSION 2.8)
#Déclaration du projet
cmake_policy(SET CMP0004 OLD)
project(MyProject)
add_executable(MyProject main.c)

include(CheckCCompilerFlag)
check_c_compiler_flag("-std=c99" C99_SUPPORTED)
if (C99_SUPPORTED)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif()

set( CMAKE_C_FLAGS_DEBUG   " -ggdb3" )

#Déclaration de l'exécutable

find_package(glfw3 REQUIRED)
include_directories(${GLFW3_INCLUDE_DIR})
target_link_libraries (MyProject ${GLFW3_LIBRARY})
message(${GLFW3_LIBRARY})
message(${GLFW3_INCLUDE_DIR})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(MyProject ${OPENGL_gl_LIBRARY})
target_link_libraries(MyProject ${OPENGL_glu_LIBRARY})
