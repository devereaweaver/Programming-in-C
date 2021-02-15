/* Program 9.9 - Using the Dictionary Lookup Program: 
 * Program is an example implementing basic C functionalities
 * in order to show how they can be used together to create
 * more complicated programming constructs
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
bool equalStrings(const char [], const char []);
int lookup(const struct entry[], const char [], const int);	// MAY NEED TO CHANGE LATER

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

//----------------------------------------------------------
int lookup(const struct entry dictionary[], const char search[],
		const int entries)
{
	/* lookup() -> searches for an entry term in a dictionary (array of struct 
	 * entry). Returns the entry number if found, return -1 if the entry term 
	 * doesn't exist in the dictionary.
	 * Args:
	 * dictionary[] - struct array, array to be searched through
	 * search[] - char array, entry term to be looked up 
	 * entries - number of entries in the dictionary
	 */
	int i;
	
	for (i = 0; i < entries; ++i)	// number of entries in dictionary
		if ( equalStrings(search, dictionary[i].word) )	// see if search is in dictionary[]
			return i;	// return the entry number if found

	return -1;	// entry wasn't found
}

//----------------------------------------------------------
