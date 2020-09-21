#pragma once
#include "..\BaseTypes.h"

UINT32 ColorToUint32(UINT8 B, UINT8 G, UINT8 R, UINT8 A);
VOID ClearScreen(UINT32 Color);
VOID SetPixel(int Y, int X, UINT32 Color);
VOID DrawLine(INT x0, INT y0, INT x1, INT y1, UINT32 Color);
VOID FillRect(INT x0, INT y0, INT x1, INT y1, UINT32 Color);