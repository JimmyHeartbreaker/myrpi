# the name of the target operating system
set(CMAKE_SYSTEM_NAME Linux)

# which compilers to use for C and C++
file(GLOB_RECURSE CMAKE_C_COMPILER ${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/*/${PROJECT_NAME}/*/recipe-sysroot-native/usr/bin/aarch64-oe-linux/aarch64-oe-linux-gcc)

get_filename_component(GCC_DIR "${CMAKE_C_COMPILER}" DIRECTORY)
set(CMAKE_CXX_COMPILER ${GCC_DIR}/aarch64-oe-linux-g++)

# where is the target environment located
# where is the target environment located
if("${PROJECT_NAME}" STREQUAL  "CMAKE_TRY_COMPILE")
    file(GLOB CMAKELIST_PATH ${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/*/helloworld/*/CMakeLists.txt)        
else()
    file(GLOB CMAKELIST_PATH ${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/*/${PROJECT_NAME}/*/CMakeLists.txt)          
endif("${PROJECT_NAME}" STREQUAL  "CMAKE_TRY_COMPILE")

get_filename_component(PROJECT_DIR "${CMAKELIST_PATH}" DIRECTORY)

set(CMAKE_FIND_ROOT_PATH ${PROJECT_DIR}/recipe-sysroot)
set(CMAKE_SYSROOT  ${CMAKE_FIND_ROOT_PATH})




set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --sysroot=${CMAKE_FIND_ROOT_PATH}" CACHE INTERNAL "" FORCE)
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} --sysroot=${CMAKE_FIND_ROOT_PATH}" CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --sysroot=${CMAKE_FIND_ROOT_PATH}" CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} --sysroot=${CMAKE_FIND_ROOT_PATH}" CACHE INTERNAL "" FORCE)

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


