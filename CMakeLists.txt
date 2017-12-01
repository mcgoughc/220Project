cmake_minimum_required(VERSION 3.8)
project(220Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BookStore.cpp Person.cpp Book.cpp)
add_executable(220Project ${SOURCE_FILES})