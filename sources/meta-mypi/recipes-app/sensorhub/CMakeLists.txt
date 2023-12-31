cmake_minimum_required(VERSION 3.10)

project(sensorhub LANGUAGES C CXX ASM VERSION 1.0)



SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)
find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)


#test program    
find_package(GTest REQUIRED)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

include(GoogleTest)
#enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)  

add_executable(${PROJECT_NAME}_Tests tests/unittestexample.cpp  )

target_link_libraries(${PROJECT_NAME}_Tests PUBLIC GTest::gtest_main)



configure_file(include/sensorhub_config.h.in include/sensorhub_config.h)
#main executable
add_executable(${PROJECT_NAME} src/sensorhub.cpp )
target_link_libraries(${PROJECT_NAME} PUBLIC  
iothub_client prov_device_client iothub_client_mqtt_transport prov_auth_client umqtt 
hsm_security_client utpm dl aziotsharedutil parson pthread curl OpenSSL::SSL OpenSSL::Crypto m 
serializer
  
  )
  
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CURL_INCLUDE_DIR}
    ${CMAKE_SYSROOT}/usr/include/glib-2.0 
    ${CMAKE_SYSROOT}/usr/lib/glib-2.0/include
    ${CMAKE_SYSROOT}/usr/include/azureiot
    ${CMAKE_SYSROOT}/usr/local/include/azureiot
    ${PROJECT_BINARY_DIR}/include)
        

#installs
install(TARGETS ${PROJECT_NAME} DESTINATION "bin")
