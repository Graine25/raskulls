
# skull - ReXGlue Recompiled Project
#
# This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(skull LANGUAGES CXX OBJC OBJCXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(SKULL_SOURCES
    src/main.cpp
    src/common/misc.cpp
)

if(WIN32)
    add_executable(skull WIN32 ${SKULL_SOURCES})
else()
    add_executable(skull ${SKULL_SOURCES})
endif()

rexglue_setup_target(skull GPU_PLUGINS xenos)

add_custom_command(TARGET skull POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/skull.toml"
            "$<TARGET_FILE_DIR:skull>/skull.toml"
    COMMENT "Copying skull.toml beside the executable"
    VERBATIM
)
