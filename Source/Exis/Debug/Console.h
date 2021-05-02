#pragma once
// Only UTF-8
#include "..\BaseTypes.h"

/* SKELETON!
short charStr[] = {'0','1','2','3','4','5','6','7','8','9',
                   'A','B','C','D','E','F'};

// My first "brain logic" IntToString implementation, pretty good asm result with compiler optimalization
char* IntToString(int Value, char Buffer[])
{
	int Count = 0;
    int Remainder;

	do  {
		Remainder = Value % 10;
        Buffer[Count] = Remainder + '0';
        Value /= 10;
        Count++;
	} while (Value != 0);

    return Buffer;
}
*/

typedef struct {
    UINT X;
    UINT Y;
} Point;

Point CursorPosition;

const CHAR* IntToString(INT64 Value);
const CHAR* IntToHex(UINT64 Value);

VOID DrawPixel(INT x, INT y, UINT32 color);
VOID DrawChar(CHAR c, INT x, INT y, UINT32 color);
VOID DrawString(const CHAR* str, INT x, INT y, UINT32 color);

VOID Print(const CHAR* str, UINT32 color);