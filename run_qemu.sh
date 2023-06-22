ip link add br0 type bridge
ip link set br0 up
# According to Arch wiki eth0 needs to be up
ip link set enp0s3 up
ip link set enp0s3 master br0

# Drop existing IP from eth0
ip addr flush dev enp0s3

# Assign IP to br0
ip addr add 192.168.7.1/24 brd + dev br0
ip route add default via 192.168.7.2 dev br0

ip tuntap add dev tap0 mode tap user jameshardaker
ip link set dev tap0 up
ip link set tap0 master br0

sudo qemu-system-aarch64 \
	-device virtio-net-pci,netdev=net0,mac=52:54:00:12:34:02 \
	-netdev tap,id=net0,ifname=tap0,script=no,downscript=no \
	-object rng-random,filename=/dev/urandom,id=rng0 \
	-device virtio-rng-pci,rng=rng0 \
	-drive id=disk0,file=/home/jameshardaker/raspberryPi4/qemu-build/tmp-glibc/deploy/images/qemuarm64/mypi-qemu-image-qemuarm64.ext4,if=none,format=raw \
	-device virtio-blk-pci,drive=disk0 -device qemu-xhci -device usb-tablet -device usb-kbd  \
	-machine virt \
	-cpu cortex-a57 \
	-smp 4 \
	-m 512 \
	-serial mon:stdio \
	-serial null \
	-display gtk,gl=on \
	-device virtio-gpu-gl-pci \
	-kernel /home/jameshardaker/raspberryPi4/qemu-build/tmp-glibc/deploy/images/qemuarm64/Image \
	-append 'root=/dev/vda rw  mem=512M ip=192.168.7.2::192.168.7.1:255.255.255.0::eth0:off:8.8.8.8 console=ttyAMA0 console=hvc0  '