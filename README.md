# myrpi

# setup (WIP)

- Run Ubuntu 23.04 in VirtualBox or full os. I used VirtualBox.
- Install vscode https://code.visualstudio.com/docs/setup/linux
- install gh
- for github authentication run: gh auth login
- Pull this repository into a handy folder, pull any submodules. See .gitmodules
- install the following tools:  chrpath diffstat gawk lz4c
- try bitbake qemu-build
      navigate to root folder in terminal
  
      source sources/poky/oe-init-build-env qemu-build
  
      bitbake mypi-qemu-image
  
# vscode setup  (WIP)
- launch vscode
- Install extensions in vscode - cmake, cmake tools, cmake language support, cmake integration, cmake test explorer, C/C++ Extension Pack
- open a CmakeLists.txt
- vscode might prompt you to install .net runtime components, do this. If it fails go here and install manually https://learn.microsoft.com/en-us/dotnet/core/install/linux-scripted-manual#scripted-install
  

