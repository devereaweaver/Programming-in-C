/* Program 9.2 - Counting the Characters in a String */

#include <stdio.h>

//================================================
// Function Definition 
//================================================
int stringLength(const char string[])
{
	/* stringLength() -> counts the numbers of 
	 * characters in a given string 
	 */
	int count = 0;

	while (string[count] != '\0')	// increment until null char
		++count;

	return count;
}

//===============================================
// Main 
//==============================================
int main(void)
{
	const char word1[] = {'a', 's', 't', 'e', 'r', '\0'};
	const char word2[] = {'a', 't', '\0'};
	const char word3[] = {'a', 'w', 'e', '\0'};

	printf("%i    %i    %i\n", stringLength(word1), 
			stringLength(word2), stringLength(word3));

	return 0;
}
