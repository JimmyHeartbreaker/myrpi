cmake_minimum_required(VERSION 3.10)

project(mydriver LANGUAGES C CXX ASM VERSION 1.0)


# Generate the Kbuild file through cmake.
FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/src/Kbuild "obj-m += mydriver.o dev_nr.o")

string(REPLACE "g++" "" TOOLCHAIN_PREFIX ${CMAKE_CXX_COMPILER})
message(${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command(OUTPUT cleaned
        COMMAND make ARCH=arm64 CROSS_COMPILE=${TOOLCHAIN_PREFIX} -C ${KERNELHEADERS_DIR} clean M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}/src
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS src/mydriver.c VERBATIM)

add_custom_command(OUTPUT mydriver.ko dev_nr.ko
        COMMAND make ARCH=arm64 CROSS_COMPILE=${TOOLCHAIN_PREFIX} -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}/src
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS cleaned VERBATIM)

add_custom_target(dev_nr ALL DEPENDS dev_nr.ko)
add_custom_target(mydriver ALL DEPENDS mydriver.ko)

install(FILES build/mydriver.ko DESTINATION "modules")
install(FILES build/dev_nr.ko DESTINATION "modules")