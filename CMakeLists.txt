cmake_minimum_required(VERSION 3.15 )
project(meow C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.c)

add_executable(meow ${SOURCES})

target_include_directories(meow PRIVATE ${CMAKE_SOURCE_DIR}/include)