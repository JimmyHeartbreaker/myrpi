#!/bin/bash

if [[ $EUID > 0 ]]
  then echo "Run this script as root"
  exit
fi

BRIDGE="br0"
TAP="tap0"
INTERFACE="enp0s3"

echo "Adding bridge $BRIDGE"
ip link add name $BRIDGE type bridge

echo "Flushing interface $INTERFACE"
ip addr flush dev $INTERFACE

echo "Setting $BRIDGE as master of $INTERFACE"
ip link set $INTERFACE master $BRIDGE

echo "Adding tap $TAP"
ip tuntap add $TAP mode tap

echo "Setting $BRIDGE as master of $TAP"
ip link set $TAP master $BRIDGE

echo "Setting $INTERFACE, $BRIDGE and $TAP up"
ip link set up dev $INTERFACE
ip link set up dev $TAP
ip link set up dev $BRIDGE

echo "Stopping NetworkManager"
systemctl stop NetworkManager

echo "Requesting ip for $BRIDGE"
dhclient $BRIDGE

if [ $? -eq 0 ]; then
    echo "Requesting ip for $INTERFACE"
    dhclient $INTERFACE
    echo "Killing dhclient and starting NetworkManager"
    pkill -9 dhclient
    systemctl start NetworkManager
fi

sudo ./qemu-build/tmp-glibc/sysroots-components/x86_64/qemu-system-native/usr/bin/qemu-system-aarch64 \
	-netdev tap,id=mynet0,ifname=tap0,script=no,downscript=no \
	-device virtio-net-pci,netdev=mynet0,mac=52:55:00:d1:55:01 \
	-object rng-random,filename=/dev/urandom,id=rng0 \
	-device virtio-rng-pci,rng=rng0 \
	-drive id=disk0,file=./qemu-build/tmp-glibc/deploy/images/qemuarm64/mypi-qemu-image-qemuarm64.rootfs.ext4,if=none,format=raw \
	-device virtio-blk-pci,drive=disk0 \
	-device qemu-xhci \
	-device usb-tablet \
	-device usb-kbd  \
	-machine virt \
	-cpu cortex-a57 \
	-smp 4 \
	-m 512 \
	-serial mon:stdio \
	-serial null \
	-display gtk \
	-device virtio-gpu-gl-pci \
	-kernel ./qemu-build/tmp-glibc/deploy/images/qemuarm64/Image \
	-append 'root=/dev/vda rw  mem=512M console=ttyAMA0 console=hvc0  '