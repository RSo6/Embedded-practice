
cmake_minimum_required(VERSION 3.22)

project(EmbeddedPractice LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


add_subdirectory(Practice)
add_subdirectory(Embedded)
add_subdirectory(LEDs_Buttons_Interrupts)