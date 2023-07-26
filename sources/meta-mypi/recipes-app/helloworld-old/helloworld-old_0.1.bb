DESCRIPTION = "A friendly program that prints Hello World!"
PRIORITY = "optional"
SECTION = "examples"
DEBUG_BUILD="1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://helloworld.c"

S = "${WORKDIR}"
do_compile() {
    
    bbplain "${CC} ${CFLAGS} ${LDFLAGS} helloworld.c -o helloworld"    
    ${CC} ${CFLAGS} ${LDFLAGS} helloworld.c -o helloworld
}
do_install() { 

    install -d ${D}${bindir}
    bbplain "install -d ${D}${bindir}";

    install -m 0755 helloworld ${D}${bindir}
    bbplain "install -m 0755 helloworld ${D}${bindir}";
}

FILES_${PN} += "${bindir}/helloworld"