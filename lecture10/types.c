#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[] = "5";
	
	// convert to int
	int a = atoi(s);
	printf("%d\n", a);
	
	// if cant convert, returns 0
	char s2[] = "g";
	int b = atoi(s2);
	printf("%d\n", b);

	char r[] = "17 20 xyz";
	int c,d;
	char buf[20];
	sscanf(r, "%d %d %s", &c, &d, buf);
	printf("c : %d\n", c);
	printf("d : %d\n", d);
	printf("buf : %s\n", buf);

	char op[40];
	sprintf(op, "%d %c %s", 5, 'x', "abc");
	printf("output : %s\n", op); 

	return 0;
}
