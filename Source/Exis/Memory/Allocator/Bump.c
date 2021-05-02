#include "..\Alloc.h"

struct BumpAllocator
{
	UINT64 Start;
	UINT64 End;
	UINT64 Next;
	UINT64 Count;
};

struct BumpAllocator bumpAllocator;

VOID Init(UINT64 Start, UINT64 Size)
{
	bumpAllocator.Start = Start;
	bumpAllocator.End = Start + Size;
	bumpAllocator.Next = Start;
	bumpAllocator.Count = 0;
};

VOID* Alloc(UINT64 size)
{
	UINT64 address = bumpAllocator.Next;
	bumpAllocator.Next = address + size;
	bumpAllocator.Count += 1;
	return (VOID*)address;
};

VOID Dealloc(VOID* address)
{
	bumpAllocator.Count -= 1;
	if(bumpAllocator.Count == 0)
		bumpAllocator.Next = bumpAllocator.Start;
};