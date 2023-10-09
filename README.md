# myrpi

# setup (WIP)

- Run Ubuntu 23.04 in VirtualBox or full os. I used VirtualBox.
- Install vscode https://code.visualstudio.com/docs/setup/linux or maybe https://linuxize.com/post/how-to-install-visual-studio-code-on-ubuntu-20-04/
- install gh
- for github authentication run: gh auth login
- Pull this repository into a handy folder, pull any submodules. See .gitmodules
- install the following tools:  chrpath diffstat gawk lz4c
- try bitbake qemu-build
      navigate to root folder in terminal
  
      source sources/poky/oe-init-build-env qemu-build
  
      bitbake mypi-qemu-image
  
# vscode setup  (WIP)
- Install through terminal cmake, cmake-extras, ninja-build, gtk+-3.0, libboost-all-dev
- launch vscode
- Install extensions in vscode - cmake, cmake tools, cmake language support, cmake integration,  C/C++ Extension Pack, testmate
- open workspace: rpi.code-workspace
- allow cmake to guess which cmakelists.txt to use, this should reconfigure the config cmake.sourceDirectory to your absolute folder
- vscode might prompt you to install .net runtime components, do this. If it fails go here and install manually https://learn.microsoft.com/en-us/dotnet/core/install/linux-scripted-manual#scripted-install

  

