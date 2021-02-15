/* Function to find the length of a string using pointers. */

#include <stdio.h>

//==========================================================
// Function Prototype(s)
//==========================================================
int stringLength(const char *);

//==========================================================
// Main
//==========================================================
int main(void)
{
	printf("%i ", stringLength("stringLength test"));	// return 17 + null
	printf("%i ", stringLength(""));
	printf("%i\n", stringLength("complete"));		// return 8 + null

	return 0;
}

//==========================================================
// Function Definition(s)
//==========================================================
int stringLength(const char *string)
{
	const char *cptr = string;  // pointer to start of string

	while(*cptr)	// while cptr is still pointing to array
		++cptr;  // point to next element
	
	return cptr - string; // final element minus start of string
}
