echo "filename: $1";
echo "workspaceFolder: $2";
source $2/sources/poky/oe-init-build-env qemu-build
bitbake $1
scp -r $2/qemu-build/tmp-glibc/work/cortexa57-oe-linux/$1/0.1-r0/image/usr/bin/$1 root@192.168.7.2:/usr/bin/