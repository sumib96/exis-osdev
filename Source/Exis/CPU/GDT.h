#pragma once
#include "..\BaseTypes.h"
#include "AsmLib.h"

// Segment Descriptor, fasz kivan
// 8 bytes
typedef struct GDT_ENTRY
{
    UINT16 Limit_0_15;
    UINT16 Base_0_15;
    UINT8 Base_16_23;
    UINT8 AccessByte;
    UINT8 Limit_16_19_Flags;
    UINT8 Base_24_31;
} __attribute__((packed)) GDT_ENTRY;

// GDT Register
// 10 bytes in long mode
typedef struct GDT_DESCRIPTOR_64
{
    UINT16 Limit;
    UINT64 Base;
} __attribute__((packed)) GDT_DESCRIPTOR_64;

// Temporary GDT for testing
typedef struct GDT
{
    GDT_ENTRY Null;
    GDT_ENTRY KernelCode;
    GDT_ENTRY KernelData;
} __attribute__((packed)) GDT;

static GDT_DESCRIPTOR_64 gdtPtr;

void LoadGDT();