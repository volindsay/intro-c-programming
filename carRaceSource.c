///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
////                                                                       ////
////                           VALENCIA RACEWAY!                           ////
////                                                                       ////
////            Written by: Vincent Lindsay                                ////
////            Written on: 07.08.18                                       ////
////            Purpose   : To create a program that will race             ////
////                        three cars made of letters across              ////
////                        the screen utilizing loops and random          ////
////                        numbers generated.                             ////
////                                                                       ////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define CLS system("cls")
#define UB 3
#define LB 1
#define RACE 80
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>

///////////////// PROTOTYPE HERE /////////////////
void delay(int number_of_seconds);
int displayCars(int A, int B, int C);
int diceRoll();
void quitMSG();
char raceMore();
void startRace();
void welcomeMSG();
void winner(int A, int B, int C);

///////////////// MAIN /////////////////
main() {

	srand((unsigned)time(NULL));
	int pick = 0;
	char another = 'N';
	welcomeMSG();
	do {
		int A = 0;
		int B = 0;
		int C = 0;
		startRace();
		do {
			
			pick = diceRoll();
			int moveA = 0;
			int moveB = 0;
			int moveC = 0;
			switch (pick) {
			case 1:
				moveA = diceRoll();
				break;
			case 2:
				moveB = diceRoll();
				break;
			case 3:
				moveC = diceRoll();
				break;
			}
			A += moveA;                             // Add to the A check
			B += moveB;                             // Add to the B check
			C += moveC;                             // Add to the C check
			displayCars(A, B, C);

		} while (A < RACE && B < RACE && C < RACE);
		winner(A, B, C);
		another = raceMore();
	} while (toupper(another) != 'N');
	quitMSG();
	PAUSE;
	return 0;
} // end main

///////////////// FUNCTIONS BELOW HERE /////////////////
void delay(int number_of_seconds)
{
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Stroing start time
	clock_t start_time = clock();

	// looping till required time is not acheived
	while (clock() < start_time + milli_seconds)
		;
}
int diceRoll() {
	int result;
	result = LB + rand() % (UB - LB + 1);
	return result;
}//end diceRoll
int displayCars(int A, int B, int C) {
	int i;
	CLS;
	printf("\n\n\n\n");
	printf("START                                                                        FINISH\n\n");
	for (i = 0; i < A; i++) {
		printf("A");
	}
	printf("\n\n");
	for (i = 0; i < B; i++) {
		printf("B");
	}
	printf("\n\n");
	for (i = 0; i < C; i++) {
		printf("C");
	}
	printf("\n\n");
	
}//end displayCars
void quitMSG() {
	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\Thanks for checking out my program!\n\n\n\n\n\n\n\t\t\t\t\t  ");
}// end quitMSG()
char raceMore() {
	char result;
	printf("\n\n\t\t\t\t\t  Race again (Y/N): ");
	scanf("%c", &result);
	return result;

}// end raceMore
void startRace() {
	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tREADY?\n\n\n\n\n\t\t\t\t\t    ");
	delay(.5);
	PAUSE;
	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSET\n\n\n\n\n\t\t\t\t\t    ");
	delay(.5);
	PAUSE;
	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tGO!!!!!!!!\n\n\n\n\n\t\t\t\t\t    ");
	delay(.5);
	PAUSE;
}
void welcomeMSG() {

	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWelcome to my program!");
	printf("\n\n\t\t\t\t  In this program you will race three letters across the ");
	printf("\n\t\t\t\t  screen by a random number generator in the background.");
	printf("\n\n\t\t\t     Don't worry, you do not have to do anything but start the race!\n\n\n\t\t\t\t\t");
	PAUSE;
}//end welcomeMSG
void winner(int A, int B, int C) {
	char winner;
	char second;
	char third;
	if (A > B && A > C) {
		printf("\n\n\n\n\t\t\t\t\t\tA is the winner!\n\n");
		winner = 'A';
		if (B > C) {
			second = 'B';
		}
		else { second = 'C'; }
		if (B < C) {
			third = 'B';
		}
		else {
			third = 'C';
		}
	}
	else if (B > A && B > C) {
		printf("\n\n\n\n\t\t\t\t\t\tB is the winner!\n\n");
		winner = 'B';
		if (A > C) {
			second = 'A';
		}else{ 
			second = 'C'; 
		}
		if (A < C) {
			third = 'A';
		}
		else {
			third = 'C';
		}
	}
	else {
		printf("\n\n\n\n\t\t\t\t\t\tC is the winner!\n\n");
		winner = 'C';
		if (A > B) {
			second = 'A';
		}
		else { second = 'B'; }
		if (A < B) {
			third = 'A';
		}
		else {
			third = 'B';
		}
	}
	printf("\n\t\t\t\t\t============================\n");
	printf("\t\t\t\t\t	Winner List\n");
	printf("\t\t\t\t\t============================\n");
	printf("\t\t\t\t\t	  1st - %c\n", winner);
	printf("\t\t\t\t\t	  2nd - %c\n", second);
	printf("\t\t\t\t\t	  3rd - %c\n", third);
	printf("\t\t\t\t\t============================\n");
} // end winner