/* Program 8.6 - Illustrating Arrays of Structures */

#include <stdio.h>

//===============================================
// Function Prototype(s)
//===============================================
struct time timeUpdate(struct time now);


//===============================================
// User-defined Type(s) 
//===============================================
struct time {
	int hours;
	int minutes;
	int seconds;
};


//===============================================
// Main
//===============================================
int main(void) {
	struct time testTimes[5] = {	// array of structs
		{11, 59, 59}, {12, 0, 0}, {1, 29, 59}, 
		{23, 59, 59}, {19, 12, 17}
	};
	
	// send each time to stdout
	for(int i = 0; i < 5; ++i) {
		printf("Time is %.2i:%.2i:%.2i", testTimes[i].hours,
			testTimes[i].minutes, testTimes[i].seconds);

		testTimes[i] = timeUpdate(testTimes[i]);  // update each struct in array

		// send updated times to stdout
		printf("...one second later it's %.2i:%.2i:%.2i\n", 
			testTimes[i].hours, testTimes[i].minutes, testTimes[i].seconds);
	}
	return 0;
}


//===============================================
// Function Defintion(s)
//===============================================
struct time timeUpdate(struct time now){
	++now.seconds;  // increment seconds

        // evaluate cases 
        if(now.seconds == 60){          // case i -> increment minutes
                now.seconds = 0;
                ++now.minutes;

                if(now.minutes == 60){  // case ii -> increment hours
                        now.minutes = 0;
                        ++now.hours;

                        if(now.hours == 24){    // case iii -> midnight, increment all
                               now.hours = 0;
                        }
                }
        }
        return now;
}
