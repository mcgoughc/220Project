cmake_minimum_required(VERSION 3.8)
project(220Project)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp BookStore.cpp Book.cpp Tests.cpp Person.cpp ArrayInventory.cpp Run.cpp)
add_executable(220Project ${SOURCE_FILES})