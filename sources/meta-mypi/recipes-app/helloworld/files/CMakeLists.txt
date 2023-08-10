cmake_minimum_required(VERSION 3.10)

project(helloworld LANGUAGES C CXX ASM VERSION 1.0)


message(CMAKE_SYSROOT: ${CMAKE_SYSROOT})

SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(PkgConfig REQUIRED)

#test program    
SET(Boost_USE_DEBUG_LIBS ON)
SET(Boost_USE_RELEASE_LIBS ON)
SET(Boost_USE_MULTITHREADED ON)

SET(PKG_CONFIG_PATH ${CMAKE_SYSROOT}/usr/lib/pkgconfig/)
find_package(Boost COMPONENTS system filesystem unit_test_framework)
SET(BOOST_LIBRARIES Boost::unit_test_framework Boost::system Boost::filesystem)

add_executable(TestProgram tests/unittestexample.cpp  )
target_link_libraries(TestProgram PUBLIC ${BOOST_LIBRARIES})



configure_file(include/helloworld_config.h.in include/helloworld_config.h)

#main executable
add_executable(${PROJECT_NAME} src/examples.cpp src/${CMAKE_SYSTEM_PROCESSOR}/examples.s src/helloworld.cpp )
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SYSROOT}/usr/include/glib-2.0 
    ${CMAKE_SYSROOT}/usr/lib/glib-2.0/include
    ${PROJECT_BINARY_DIR}/include)
        

#installs
install(TARGETS ${PROJECT_NAME} DESTINATION "bin")
