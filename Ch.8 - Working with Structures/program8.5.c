/* Program 8.5 - Updating the time by one second */

#include <stdio.h> 

//===============================================
// Function Prototype(s)
//===============================================
struct time timeUpdate(struct time now);  // timeUpdate() defined later


//===============================================
// User-Defined Type(s)
//===============================================
struct time {
	int hours;
	int minutes;
	int seconds;
};


//===============================================
// Main
//===============================================
int main(void){
	struct time currentTime, nextTime;	  // declare 2 time structs

	printf("Enter the time (hh:mm:ss): ");	  // read values into currentTime
	scanf("%i:%i:%i", &currentTime.hours,
		&currentTime.minutes, &currentTime.seconds);
	
	nextTime = timeUpdate(currentTime);  // pass currentTime to timeUpdate() 
					    // nextTime members set return value 

	printf("Updated time is %.2i:%.2i:%.2i\n", nextTime.hours, 
			nextTime.minutes, nextTime.seconds);

	return 0;
}


//===============================================
// Function Definition(s) 
//===============================================
/* timeUpdate(struct time now) -> function accepts a struct time type
 * 	as an argument an increments the seconds member by one. It will
 * 	return a struct time type with the updated time to the caller. 
 */
struct time timeUpdate(struct time now){
	++now.seconds;	// increment seconds

	// evaluate cases 
	if(now.seconds == 60){		// case i -> increment minutes
		now.seconds = 0;
		++now.minutes;

		if(now.minutes == 60){	// case ii -> increment hours
			now.minutes = 0;
			++now.hours;

			if(now.hours == 24){	// case iii -> midnight, increment all
			       now.hours = 0;
			}
		}
	}
	return now;
}	
