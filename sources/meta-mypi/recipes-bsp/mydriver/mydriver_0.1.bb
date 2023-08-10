SUMMARY = "Simple Hello World Cmake application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
INHIBIT_PACKAGE_STRIP = "1"
SRC_URI = "\
            file://CMakeLists.txt \
            file://mydriver.c \
            file://cmake/FindKernelHeaders.cmake \
        "

S = "${WORKDIR}"

inherit module kernel-module-split cmake

RPROVIDES:${PN} = "kernel-module-mydriver" 
KERNEL_MODULE_AUTOLOAD += " mydriver "

EXTRA_OECMAKE = " \
                 -DKERNELHEADERS_DIR=./../../../../../work-shared/${MACHINE}/kernel-build-artifacts/ \
                 -DKERNELHEADERS_INCLUDE_DIRS=  ./../../../../../work-shared/${MACHINE}/kernel-source/arch/arm64/include/ \
                 "

FILES:${PN} = "/usr/modules/mydriver.ko"