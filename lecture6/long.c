#include <stdio.h>

int main ()
{
	// 4 byte int
	int a = 4000000000; 
	// some negative big value prints
	printf("%d\n", a);
	// 8 byte long
	long b = 4000000000; 
	// actual 'b' value prints
	printf("%ld\n", b);

	return 0;
}
