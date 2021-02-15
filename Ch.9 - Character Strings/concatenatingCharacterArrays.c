/* Function to concatenate two character arrays */

#include <stdio.h>

//===============================================
// Function Prototype
//===============================================
void concat (char [], const char [], int,
		const char [], int);

//===============================================
// Main 
//===============================================
int main(void)
{
	/* function assumes fixed lengths for char strings */
	const char s1[5] = {'T', 'e', 's', 't', ' '};
	const char s2[6] = {'w', 'o', 'r', 'k', 's', '.'};
	char s3[11];	

	concat(s3, s1, 5, s2, 6);

	/* Char string to stdout */
	for (int i = 0; i < 11; ++i)
		printf("%c", s3[i]);
	
	printf("\n");
	return 0;
}

//===============================================
// Function Definition
//==============================================
void concat (char result[], const char str1[], int n1,
		const char str2[], int n2)
{
	/* concat() - concatenates two strings */

	int i, j;

	/* Copy str1 to result */
	for (i = 0; i < n1; ++i)
		result[i] = str1[i];

	/* Copy str2 to result */
	for (j = 0; j < n2; ++j)
		result[n1 + j] = str2[j];	
}
