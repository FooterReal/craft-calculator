# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.24
cmake_policy(SET CMP0009 NEW)

# main_SRC at CMakeLists.txt:6 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "F:/ELTE/Projects/MMC/*.c")
set(OLD_GLOB
  "F:/ELTE/Projects/MMC/main.c"
  "F:/ELTE/Projects/MMC/material.c"
  "F:/ELTE/Projects/MMC/recipe.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "F:/ELTE/Projects/MMC/CMakeFiles/cmake.verify_globs")
endif()
