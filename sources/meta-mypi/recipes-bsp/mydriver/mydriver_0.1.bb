SUMMARY = "Simple driver examples"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
INHIBIT_PACKAGE_STRIP = "1"
SRC_URI = "\
            file://CMakeLists.txt \
            file://src/ \
            file://tests/ \
        "

S = "${WORKDIR}"

inherit module kernel-module-split cmake

RPROVIDES:${PN} = "kernel-module-mydriver" 

EXTRA_OECMAKE = " \
                 -DKERNELHEADERS_DIR=./../../../../../work-shared/${MACHINE}/kernel-build-artifacts/ \
                 -DKERNELHEADERS_INCLUDE_DIRS=  ./../../../../../work-shared/${MACHINE}/kernel-source/arch/arm64/include/ \
                 "

FILES:${PN} += "/usr/modules/mydriver.ko"
FILES:${PN} += "/usr/modules/dev_nr.ko"
FILES:${PN} += "/usr/modules/read_write.ko"
FILES:${PN} += "/usr/modules/gpio_driver.ko"

DEPENDS = "googletest"