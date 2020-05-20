# Hardware Specific Interface
# Arch x86-x64
## Paging Implementation
We must use Paging in 64 bit mode, as I want to use 64 bit technology and no any lower bits,
this is the first thing we should implement for our kernel. Paging is actually a protection
for the Operational Memory, where program code usually stored for execution, so its important
to mention that its an IT. protocol, because later I want to make controllable behavior of
the kernel initialization and execution as Exis is a Generalized OS for any IT. Computing System.