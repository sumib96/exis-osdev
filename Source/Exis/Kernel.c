#include "BaseTypes.h"
#include "UEFI\Graphics.h"
#include "Debug\Console.h"

void main(void)
{
	ClearScreen((UINT32)0x0000BB11);

	DrawChar('F', 30, 30, 16777215);
}