# x64 Architecture Basics for Generalization
## Feature Levels (2020 Convention)
- https://en.wikipedia.org/wiki/X86-64

x86-64: CMOV, CMPXCHG8B, FPU, FXSR, MMX, FXSR, SCE, SSE, SSE2 \
x86-64-v2: (close to Nehalem) CMPXCHG16B, LAHF-SAHF, POPCNT, SSE3, SSE4.1, SSE4.2, SSSE3 \
x86-64-v3: (close to Haswell) AVX, AVX2, BMI1, BMI2, F16C, FMA, LZCNT, MOVBE, XSAVE \
x86-64-v4: AVX512F, AVX512BW, AVX512CD, AVX512DQ, AVX512VL

## Descriptor Tables
### Global Descriptor Table (GDT)
- Holds information about memory segments (SegmentDescriptor)
- SegmentDescriptor: Base Address, Limit (Segment Size), DPL (Descriptor Privilege Level), Readable / Writable etc.
- Loadable by opcode (LGDT)
- Max 8192 descriptors

An GDT Entry:

```c
struct gdt_entry
{
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed));
```

Where gdtr is a pointer to 6 bytes of memory containing the desired GDTR value. Note that to complete the process of loading a new GDT, the segment registers need to be reloaded. The CS register must be loaded using a far jump:

```assembly
flush_gdt:
    lgdt [gdtr]
    jmp 0x08:complete_flush
 
complete_flush:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret
```

- The LGDT instruction will look for a 8-byte base address in long mode! + Limit = 10 bytes

### Local Descriptor Table (LDT)
- Same
- Each task can have its own LDT, useful with HARDWARE task switching
- Loadable by opcode (LLDT)

### Interrupt Descriptor Table (IDT)
- Holds information about Interrupt Gates and Trap Gates (yes these are called Gates)
- Usually pointers to ISR (Interrupt Services Routines), which is a bunch of crap in the memory
- Max 256 interrupts
- Loadable by opcode (LIDT)
- Opcode for disabling and enabling interrupts (CLI/STI)

### Paging