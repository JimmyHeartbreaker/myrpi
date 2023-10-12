cmake_minimum_required(VERSION 3.10)

project(mydriver LANGUAGES C CXX ASM VERSION 1.0)

SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)

#test program    
find_package(GTest REQUIRED)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

include(GoogleTest)
enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)  

add_executable(${PROJECT_NAME}_Tests tests/dev_nr_tests.cpp )
target_link_libraries(${PROJECT_NAME}_Tests PUBLIC GTest::gtest_main)

# Generate the Kbuild file through cmake.
FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/src/Kbuild "obj-m += mydriver.o dev_nr.o")

string(REPLACE "g++" "" TOOLCHAIN_PREFIX ${CMAKE_CXX_COMPILER})
message(${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command(OUTPUT cleaned
        COMMAND make ARCH=arm64 CROSS_COMPILE=${TOOLCHAIN_PREFIX} -C ${KERNELHEADERS_DIR} clean M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}/src
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${PROJECT_NAME}_Tests VERBATIM)

add_custom_command(OUTPUT mydriver.ko dev_nr.ko
        COMMAND make ARCH=arm64 CROSS_COMPILE=${TOOLCHAIN_PREFIX} -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}/src
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS cleaned VERBATIM)

add_custom_target(dev_nr ALL DEPENDS dev_nr.ko)
#add_custom_target(read_write ALL DEPENDS read_write.ko)
add_custom_target(mydriver ALL DEPENDS mydriver.ko)
#add_custom_target(gpio_driver ALL DEPENDS gpio_driver.ko)


install(FILES build/mydriver.ko build/dev_nr.ko DESTINATION "modules")