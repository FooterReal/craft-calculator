cmake_minimum_required(VERSION 3.14)
project(MMC)

set(CMAKE_CXX_STANDARD 14)

file(GLOB main_SRC CONFIGURE_DEPENDS "./*.c")

add_executable(mmc ${main_SRC})