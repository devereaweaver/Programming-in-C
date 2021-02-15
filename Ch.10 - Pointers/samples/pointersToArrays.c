// Function to sum the elements of an integer array 

#include <stdio.h>

//==========================================================
// Function Defintion(s)
//==========================================================
int arraySum(int arr[], const int n)
{
	/* arraySum() - sums the value of all the integers in an 
	 * array. Uses pointer notation to traverse array and sum 
	 * values.
	 */
	int sum = 0, *ptr;
	int * const arrayEnd = arr + n;  // end of array is fixed

	for (ptr = arr; ptr < arrayEnd; ++ptr)  // loop from begging to end of array
		sum += *ptr;  // dereference and add to sum 

	return sum;
}

//==========================================================
// Main
//==========================================================
int main(void)
{
	int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

	printf("The sum is %i\n", arraySum(values, 10));
		
	return 0;
}
