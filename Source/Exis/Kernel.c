#include "BaseTypes.h"
#include "UEFI\UEFI.h" // BootInfo, First baby step for memory management
#include "UEFI\Graphics.h"
#include "Debug\Console.h"
#include "Memory\Alloc.h"

typedef struct {
  UINT32 Type;
  UINT64 PhysicalStart;
  UINT64 VirtualStart;
  UINT64 NumberOfPages;
  UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

//#define EAPI __fastcall

void main(BootInfo* bootInfo)
{
	UINT32 White = ColorToUINT32(255, 255, 255, 255);
	UINT32 Black = ColorToUINT32(0, 0, 0, 0);
	//UINT32 Red = ColorToUINT32(0, 0, 255, 0);
	//UINT32 Green = ColorToUINT32(0, 255, 0, 0);
	//UINT32 Blue = ColorToUINT32(255, 0, 0, 0);

	ClearScreen(Black);

	//CHAR Char = (CHAR)0x3C;
	//CHAR* String = "HELLO WORLD! 12345 - 0000, We are in kernel mode. :) #&@<>?:_;*+/666";

	//DrawChar(Char, 10, 10, White);
	//DrawString(String, 30, 30, White);
	//DrawString(String, 30, 60, Black);
	//DrawString(String, 30, 90, Red);
	//DrawString(String, 30, 120, Green);
	//DrawString(String, 30, 150, Blue);

	// IntToString Test
	//DrawString("IntToString Test:", 30, 180, Blue);
	//DrawString(IntToString(-1234567890), 30, 210, Blue);
	//DrawString(IntToString(27634), 30, 240, Blue);
	//DrawString(IntToString(2), 30, 260, Blue);
	//DrawString(IntToString(-7365784), 30, 280, Blue);

	//DrawPixel(0, 0, White);
	//ClearScreen(Black);

	CursorPosition.X = 0;
    CursorPosition.Y = 0;

	for (int i = 0; i < 10; i++)
	{
		Print("FASZOMAT! ", White);
		CursorPosition.X = 0;
		CursorPosition.Y += 8;
	}

	UINT64 mapEntries = bootInfo->MemoryMapSize / bootInfo->MemoryMapDescSize;
	Print("MapSize: ", White);
	Print(IntToString(bootInfo->MemoryMapSize), White);
	Print("MapDescSize: ", White);
	Print(IntToString(bootInfo->MemoryMapDescSize), White);
	Print("mapEntries: ", White);
	Print(IntToString(mapEntries), White);
	Print("MapBase: ", White);
	Print(IntToHex((UINT64)bootInfo->MemoryMap), White);
	Print("Cycle:", White);
	for (UINT i = 0; i < mapEntries; i++)
	{
		Print("Ciklus: ", White);
		Print(IntToString(i), White);
		EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((UINT64)bootInfo->MemoryMap + (i * bootInfo->MemoryMapDescSize));
		Print(EfiMemoryTypeString[desc->Type], White);
		CursorPosition.X = 0;
		CursorPosition.Y += 8;
	}
	
	Print("ASD!", White);

	// MEMORY ALLOCATION TESTING
	//Init(100000, 10000);
	
	//VOID* fasz = Alloc(64);
	//fasz = Alloc(64);

	//DrawString(IntToString((INT64)&fasz), 60, 30, White);
}