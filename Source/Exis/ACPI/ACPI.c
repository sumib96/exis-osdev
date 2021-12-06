#include "ACPI.h"
//#include "..\Debug\Console.h"


VOID* FindTable(ACPI_SDT_HEADER* sdtHeader, CHAR* signature) {
    int entries = (sdtHeader->Length - sizeof(ACPI_SDT_HEADER)) / 8;

    for (int entry = 0; entry < entries; entry++) {
        ACPI_SDT_HEADER* newSdtHeader = (ACPI_SDT_HEADER*)*(UINT64*)((UINT64)sdtHeader + sizeof(ACPI_SDT_HEADER) + (entry * 8));

        for (int i = 0; i < 4; i++) {
            if (newSdtHeader->Signature[i] != signature[i]) break;
            if (i == 3) return newSdtHeader;
        }
    }
    return 0;
}