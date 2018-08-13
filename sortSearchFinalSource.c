///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
////                                                                           ////
////                           sortSearch Program                              ////
////                                                                           ////
////              Written by: Vincent Lindsay and Charlie Cristobal            ////
////                                                                           ////
////              Written on: 07.15.18                                         ////
////                                                                           ////
////              Purpose   : This program was created to show off             ////
////                          the usage of functions and arrays                ////
////                          to save, recall and manipulate the               ////
////                          array values created by the user.                ////
////                                                                           ////
////                                                                           ////
////                                                                           ////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define CLS system("cls")
#define SIZE 1000
#define FLUSH myFlush()
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>



void fillArrays(float userGPAs[]);
char getChoice(int counter, char choice);
float getGPAs(float userGPAs[]);
void getGPAAverage(float userGPAs[], float gpaCount);
void displayHighestGPA(float userGPAs[], float gpaCount);
void displayLowestGPA(float userGPAs[]);
void displayAdjustedGPA(float userGPAs[], float gpaCount);
void findGPA(float userGPAs[], float gpaCount);
void displayUserGPAs(float userGPAs[]);
void displayQuitMSG();

main() {
	int counter = 1; // this is to see how many times the do while loop has ran to force user to pick entry of numbers first.
	char choice = '\0';
	float userGPAs[SIZE];
	float gpaCount=0;
	fillArrays(userGPAs);
	do {
		
		CLS;
		printf("\n\n\n\n\t\t******************************************\n");                   // menu
		printf("\t\t\t\t Main Menu\n");
		printf("\t\t******************************************\n");
		printf("\n");
		printf("\t\tA. Enter GPA\n");
		printf("\t\tB. Display Average of all GPAs\n");
		printf("\t\tC. Display the Highest GPA\n");
		printf("\t\tD. Display the Lowest GPA\n");
		printf("\t\tE. Display the adjusted average\n");
		printf("\t\tF. See if a certain GPA was entered.\n");
		printf("\t\tG. Display the contents of the Array\n");
		printf("\n");
		printf("\t\tQ. Quit.\n\n");
		printf("\t\t******************************************\n\n");
		printf("\t\tPlease enter your selection: ");
		
		scanf(" %c", &choice);
		getChoice(counter, choice);
		switch (choice) {
		case 'a': case 'A':
			gpaCount = getGPAs(userGPAs);
			break;
		case 'b': case 'B':
			getGPAAverage(userGPAs, gpaCount);
			break;
		case 'c': case 'C':
			CLS;			
			displayHighestGPA(userGPAs, gpaCount);
			break;
		case 'd': case 'D':
			CLS;
			displayLowestGPA(userGPAs);
			break;
		case 'e': case 'E':
			CLS;
			displayAdjustedGPA(userGPAs, gpaCount);
			break;
		case 'f': case 'F':
			CLS;
			findGPA(userGPAs, gpaCount);
			PAUSE;
			break;
		case 'g': case 'G':
			CLS;
			displayUserGPAs(userGPAs);			
			break;
		case 'q': case 'Q':
			CLS;
			displayQuitMSG();
			PAUSE;
			break;
		default:
			break;
		}


	} while (toupper(choice) != 'Q');

	return 0;

} // end main


char getChoice(int counter, char choice) {
	int result = 0;
	
	if (choice == 'q') {              // check for what key user presses to allow quit or force first option for number entry
		choice = 'Q';
	}
	else if (counter == 1) {       // force the user to go to option A first
		choice = 'A';
	}
	else {
		choice = choice;               // after the above counter has increased it will allow any option.
	}
	return result;
} // end getChoice()
void getGPAAverage(float userGPAs[], float gpaCount) {
	CLS;
	float average = 0;
	float total = 0;
	for (int i = 0; i < gpaCount; i++) {
		total += userGPAs[i];
		if (userGPAs[i] == -999) {
			total += 999;
		} // end if else statement
	}// end for loop
	average = total / gpaCount;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThe average of the GPAs entered is: %.2f\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t", average);
	PAUSE;
	return;
}//end getGPAAverage

