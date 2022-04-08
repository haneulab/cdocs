#include <ctype.h>
#include <stdio.h>

int main()
{
	printf("%d\n", isupper('A'));
	printf("%d\n", isupper('V'));
	printf("%d\n", islower('v'));
	printf("---\n");
	printf("%d\n", isdigit('V'));
	printf("%d\n", isdigit('5'));
	printf("%d\n", isdigit(' '));

	if (isdigit('3'))
		printf("Found digit\n");
	printf("---\n");

	printf("%d\n", isalpha('X'));
	printf("%d\n", isspace(' '));

	return 0;
}
