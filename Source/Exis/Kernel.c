#include "BaseTypes.h"
#include "UEFI\Graphics.h"
#include "Debug\Console.h"

void main(void)
{
	UINT32 White = ColorToUint32(255, 255, 255, 255);
	UINT32 Black = ColorToUint32(0, 0, 0, 0);

	ClearScreen(Black);

	//CHAR Char = (CHAR)0x3C;
	CHAR* String = "HELLO WORLD! 12345 - 0000, We are in kernel mode. :) #&@<>?:_;*+/";

	//DrawChar(Char, 10, 10, White);
	DrawString(String, 30, 30, White);
	
	DrawPixel(0, 0, White);
	ClearScreen(White);
	
}