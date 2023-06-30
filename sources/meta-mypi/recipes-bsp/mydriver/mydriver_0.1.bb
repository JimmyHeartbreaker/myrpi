DESCRIPTION = "Simple Driver example"
PRIORITY = "optional"
SECTION = "examples"
DEBUG_BUILD="1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://mydriver.c \
           "

S = "${WORKDIR}"

do_compile() {
    
    bbplain "${CC} ${CFLAGS} ${LDFLAGS} mydriver.c -o mydriver"    
    ${CC} ${CFLAGS} ${LDFLAGS} mydriver.c -o mydriver
}
do_install() { 

    bbplain "install -d ${D}${bindir}";
    install -d ${D}${bindir}

    bbplain "install -m 0755 mydriver ${D}${bindir}";
    install -m 0755 mydriver ${D}${bindir}

}

FILES:${PN} += "${bindir}/mydriver"
RDEPENDS:${PN} += "bash"