float getGPAs(float userGPAs[]) {
	CLS;
	float result = 0;
	int i;
	int gpaCount = 0.00;
	printf("\n\n\t\t\t==========================================\n");
	printf("\t\t\t\t\tGPA ENTRY\n");
	printf("\t\t\t==========================================\n\n");
	for (i = 0; i < SIZE; i++) {
		printf("\n\nPlease provide GPA number %i (0-5 / -999 to quit): ", i + 1);
		scanf("%f", &userGPAs[i]);
		
		if (userGPAs[i] == -999) {
			printf("\n\nThanks for your GPA entries!\n\n");
			PAUSE;
			break;
		}if (userGPAs[i] < 0 || userGPAs[i] > 5) {
			CLS;
			printf("\n\nPlease input a valid number 0 - 5 for a GPA.\n\n");
			PAUSE;
		}
		else if (userGPAs[i] <= 2.5) {
			printf("\nYou need to study harder\n\n");
		}
		else if (userGPAs[i] >= 3.5) {
			printf("\nNice work.\n\n");
		} // end if else statements
		gpaCount++;
	} // end for loop
	result = gpaCount;
	return result;
}//end getGPAs


void fillArrays(float userGPAs[]) {
	int i;
	for (i = 0; i < SIZE; i++) {
			userGPAs[i] = 0;
		}
	return;
}// end fillArrays
void displayHighestGPA(float userGPAs[], float gpaCount) {
	float bottom;
	int switchMade = 0;
	bottom = gpaCount - 1;
	do {
		switchMade = 0;
		for (int i = 0; i < bottom; i++) {
			if (userGPAs[i] > userGPAs[i + 1]) {
				int temp = userGPAs[i];
				userGPAs[i] = userGPAs[i + 1];
				userGPAs[i + 1] = temp;
				switchMade = 1;
			}//end if 
		}//end for
		bottom--;
	} while (switchMade == 1);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\The highest GPA entered is: ");
	printf("%.2f\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t", userGPAs[(int)gpaCount-1]);
	PAUSE;
	return;
} //end displayHighestGPA

void displayLowestGPA(float userGPAs[]) {
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\The lowest GPA entered is: ");
	printf("%.2f\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t", userGPAs[0]);


	PAUSE;
	return;

} //end displayLowestGPA

void displayAdjustedGPA(float userGPAs[], float gpaCount) {
	CLS;
	float adjusted = 0.00;
	float average = 0.00;
	float total = 0.00;
	for (int i = 0; i < gpaCount; i++) {
		total += userGPAs[i];
		if (userGPAs[i] == -999) {
			total += 999;
		} // end if else statement
	}// end for loop
	adjusted = (total - userGPAs[0]);
	average = adjusted / (gpaCount-1);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThe adjusted average of the GPAs entered is: %.2f\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t", average);
	PAUSE;
	return;
}//end displayAdjustedGPA

void findGPA(float userGPAs[], float gpaCount) {
	float findGPA = 0;
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\tPlease enter a GPA value that you would like to find (up to 2 decimal places): ");
	scanf("%f", &findGPA);
	CLS;
	int found = 0;
	for (int i = 0; i <= gpaCount; i++) {
		if (userGPAs[i] == findGPA) {
			printf("\n\n\t\t\t\t\tThe GPA, %.2f, was found at %i position in the array.\n\n", findGPA, i);
			found++;
		}
	}
	if (found == 0) {
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tNo matches were found. Sorry.\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
	}
	
	return;
}//end findGPA

void displayUserGPAs(float userGPAs[]) {
	CLS;
	printf("\n\n\nDisplaying the full array for you.\n");
	printf("----------------------------------\n");
	//printf("\n\n");
	//for (int i = 0; i < userGPAs[SIZE]; i++) {
	for (int i = 0; i < SIZE; i++) {
		printf("%i %.2f\n", i+1, userGPAs[i]);
	}
	
	PAUSE;
	return;
}// end displayuserGPAs

void displayQuitMSG() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\Thanks for checking out our program.\n\n\n\n\t\t\t\t\t");
	return;
}// end displayQuitMSG()