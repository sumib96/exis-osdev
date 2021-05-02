#include "BaseTypes.h"

// Implementation for 4k pages only

typedef struct
{
    UINT64 Type;
    UINT64 Name;
    UINT64 PhysicalStart;
    UINT64 FrameNumber;
} MemoryDescriptor; // 32 bytes