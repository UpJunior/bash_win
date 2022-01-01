
cmake_minimum_required(VERSION 3.10)

set (CMAKE_C_COMPILER "gcc")
set (CMAKE_CXX_COMPILER "g++")

set (PROJECT_NAME "win_bash")
project (${PROJECT_NAME})
set(PUBLISH_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/publish)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PUBLISH_OUTPUT})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(src)

