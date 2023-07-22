
project(helloworld-gtk C CXX)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
cmake_minimum_required(VERSION 3.10)

SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

MESSAGE(SYSROOT ${CMAKE_SYSROOT})
if(NOT DEFINED CMAKE_SYSROOT)
    SET(CMAKE_SYSROOT ${CMAKE_CURRENT_SOURCE_DIR}/recipe-sysroot)
endif(NOT DEFINED CMAKE_SYSROOT)


add_executable(${CMAKE_PROJECT_NAME} helloworld-gtk.c)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC cairo ${GTK3_LIBRARIES})
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC
    -I${CMAKE_SYSROOT}/usr/include/gtk-3.0 
    -I${CMAKE_SYSROOT}/usr/include/at-spi2-atk/2.0 
    -I${CMAKE_SYSROOT}/usr/include/at-spi-2.0 
    -I${CMAKE_SYSROOT}/usr/include/dbus-1.0 
    -I${CMAKE_SYSROOT}/usr/lib/dbus-1.0/include 
    -I${CMAKE_SYSROOT}/usr/include/gtk-3.0 
    -I${CMAKE_SYSROOT}/usr/include/gio-unix-2.0 
    -I${CMAKE_SYSROOT}/usr/include/cairo 
    -I${CMAKE_SYSROOT}/usr/include/pango-1.0 
    -I${CMAKE_SYSROOT}/usr/include/harfbuzz 
    -I${CMAKE_SYSROOT}/usr/include/pango-1.0 
    -I${CMAKE_SYSROOT}/usr/include/fribidi 
    -I${CMAKE_SYSROOT}/usr/include/harfbuzz 
    -I${CMAKE_SYSROOT}/usr/include/atk-1.0 
    -I${CMAKE_SYSROOT}/usr/include/cairo 
    -I${CMAKE_SYSROOT}/usr/include/pixman-1 
    -I${CMAKE_SYSROOT}/usr/include/freetype2 
    -I${CMAKE_SYSROOT}/usr/include/directfb 
    -I${CMAKE_SYSROOT}/usr/include/libdrm 
    -I${CMAKE_SYSROOT}/usr/include/gdk-pixbuf-2.0 
    -I${CMAKE_SYSROOT}/usr/include/libpng16 
    -I${CMAKE_SYSROOT}/usr/include/libmount 
    -I${CMAKE_SYSROOT}/usr/include/blkid 
    -I${CMAKE_SYSROOT}/usr/include/glib-2.0 
    -I${CMAKE_SYSROOT}/usr/lib/glib-2.0/include
        )


install(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION "bin")

install(FILES helloworld-gtk-debug.sh DESTINATION "bin")