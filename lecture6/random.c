#include <stdio.h>

int main ()
{
	/*
	 * control flow statements
	 */

	int a = 5;
	if (a == 5 && a != 30)
		printf("AAA\n");
	if (a == 7 && a == 5)
		printf("BBB\n");
	if (!(a == 7))
		printf("CCC\n");
	if (a != 7)
		printf("DDD\n");

	/*
	 * loops & breaks
	 */
	while (1)
	{       
		/*
		 * continue keyword sets the cur state to the top of the loop (causing infinite loop in the below case)
		 */
		if (x == 10)
			continue;
		int x;
		scanf("%d", &x);
		if (x == 5)
			break;
	}


	return 0;
}
