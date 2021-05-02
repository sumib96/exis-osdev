/*  Tibor P., Created 2020. Dec. 26.
    Allocator Design:
    - Memory area based changable allocator, Set up your working memory area, and change them in runtime
    Future:
    - Allocate more Heap (Slow, at first kernel init), use an Allocator you desire within that as an Object (Memory Hierarchy / Kernel Object Tables)
    - Use any allocator within an other allocator... FUCK.
*/

#include "Exis\BaseTypes.h"

/*typedef struct
{
    UINT64 PhysStart;
    UINT64 PhysEnd;
} MemoryArea;

MemoryArea currentArea;

VOID MemAllocInit(MemoryArea area)
{
    currentArea.PhysStart   = area.PhysStart;
    currentArea.PhysEnd     = area.PhysEnd;
}*/

VOID* MemAlloc(INT size)
{

}

VOID MemFree(VOID* pointer)
{

}