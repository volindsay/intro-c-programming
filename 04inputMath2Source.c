/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
////                                        inputMath2                                           ////
////                                                                                             ////
////         Written By   : Vincent Lindsay                                                      ////
////         Date Written : 05/24/2018                                                           ////
////         Purpose      : The purpose of this program is to have simple arithmetic actions     ////
////                        performed with numbers requested from the user. The numbers will     ////
////                        display to the screen. The test case numbers are provided on the     ////
////	                    bottom of the screen. This project will display knowledge of         ////
////                   	    variables, float, double float, placeholders, etc.                   ////
////                                                                                             ////
////                                                                                             ////
////                                                                                             ////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS      // used for scanf function
#define PAUSE system("pause")        // shortcut for system function pause
#include <stdio.h>                   // header file for standard input and output
#include <stdlib.h>			         // header file for the standard library

main() {				             // start of the main block

	// Define Variables 
	double fOne = 0.0;				 // double float variable
	double fTwo = 0.0;               // double float variable
	double fThree = 0.0;             // double float variable
	double fResult = 0.0;            // double float variable
	double fMResult = 0.0;           // double float variable
	double fDResult = 0.0;           // double float variable

	// Input 

	printf("\t\t\t\t\t\tinputMath2\n");                                // name of the program
	printf("\n\n\t\t\t\t\tWelcome to my Program!");                    // welcoming user to program
	printf("\n\n\nPlease provide me with three decimal numbers.\n");   // Request for decimal numbers
	printf("\nFirst decimal number: ");                                // request for first decimal
	scanf("%lf", &fOne);                                               // scan for decimal and set variable to number
	printf("\nSecond decimal number: ");                               // request for second decimal                              
	scanf("%lf", &fTwo);                                               // scan for decimal and set variable to number
	printf("\nThird decimal number:  ");                               // request for third decimal
	scanf("%lf", &fThree);                                             // scan for decimal and set variable to number

	// process 
	fResult = fOne + fTwo + fThree;                                    // additions of the variables set to fResult
	fMResult = fResult * fThree;                                       // multiplication of fResult and fThree set to fMResult
	fDResult = fMResult / fTwo;                                        // division of fMResult and fTwo set to fDResult

	printf("\n\nThe sum of %.2lf + %.2lf + %.2lf = %.2lf", fOne, fTwo, fThree, fResult);     // output sum to screen going two decimal places to the right only and remind of what numbers were used
	printf("\n\nThe sum of %.2lf multiplied by %.2lf = %.2lf.", fResult, fThree, fMResult);  // output multiplication to screen going two decimal places to the right only and remind of what numbers were used
	printf("\n\nAfter multiplying %.2lf and obtaining the result %.2lf, we can divide it by %.2lf for a result of %.2lf.\n\n\n\n", fResult, fMResult, fTwo, fDResult); // output division to screen going two decimal places to the right only and remind of what numbers were used

	PAUSE;       // stop the program from closing after execution

	return 0;    // send 0 back if program was ran properly. 
} // end main
