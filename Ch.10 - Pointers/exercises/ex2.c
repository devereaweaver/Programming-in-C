/* Ch.10 - Exercise 2: Write a function to insert an entry into a linked list.*/

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
void insertEntry(struct entry *, struct entry *);
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
	
	// Check linked list before insertion
	printf("Values before insertion:\n");
	displayList(list_pointer);
	
	// insert new element for linked list 
	struct entry e4;
	e4.value = 100;
	insertEntry(&e4, &e2);
	
	printf("Values after insertion:\n");
	displayList(list_pointer);
	
	return 0;
}

//==========================================================
// Function Definitions
//==========================================================
void insertEntry(struct entry *newEntry, struct entry *antecendent)	/* TO DO: Better arg names */
{
	/* insertEntry() - function inserts newEntry argument into a linked list
	 * after the antecendent argument. (Sorry for the bad naming, couldn't
	 * think of a better name at the time.
	 */
	struct entry *temp = antecendent->next;  // use -> operator, look up why again later
	antecendent->next = newEntry;  // newEntry already a pointer
	newEntry->next = temp;
}

//----------------------------------------------------------
void displayList(struct entry *listPointer)
{
	while(listPointer != (struct entry *)0)
	{
		printf("%i\n", listPointer->value);	// diplay current element value
		listPointer = listPointer->next;	// point to next element
	}
	putchar('\n');
}
