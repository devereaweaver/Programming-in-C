// Program to illustrate using pointers and functions 

#include <stdio.h>

void test (int *int_pointer)
{
	/* Sets pointed to value to 100 */
	*int_pointer = 100;
}

int main(void)
{
	int i = 50, *p = &i;

	printf("Before function call: i = %i\n", i);

	test(p); // change pointed to value 
	printf("After the call to test i = %i\n", i);

	return 0;
}
