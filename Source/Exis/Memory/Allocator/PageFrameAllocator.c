/*
    PageFrameAllocator:
    - The Kernel is loaded into UEFI application memory area by UEFIEXL
    - This is the reason we dont need to know where the kernel is in memory to determine free space
    - The memorymap contains all the information what was fixed before ExitBootServices call
    The easy method:
    - Know what page size were used by UEFI
    - Use the free space from MemoryMap, efi memory types? and operate on that area
    - Mark the used and free pages in any form (bitmap for the minimal size possible, bitwise operations doesnt take long time)
        - Have to make a full bitmap for the whole physical memory
        Other solution would be:
        - using a list with adresses (too much space)
        - using the bitmap on a start / end memory address (or more bitmaps) -> portable
        - using a UEFI like memory map for the allocations (do I want to reinvent UEFI?)
    - Invent some minimal functions (AllocatePages, Dealloc or whatever)
    End goal:
    - Separate the UEFI informations and functionality to a module (Uefi Driver?)

    Math:
    - 4K page = 4096 bytes = 64^2
    - 64 bit address space: 2^64 bytes (16 exabytes)
    - 32768 x 4K page size = 
    - 4096 x 8 = 32768 = maximum frames storable in one 4K frame

    Practise:
    Example for 00000111:
    INT bits = 3; // 3 lower bits
    UINT8 mask = (1 << bits) - 1; // 7

    Set bit
    number |= 1UL << n;
    number = (number & ~(1UL << n)) | (x << n);
*/
#include "PageFrameAllocator.h"

static EFI_MEMORY_DESCRIPTOR* largestFreeSpaceDesc;

UINT64 GetMemSize(BootInfo* bootInfo)
{
    UINT64 mapEntries = bootInfo->MemoryMapSize / bootInfo->MemoryMapDescSize;
    UINT64 memSize = 0;

    //if (memSize > 0) return memSize;

	for (UINT i = 0; i < mapEntries; i++) {
		EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((UINT64)bootInfo->MemoryMap + (i * bootInfo->MemoryMapDescSize));
		if (desc->Type == EfiConventionalMemory & memSize < desc->NumberOfPages * 4096) {
			memSize = desc->NumberOfPages * 4096;
            largestFreeSpaceDesc = desc;
		}
	}
	return memSize;
}

VOID SetMem(VOID* Pointer, UINT8 Value, UINT64 Lenght) {
    UINT8* Ptr = (UINT8*)Pointer;
    for (UINT64 i = 0; i < Lenght; i++)
    {
        Ptr[i] = Value;
    }
}

VOID ZeroMem(VOID* Pointer, UINT64 Lenght) {
    SetMem(Pointer, 0, Lenght);
}

typedef struct {
    UINT8 *BufferAddress;
    UINT64 BufferSize;
} BITSET;

BITSET bitmap;
VOID* memory;

UINT8 GetBit(UINT8 Byte, UINT64 Index) {
    return (Byte >> Index) & 1;
}

UINT8 SetBit(UINT8 Byte, UINT64 Index, UINT64 Value) {
    return (Byte & ~(1 << Index)) | (Value << Index);
}

UINT64 GetBitmapValue(UINT64 BitIndex) {
    //if (bitmap.BufferSize * 8 < BitIndex) return 0;
    return (UINT64)GetBit(bitmap.BufferAddress[BitIndex / 8], BitIndex % 8);
}

UINT64 SetBitmapValue(UINT64 BitIndex, UINT64 Value) {
    //if (bitmap.BufferSize * 8 < BitIndex) return 0;
    bitmap.BufferAddress[BitIndex / 8] = SetBit(bitmap.BufferAddress[BitIndex / 8], BitIndex % 8, Value);
    return 1;
}

UINT64 SetBitmap(BootInfo* bootInfo) {
    UINT64  pageFrameSize = 4096;       // 4KB
    UINT64  largestFreeSpaceSize = GetMemSize(bootInfo);
    UINT64  bitMapSize = largestFreeSpaceSize / pageFrameSize / 8 + 1;

    bitmap.BufferSize = bitMapSize;
    bitmap.BufferAddress = (UINT8*)largestFreeSpaceDesc->PhysicalStart;
    
    ZeroMem(bitmap.BufferAddress, bitmap.BufferSize);

    // Crap
    memory = (VOID*)((UINT64)bitmap.BufferAddress + bitmap.BufferSize);

    return (UINT64)bitmap.BufferAddress;
}

VOID* NextFreeFrame()
{
    for (UINT64 Index = 0; Index < bitmap.BufferSize * 8; Index++)
    {
        if (GetBitmapValue(Index) == 1) continue;
        SetBitmapValue(Index, 1);
        return (VOID*)((UINT64)memory + Index * 4096);
    }
    
    return 0;
}