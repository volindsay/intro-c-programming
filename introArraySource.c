/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//////                                                                           ////
//////                                                                           ////
//////                           Intro to Arrays                                 ////
//////                                                                           ////
//////              Written by: Vincent Lindsay                                  ////
//////                                                                           //// 
//////              Written on: 07.09.18                                         ////
//////              Purpose   : This program was created to show off             ////
//////                          the usage of arrays, the passing of              ////
//////                          arrays to functions along with a full            ////
//////                          menu system and counter. The user is             ////
//////                          forced to choose option 1 or quit as             ////
//////                          the first choice to force input of               ////
//////                          numbers by the user.                             ////
//////                                                                           ////
//////                                                                           ////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define CLS system("cls")
#define NUMBERS 3
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/////////// PROTOTYPE IN HERE /////////////

void displayAllNumbers(int userNumbers[], int numberCount);
void displayAverage(int total, int numberCount, int userNumbers[]);
void displayErrorMSG();
void displayMenu();
int getChoice(int i);
int getTotal(int userNumbers[], int numberCount);
int getUserNumbers(int userNumbers[], int counter);
void quitMSG();
void welcomeMSG();
void displaySwitch();

/////////// MAIN CODE HERE ///////////////

main() {

	welcomeMSG();
	displaySwitch();

}

/////////// FUNCTIONS DOWN HERE ///////////
void displaySwitch() {
	int numberCount = 0;
	double average = 0.0;
	int choice = 0;
	int counter = 1;
	int i = 0;
	int total = 0;
	int userNumbers[NUMBERS] = { 0 };

	do {


		displayMenu();
		choice = getChoice(counter);
		switch (choice) {
		case 1:
			numberCount = getUserNumbers(userNumbers, counter);
			break;
		case 2:
			total = getTotal(userNumbers, numberCount);
			break;
		case 3:
			displayAverage(total, numberCount, userNumbers);
			break;
		case 4:
			displayAllNumbers(userNumbers, numberCount);
			break;
		case 5:
			quitMSG();
			break;
		default:
			displayErrorMSG();
			break;
		}
		counter++;
	} while (choice != 5);

	return;
}

void displayErrorMSG() {

	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPlease input a valid option. Thank you.\n\n\n\t\t\t\t\t    ");
	PAUSE;
	return;

} // end displayErrorMSG

int getUserNumbers(int userNumbers[], int counter) {
	int i;
	int result = 0;
	if (counter > 1) {                        // resetting the array 
		for (i = 0; i < NUMBERS; i++) {
			userNumbers[i] = 0;
		}
	}
	
	CLS;
	for (i = 0; i < NUMBERS; i++) {
		
			printf("\nPlease input a number (Press -999 to quit inputting numbers)\n");
			printf("%i: ", i + 1);
			scanf("%i", &userNumbers[i]);

			if (userNumbers[i] == -999) {
				result++;
				return result;
			}
			result++;
		
	} //end for loop 
	return result; 
} // end getUserNumbers

int getTotal(int userNumbers[], int numberCount){
	int result = 0;
	int counter = 0;   // counter for the amount of numbers input by user in to array. 
	int i;             
	int total = 0;

	for (i = 0; i <= numberCount; i++) {
		
		total += userNumbers[i];
		if (numberCount == userNumbers[i]) {
			
		}else if (userNumbers[i] == -999) {
			total += 999;           // I tried to make a check for -999 to quit but I could not figure how to get it to work
									// to bring the total back in line. 
		}
		//counter++;
	}

	result == total;
	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThe total for your numbers input is: %i\n\n\n\t\t\t\t\t", total);
	PAUSE;
	return total; 
} //end getTotal

void displayAverage(int total, int numberCount, int userNumbers[]) {
	int i;
	float average = 0.0;
	int correctAnswer = 0;                       // to make sure to use the proper formula. 
	for (i = 0; i < NUMBERS; i++) {
		if (userNumbers[i] == -999) {
			correctAnswer = 1;
		}
	}
	if (correctAnswer == 1) {
		average = (float)total / (numberCount - 1);
	}else{
		average = (float)total / numberCount;
	}

	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThe average for the numbers input is: %.2lf\n\n\n\t\t\t\t\t", average);
	printf("%i", numberCount);
	PAUSE;
	return;
} // end displayAverage

void displayAllNumbers(int userNumbers[], int numberCount){
	int i;
	CLS;
	printf("\n\n\n\nI will now post all the numbers you have input.\n\n");
	for (i = 0; i < NUMBERS; i++) {
		printf("%i. %i\n", i + 1, userNumbers[i]);
	} // end for loop
	printf("\nAll %i numbers have been posted to the screen.\n\n\n", NUMBERS);
	PAUSE;
	return;
} // end displayAllNumbers

void quitMSG(){
	
	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThanks for checking out my program!\n\n\n\t\t\t\t\t  ");
	PAUSE;
	return;

} //end quitMSG

void welcomeMSG(){
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThanks for checking out my program.");
	printf("\n\t\t\t\tYou will have a few options to perform math functions.");
	printf("\n\t\t\t\t\t\tPlease go in order.\n\n\n\n\t\t\t\t\t"); 
	PAUSE;
	return;
	
} //end welcomeMSG

void displayMenu(){
	
	CLS;
	printf("\n\n\n\n\t\t========================\n");                   // menu
	printf("\t\t      Main Menu\n");
	printf("\t\t========================\n");
	printf("\t\t1. Input numbers\n");
	printf("\t\t2. Your numbers totaled\n");
	printf("\t\t3. Your numbers averaged.\n");
	printf("\t\t4. Repeat your numbers.\n");
	printf("\n");
	printf("\t\t5. Quit.\n");
	printf("\t\t========================\n\n");
	printf("\t\tPlease select a number: ");
	return;

}//end displayMenu

int getChoice(int counter) {

	int i = counter;
	int choice;
	int result;
	scanf("%i", &choice);
	if (choice == 5)
	{
		result = 5;
	} else if (i == 1) {                // force user to use option 1 first for name input.
		result = i;
	} else {
		result = choice;
	}

	return result;

}// end getChoice