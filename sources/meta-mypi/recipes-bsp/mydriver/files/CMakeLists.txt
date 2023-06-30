set(CMAKE_SYSTEM_PROCESSOR aarch64)
cmake_minimum_required(VERSION 3.10)

project(mydriver VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find kernel headers
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(KernelHeaders REQUIRED)
include_directories(${KERNELHEADERS_INCLUDE_DIRS})

set(DRIVER_FILE mydriver.ko)


# Generate the Kbuild file through cmake.
FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild "obj-m := mydriver.o")

add_custom_command(OUTPUT ${DRIVER_FILE}
        COMMAND make -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS mydriver.c VERBATIM)

add_custom_target(mydriver ALL DEPENDS ${DRIVER_FILE})
