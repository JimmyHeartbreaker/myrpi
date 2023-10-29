# !/bin/bash

# if [[ $EUID > 0 ]]
#   then echo "Run this script as root"
#   exit
# fi

# BRIDGE="br0"
# TAP="tap0"
# INTERFACE="wlp1s0"

# echo "Adding bridge $BRIDGE"
# ip link add name $BRIDGE type bridge

# echo "Flushing interface $INTERFACE"
# ip addr flush dev $INTERFACE

# echo "Setting $BRIDGE as master of $INTERFACE"
# ip link set $INTERFACE master $BRIDGE

# echo "Adding tap $TAP"
# ip tuntap add $TAP mode tap

# echo "Setting $BRIDGE as master of $TAP"
# ip link set $TAP master $BRIDGE

# echo "Setting $INTERFACE, $BRIDGE and $TAP up"
# ip link set up dev $INTERFACE
# ip link set up dev $TAP
# ip link set up dev $BRIDGE

# echo "Stopping NetworkManager"
# systemctl stop NetworkManager

# echo "1Requesting ip for $BRIDGE"
# dhclient $BRIDGE

# if [ $? -eq 0 ]; then
#     echo "Requesting ip for $INTERFACE"
#     dhclient $INTERFACE
#     echo "Killing dhclient and starting NetworkManager"
#     pkill -9 dhclient
#     systemctl start NetworkManager
# fi

# ip link delete br0
# ip link delete tap0

# ip link add br0 type bridge
# ip link set br0 up

# # Assign IP to br0
# ip addr add 192.168.7.1/24 brd + dev br0
# ip route add default via 192.168.7.2 dev br0

# ip tuntap add dev tap0 mode tap user jameshardaker
# ip link set dev tap0 up
# ip link set tap0 master br0

# ip link set br0 down
# ip link set br0 up

sudo ./qemu-build/tmp-glibc/sysroots-components/x86_64/qemu-system-native/usr/bin/qemu-system-aarch64 \
	-netdev tap,id=mynet0,ifname=tap0,script=no,downscript=no \
	-device virtio-net-pci,netdev=mynet0,mac=52:55:00:d1:55:01 \
	-object rng-random,filename=/dev/urandom,id=rng0 \
	-device virtio-rng-pci,rng=rng0 \
	-drive id=disk0,file=./qemu-build/tmp-glibc/deploy/images/qemuarm64/mypi-qemu-image-qemuarm64.ext4,if=none,format=raw \
	-device virtio-blk-pci,drive=disk0 \
	-device qemu-xhci \
	-device usb-tablet \
	-device usb-kbd  \
	-machine virt \
	-bt hci,host \
	-cpu cortex-a57 \
	-smp 4 \
	-m 512 \
	-serial mon:stdio \
	-serial null \
	-display gtk \
	-device virtio-gpu-pci \
	-kernel ./qemu-build/tmp-glibc/deploy/images/qemuarm64/Image \
	-append 'root=/dev/vda rw  mem=512M console=ttyAMA0 console=hvc0  ' \
	-nic user,hostfwd=tcp::8888-:1234,hostfwd=tcp::22-:22