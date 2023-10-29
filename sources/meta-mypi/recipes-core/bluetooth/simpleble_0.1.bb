DESCRIPTION = "Simple ble library"
PRIORITY = "optional"
SECTION = "libraries"
DEBUG_BUILD="1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
PR = "r1"
SRCREV = "${AUTOREV}"

SRC_URI = "git://github.com/OpenBluetoothToolbox/SimpleBLE.git;protocol=https;branch=main"
SRC_URI[sha256sum] = "6e4f3f759f97f0c36eafe249e98de085420a302da725ea4eafbe1eaed87f0782"


S = "${WORKDIR}/git/simpleble"


inherit cmake pkgconfig 

DEPENDS = "dbus fmt"

PACKAGE_DEBUG_SPLIT_STYLE = "debug-without-src"
EXTRA_OECMAKE = " \
                 -DCMAKE_SYSROOT=recipe-sysroot \    
                 -DLIBFMT_VENDORIZE=OFF \             
                 "

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"