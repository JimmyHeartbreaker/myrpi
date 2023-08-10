cmake_minimum_required(VERSION 3.10)

project(mydriver LANGUAGES C CXX ASM VERSION 1.0)

set(DRIVER_FILE mydriver.ko)

# Generate the Kbuild file through cmake.
FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild "obj-m := mydriver.o")

string(REPLACE "g++" "" TOOLCHAIN_PREFIX ${CMAKE_CXX_COMPILER})

add_custom_command(OUTPUT ${DRIVER_FILE}
        COMMAND make ARCH=arm64 CROSS_COMPILE=${TOOLCHAIN_PREFIX} -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}      
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}  
        DEPENDS mydriver.c VERBATIM)

add_custom_target(mydriver ALL DEPENDS ${DRIVER_FILE}) 

install(FILES build/mydriver.ko DESTINATION "modules")