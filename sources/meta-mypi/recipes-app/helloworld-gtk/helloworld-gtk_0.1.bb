DESCRIPTION = "Simple GTK 3.0 Hello World Application"
PRIORITY = "optional"
SECTION = "examples"
DEBUG_BUILD="1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://helloworld-gtk.c \
           file://helloworld-gtk-debug.sh \           
            file://CMakeLists.txt \
           "

S = "${WORKDIR}"


inherit cmake pkgconfig

PACKAGE_DEBUG_SPLIT_STYLE = "debug-without-src"

DEPENDS = "gtk+3 shared-mime-info"



EXTRA_OECMAKE = ""

FILES:${PN} += "/usr/bin/helloworld-gtk"
FILES:${PN} += "/usr/bin/helloworld-gtk-debug.sh"

