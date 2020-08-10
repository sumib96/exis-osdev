typedef unsigned int UINT32;

void SetPixel (int Y, int X, UINT32 Color)
{
	char *memory = (char*)0x90000000;
	memory[4 * (Y * 800 + X)] = Color;
}

void main(void)
{
	char *memory = (char*)0x90000000;
	
	for (int i = 0; i < 1920000; i++)
	{
		memory[i] = 0;
	}

	for (int i = 0; i < 800; i++)
	{
		for (int l = 0; l < 600; l++)
		{
			SetPixel(l, i, 300);
		}
	}
}