source sources/poky/oe-init-build-env qemu-build
bitbake helloworld
scp -r /home/jameshardaker/raspberryPi4/qemu-build/tmp-glibc/work/cortexa57-oe-linux/helloworld/0.1-r0/image/usr/bin/helloworld root@192.168.7.2:/usr/bin/