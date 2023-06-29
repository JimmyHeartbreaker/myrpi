
project(helloworld-gtk C CXX)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
cmake_minimum_required(VERSION 3.10)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)


set(LIBS cairo pixman fontconfig freetype directfb fusion direct libpng libxcb libxrender libx11 libxext zlib libgl mesa expat util-linux-libuuid zstd libcap
    libxau libxdmcp libdrm libxfixes libxxf86vm libxshmfence gtk+3 pango harfbuzz atk gdk-pixbuf gobject-introspection glib-2.0 libxrandr libxcursor systemd
    libxi libxcomposite libxdamage libatk-bridge libepoxy util-linux at-spi2-atk libxkbcommon wayland dbus libjpeg-turbo libpcre libffi fribidi at-spi2-core)
SET(LIBROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../qemu-build/tmp-glibc/sysroots-components/cortexa57)

foreach(LIB IN LISTS LIBS)
link_directories(${LIBROOT}/${LIB}/usr/lib)
link_directories(${LIBROOT}/${LIB}/lib)
endforeach()
add_executable(${CMAKE_PROJECT_NAME} helloworld-gtk.c)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC cairo ${GTK3_LIBRARIES})
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC
        -I${LIBROOT}/gtk+3/usr/include/gtk-3.0/
        -I${LIBROOT}/glib/usr/include/gtk-3.0/
        -I${LIBROOT}/glib-2.0/usr/lib/glib-2.0/include/
        -I${LIBROOT}/glib-2.0/usr/include/glib-2.0/
        -I${LIBROOT}/cairo/usr/include/cairo 
        -I${LIBROOT}/pango/usr/include/pango-1.0  
        -I${LIBROOT}/harfbuzz/usr/include/harfbuzz
        -I${LIBROOT}/gdk-pixbuf/usr/include/gdk-pixbuf-2.0
        -I${LIBROOT}/atk/usr/include/atk-1.0    
        )