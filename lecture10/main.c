#include<stdio.h>

int main()
{
	int a; 
	scanf("%d", &a);
	printf("a: %d\n", a);

	// standard output
	fprintf(stdout, "a: %d\n", a);
	fprintf(stderr, "This is printed to the standard error.\n");

	return 0;

}
