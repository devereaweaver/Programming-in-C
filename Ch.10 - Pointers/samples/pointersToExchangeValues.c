// More on functions and pointers 

#include <stdio.h>

void exchange (int * const pint1, int * const pint2)
{
	// Use pointers to swap values 
	// const, function won't change pointers
	int temp;

	temp = *pint1;		// pointed to value of pint1
	*pint1 = *pint2;	// swap
	*pint2 = temp;
}

int main(void)
{
	int i1 = -5, i2 = 66, *p1 = &i1, *p2 = &i2;

	printf("i1 = %i, i2 = %i\n", i1, i2);		// -5, 66

	exchange(p1, p2);	// swap values
	printf("i1 = %i, i2 = %i\n", i1, i2);		// 66, -5

	return 0;
}
