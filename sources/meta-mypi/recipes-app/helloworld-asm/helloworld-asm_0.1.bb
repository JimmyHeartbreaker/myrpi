DESCRIPTION = "A friendly program that prints Hello World written in assembly!"
PRIORITY = "optional"
SECTION = "examples"
DEBUG_BUILD="1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://helloworld.S"

S = "${WORKDIR}"

do_compile() {

    #${AS} helloworld.S -o helloworld-asm.o
    #bbplain "${AS} helloworld.S -o helloworld-asm.o"
    
    #{LD} helloworld-asm.o -o helloworld-asm
    #bbplain "${LD} helloworld-asm.o -o helloworld-asm"

     
    bbplain "${CC} ${CFLAGS} ${LDFLAGS} helloworld.S -o helloworld-asm"
    ${CC} ${CFLAGS} ${LDFLAGS} helloworld.S -o helloworld-asm
}
do_install() {
    install -d ${D}${bindir}
    bbplain "install -d ${D}${bindir}"

    install -m 0755 helloworld-asm ${D}${bindir}
    bbplain "install -m 0755 helloworld-asm ${D}${bindir}"
}
