// Common header for the firmware informations, also used in UEFIEXL.

#pragma once

#include "..\BaseTypes.h"
#include "..\ACPI\ACPI.h"

typedef struct
{
    VOID* MemoryMap;
    UINT64 MemoryMapSize;
    UINT64 MemoryMapDescSize;
} MemoryMapInfo;

typedef struct
{
    void* FrameBufferBase;
    UINT64 FrameBufferSize;
    UINT64 PixelsPerScanLine;
    UINT64 Width;
    UINT64 Height;
} FrameBufferInfo;

typedef struct
{
    VOID* MemoryMap;
    UINT64 MemoryMapSize;
    UINT64 MemoryMapDescSize;
    // ACPI
    ACPI_RSDP* RSDP;
    //MemoryMapInfo* MemoryInfo;
    //FrameBufferInfo* BufferInfo;
} BootInfo;