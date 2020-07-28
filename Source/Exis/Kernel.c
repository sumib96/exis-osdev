void main(void)
{
	int x = 10;
	x++;
	
	int* memory = (int*)0x1000;
	memory[0] = x;
}