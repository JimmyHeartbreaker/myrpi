cmake_minimum_required(VERSION 3.10)

project(starfield LANGUAGES C CXX ASM VERSION 1.0)


SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)


if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
add_compile_definitions(SF_X86)
endif(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")

#test program    
SET(Boost_USE_DEBUG_LIBS ON)
SET(Boost_USE_RELEASE_LIBS ON)
SET(Boost_USE_MULTITHREADED ON)      

find_package(Boost COMPONENTS system filesystem unit_test_framework)
SET(BOOST_LIBRARIES Boost::unit_test_framework Boost::system Boost::filesystem)

add_executable(TestProgram tests/main_tests.cpp tests/${CMAKE_SYSTEM_PROCESSOR}/matrix_tests.cpp tests/starfield_tests.cpp  src/${CMAKE_SYSTEM_PROCESSOR}/matrix4x4.cpp src/${CMAKE_SYSTEM_PROCESSOR}/vector4.cpp )
target_link_libraries(TestProgram PUBLIC ${BOOST_LIBRARIES})

#set version
configure_file(include/starfield_config.h.in include/starfield_config.h)

#libraries
#target_include_directories(sf PUBLIC ${PROJECT_BINARY_DIR}/include)
#SET_TARGET_PROPERTIES(sf PROPERTIES VERSION ${PROJECT_VERSION})

#main executable
add_executable(${PROJECT_NAME} src/${CMAKE_SYSTEM_PROCESSOR}/examples.s src/starfield.cpp src/examples.cpp src/main.cpp  src/star.cpp src/${CMAKE_SYSTEM_PROCESSOR}/matrix4x4.cpp src/${CMAKE_SYSTEM_PROCESSOR}/vector4.cpp )
target_link_libraries(${PROJECT_NAME} PUBLIC ${GTK3_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC 
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
    ${CMAKE_SYSROOT}/usr/lib/gcc-cross/aarch64-linux-gnu/12/include
    ${PROJECT_BINARY_DIR}/include)        

#installs
install(TARGETS ${PROJECT_NAME} DESTINATION "bin")
#install(TARGETS sf DESTINATION "lib")
