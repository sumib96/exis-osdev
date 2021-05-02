#pragma once
#include "..\BaseTypes.h"

VOID Init(UINT64 Start, UINT64 Size);
VOID* Alloc(UINT64 size);
VOID Dealloc(VOID* address);