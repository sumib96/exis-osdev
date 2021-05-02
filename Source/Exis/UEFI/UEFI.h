// Common header for the firmware informations, also used in UEFIEXL.

#pragma once

#include "..\BaseTypes.h"

const char* EfiMemoryTypeString[] = {
  "EfiReservedMemoryType",
  "EfiLoaderCode",
  "EfiLoaderData",
  "EfiBootServicesCode",
  "EfiBootServicesData",
  "EfiRuntimeServicesCode",
  "EfiRuntimeServicesData",
  "EfiConventionalMemory",
  "EfiUnusableMemory",
  "EfiACPIReclaimMemory",
  "EfiACPIMemoryNVS",
  "EfiMemoryMappedIO",
  "EfiMemoryMappedIOPortSpace",
  "EfiPalCode",
  "EfiPersistentMemory",
  "EfiMaxMemoryType"
};

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
    //MemoryMapInfo* MemoryInfo;
    //FrameBufferInfo* BufferInfo;
} BootInfo;