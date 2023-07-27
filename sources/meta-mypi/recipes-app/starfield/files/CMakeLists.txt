cmake_minimum_required(VERSION 3.10)

project(starfield LANGUAGES C CXX ASM VERSION 1.0)


SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

#fudge to make it work between vscode/cmake and bitbake/cmake
if(NOT DEFINED CMAKE_SYSROOT)
    SET(CMAKE_SYSROOT ${CMAKE_CURRENT_SOURCE_DIR}/recipe-sysroot)
endif(NOT DEFINED CMAKE_SYSROOT)

configure_file(include/starfield_config.h.in include/starfield_config.h)

#libraries
add_library(sf SHARED src/starfield.cpp)
target_include_directories(sf PUBLIC ${PROJECT_BINARY_DIR}/include)
SET_TARGET_PROPERTIES(sf PROPERTIES VERSION ${PROJECT_VERSION})

#main executable
add_executable(${CMAKE_PROJECT_NAME} src/${CMAKE_SYSTEM_PROCESSOR}/examples.s src/examples.cpp src/main.cpp )
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${GTK3_LIBRARIES} sf)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC 
    ${CMAKE_SYSROOT}/usr/include/at-spi2-atk/2.0 
    ${CMAKE_SYSROOT}/usr/include/at-spi-2.0 
    ${CMAKE_SYSROOT}/usr/include/dbus-1.0 
    ${CMAKE_SYSROOT}/usr/lib/dbus-1.0/include 
    ${CMAKE_SYSROOT}/usr/include/gtk-3.0 
    ${CMAKE_SYSROOT}/usr/include/gio-unix-2.0 
    ${CMAKE_SYSROOT}/usr/include/cairo 
    ${CMAKE_SYSROOT}/usr/include/pango-1.0 
    ${CMAKE_SYSROOT}/usr/include/harfbuzz 
    ${CMAKE_SYSROOT}/usr/include/fribidi 
    ${CMAKE_SYSROOT}/usr/include/atk-1.0 
    ${CMAKE_SYSROOT}/usr/include/pixman-1 
    ${CMAKE_SYSROOT}/usr/include/freetype2 
    ${CMAKE_SYSROOT}/usr/include/directfb 
    ${CMAKE_SYSROOT}/usr/include/libdrm 
    ${CMAKE_SYSROOT}/usr/include/gdk-pixbuf-2.0 
    ${CMAKE_SYSROOT}/usr/include/libpng16 
    ${CMAKE_SYSROOT}/usr/include/libmount 
    ${CMAKE_SYSROOT}/usr/include/blkid 
    ${CMAKE_SYSROOT}/usr/include/glib-2.0 
    ${CMAKE_SYSROOT}/usr/lib/glib-2.0/include
    ${CMAKE_SYSROOT}/usr/lib/x86_64-linux-gnu/glib-2.0/include
    ${PROJECT_BINARY_DIR}/include)
        

#installs
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION "bin")
install(TARGETS sf DESTINATION "lib")
