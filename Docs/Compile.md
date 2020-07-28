## Compilation method
C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis>clang -c --target=i686-pc-none-elf -march=i686 -Wall -Werror -ffreestanding -fno-pic -fno-builtin -nostdlib -nostdinc -Ikernel -O2 -flto -g Kernel.c

C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis>ld.lld -nostdlib -T link.ld Kernel.o -o Kernel.elf

## To remove symbols
--discard-all --strip-all

## 64 Kernel
C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis>clang -c -m64 --target=i686-pc-none-elf -Wall -Werror -ffreestanding -fno-pic -fno-builtin -nostdlib -nostdinc -Ikernel -O2 -flto -g Kernel.c

C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis>elf
'elf' is not recognized as an internal or external command,
operable program or batch file.

C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis>elf
'elf' is not recognized as an internal or external command,
operable program or batch file.

C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis>ld.lld -nostdlib -T link.ld Kernel.o -o Kernel.elf

C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis>ld.lld --strip-all -nostdlib -T link.ld Kernel.o -o Kernel.elf

C:\Users\MainDev\Documents\GitHub\exis-osdev\Source\Exis>