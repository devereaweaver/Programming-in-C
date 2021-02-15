/* Program 9.3 - Concatenating Character Strings */

#include <stdio.h>

//======================================
// Function Prototype
//======================================
void concat(char [], const char [], const char []);

//======================================
// Main 
//======================================
int main(void)
{
	const char s1[] = {"Test "};
	const char s2[] = {"works."};
	char s3[20];	// big enough to fit concatenation

	concat(s3, s1, s2);

	printf("%s\n", s3);

	return 0;
}

//======================================
// Function Definitions
//======================================
/* concat() - concatenates two strings */
void concat(char result[], const char str1[], const char str2[])
{
	int i, j;
		
	// Copy str1 to result 
	for (i = 0; str1[i] != '\0'; ++i)	// doesn't add null char to concatenation
		result[i] = str1[i];

	// Copy str2 to result 
	for (j = 0; str2[j] != '\0'; ++j)
		result[i + j] = str2[j];

	// terminate the concatenated string with a null character
	result[i + j] = '\0';
}
