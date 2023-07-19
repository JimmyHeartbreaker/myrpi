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
message(STATUS ${KERNELHEADERS_DIR} )
set(TOOLCHAIN_PREFIX /home/jameshardaker/raspberryPi4/qemu-build/tmp-glibc/sysroots-components/x86_64/gcc-cross-aarch64/usr/bin/aarch64-oe-linux/aarch64-oe-linux-)

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