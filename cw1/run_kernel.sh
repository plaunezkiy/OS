qemu-system-x86_64 -m 4G -smp 4 -drive file=/home/os/debian.qcow2 \
 -kernel /home/os/linux-cw1/arch/x86/boot/bzImage \
 -append 'root=/dev/sda1 console=ttyS0 nokaslr' \
 -nographic -S -gdb tcp::1104