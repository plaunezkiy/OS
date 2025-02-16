1. Make a change

2. Update the configs

3. Compile the kernel
`time make -j(#threads)`

4. Run the kernel
```qemu-system-x86_64 -m 4G -smp 4 -drive file=debian.qcow2 -kernel linux-6.13/arch/x86/boot/bzImage -append 'root=/dev/sda1 console=ttyS0 nokaslr' -nographic -S -gdb tcp::1104```