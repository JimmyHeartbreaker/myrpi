DESCRIPTION = "A friendly program that prints Hello World written in assembly!"
PRIORITY = "optional"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://helloworld.S"

S = "${WORKDIR}"
do_compile() {
${AS} helloworld.S -o helloworld-asm.o
${LD} helloworld-asm.o -o helloworld-asm
}
do_install() {
install -d ${D}${bindir}
install -m 0755 helloworld-asm ${D}${bindir}
}
