cmake_minimum_required(VERSION 3.15)
project(TEA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(tea src/main.cpp)

llvm_map_components_to_libnames(llvm_libs, support, core, irreader, nativecodegen)

target_link_libraries(tea ${llvm_libs})