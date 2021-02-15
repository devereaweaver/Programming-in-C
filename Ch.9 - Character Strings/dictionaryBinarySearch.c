/* Program 9.10 - Using the Dictionary Lookup Program: 
 * Program is an example implementing basic C functionalities
 * in order to show how they can be used together to create
 * more complicated programming constructs. This example also 
 * shows how to implement a binary search algorithm to compare 
 * strings lexicographically. 
 */

#include <stdio.h>
#include <stdbool.h>

//==========================================================
// Structures
//==========================================================
struct entry		
{
	/* holds a dictionary entry */
	char word[15];
	char definition[50];
};


//==========================================================
// Function Prototypes
//==========================================================
int compareStrings(const char [], const char []);
int lookup(const struct entry[], const char [], const int);

//==========================================================
// Main 
//==========================================================
int main(void)
{
	const struct entry dictionary[100] = // dictionary of struct entry
	{ {"aardvark", "a burrowing African mammal"	},
	  {"abyss", "a bottomless pit"			},
	  {"acumen", "mentally sharp; keen"		},
	  {"addle", "to become confused"		},
	  {"aerie", "a high nest"			}, 
	  {"affix", "to append; attach"			},
	  {"agar", "a jelly made from seaweed"		}, 
	  {"ahoy", "a nautical call of greeting"	}, 
	  {"aigrette", "an ornamental cluster of feathers"},
	  {"ajar", "partially opened"			}
	};

	char word[10];
	int entries = 10;
	int entry;	// hold entry number in dictionary
	
	printf("Enter word: ");
	scanf("%14s", word);		// actually...still don't know
	entry = lookup(dictionary, word, entries);	// number of entry in dictionary
	
	if (entry != -1)  // print definition if exists
		printf("%s\n", dictionary[entry].definition);
	else 
		printf("Sorry, the word %s is not in my dictionary.\n", word);

	return 0;
}

//==========================================================
// Function Definitions 
//==========================================================
int compareStrings(const char s1[], const char s2[])
{
	/* compareStrings() -> compares two character strings 
	 * lexicographically.
	 * Return:
	 * -1 if s1 < s2
	 *  0 if strings are equal
	 *  1 if s1 > s2
	 *  Args:
	 *  s1[], s2[] - characters strings to be compared
	 */ 
	int i = 0, answer;

	while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')		
		++i;

	/* Analyze the two characters that caused the while loop to exit.
	 * The characters are compared and then a decision on their order 
	 * is made and a value is returned to the caller.
	 */

	if (s1[i] < s2[i])			
		answer = -1;	/* s1 < s2 */
	else if (s1[i] == s2[i])
		answer = 0;	/* s1 == s2 */
	else
		answer = 1; 	/* s1 > s2*/

	return answer;
}

//----------------------------------------------------------
int lookup(const struct entry dictionary[], const char search[],
		const int entries)
{
	/* lookup() -> searches for an entry term in a dictionary (array of struct 
	 * entry) using a binary search algorithm. Returns the entry number if found,
	 * return -1 if the entry term doesn't exist in the dictionary.
	 * Args:
	 * dictionary[] - struct array, array to be searched through
	 * search[] - char array, entry term to be looked up 
	 * entries - number of entries in the dictionary
	 */
	int low = 0;
	int high = entries - 1;		
	int mid, result;

	while (low <= high)	
	{
		mid = (low + high) / 2;	
		result = compareStrings(dictionary[mid].word, search);	
		
		if (result == -1)		
			low = mid + 1;	
		else if (result == 1)	
			high = mid - 1;
		else 
			return mid; // RESULT FOUND AT MIDPOINT
	}

	return -1; // RESULT NOT FOUND
}

//----------------------------------------------------------
