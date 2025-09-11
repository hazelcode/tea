cmake_minimum_required(VERSION 3.15)
project(tea)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(tea ${SOURCES})

target_include_directories(tea PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)