cmake_minimum_required(VERSION 3.15)
project(EASUI)

# === SDL SETUP ===

# Enable static linking
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# get SDL
include(FetchContent)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG main  # or a specific commit hash
)

# static build
set(SDL_STATIC ON CACHE BOOL "Build SDL3 as static library")
set(SDL_SHARED OFF CACHE BOOL "Build SDL3 as shared library")
set(SDL_TEST OFF CACHE BOOL "Build SDL3 tests")

FetchContent_MakeAvailable(SDL3)

# === === ===

# === CGLM SETUP ===

include(FetchContent)

FetchContent_Declare(
    cglm
    GIT_REPOSITORY https://github.com/recp/cglm.git
    GIT_TAG v0.9.6
)

FetchContent_MakeAvailable(cglm)

# === LIBRARY SETUP ===

file(GLOB_RECURSE LIB_CODE "${CMAKE_CURRENT_SOURCE_DIR}/SOURCE/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/SOURCE/*.cpp")

file(GLOB_RECURSE PRIV_HEAD "${CMAKE_CURRENT_SOURCE_DIR}/PRIVATE_*.h")
file(GLOB_RECURSE PUB_HEAD "${CMAKE_CURRENT_SOURCE_DIR}/*.h")


add_library(EASUI STATIC
    ${LIB_CODE}
    ${PUB_HEAD}
    ${PRIV_HEAD}
)

target_include_directories(EASUI PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# -- Glad setup

add_library(glad STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/DEPENDENCIES/GLAD/src/glad.c
)

target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/DEPENDENCIES/GLAD/include
)

# -- --

# -- COMMON setup

add_library(COMMON STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/DEPENDENCIES/COMMON/STRINGS.c
)

target_include_directories(COMMON PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/DEPENDENCIES/include
)

# --

# -- Link Depndendencies

target_compile_definitions(EASUI PRIVATE SDL_STATIC)
target_link_libraries(EASUI PUBLIC
    glad
    SDL3::SDL3-static
    COMMON
    cglm
)

# === === ===