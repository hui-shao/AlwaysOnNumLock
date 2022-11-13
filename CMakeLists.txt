cmake_minimum_required(VERSION 3.23)
project(AlwaysOnNumLock C)

set(CMAKE_C_STANDARD 11)

add_executable(AlwaysOnNumLock main.c)
add_executable(AlwaysOnNumLock_loop_VER loop_ver.c)

target_compile_definitions(AlwaysOnNumLock PRIVATE EXE_VERSION="v1.0.0")
target_compile_definitions(AlwaysOnNumLock_loop_VER PRIVATE EXE_VERSION="v1.0.0")

#set_target_properties(AlwaysOnNumLock PROPERTIES LINK_FLAGS " /MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\" ")
#set_target_properties(AlwaysOnNumLock_loop_VER PROPERTIES LINK_FLAGS " /MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\" ")

