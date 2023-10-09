# the name of the target operating system
set(CMAKE_SYSTEM_NAME Linux)

# which compilers to use for C and C++

set(CMAKE_C_COMPILER   ${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/cortexa57-oe-linux/gcc-runtime/13.2.0/recipe-sysroot-native/usr/bin/aarch64-oe-linux/aarch64-oe-linux-gcc)
set(CMAKE_CXX_COMPILER ${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/cortexa57-oe-linux/gcc-runtime/13.2.0/recipe-sysroot-native/usr/bin/aarch64-oe-linux/aarch64-oe-linux-g++)

# where is the target environment located
if("${PROJECT_NAME}" STREQUAL  "CMAKE_TRY_COMPILE")
    set(CMAKE_FIND_ROOT_PATH "${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/cortexa57-oe-linux/helloworld/0.1/recipe-sysroot")
    set(CMAKE_SYSROOT  "${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/cortexa57-oe-linux/helloworld/0.1/recipe-sysroot")
else()
    set(CMAKE_FIND_ROOT_PATH ${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/cortexa57-oe-linux/${PROJECT_NAME}/0.1/recipe-sysroot)
    set(CMAKE_SYSROOT ${CMAKE_CURRENT_LIST_DIR}/../tmp-glibc/work/cortexa57-oe-linux/${PROJECT_NAME}/0.1/recipe-sysroot)
endif("${PROJECT_NAME}" STREQUAL  "CMAKE_TRY_COMPILE")




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


