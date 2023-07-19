# Find the kernel release
execute_process(
        COMMAND uname -r
        OUTPUT_VARIABLE KERNEL_RELEASE
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Find the headers
find_path(KERNELHEADERS_DIR
        include/linux/user.h
        PATHS /home/jameshardaker/raspberryPi4/qemu-build/tmp-glibc/work-shared/qemuarm64/kernel-source/
        NO_CMAKE_FIND_ROOT_PATH
        )

SET(KERNELHEADERS_DIR /home/jameshardaker/raspberryPi4/qemu-build/tmp-glibc/work-shared/qemuarm64/kernel-build-artifacts/)
message(STATUS "Kernel release: ${KERNEL_RELEASE}")
message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}")

if (KERNELHEADERS_DIR)
    set(KERNELHEADERS_INCLUDE_DIRS
    #    /home/jameshardaker/raspberryPi4/qemu-build/tmp-glibc/work-shared/qemuarm64/kernel-source/include/
        /home/jameshardaker/raspberryPi4/qemu-build/tmp-glibc/work-shared/qemuarm64/kernel-source/arch/arm64/include/
            CACHE PATH "Kernel headers include dirs"
            )
    set(KERNELHEADERS_FOUND 1 CACHE STRING "Set to 1 if kernel headers were found")
else (KERNELHEADERS_DIR)
    set(KERNELHEADERS_FOUND 0 CACHE STRING "Set to 1 if kernel headers were found")
endif (KERNELHEADERS_DIR)

mark_as_advanced(KERNELHEADERS_FOUND)
