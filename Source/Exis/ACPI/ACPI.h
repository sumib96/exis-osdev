#pragma once
#include "..\BaseTypes.h"
//#include "..\UEFI\BootInfo.h"

typedef struct {
  UINT64  Signature;
  UINT8   Checksum;
  UINT8   OemId[6];
  UINT8   Revision;
  UINT32  RsdtAddress;
  UINT32  Length;
  UINT64  XsdtAddress;
  UINT8   ExtendedChecksum;
  UINT8   Reserved[3];
} ACPI_RSDP;

typedef struct {
  UINT8     Signature[4];
  UINT32    Length;
  UINT8     Revision;
  UINT8     Checksum;
  CHAR     OemId[6];
  CHAR     OemTableId[8];
  UINT32    OemRevision;
  UINT32    CreatorId;
  UINT32    CreatorRevision;
} ACPI_SDT_HEADER;

typedef struct {
  ACPI_SDT_HEADER SdtHeader;
  UINT64 Reserved;
} ACPI_MCFG_HEADER;

VOID* FindTable(ACPI_SDT_HEADER* sdtHeader, CHAR* signature);