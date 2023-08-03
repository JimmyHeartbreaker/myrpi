SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe created by bitbake-layers"
LICENSE = "MIT"

# Base this image on core-image-base
include recipes-graphics/images/core-image-weston.bb
inherit extrausers

EXTRA_USERS_PARAMS = " useradd ace; \
                       usermod  -p '\$6\$11223344\$YzaRt.fnidpXmKw.Dl20htfOrJ8X2Yx3V.h5zUlhlN2SdczempQmQcDcMYd6mHiXlaMqyGt200zDwuZiC8ZZw1' ace; \
                       usermod  -a -G sudo ace; \
                       "
#password
python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  Example recipe created by bitbake-layers QEMU  *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
