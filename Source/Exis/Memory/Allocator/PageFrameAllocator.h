#pragma once
#include "..\..\BaseTypes.h"
#include "..\..\UEFI\Standard.h"
#include "..\..\UEFI\BootInfo.h"

UINT8 GetBit(UINT8 Byte, UINT64 Index);
UINT8 SetBit(UINT8 Byte, UINT64 Index, UINT64 Value);

UINT64 GetMemSize(BootInfo* bootInfo);
UINT64 SetBitmap(BootInfo* bootInfo);

VOID* NextFreeFrame();