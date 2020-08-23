#include "Console.h"
#include "..\UEFI\Graphics.h"

unsigned char Glyph[8] = {
    0xFF,
    0xF1,
    0x12,
    0x32,
    0x43,
    0x32,
    0xA3,
    0x3A };

VOID DrawChar(UCHAR Char, INT xc, INT yc, UINT32 Color)
{
	for(int x = 0; x < 8 + 8; x++){
		for(int y = 0; y < 8; y++){
			if(Glyph[y] & (1 << x)) SetPixel(yc + y, xc + x, Color);
		}
	}
}