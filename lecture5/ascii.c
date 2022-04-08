#include <stdio.h>

int main()
{
	char var = 'A';
	printf("%c %d\n", var, var);
	// chars are integers
	var = 73;
	printf("%c %d\n", var, var);

	var += 2;
	printf("%c %d\n", var, var);

	var = 200;
	printf("%c %d\n", var, var);

	var = 21;
	printf("%c %d\n", var, var);

	return 0;
}
