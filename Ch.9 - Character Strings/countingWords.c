/* Program 9.7 - Counting Words						 
 * Function gives an example of how to implement a word couting function
 */

#include <stdio.h>
#include <stdbool.h>

//======================================
// Funtion Prototypes
//======================================
bool alphabetic(const char);
int countWords(const char []);	// TO DO: may need to fix parameter if it doesn't work

//======================================
// Main
//======================================
int main(void)
{
	const char text1[] = "Well, here goes.";
	const char text2[] = "And here we go... again.";
	
	printf("%s - words = %i\n", text1, countWords(text1));
	printf("%s - words = %i\n", text2, countWords(text2));

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
