DESCRIPTION = "Simple GTK 3.0 Hello World Application"
PRIORITY = "optional"
SECTION = "examples"
DEBUG_BUILD="1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://main.cpp \
           file://starfield-debug.sh \
           "

S = "${WORKDIR}"

inherit pkgconfig

DEPENDS = "gtk+3"
do_compile() {
    
    bbplain "${CC} ${CFLAGS} ${LDFLAGS} main.cpp -o starfield `pkg-config --cflags --libs gtk+-3.0` -lwayland-client -lstdc++"    
    ${CC} ${CFLAGS} ${LDFLAGS} main.cpp -o starfield `pkg-config --cflags --libs gtk+-3.0` -lwayland-client -lstdc++
}
do_install() { 

    bbplain "install -d ${D}${bindir}";
    install -d ${D}${bindir}

    bbplain "install -m 0755 starfield ${D}${bindir}";
    install -m 0755 starfield ${D}${bindir}

    bbplain "install -m 0755 starfield-debug.sh ${D}${bindir}";
    install -m 0755 starfield-debug.sh ${D}${bindir}
}

FILES:${PN} += "${bindir}/starfield"
RDEPENDS:${PN} += "bash"