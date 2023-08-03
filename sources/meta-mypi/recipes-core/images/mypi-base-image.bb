SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe created by bitbake-layers"
LICENSE = "MIT"
IMAGE_FEATURES += "splash package-management ssh-server-dropbear hwcodecs weston"

QB_MEM = "-m 512"


# Base this image on core-image-base
include recipes-core/images/rpi-test-image.bb
inherit extrausers

EXTRA_USERS_PARAMS = " useradd ace; \
                       usermod  -p '\$6\$11223344\$YzaRt.fnidpXmKw.Dl20htfOrJ8X2Yx3V.h5zUlhlN2SdczempQmQcDcMYd6mHiXlaMqyGt200zDwuZiC8ZZw1' ace; \
                       usermod  -a -G sudo ace; \
                       usermod  -p '' root; \
                       "
# Define a variable to hold the list of systemd unit config files to be modified.
# Modify the serial console config and the video console config files.
TN_LOCAL_GETTY ?= " \
     ${IMAGE_ROOTFS}${systemd_system_unitdir}/getty@.service \
"
# Define a function that modifies the systemd unit config files with the autologin arguments
local_autologin () {
    sed -i -e 's/^\(ExecStart *=.*getty \)/\1--autologin root /' ${TN_LOCAL_GETTY}
}

# Add the function so that it is executed after the rootfs has been generated
ROOTFS_POSTPROCESS_COMMAND += "local_autologin; "

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  Example recipe created by bitbake-layers   *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build




