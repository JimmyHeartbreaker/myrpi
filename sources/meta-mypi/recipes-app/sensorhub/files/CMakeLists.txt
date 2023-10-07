cmake_minimum_required(VERSION 3.10)

project(sensorhub LANGUAGES C CXX ASM VERSION 1.0)


message(CMAKE_SYSROOT: ${CMAKE_SYSROOT})

SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)

#test program    
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

include(GoogleTest)
enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)  

add_executable(${PROJECT_NAME}_Tests tests/unittestexample.cpp  )
target_link_libraries(${PROJECT_NAME}_Tests PUBLIC GTest::gtest_main)


configure_file(include/sensorhub_config.h.in include/sensorhub_config.h)

#main executable
add_executable(${PROJECT_NAME} src/sensorhub.cpp )
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SYSROOT}/usr/include/glib-2.0 
    ${CMAKE_SYSROOT}/usr/lib/glib-2.0/include
    ${PROJECT_BINARY_DIR}/include)
        

#installs
install(TARGETS ${PROJECT_NAME} DESTINATION "bin")
