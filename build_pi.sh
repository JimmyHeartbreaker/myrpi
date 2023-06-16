source sources/poky/oe-init-build-env rpi-build
bitbake mypi-base-image
sudo umount /dev/sdb1
sudo umount /dev/sdb2
sudo bmaptool copy tmp-glibc/deploy/images/raspberrypi4-64/mypi-base-image-raspberrypi4-64.wic.bz2 /dev/sdb
sudo mount /dev/sdb1 /media/boot
sudo mount /dev/sdb2 /media/root
