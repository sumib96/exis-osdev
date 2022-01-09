//; retq does the same as ret, just the name is different for convention on x64 (AT&T), pops quadword from the stack to %rip and return
//; %rcx is the first function argument on x64 msabi convention, for output
//; I dont know what asm syntax should I use, doesnt matter anyway



.global x64_Lgdt
x64_Lgdt:
lgdt [rcx]
ret

.global x64_Sgdt
x64_Sgdt:
sgdt [rcx]
ret

.global x64_Lidt
x64_Lidt:
lidt [rcx]
ret