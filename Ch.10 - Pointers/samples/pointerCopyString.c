/* A pointer version of the typical copyString() function */

#include <stdio.h>

//==========================================================
// Function Definition(s)
//==========================================================
void copyString(char *to, char *from)
{
	/* copyString() - copies the contents of one character 
	 * string to be the contents of another character string.
	 */
	for ( ; *from != '\0'; ++from, ++to)  // no inital condition, keep going untiln
		*to = *from;		      // the end of the from char string

	*to = '\0';
}

int main(void)
{
	char string1[] = "A string to be copied.";
	char string2[50];

	copyString(string2, string1);
	printf("%s\n", string2);
	
	copyString(string2, "So is this.");  // I had it backwards...
	printf("%s\n", string2);

	return 0;
}
