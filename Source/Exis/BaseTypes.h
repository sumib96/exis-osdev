/*  Only for 64 bit + architectures
    LLVM bind
*/

#pragma once

typedef void                    VOID;

typedef unsigned char           UCHAR;      // 1 byte
typedef unsigned short          USHORT;     // 2 byte
typedef unsigned int            UINT;       // 4 byte

typedef char                    CHAR;       // 1 byte
typedef short                   SHORT;      // 2 byte
typedef int                     INT;        // 4 byte

// Unsigned values
typedef unsigned int            UINT32;     // 4 byte
typedef unsigned long long      UINT64;     // 8 byte

// Signed values
typedef int                     INT32;      // 4 byte
typedef long long               INT64;      // 8 byte

// Plus
typedef UCHAR                   UINT8;      // 1 byte
typedef USHORT                  UINT16;     // 2 byte