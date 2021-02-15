/* A revised version of the copyString() function using a while loop
 * and a pointer instead of a for loo.
 */

#include <stdio.h>

//==========================================================
// Function Definition(s)
//==========================================================
void copyString(char *to, char *from)
{
	while (*from)			// execute until the end of string
		*to++ = *from++;	// dereference, assign, increment

	*to = '\0';	// final char in string is null
}

//==========================================================
// Main
//==========================================================
int main(void)
{
	char string1[] = "A string to be copied.";
	char string2[50];

	copyString(string2, string1);
	printf("%s\n", string2);

	copyString(string2, "So is this");
	printf("%s\n", string2);

	return 0;
}
