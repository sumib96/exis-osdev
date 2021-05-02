/*
    Used for help:
    https://jared.geek.nz/2014/jan/custom-fonts-for-microcontrollers
	
	Integer to string:
	https://clc-wiki.net/wiki/K&R2_solutions:Chapter_3:Exercise_4
*/

#include "Console.h"
#include "Font.h"
#include "..\UEFI\Graphics.h"

#define CHAR_WIDTH 7
#define CHAR_HEIGHT 8
#define FRAMEBUFFER_WIDTH 800

// Almost got braincancer... I came up with this algo at job by mind
// May its the fastest / portable approach without using crazy division laws and lookup tables / bitshifting
#define BUFFER_SIZE 64
CHAR Buffer[BUFFER_SIZE];
const CHAR* IntToString(INT64 Value)
{
    Buffer[BUFFER_SIZE - 1] = '\0';
    int Count = BUFFER_SIZE - 2;
    int Sign = 1;

    // this trick should handle all the negatives now
    if (Value < 0)
       Sign = (-1);

	do  {
        Buffer[--Count] = (Value % 10) * Sign + '0';
	} while ((Value /= 10) != 0);

    if (Sign < 0) {
        Count--;
        Buffer[Count] = '-';
    }

     // crap
    return &Buffer[Count];
}

// IntToHex, had no time to think more
short charStr[] = {'0','1','2','3','4','5','6','7','8','9',
                   'A','B','C','D','E','F'};
const CHAR* IntToHex(UINT64 Value)
{
    Buffer[BUFFER_SIZE - 1] = '\0';
    int Count = BUFFER_SIZE - 2;

	do  {
        Buffer[--Count] = charStr[Value % 16];
	} while ((Value /= 16) != 0);

    return &Buffer[Count];
}

VOID DrawPixel(INT x, INT y, UINT32 color) {
    SetPixel(x, y, color);
}

VOID DrawChar(CHAR c, INT x, INT y, UINT32 color) {
    UINT8 i, j;

    // Convert the character to an index
    c = c & 0x7F;
    if (c < ' ') {
        c = 0;
    } else {
        c -= ' ';
    }

    // 'font' is a multidimensional array of [96][char_width]
    // which is really just a 1D array of size 96*char_width.
    const UINT8* chr = font[(UCHAR)c];

    // Draw pixels
    for (j = 0; j < CHAR_WIDTH; j++) {
        for (i = 0; i < CHAR_HEIGHT; i++) {
            if (chr[j] & (1 << i)) {
                DrawPixel(x + j, y + i, color);
            }
        }
    }
}

VOID DrawString(const CHAR* str, INT x, INT y, UINT32 color) {
    while (*str) {
        DrawChar(*str++, x, y, color);
        x += CHAR_WIDTH;
    }
}

VOID PutChar(CHAR c)
{
    DrawChar(c, CursorPosition.X, CursorPosition.Y, ColorToUINT32(255, 255, 255, 255));
    CursorPosition.X += CHAR_WIDTH;
}

VOID Print(const CHAR* str, UINT32 color) {
    while (*str != 0) {
        DrawChar(*str++, CursorPosition.X, CursorPosition.Y, color);
        CursorPosition.X += CHAR_WIDTH;

        if(CursorPosition.X + CHAR_WIDTH > FRAMEBUFFER_WIDTH) {
            CursorPosition.X = 0;
            CursorPosition.Y += CHAR_HEIGHT;
        }
    }
}

VOID Next()
{
    CursorPosition.X = 0;
    CursorPosition.Y += CHAR_HEIGHT;
}