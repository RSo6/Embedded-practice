cmake_minimum_required(VERSION 4.2)

project(Embedded_practice C)

set(CMAKE_C_STANDARD 11)

#file(GLOB SOURCES
#        Practice/*.c
#)

add_executable(Embedded_practice main.c
        ${SOURCES}
        Practice/mathematicalOperations.c
        Practice/strings.c
)

target_include_directories(Embedded_practice PRIVATE
        Practice
)
