// An example of how to return a pointer from a function in C

#include <stdio.h>

struct entry
{
	int value;
	struct entry	*next;
};

struct entry *findEntry (struct entry *listPtr, int match)
{
	/* returns a pointer to entry found in a linked list
	 * takes pointer to start of linked list and the 
	 * value to search for
	 */
	while (listPtr != (struct entry *) 0)	// traverse list until null pointer
		if (listPtr->value == match)	// if the value of the entry is found
			return (listPtr);	// return the entry 
		else
			listPtr = listPtr->next;	// if not found, go to next entry 

	return (struct entry *) 0;	// return null pointer?
}

int main(void)
{
	struct entry n1, n2, n3;	// items in linked list 
	struct entry *listPtr, *listStart = &n1;  // found entry, start of list

	int search;

	n1.value = 100;
	n1.next = &n2;

	n2.value = 200;
	n2.next = &n3;

	n3.value = 300;
	n3.next = 0;	// last item 

	printf("Enter value to locate: ");
	scanf("%i", &search);

	listPtr = findEntry(listStart, search);

	if (listPtr != (struct entry *) 0)	// if not null pointer
		printf("Found %i.\n", listPtr->value);
	else 
		printf("Not found.\n");

	return 0;
}
