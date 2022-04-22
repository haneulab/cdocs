#include <stdio.h>

int main()
{
	// string ends in a null byte
	char s[] = "abc";
	for (unsigned i = 0; i < 3; i++)
	{
		printf("%c %d\n", s[i], s[i]);
	}
	
	char q[] = "abcdefghij";
	printf("str q : %s\n", q);
	q[5] = 0;
	printf("str q cut at [5] because q[5] = 0 => cutting the string q ends at index 5\n%s\n", q);


	// mutable string
	char mstr[] = "abc";
	mstr[0] = "A"; // ok
	// immutable string
	char imstr[] = "abc";	
	imstr[0] = "A" // not ok
	return 0;
}
