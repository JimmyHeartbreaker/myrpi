cmake_minimum_required(VERSION 3.10)

project(sensorhub LANGUAGES C CXX ASM VERSION 1.0)


message(CMAKE_SYSROOT: ${CMAKE_SYSROOT})

SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)
#find_library(WASTORAGE_LIBRARY azurestorage)
#find_package(iothub_client REQUIRED)


#azure-identity-cpp
#azure-security-attestation-cpp
#azure-security-keyvault-certificates-cpp
#azure-security-keyvault-keys-cpp
#azure-security-keyvault-secrets-cpp
#azure-storage-blobs-cpp
#azure-storage-files-datalake-cpp
#azure-storage-files-shares-cpp
#azure-storage-queues-cpp

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
#target_link_directories()
target_link_libraries(${PROJECT_NAME} PUBLIC iothub_client)
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SYSROOT}/usr/include/glib-2.0 
    ${CMAKE_SYSROOT}/usr/lib/glib-2.0/include
    /home/JimmyHeartbreaker/repositories/myrpi/sources/azure-iot-sdk-c/c-utility/inc
    /home/JimmyHeartbreaker/repositories/myrpi/sources/azure-iot-sdk-c/iothub_client/inc
    /home/JimmyHeartbreaker/repositories/myrpi/sources/azure-iot-sdk-c/deps/azure-macro-utils-c/inc
    /home/JimmyHeartbreaker/repositories/myrpi/sources/azure-iot-sdk-c/deps/umock-c/inc
    /home/JimmyHeartbreaker/repositories/myrpi/sources/azure-iot-sdk-c/serializer/inc
    ${PROJECT_BINARY_DIR}/include)
        

#installs
install(TARGETS ${PROJECT_NAME} DESTINATION "bin")
