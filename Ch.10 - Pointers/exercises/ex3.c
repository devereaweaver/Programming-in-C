/* Ch.10 - Exercise 3: Update insert function to allow an entry 
 * to be inserted into the beginning of the list.
 */

#include <stdio.h>

//==========================================================
// User Defined Types
//==========================================================
struct entry 
{
	int value;	
	struct entry *next;	
};

//==========================================================
// Function Prototype(s)
//==========================================================
void insertEntry(struct entry *, struct entry *, struct entry **);
void displayList(struct entry *);

//==========================================================
// Main
//==========================================================
int main(void)
{
	struct entry e1, e2, e3;
	struct entry *list_pointer = &e1;	// point to start of list
	
	e1.value = 5;
	e1.next = &e2;
	e2.value = 10;
	e2.next = &e3;
	e3.value = 15;
	e3.next = (struct entry *) 0;	// last address to null pointer
	
	// Display values before function call
	printf("Values before insertion:\n");
	displayList(list_pointer);
	
	// Create new element
	struct entry e4;
	e4.value = 100;

	// Insert an element to the beginning of the list
	insertEntry(&e4, &e1, &list_pointer);  

	// Display values after function call
	printf("Values after insertion:\n");
	displayList(list_pointer);

	// Create new element
	struct entry e5;
	e5.value = 1010101010;

	// Insert e5 into middle of linked list
	insertEntry(&e5, &e1, &list_pointer);
	printf("Values after second intertion:\n");
	displayList(list_pointer);

	// Insert one more element into the list
	struct entry e6;
	e6.value = 123456;
	insertEntry(&e6, &e5, &list_pointer);
	printf("Values after third insertion:\n");
	displayList(list_pointer);

	/* TO DO: Place the creation and insertion of new elements 
	 * into its own function to stop repeating process in main()
	 */

	return 0;
}

//==========================================================
// Function Definitions
//==========================================================
void insertEntry(struct entry *newEntry, struct entry *antecedent, struct entry **listPointer)	
{
	/* insertEntry() - function inserts newEntry argument into a linked list
	 * after the antecedent argument. (Sorry for the bad naming, couldn't
	 * think of a better name at the time.
	 */

	/* Note to self: To change the address of what list_pointer points in in main(), you 
	 * have to assign a pointer to the list_pointer. In the function you would dereference
	 * the pointer to list_pointer and assign it a new address. This will allow you to change 
	 * its pointed to address for the entrie program and not just change the local copy
	 */
	
	/* Insert into beginning of linked list */
	if (*listPointer == antecedent) // listPointer points to address of antecedent
	{
		*listPointer = newEntry;			// set newEntry as front of list
		newEntry->next = antecedent;		// newEntry next points to old first element 	
	}
	/* Insert elsewhere into linked list */
	else
	{
		struct entry *temp = antecedent->next;  // use -> operator, look up why again later
		antecedent->next = newEntry;  // newEntry already a pointer
		newEntry->next = temp;
	}

}

//----------------------------------------------------------
void displayList(struct entry *listPointer)
{
	while(listPointer != (struct entry *)0)
	{
		printf("%i\n", listPointer->value);	// display current element value
		listPointer = listPointer->next;	// point to next element
	}
	putchar('\n');
}
