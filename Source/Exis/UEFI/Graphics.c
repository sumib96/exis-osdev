#include "Graphics.h"
#include "..\Util\Math.h"

// Help: https://gist.github.com/bert/1085538

UINT32 *FramebufferAddress = (UINT32*)0xE0000000;

// GOP supports these: BGRR (BGRA), RGBR (RGBA) formats, so we have to convert color values
// BGRA is the current
// PixelBlueGreenRedReserved8BitPerColor << We have this mode on QEMU, 800 x 600
// PixelRedGreenBlueReserved8BitPerColor
// 
UINT32 ColorToUint32(UINT8 A, UINT8 B, UINT8 G, UINT8 R) {
	//UINT32 Result = (UINT32)R << 16 | (UINT32)G << 8 | (UINT32)B | (UINT32);

	UINT32 Result = (UINT8)(A << 24) + (UINT8)(B << 16) + (UINT8)(G << 8) + (UINT8)R;
	return Result;
}

VOID ClearScreen(UINT32 Color)
{
    for (int i = 0; i < 800 * 600; i++)
	{
		FramebufferAddress[i] = Color;
	}
}

VOID SetPixel (int X, int Y, UINT32 Color)
{
	FramebufferAddress[(Y * 800) + X] = Color;
}

VOID DrawLine(INT x0, INT y0, INT x1, INT y1, UINT32 Color)
{
    INT dx =  Abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
    INT dy = -Abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
    INT err = dx + dy, e2; /* error value e_xy */
    
    for (;;)
    {  /* loop */
        SetPixel(y0, x0, Color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
        if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
    }
}

VOID FillRect(INT x0, INT y0, INT x1, INT y1, UINT32 Color)
{
    for (INT x = x0; x <= x1; x++)
    {
        for (INT y = y0; y <= y1; y++)
        {
            SetPixel(y, x, Color);
        }
    }
}