cmake_minimum_required(VERSION 3.10)

project(mydriver LANGUAGES C CXX ASM VERSION 1.0)

#fudge to make it work between vscode/cmake and bitbake/cmake
if(NOT DEFINED CMAKE_SYSROOT)
    SET(CMAKE_SYSROOT ${CMAKE_CURRENT_SOURCE_DIR}/recipe-sysroot)
endif(NOT DEFINED CMAKE_SYSROOT)


# Find kernel headers
if(NOT DEFINED KERNELHEADERS_DIR )
        list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
        find_package(KernelHeaders REQUIRED)
        include_directories(${KERNELHEADERS_INCLUDE_DIRS})
endif(NOT DEFINED KERNELHEADERS_DIR )

set(DRIVER_FILE mydriver.ko)

# Generate the Kbuild file through cmake.
FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild "obj-m := mydriver.o")
string(REPLACE "g++" "" TOOLCHAIN_PREFIX ${CMAKE_CXX_COMPILER})
message(toolchainPrefix: ${TOOLCHAIN_PREFIX})
add_custom_command(OUTPUT cleaned
        COMMAND make ARCH=arm64 CROSS_COMPILE=${TOOLCHAIN_PREFIX} -C ${KERNELHEADERS_DIR} clean M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}      
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}  
        DEPENDS mydriver.c VERBATIM)

add_custom_command(OUTPUT ${DRIVER_FILE}
        COMMAND make ARCH=arm64 CROSS_COMPILE=${TOOLCHAIN_PREFIX} -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}      
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}  
        DEPENDS cleaned VERBATIM)

add_custom_target(mydriver ALL DEPENDS ${DRIVER_FILE})

install(FILES build/mydriver.ko DESTINATION "modules")