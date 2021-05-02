@echo off

set Sources="UEFI\Graphics.c" "Kernel.c" "Debug\Console.c" "Memory\Allocator\Bump.c"
set Objects="Graphics.o" "Kernel.o" "Console.o" "Bump.o"

clang -c -m64 --target=i686-pc-none-elf -Wall -Werror -ffreestanding -fno-pic -fno-builtin -nostdlib -nostdinc -O2 -flto -g %Sources%
ld.lld --strip-all -nostdlib -T link.ld %Objects% -o Kernel.elf

copy "Kernel.elf" "C:\!Pro\Repo\VisualUefi\samples\x64\Release" /y