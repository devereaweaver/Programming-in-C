/* Program 9.6 - Reading Lines Of Data
 * Example of how to create a function that is similar to 
 * gets() library function.
 */

#include <stdio.h>

//======================================
// Function Protoypes
//======================================
void readLine(char []);

//======================================
// Main 
//======================================
int main(void)
{
	int i;
	char line[81];
	
	for (i = 0; i < 3; ++i)		
	{
		readLine(line);		 // read chars into line 
		printf("%s\n\n", line);  // send line to stdout
	}

	return 0;
}

//======================================
// Function Definitions
//======================================
void readLine(char buffer[])
{
	/* readLine() -> reads a line of text from the terminal */
	char character;
	int i = 0;

	do
	{
		character = getchar();    // read character from stdin
		buffer[i] = character;	 // read char into buffer array   
		++i;			 // increment array element
	} while (character != '\n');	 // keep reading until newline

	buffer[i - 1] = '\0';		 // add null terminator as last elementread in character	
}
