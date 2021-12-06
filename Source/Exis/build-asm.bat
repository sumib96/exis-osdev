set ClangRoot=C:\Program Files\LLVM\bin

%ClangRoot%\clang -c -m64 "CPU\AsmLib.S" -mllvm --x86-asm-syntax=att --target=i686-pc-none-elf