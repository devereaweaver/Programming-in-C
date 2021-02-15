/* Program 9.8 - Counting Words in a Piece of Text */

#include <stdio.h>
#include <stdbool.h>

//======================================
// Function Prototypes 
//======================================
bool alphabetic(const char);
void readLine(char []);
int countWords(const char []);

//======================================
// Main 
//======================================
int main(void) 
{
	char text[81];
	int totalWords = 0;
	bool endOfText = false;

	printf("Type in your text.\n");
	printf("When you are done, press 'RETURN'.\n\n");

	while (! endOfText)
	{
		readLine(text);		// read lines from stdin
		
		if (text[0] == '\0')	// reached end of text input
			endOfText = true;
		else
			totalWords += countWords(text);	// count words in input text
	}	

	printf("\nThere are %i words in the above text.\n", totalWords);

	return 0;
}
		
//======================================
// Function Definitions
//======================================
bool alphabetic(const char c)
{
	/* alphabetic() -> function tests if argument c is a valid character in
	 * the alphabet. 
	 */
	if ( (c>= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
		return true;
	else 
		return false;
}	

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


int countWords(const char string[])
{
	/* countWords() -> counts the number of words containing alphabetic
	 * characters. (Review this algorithm as needed until understood)
	 */
	int i, wordCount = 0;
	bool lookingForWord = true;	// flag, indicates looking for start
       					// of a new word

	for (i = 0; string[i] != '\0'; ++i)
		if ( alphabetic(string[i]) )	// test if char is valid
		{
			if (lookingForWord)	// execute if start of new word
			{
				++wordCount;
				lookingForWord = false;
			}
		}
		else
			lookingForWord = true;	// end of word
	return wordCount;
}
