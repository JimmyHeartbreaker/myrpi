# myrpi
This is a project for developing prototype applications for my custom distro built ontop of open embedded layer. Targetting raspberry-pi 4b

Starfield is an app that renders a basic starfield as you move through it. Uses ARM Neon SIMD library.

Helloworld demonstrates some x86 and Arm assembly

Sensorhub is in progress and will be taking data from my arduino over bluetooh and sending it to azure. A later version of this will deploy Azure IoT Edge to raspberry pi.

Mydriver is for learning how to develop and deploy drivers in linux.


# setup

- Run Ubuntu 22.04 in VirtualBox or full os. I used VirtualBox. 
- Install vscode https://code.visualstudio.com/docs/setup/linux or maybe https://linuxize.com/post/how-to-install-visual-studio-code-on-ubuntu-20-04/
- install gh
- for github authentication run: gh auth login
- Clone this repository into a handy folder, clone any submodules.

      git clone https://github.com/JimmyHeartbreaker/myrpi.git <folderName>
      
      cd <folderName>
  
      git submodule init
  
      git submodule update
- install the following tools:  chrpath diffstat gawk lz4 g++ make
- try bitbake qemu-build
      navigate to root folder in terminal
  
      source sources/poky/oe-init-build-env qemu-build
  
      bitbake mypi-qemu-image
- try bitbake rpi-build (for physical deployment)
      navigate to root folder in terminal
  
      source sources/poky/oe-init-build-env rpi-build
  
      bitbake mypi-rpi-image
  
# vscode setup 
- Install through terminal cmake, cmake-extras, pkg-config, ninja-build, libgtk-3-dev, libgtest-dev, gdb, curl, openssl, libcurl4-openssl-dev, libssl-dev
- launch vscode
- Install extensions in vscode - cmake, cmake tools, cmake language support, cmake integration,  C/C++ Extension Pack, testmate
- open workspace: rpi.code-workspace
- allow cmake to guess which cmakelists.txt to use, this should reconfigure the config cmake.sourceDirectory to your absolute folder
- vscode might prompt you to install .net runtime components, do this. If it fails go here and install manually https://learn.microsoft.com/en-us/dotnet/core/install/linux-scripted-manual#scripted-install

# qemu setup
 - QEMU is included in the recipes and should be built as part of the above steps. Last time i did a fresh install I had some issues with some dependencies that were not on my system - the error logs are clear, just install whatever it says.
 - To run qemu for this setup i recommend execuiting "run_qemu.sh" in the root folder.

   
  

