/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//                        Weekly Food Calculator                           //
//                                                                         //
//              Written by: Vincent Lindsay                                //
//              Written on: 06.09.18                                       //
//              Purpose   : The purpose of this program is to create       //
//                          a program that utilizes the while loop         //
//                          and tells the user based on their input        //
//                          what the lowest and highest amounts they       //
//					        have paid.                                     //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS   // scan without errors
#define PAUSE system("pause")     // Setup a pause shorthand
#define CLS   system("cls")       // setup a clear screen shorthand
#define FLUSH myFlush()           // flush the keyboard buffer 
#include <stdio.h>                // load the standard input output header file
#include <stdlib.h>               // load the standard library header file

void myFlush() {                    // code for a keyboard buffer flush
	while (getchar() != '\n');
} // end myFlush

main() {

	// Variables 
	double const STARVE = 50.55;   // constant variable for the STARVE variable (when the user is eating too little)
	double const FAT = 250.00;     // constant variable for the FAT variable (when the user is eating too much)
	int week = 1;                  // starting week
	double low = 0.0;              // low amount spent
	double high = 0.0;             // high amount spent
	double foodCost = 0.0;         // cost of food that week
	
	while (week <= 20) {                                                // start of the while loop
		printf("\nWeek %i\n", week);
		printf("How much did you spend this week on food ($xx.xx):  ");
		scanf("%lf", &foodCost);
		if (week == 1) {                    // when the week is 1
			high = foodCost;                // the high cost variable is set to the foodCost
			low = foodCost;                 // the lwo cost variable is set to the foodCost
		}
		week++;                               // increase the week counter variable 
		if (foodCost < STARVE) {                    // if the foodCost is lower than the constant STARVE
			printf("\nYou're going to starve!\n");  // say this to the user
		}
		else {
			if (foodCost > FAT)                     // if the foodCost is HIGHER than the constant FAT
				printf("\n You are going to get fat buying that much food.\n");  // say this to the user
		}

		if (foodCost >= high) {   // if the foodcost is higher or equal to the high variable
			high = foodCost;      // make high the value foodCost
		}
		else if (foodCost <= low) {    // if the foodCost is lower or equal to the low variable
			low = foodCost;            // make low variable get the value for foodCost
		}

	}  // end while loop 
	CLS; 
	
	printf("\nThe least you've spent on food is: $%.2lf \n", low);
	printf("\nThe most you've spent on food is: $%.2lf \n\n\n", high);

	PAUSE;
	return 0; 
	
} // end main