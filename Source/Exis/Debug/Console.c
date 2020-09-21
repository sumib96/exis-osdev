/*
    Used for help:
    https://jared.geek.nz/2014/jan/custom-fonts-for-microcontrollers
*/

#include "Console.h"
#include "Font.h"
#include "..\UEFI\Graphics.h"

#define CHAR_WIDTH 7
#define CHAR_HEIGHT 8

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