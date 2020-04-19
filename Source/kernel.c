// Test main
void kmain(void)
{
    int* terminal_buffer = (int*) 0xB8000;
	for (int y = 0; y < 300; y++) {
		for (int x = 0; x < 300; x++) {
			const int index = y * 300 + x;
			terminal_buffer[index] = 0;
		}
	}
}
