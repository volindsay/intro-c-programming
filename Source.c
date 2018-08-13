/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//                        Shipping Cost Calculator                         //
//                                                                         //
//              Written by: Vincent Lindsay                                //
//              Written on: 06.03.18                                       //
//              Purpose   : To create a program to show shipping costs     //
//                          based on the distance input by the user.       //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS   // scan without errors
#define PAUSE system("pause")     // Setup a pause shorthand
#define CLS   system("cls")       // setup a clear screen shorthand
#define FLUSH myFlush()           // flush the keyboard buffer 
#include <stdio.h>                // load the standard input output header file
#include <stdlib.h>               // load the standard library header file

void myFlush() {                  // code for the keyboard flush
	while (getchar() != '\n');
} // end myFlush


main() {

	// Define Variables

	double weight = 0.0;      // weight of the package
	int    shipDistance = 0;  // distance to ship
	double flatShip = 10.00;  // flat shipping cost
	double costDist = 0.0;    // cost based on distance
	double costWeight = 0.0;  // cost based on weight
	double totalShipCost = 0.0; // final shipping cost
	char location[50];          // location of shipping destination

	// [I]nput
	printf("\t\t\t\t\tShipping Cost Calculator\n\n");
	printf("\t\t\t\t\t\tWelcome!\n");
	printf("You're looking to find some shipping costs.\n");
	printf("I'd be happy to help you today.\n\n\n");

	printf("What city are you shipping this package to: ");
	scanf("%s", &location); FLUSH;                           // scan for location string input
	printf("\nHow far is this location (in miles): ");
	scanf("%i", &shipDistance);                              // scan for shipping distance input

	printf("\nHow much does the package weigh (in pounds): ");
	scanf("%lf", &weight);                                   // scan for package weight input
	
// [P]rocess
	if (weight <= 10) {                                // see if the weight is more than 10 pounds
		costWeight = flatShip;                         // set the cost of shipping by weight to the flat rate
		}else{                                         // otherwise, if the above isnt true do whats below
		costWeight = (weight - 10) * 1.55 + flatShip;  // set the cost of shipping by weight using the formula given
		
	
	}//end if

	if (shipDistance <= 250) {                         // look to see if shipDistance is less than or equal to 250 miles
		costDist = 6.66;                               // flat shipping cost of $6.66
	}else{
		//costDist = 6.66 * ((shipDistance / 250)+1);  < not sure why this did not work but the following does. 
		costDist = 6.66 * ((shipDistance-1) / 250 +1); // calculate the cost based on the distance. 
		                                               // every 250 miles is an increase of $6.66
	}// end if

	totalShipCost = costWeight + costDist;            // formula for total shipping cost 

	// [O]utput
	
	CLS; 

	printf("\nThank you.\n");
	printf("\n\n------------------------------------------------------------------------");
	printf("\nYou are shipping this package to: \t\t %s", location);
	printf("\nThe distance you want to ship this package is:\t %i miles.", shipDistance);
	printf("\nYour package weighs:\t\t\t\t %.2lf pounds.", weight);
	printf("\nCost to ship this package based on weight:\t $%.2lf", costWeight);
	printf("\nThe additional cost due to distance is:   \t $%.2lf ", costDist);
	printf("\n------------------------------------------------------------------------");
	printf("\n\nYour total today to ship this package is: \t $%.2lf\n\n", totalShipCost);
	printf("------------------------------------------------------------------------");
	printf("\n\n\n\n\nThank you and we look forward to shipping your package.\n\n\n\n\n");

	PAUSE;    // pause the screen
	return 0;  // return 0 to the computer if the program ran properly. 

}// End Main 