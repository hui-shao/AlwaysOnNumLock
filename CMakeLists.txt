cmake_minimum_required(VERSION 3.23)
project(AlwaysOnNumLock C)

set(CMAKE_C_STANDARD 11)

add_executable(AlwaysOnNumLock main.c)

add_compile_definitions(EXE_VERSION="v1.0.0")

#set_target_properties(AlwaysOnNumLock PROPERTIES LINK_FLAGS " /MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\" ")
