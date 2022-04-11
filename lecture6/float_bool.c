#include <stdio.h>
#include <stdbool.h>

int main ()
{
	float x = 32.23;
	double y = 32.25;
	
	// fixed (rounded)
	printf("x=%.2f,y=%.2lf\n", x, y);

	bool a = true;
	bool b = false;

	printf("a=%d,b=%d\n", a, b);

	return 0;
	
}
