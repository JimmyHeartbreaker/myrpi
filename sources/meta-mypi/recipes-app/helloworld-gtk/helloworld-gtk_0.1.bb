DESCRIPTION = "Simple GTK 3.0 Hello World Application"
PRIORITY = "optional"
SECTION = "examples"
DEBUG_BUILD="1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://helloworld-gtk.c"

S = "${WORKDIR}"

inherit pkgconfig

DEPENDS = "gtk+3"

do_compile() {
    
    bbplain "${CC} ${CFLAGS} ${LDFLAGS} helloworld-gtk.c -o helloworld-gtk `pkg-config --cflags --libs gtk+-3.0`"    
    ${CC} ${CFLAGS} ${LDFLAGS} helloworld-gtk.c -o helloworld-gtk `pkg-config --cflags --libs gtk+-3.0` -lwayland-client
}
do_install() { 

    install -d ${D}${bindir}
    bbplain "install -d ${D}${bindir}";

    install -m 0755 helloworld-gtk ${D}${bindir}
    bbplain "install -m 0755 helloworld-gtk ${D}${bindir}";
}
FILES_${PN} += "${bindir}/helloworld-gtk"