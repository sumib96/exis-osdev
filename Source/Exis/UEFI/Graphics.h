#pragma once
#include "..\BaseTypes.h"

VOID ClearScreen(UINT32 Color);
VOID SetPixel(int Y, int X, UINT32 Color);
VOID DrawLine(INT x0, INT y0, INT x1, INT y1, UINT32 Color);
VOID FillRect(INT x0, INT y0, INT x1, INT y1, UINT32 Color);