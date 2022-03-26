@echo off

set ClangRoot=C:\Program Files\LLVM\bin
set ProjectRoot=C:\Users\faszomat\Desktop\Repo
cd /D %ProjectRoot%\exis-osdev\Source\Exis

set Sources="UEFI\Graphics.c" "Kernel.c" "Debug\Console.c" "Memory\Allocator\Bump.c" "ACPI\ACPI.c" "CPU\GDT.c" "Memory\Allocator\PageFrameAllocator.c"
set Objects="Graphics.o" "Kernel.o" "Console.o" "Bump.o" "ACPI.o" "AsmLib.o" "GDT.o" "PageFrameAllocator.o"

:: Kernel Asm lang part
"%ClangRoot%\clang" -c -m64 "CPU\AsmLib.S" -mllvm --x86-asm-syntax=intel --target=i686-pc-none-elf


:: Kernel C lang part
"%ClangRoot%\clang" -c -m64 --target=i686-pc-none-elf -Wall -Werror -ffreestanding -fno-pic -fno-builtin -nostdlib -nostdinc -O2 -flto -g %Sources%
"%ClangRoot%\ld.lld" --strip-all -nostdlib -T link.ld %Objects% -o "Build/Kernel.elf"

copy "Build\Kernel.elf" "%ProjectRoot%\VisualUefi\samples\x64\Release" /y