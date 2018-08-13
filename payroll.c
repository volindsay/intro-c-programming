/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//                           Payroll Calculator                            //
//                                                                         //
//              Written by: Vincent Lindsay                                //
//              Written on: 06.09.18                                       //
//              Purpose   : To create a program that will calculate        //
//                          a total paycheck amount based on the           //
//                          users input in to the program.                 //
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

	int selection;                // menu selection number
	char another;                 // repeating quesiton in menus

	do {                          // start of the do while loop; a piece of code to repeat
		CLS;                      // clear the screen 
	printf("==============================\n");     // outputs to the screen of menu
	printf("\tCalculators!\n");
	printf("==============================\n\n");
	printf("Select an option:\n");
	printf("\n\n1. Payroll Calculator\n");
	printf("2. Shipping Calculator\n");
	printf("3. Quit.\n");
	printf("\n\nYour selection is: ");
	scanf("%i", &selection);                       // scan for menu selection

	
		switch (selection) {                        // switch of the menu. code is ran when case number is selected.
		case 1:                                     // case 1 or option 1 from the menu
			do {                                    // start of a new do while loop nested in the previous do while loop. 
				CLS;								// clear the screen 
				float rate = 0.0;                   // variables for this set of code. variables need to be placed in to the local area 
				float pay = 0.0;                    // and not in to the overall global area. 
				float hours = 0.0;
				float overtime = 0.0;
				float overtimePay = 0.0;
				float gross = 0.0;
				float const FED = .27;            // federal tax rate as a constant. If this ever changes we only need to change the number here
				float const MED = .14;            // medical insurance rate from check.   
				float fico = 0.0;                 
				float medical = 0.0;
				float netPay = 0.0;
				float deductions = 0.0;
				float totalGross = 0.0;
				

				printf("\t\t\tPayroll Calculator\n\n");
				printf("Let's find out how much your paycheck will be.\n\n");

				// [I]nput
				printf("Enter your pay rate: ");                   // show the text to the screen
				scanf("%f", &rate);                                //scan for the pay rate
				printf("\nEnter your normal hours: ");             // show the text to the screen
				scanf("%f", &hours);                               //scan for the hours worked
				printf("\nEnter your overtime hours: ");           // show the text to the screen
				scanf("%f", &overtime);                            // scan if they performed any overtime

				// [P]rocess
				gross = hours * rate;                             // gross pay before Overtime
				overtimePay = overtime * (1.5 * rate);            // overtime pay
				totalGross = gross + overtimePay;                 // total gross pay for the time period
				fico = totalGross * FED;                          // the user's federal tax amount taken out
				medical = totalGross * MED;                       // the user's medical deduction
				deductions = fico + medical;                      // total of the deductions 
				netPay = totalGross - deductions;                 // net pay after deductions removed. 

				// [O]utput
				CLS;                                                                         // clear the screen
				printf("=========================================================\n");       // output the following to the screen
				printf("=                   YOUR PAY BREAKDOWN                  =\n");
				printf("=========================================================\n");
				printf("                  Payrate: $%.2lf                      \n", rate);  // calls for what is stored in the rate variable
				printf("                                                       \n");
				printf("     Hours Worked: %.2f     Overtime Hours: %.2f     \n", hours, overtime); // calls for what is in the hour and overtime variables.
				printf("     Normal Pay: $%.2f       Overtime Pay: $%.2f     \n", gross, overtimePay);  // calls for gross and overtime pay
				printf("                                                       \n");
				printf("                 Gross Pay: $%.2f                     \n", totalGross);    // total amount with OT but not deductions
				printf("                                                       \n");
				printf("       Federal Tax: $%.2f    Medical: $%.2f        \n", fico, medical);    // deductions 
				printf("                                                      \n");
				printf("=========================================================\n");
				printf("=                   Net Pay: $%.2lf\t\t\t=\n", netPay);                     // final pay for the hours worked. 
				printf("=========================================================\n\n\n\n\n\n");


				PAUSE;                                                                // pause the screen so that the output can be seen.
				CLS;                                                                  // clear the screen
				printf("Would you like to calculate another check (Y/N): ");          // ask the user if they want to calculate another check 
				scanf(" %c", &another);                                               // scan for answer 
			} while (another != 'n');                                                 // if the answer is NOT n, redo the previous code aka loop.
			                                                                          // when this is n, stop the code and move on. 
			break;                                                                    // stop the code and do not process any other cases.



			// CASE 2 SHIPPING CALC
		case 2:
			CLS;
			do {
				// Define Variables

				double weight = 0.0;      // weight of the package
				int    shipDistance = 0;  // distance to ship
				double flatShip = 10.00;  // flat shipping cost
				double costDist = 0.0;    // cost based on distance
				double costWeight = 0.0;  // cost based on weight
				double totalShipCost = 0.0; // final cost
				char location[50];
				// [I]nput
				printf("\t\t\t\t\tShipping Cost Calculator\n\n");
				printf("\t\t\t\t\t\tWelcome!\n");
				printf("You're looking to find some shipping costs.\n");
				printf("I'd be happy to help you today.\n\n\n");

				printf("What city are you shipping this package: ");
				scanf("%s", &location); FLUSH;                           // scan for location string input
				printf("\nHow far is this location (in miles): ");
				scanf("%i", &shipDistance);                              // scan for shipping distance input

				printf("\nHow much does the package weigh (in pounds): ");
				scanf("%lf", &weight);                                   // scan for package weight input

				// [P]rocess
				if (weight <= 10) {                                // see if the weight is more than 10 pounds
					costWeight = flatShip;                         // set the cost of shipping by weight to the flat rate
				}
				else {                                         // otherwise, if the above isnt true do whats below
					costWeight = (weight - 10) * 1.55 + flatShip;  // set the cost of shipping by weight using the formula given


				}//end if
				if (shipDistance <= 250) {                         // look to see if shipDistance is less than or equal to 250 miles
					costDist = 6.66;                               // flat shipping cost of $6.66
				}
				else {

					costDist = 6.66 * ((shipDistance - 1) / 250 + 1); // calculate the cost based on the distance. 
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
				CLS;
				printf("Would you like to calculate another package cost (Y/N): ");
				scanf(" %c", &another);
			}while (another != 'n');
			break;
		case 3:                                                        // case 3, quit. if the user picks this
			CLS;                                                       // the screen will clear out
			printf("Have a nice day!\n\n\n");                          // and tell the user have a nice day
			PAUSE;                                                     // when the user hits any key it will
			break;                                                     // exit the program fully. 
		default:                                                       // default case. If the user provides a wrong choice in the 
			                                                           // inital menu this will correct them to choose a proper answer. 
			CLS;                                                       // clear the screen
			printf("\nThat is not a valid selection. Please choose again.\n\n\n");  // inform the user of wrong choice. 
			PAUSE; 
		} // end switch
	}while (selection != 3);                // when the answer is not 3, repeat. When the answer hits three, exit the program. 

	
	return 0;                              // return 0 to the cpu if nothing is wrong. 

} // end main