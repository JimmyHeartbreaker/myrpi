cmake_minimum_required(VERSION 3.10)

project(helloworld LANGUAGES C CXX ASM VERSION 1.0)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp")


SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)

#fudge to make it work between vscode/cmake and bitbake/cmake
if(NOT DEFINED CMAKE_SYSROOT)
    SET(CMAKE_SYSROOT ${CMAKE_CURRENT_SOURCE_DIR}/recipe-sysroot)
endif(NOT DEFINED CMAKE_SYSROOT)

configure_file(include/helloworld_config.h.in include/helloworld_config.h)




#main executable
add_executable(${CMAKE_PROJECT_NAME} src/examples.cpp src/examples.s src/helloworld.cpp )
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC 
    ${CMAKE_SYSROOT}/usr/include/glib-2.0 
    ${CMAKE_SYSROOT}/usr/lib/glib-2.0/include
    ${PROJECT_BINARY_DIR}/include)
        

#installs
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION "bin")
