# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(timers)

#
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-O0  -g  -gdwarf-4")

set(CMAKE_BUILD_TYPE "DEBUG")

set(CMAKE_C_FLAGS "-w")

add_compile_options(CMAKE_C_FLAGS "-w")
add_compile_options(CMAKE_CXX_FLAGS "-w")

# set(CMAKE_CXX_COMPILER "/home/hadoop/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20240530/xtensa-esp-elf/bin/xtensa-esp-elf-g++")
# set(CUSTOM_LINKER "/home/hadoop/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20240530/xtensa-esp-elf/bin/xtensa-esp-elf-ld")
# set(CMAKE_LINKER "${CUSTOM_LINKER}")

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -EL")