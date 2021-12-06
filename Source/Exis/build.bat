@echo off

set Sources="UEFI\Graphics.c" "Kernel.c" "Debug\Console.c" "Memory\Allocator\Bump.c" "ACPI\ACPI.c" "CPU\GDT.c"
set Objects="Graphics.o" "Kernel.o" "Console.o" "Bump.o" "ACPI.o" "AsmLib.o" "GDT.o"

:: Kernel Asm lang part
clang -c -m64 "CPU\AsmLib.S" -mllvm --x86-asm-syntax=intel --target=i686-pc-none-elf


:: Kernel C lang part
clang -c -m64 --target=i686-pc-none-elf -Wall -Werror -ffreestanding -fno-pic -fno-builtin -nostdlib -nostdinc -O2 -flto -g %Sources%
ld.lld --strip-all -nostdlib -T link.ld %Objects% -o Kernel.elf

copy "Kernel.elf" "C:\!Pro\Repo\VisualUefi\samples\x64\Release" /y