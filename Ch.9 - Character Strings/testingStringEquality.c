/* Program 9.4 - Testing Strings for Equality */

#include <stdio.h>
#include <stdbool.h>

//======================================
// Function Definitions
//======================================
bool equalStrings(const char s1[], const char s2[])
{
	/* equalStrings() -> compares the characters in two strings to 
	 * see if they are equal. Char arrays must have same characters 
	 * in the relative same positions AND they my terminate with null
	 * terminator in the same positions.   
	 */
	int i = 0;	// i needs entire scope
	bool areEqual;

	// read each character until they don't match 
	// or either reaches the null terminator
	while (s1[i] == s2[i] && s1[i] != '\0'
			&& s2[i] != '\0')
		++i;

	// test if null terminator is in same position  
	if (s1[i] == '\0' && s2[i] == '\0')
		areEqual = true;
	else 
		areEqual = false;

	return areEqual;
}

//======================================
// Main
//======================================
int main(void)
{
	const char stra[] = "string compare test";
	const char strb[] = "string";

	printf("%i\n", equalStrings(stra, strb));	// false
	printf("%i\n", equalStrings(stra, stra));	// true
	printf("%i\n", equalStrings(strb, "string"));	// true

	return 0;
}
