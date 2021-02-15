/* Progam to illustrate structure pointers */

#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

int main(void){
	struct date today, *datePtr;  // pointer to date struct

	datePtr = &today;  // point to today
	
	datePtr->month = 2;
	datePtr->day = 11;
	datePtr->year = 2021;

	printf("Today's date is %i/%i/%i.\n", datePtr->month, datePtr->day,
			datePtr->year);
	return 0;
}
