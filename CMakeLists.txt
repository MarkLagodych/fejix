cmake_minimum_required(VERSION 3.16)
project(fejix VERSION 0.0.1)


### Project features


set(FJ_TESTS OFF CACHE BOOL "Build Fejix tests")

set(FJ_CPU_RENDERING OFF CACHE BOOL "Enable CPU rendering")
set(FJ_OPENGL_RENDERING OFF CACHE BOOL "Enable OpenGL rendering")
set(FJ_VULKAN_RENDERING OFF CACHE BOOL "Enable Vulkan rendering")

set(FJ_X11_BACKEND OFF CACHE BOOL "Build X11 backend")
set(FJ_WAYLAND_BACKEND OFF CACHE BOOL "Build Wayland backend")
set(FJ_WINDOWS_API_BACKEND OFF CACHE BOOL "Build Windows API backend")
set(FJ_COCOA_BACKEND OFF CACHE BOOL "Build Cocoa backend")


### CMake features


enable_language(C)

if(FJ_COCOA_BACKEND)
    enable_language(OBJC)
endif()

if(FJ_TESTS)
    enable_testing()
endif()

include(GNUInstallDirs)


### The main target


# The library type (static/shared) is determined by BUILD_SHARED_LIBS (ON/OFF)
add_library(fejix)

set_target_properties(fejix PROPERTIES
    VERSION "${CMAKE_PROJECT_VERSION}"
    SOVERSION "${CMAKE_PROJECT_VERSION_MAJOR}"
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF)

# The destination root path is defined by CMAKE_INSTALL_PREFIX
install(TARGETS fejix
    LIBRARY ARCHIVE RUNTIME)

install(DIRECTORY "include/fejix"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# Please, don't use Clang with MSVC frontend, it's confusing
if(CMAKE_C_COMPILER_ID MATCHES MSVC)
    target_compile_options(fejix PRIVATE
        "/W4" "/WX" "/D_CRT_SECURE_NO_WARNINGS")
else()
    target_compile_options(fejix PRIVATE
        "-Wall" "-Wextra" "-Wpedantic" "-Werror=vla")
endif()

target_include_directories(fejix
    PUBLIC "include"
    # The root directory is used to include <src/...> and <deps/...>
    PRIVATE ".")

target_sources(fejix PRIVATE
    "src/utils.c"
    "src/backends.c")


### Backends


if(FJ_X11_BACKEND)
    target_compile_definitions(fejix PRIVATE "FJ_X11_BACKEND")

    target_sources(fejix PRIVATE
        "src/x11/backend.c")

    target_link_libraries(fejix PRIVATE
        "X11" "X11-xcb" "xcb")

    if(FJ_CPU_RENDERING)
        target_link_libraries(fejix PRIVATE
            "xcb-shm")
    endif()
endif()




