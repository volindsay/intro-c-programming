/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                           Payroll Calculator                                //
//                                                                             //
//              Written by: Brad Cowgill, Jose Rodolfo Gamez Alvarado,         //
//                          Vincent Lindsay and Casey Smith                    // 
//              Written on: 06.11.18                                           //
//              Purpose   : Created for exam02, as a team, we were tasked      //
//                          to create a program that will ask for input        //
//                          from the user, sort the numbers, add, multiply     //
//                          as well as inform the user if the number is        //
//                          even, odd, prime or not prime.                     //
//                                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH myFlush()
#include <stdio.h>
#include <stdlib.h>

// code to flush the buffer 

void myFlush() {
	while (getchar() != '\n');
} // end myFlush

main() {                     // start of the main block

							 //define the variables 

	int firstNumber, secondNumber, thirdNumber, fourthNumber = 0;
	int numberEntered = 0;
	int repetition;
	int repetititon2;
	int number = 0;
	int sum, product = 0;
	int largestNumber, smallestNumber = 0;
	int factor, countFactors = 0;


	// User instructions

	printf("\nIn the following program you will enter four integer values.\n\n");
	printf("The program will output: \n");
	printf("\n- the largest number\n");
	printf("- the smallest number\n");
	printf("- if the number is even or odd\n");
	printf("- if the number is PRIME or NOT PRIME\n");
	printf("- the sum and product of the numbers.\n");
	printf("\n\nEnjoy :)\n\n\n");
	PAUSE;
	CLS;

	//Ask the user for input
	printf("\n\n\n");

	for (repetition = 1; repetition < 5; repetition++) {                                    // start of repetition loop
		do {                                                                                // Error checking 

			printf("Enter your integer #%i (a number between -50 and 100):", repetition);   // request a number from the user between -50 and 100
			scanf("%i", &numberEntered); FLUSH;                                             // scan for the input by the user and set to numberEntered. Flush the buffer after
			if (numberEntered < -50 || numberEntered > 100) {                               // if the user does not input properly perform this check
				printf("Make sure you entering a value between -50 and 100.\n\n");          // inform the user they did wrong. 
				PAUSE;                                                                      // pause so the user can see the issue
				printf("\n\n");                                                             // spacing for the loop to start again. 
			} //end if
			if (repetition == 1)                                                            // if the loop is on loop 1 
				firstNumber = numberEntered;                                                // give the firstNumber the value of the numberEntered
			if (repetition == 2)                                                            // if the loop is on loop 2 
				secondNumber = numberEntered;                                               // give the secondNumber the value of the numberEntered
			if (repetition == 3)                                                            // if the loop is on loop 3 
				thirdNumber = numberEntered;                                                // give the thirdNumber the value of the numberEntered
			if (repetition == 4)                                                            // if the loop is on loop 4 
				fourthNumber = numberEntered;                                               // give the fourthNumber the value of the numberEntered
		} while (numberEntered < -50 || numberEntered > 100);                               // only perform this if the number makes it true < -50 or > 100 
	} // end for loop and end of input

	CLS;                                                                                    // clears input 

	printf("\n===========================================================================\n\n");


	// Beginning of process 

	printf("The four numbers you entered are :  %i, %i, %i, %i\n\n",
		firstNumber, secondNumber, thirdNumber, fourthNumber);              // inform the user of the numbers input
	sum = firstNumber + secondNumber + thirdNumber + fourthNumber;          // add the numbers provided above

	printf("The sum of %i + %i + %i + %i = %i\n\n", firstNumber, secondNumber, thirdNumber, fourthNumber, sum); // output the sum

	product = firstNumber * secondNumber * thirdNumber * fourthNumber;   // multiplication of the numbers 

	printf("The product of %i * %i * %i * %i = %i\n\n", firstNumber, secondNumber, thirdNumber, fourthNumber, product); // output the product of the numbers

	smallestNumber = firstNumber;                 // set smallestNumber to firstNumber 
	largestNumber = firstNumber;                  // set largestNumber to firstNumber

	if (secondNumber < smallestNumber)            // If the secondNumber less than smallestNumber
		smallestNumber = secondNumber;            // set smallestNumber to secondNumber

	if (secondNumber > largestNumber)             // If the secondNumber is bigger than largestNumber
		largestNumber = secondNumber;             // set largestNumber to secondNumber


	if (thirdNumber < smallestNumber)             // If the thirdNumber less than smallestNumber
		smallestNumber = thirdNumber;             // set smallestNumber to thirdNumber 

	if (thirdNumber > largestNumber)              // If the thirdNumber less than largestNumber
		largestNumber = thirdNumber;              // set largestNumber to thirdNumber


	if (fourthNumber < smallestNumber)            // If the fourthNumber less than smallestNumber
		smallestNumber = fourthNumber;            // set smallestNumber to fourthNumber

	if (fourthNumber > largestNumber)            // If the fourthNumber less than largestNumber
		largestNumber = fourthNumber;            // set largestNumber to fourthNumber

	// output for smallest and largest numbers

	printf("The largest number is %i.\n\n", largestNumber);
	printf("The smallest number is %i.\n\n", smallestNumber);



	// beginning of loop for even/odd and prime/not prime

	for (repetititon2 = 1; repetititon2 < 5; repetititon2++) {
		if (repetititon2 == 1)                                         // if this is the first repetition
			number = firstNumber;                                      // number gets firstNumber
		if (repetititon2 == 2)                                         // if this is the second repetition
			number = secondNumber;                                     // number gets secondNumber
		if (repetititon2 == 3)                                         // if this is the thirdrepetition
			number = thirdNumber;                                      // number gets thirdNumber
		if (repetititon2 == 4)                                         // if this is the fourth repetition
			number = fourthNumber;                                     // number gets fourthNumber

		if (number % 2 == 0)                                           // checks to see if the number is even or odd
			printf("The number %i is even and ", number);              // output if the number is even 
		else printf("The number %i is odd and ", number);              // or odd



		for (factor = 1; factor <= number; factor++) {                 // checks for prime and not prime
			if (number % factor == 0) {
				countFactors++;
			}
		}

		if (countFactors == 2)
			printf("is PRIME.\n\n");
		else
			printf("is NOT PRIME.\n\n");

		countFactors = 0;

	}
	printf("===========================================================================\n\n\n");

	PAUSE;                                                      // pause the screen for user to see output
	CLS;                                                        // clear the screen after keyboard press
	printf("\n\n\n\n");                                         // space
	printf("Thank you for using our program :)\n\n\n\n\n");     // thank the user

	PAUSE;
	CLS;

} // end of main 