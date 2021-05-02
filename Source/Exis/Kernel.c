#include "BaseTypes.h"
#include "UEFI\BootInfo.h" // BootInfo, First baby step for memory management
#include "UEFI\Graphics.h"
#include "Debug\Console.h"
#include "Memory\Alloc.h"
#include "ACPI\ACPI.h"

typedef struct {
  UINT32 Type;
  UINT64 PhysicalStart;
  UINT64 VirtualStart;
  UINT64 NumberOfPages;
  UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

#define EAPI __attribute((ms_abi)) // XD

VOID PrepareACPI(BootInfo* bootInfo)
{
    ACPI_SDT_HEADER* xsdt = (ACPI_SDT_HEADER*)(bootInfo->RSDP->XsdtAddress);

    int entries = (xsdt->Length - sizeof(ACPI_SDT_HEADER)) / 8;
    for (int i = 0; i < entries; i++)
    {
        ACPI_SDT_HEADER* newSdtHeader = (ACPI_SDT_HEADER*)*(UINT64*)((UINT64)xsdt + sizeof(ACPI_SDT_HEADER) + (i * 8));
        for (int j = 0; j < 4; j++)
        {
            PutChar((CHAR)newSdtHeader->Signature[j]);
        }
        PutChar(' ');
    }
    Next();
}

void EAPI main(BootInfo* bootInfo)
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

	Print(IntToHex((UINT64)bootInfo->RSDP), White);

	//for (int i = 0; i < 100; i++)
	//{
	//	PutChar(*((UCHAR*)bootInfo->RSDP + i));
	//}

	PrepareACPI(bootInfo);
	Next();

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
	/*for (UINT i = 0; i < mapEntries; i++)
	{
		Print("Ciklus: ", White);
		Print(IntToString(i), White);
		EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((UINT64)bootInfo->MemoryMap + (i * bootInfo->MemoryMapDescSize));
		Print(EfiMemoryTypeString[desc->Type], White);
		Print(IntToString(desc->NumberOfPages), White);
		CursorPosition.X = 0;
		CursorPosition.Y += 8;
	}*/
}