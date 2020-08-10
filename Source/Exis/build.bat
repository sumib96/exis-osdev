clang -c -m64 --target=i686-pc-none-elf -Wall -Werror -ffreestanding -fno-pic -fno-builtin -nostdlib -nostdinc -Ikernel -O2 -flto -g Kernel.c
ld.lld --strip-all -nostdlib -T link.ld Kernel.o -o Kernel.elf
copy "C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis\Kernel.elf" "C:\Users\MainDev\Desktop\VisualUefi-master\samples\x64\Release" /y