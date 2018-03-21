#include <stdio.h>

int main(int argc, char const *argv[])
{
	unsigned int a = 0x87654321;
	unsigned char *ptr = (unsigned char*)&a;
	if (*ptr == 0x87)
	{
		printf("%s\n", "large");
	}
	else
	{
		printf("%s\n", "small");
	}
	return 0;
}