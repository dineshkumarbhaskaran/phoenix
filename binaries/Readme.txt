Download the linux kernel from 

1. https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.8.11.tar.xz 

Preparing 32bit environment
2. Compile kernel for 32bit as 
   a. make CROSS_COMPILE=arm-linux-gnueabihf- ARCH=arm bcm2709_defconfig
   b. make CROSS_COMPILE=arm-linux-gnueabihf- ARCH=arm -j4
   c. make CROSS_COMPILE=arm-linux-gnueabihf- ARCH=arm modules_install INSTALL_MOD_PATH=<mod_install_path>
 
Preparing 64bit environment
3. Compile kernel for 64 bit
   a. make CROSS_COMPILE=aarch64-linux-gnu- ARCH=arm64 bcmrpi3_defconfig
   b. make CROSS_COMPILE=aarch64-linux-gnu- ARCH=arm64 -j4
   c. make CROSS_COMPILE=aarch64-linux-gnu- ARCH=arm64 modules_install INSTALL_MOD_PATH=<mod_install_path>

Preparing the SD card
1. Create two partitions 
   a. First partition can be of 100MB and second partition can be of any size 
        1. make sure to toggle the partition 1 to Id 'c' i.e. W95 FAT32 (LBA) 
        2. make sure to set the partition 1 to bootable using fdisk option 'a'
   b  sudo mkfs.vfat -n boot /dev/sd<n>1
   c. sudo mkfs.ext3 /dev/sd<n>2

2. Extract contents of linaro-jessie-developer-20160913-31.tar.gz/
    linaro-jessie-developer-20161006-97.tar.gz to second partition
   a. cp the contents of lib/modules to second partition's /lib directory.
 
3. Move contents of boot_32/boot_64 to first partition

4. 32 bits boots out of the box.

5. 64 bit boots happens through u-boot, once at the prompt execute "run rpi_boot"

Reference
https://www.raspberrypi.org/forums/viewtopic.php?f=72&t=143765
