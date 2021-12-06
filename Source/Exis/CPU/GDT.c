#include "GDT.h"

struct GDT TestGDT = {
    {0, 0, 0, 0x00, 0x00, 0},
    {0, 0, 0, 0x00, 0x00, 0},
    {0, 0, 0, 0x00, 0x00, 0}
};

void LoadGDT()
{
	gdtPtr.Limit = sizeof(GDT) - 1;
	gdtPtr.Base = (UINT64)&TestGDT;
	
	x64_Lgdt((void*)&gdtPtr);
};