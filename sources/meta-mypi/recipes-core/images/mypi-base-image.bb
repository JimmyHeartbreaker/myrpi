SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe created by bitbake-layers"
LICENSE = "MIT"
IMAGE_FEATURES += "splash package-management ssh-server-dropbear hwcodecs weston"
CORE_IMAGE_BASE_INSTALL += "${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'weston-xwayland matchbox-terminal', '', d)}"


# Base this image on core-image-base
include recipes-core/images/rpi-test-image.bb

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  Example recipe created by bitbake-layers   *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
