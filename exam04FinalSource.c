///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
////                                                                           ////
////                      INTRO TO C PROGRAMMING EXAM 04                       ////
////                                                                           ////
////              Written by: Vincent Lindsay                                  ////
////                                                                           ////
////              Written on: 07.15.18                                         ////
////                                                                           ////
////              Purpose   : This program was created for the last            ////
////                          exam of the class. It is an election             ////
////                          simulator for what would happen with             ////
////                          an election between Michelle Obama               ////
////                          and Ivanka Trump. Each section should            ////
////                          be performed in order and will give              ////
////                          the run down of stats. This was done             ////
////                          as an automatic simulator based on               ////
////                          translation of the spec. Options can             ////
////                          easily be modified to allow only user            ////
////                          input in to the arrays.                          ////
////                                                                           ////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define CLS system("cls")
#define UB 100000000 
#define LB 1000000
#define VOTES 50
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



void displayCombinedVotes(int i, int states[], int obamaVotes[], int trumpVotes[]);
void displayElectionStats(int obamaVotes[], int trumpVotes[]);
void displayElectionOver();
void displayEqualVotes(int oV[], int tV[]);
void displayErrorMSG();
void displayIntro();
void displayMenu();
void displayObamaVotes(int obamaVotes[], int states[]);
void displayTotalVotes(int obamaVotes[], int trumpVotes[]);
void displayTrumpVotes(int trumpVotes[], int states[]);
void fillStatesArray(int i, int states[], int voters[], int obamaVotes[], int trumpVotes[]);
int getVotes();
void sorter(int obamaVotes[], int trumpVotes[]);
void sorterTrump(int trumpVotes[]);
void sorterObama(int obamaVotes[]);

main() {
	srand(time(NULL));  // seed the random function
	int voters[VOTES] = { 0 };
	int states[VOTES] = { 0 };
	int obamaVotes[VOTES] = { 0 };
	int trumpVotes[VOTES] = { 0 };
	int i = 0;
	int selection = 0; 
	int counter = 1; // force the user to populate the votes. 
	displayIntro();
	fillStatesArray(i, states, voters, obamaVotes, trumpVotes); // load the arrays with zeros
	
	do {
		displayMenu();
		selection = getChoice(counter);

		switch (selection) {
				case 1:
					displayTrumpVotes(trumpVotes, states);
					break;
				case 2:
					displayObamaVotes(obamaVotes, states);
					break;
				case 3:
					displayTotalVotes(obamaVotes, trumpVotes);
					break;
				case 4:
					sorter(obamaVotes, trumpVotes);
					break;
				case 5:
					displayEqualVotes(obamaVotes, trumpVotes);
					break;
				case 6:
					displayElectionStats(obamaVotes, trumpVotes);
					break;
				case 7:
					displayElectionOver();
					break;
				default:
					displayErrorMSG();
					break;
			
				}
		counter++;
	} while (selection != 7);   // do this until 7 is selected. 
	
	PAUSE;
	return 0;
}


void displayCombinedVotes(int i, int states[], int obamaVotes[], int trumpVotes[]) {
	CLS;
	printf("==================================================\n");
	printf("||\tObama Votes\t||\tTrump Votes\t||\n");
	printf("==================================================\n");
	for (i = 0; i < VOTES; i++) {

		printf("||\t%i. %i\t||\t%i. %i\t||\n", states[i] + 1, obamaVotes[i], states[i] + 1, trumpVotes[i]);
	}
	PAUSE;
} //end displayCombinedVotes

void displayElectionOver() {
	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe election is now over. ");
	printf("\n\t\t\t\t\t  Your new president has been chosen.");
	printf("\n\t\t\t\t\t\t  Was it your choice?\n\n\n\n\t\t\t\t\t   ");
}// end displayElectionOver

void displayElectionStats(int obamaVotes[], int trumpVotes[]) {
	int obamaTotal = 0;
	int trumpTotal = 0;
	for (int i = 0; i < VOTES; i++) {

		obamaTotal += obamaVotes[i];
	}
	for (int i = 0; i < VOTES; i++) {

		trumpTotal += trumpVotes[i];
	}
	CLS;
	printf("\t\t\t==================================================================\n");
	printf("\t\t\t||\t\t     Election Stats Breakdown\t\t\t||\n");
	printf("\t\t\t==================================================================\n");
	printf("\t\t\t||               ||\tMichelle Obama\t||\tIvanka Trump\t||\n");
	printf("\t\t\t==================================================================\n");
	printf("\t\t\t|| Highest Votes ||\t%i\t\t||\t%i\t\t||\n", obamaVotes[VOTES-1], trumpVotes[VOTES - 1]);
	printf("\t\t\t------------------------------------------------------------------\n");
	printf("\t\t\t|| Lowest Votes  ||\t%i\t\t||\t%i\t\t||\n", obamaVotes[0], trumpVotes[0]);
	printf("\t\t\t------------------------------------------------------------------\n");
	printf("\t\t\t|| Average Votes ||\t%i\t\t||\t%i\t\t||\n", (obamaTotal / VOTES) , (trumpTotal / VOTES));
	printf("\t\t\t------------------------------------------------------------------\n");
	printf("\t\t\t||\t\t\t\t\t\t\t\t||\n");
	printf("\t\t\t------------------------------------------------------------------\n");
	printf("\t\t\t||  Total Votes  ||\t%i\t||\t%i\t||\n", obamaTotal, trumpTotal);
	printf("\t\t\t==================================================================\n");
	printf("\n\n\n\t\t\t\t\tWinner: ");
	if (obamaTotal > trumpTotal) {
		printf("Michelle Obama\n\n\n\t\t\t\t  ");
	}
	else
	{
		printf("Ivanka Trump\n\n\n\t\t\t\t  ");
	}
	PAUSE;
}// end displayElectionStats()

void displayEqualVotes(int oV[], int tV[]) {

	CLS;
	int counter = 0;  // tie counter
	int tied[VOTES] = { 0 };
	for (int i = 0; i < VOTES; i++) {
		if (oV[i] == tV[i]) {
			tied[i] = i;
			counter++;
			printf("\n\nObama and Trump had the same votes in the following states:\n\n");
			for (i = 0; i <= strlen(tied); i++) {
				printf("%i\n", tied[i]);
			}

		}
	}//end for
	if (counter == 0) {
		printf("\n\n\n\n\n\t\t\t\tThere were no states where the candidates tied.\n\n\n\n\n\t\t\t\t\t");
	}

	PAUSE;
} //end displayEqualVotes

void displayErrorMSG() {

	CLS;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPlease input a valid option. Thank you.\n\n\n\t\t\t\t\t    ");
	PAUSE;
	return;

} // end displayErrorMSG

void displayIntro() {
	printf("\n\n\n\n\n\n\t\t\t==============================================================================");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t    2020 ELECTION SIMULATOR\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==\t\t\t\t\t\t\t\t\t\t==");
	printf("\n\t\t\t==============================================================================\n\n\n\n\n\t\t\t\t\t\t");
	PAUSE;
	CLS;
} // end displayIntro

void displayMenu() {

	CLS;
	printf("\n\n\n\n\t\t=========================================================\n");                   // menu
	printf("\t\t      Main Menu\n");
	printf("\t\t=========================================================\n");
	printf("\t\t1. Enter votes for Ivanka Trump\n");
	printf("\t\t2. Enter votes for Michelle Obama\n");
	printf("\t\t3. Display total votes for each candidate\n");
	printf("\t\t4. Display all votes for selected candidate in order\n");
	printf("\t\t5. Display equal state votes\n");
	printf("\t\t6. Voting breakdown\n");
	printf("\n");
	printf("\t\t7. Exit.\n");
	printf("\t\t=========================================================\n\n");
	printf("\t\tPlease select a number: ");
	return;

}//end displayMenu

void displayObamaVotes(int obamaVotes[], int states[]) {
	CLS;
	for (int i = 0; i < VOTES; i++) {
		obamaVotes[i] = getVotes(i);
	}
	printf("==================================\n");
	printf("||\t    Obama Votes\t\t||\n");
	printf("==================================\n");
	printf("||\tState\t||     Votes\t||\n");
	printf("==================================\n");
	for (int i = 0; i < VOTES; i++) {
		printf("||\t%i.\t||    %i\t||\n", states[i] + 1, obamaVotes[i]);
	}
	PAUSE;
} // end displayObamaVotes

void displayTotalVotes(int obamaVotes[], int trumpVotes[]) {

	int obamaTotal = 0;
	int trumpTotal = 0;
	for (int i = 0; i < VOTES; i++) {

		obamaTotal += obamaVotes[i];
	}
	for (int i = 0; i < VOTES; i++) {

		trumpTotal += trumpVotes[i];
	}
	CLS;
	printf("\t\t\t\t==================================================\n");
	printf("\t\t\t\t||\t\t    Total Votes\t\t\t||\n");
	printf("\t\t\t\t==================================================\n");
	printf("\t\t\t\t||\tObama Votes\t||\tTrump Votes\t||\n");
	printf("\t\t\t\t==================================================\n");
	printf("\t\t\t\t||\t%i\t-\t%i\t||\n", obamaTotal, trumpTotal);
	printf("\t\t\t\t==================================================\n\n\n\t\t");
	if (obamaTotal > trumpTotal) {
		printf("\n\n\n\t\t\t\tMichelle Obama has won the election by %i votes.\n\n\n\t\t\t\t", obamaTotal - trumpTotal);
	}
	else {
		printf("\n\n\n\t\t\t\tIvanka Trump has won the election by %i votes.\n\n\n\t\t\t\t\t", trumpTotal - obamaTotal);
	}
	PAUSE;
	return;

} //end displayTotalVotes()

void displayTrumpVotes(int trumpVotes[], int states[]) {
	CLS;
	for (int i = 0; i < VOTES; i++) {
	trumpVotes[i] = getVotes(i);
	}
	printf("==================================\n");
	printf("||\t    Trump Votes\t\t||\n");
	printf("==================================\n");
	printf("||\tState\t||     Votes\t||\n");
	printf("==================================\n");
	for (int i = 0; i < VOTES; i++) {
		printf("||\t%i.\t||    %i\t||\n", states[i] + 1, trumpVotes[i]);
	}
	PAUSE;
} // end displayTrumpVotes()

void fillStatesArray(int i, int states[], int voters[], int obamaVotes[], int trumpVotes[]) {
	for (i = 0; i < VOTES; i++) {
		states[i] = i;
	}
	for (i = 0; i < VOTES; i++) {
		obamaVotes[i] = i;
	}
	for (i = 0; i < VOTES; i++) {
		trumpVotes[i] = i;
	}
	for (i = 0; i < VOTES; i++) {
		voters[i] = i;
	}
} //end fillStatesArray

int getChoice(int counter) {
	// force user to use options in order to make sure that there are no errors in the results. 
	int i = counter;
	int selection;
	int result;
	scanf("%i", &selection);
	if (selection == 7)
	{
		result = 7;
	}
	else if (i == 1 ) {                
		
		result = i;
	}
	else if (i == 2) {
		result = i;
	}
	else if (i == 3) {
		result = i;
	}
	else if (i == 4) {
		result = i;
	}else {
		result = selection;
	}

	return result;

}// end getChoice

int getVotes() {
	int result;
	result = LB + rand() % (UB - LB) + 1;
	return result;
} // end getVotes() 

void sorter(int obamaVotes[], int trumpVotes[]) {
	int choice = 0;
	do {
		CLS;
		printf("Who would you like to see the votes for in order?\n");
		printf("1. Ivanka Trump\n");
		printf("2. Michelle Obama\n");
		printf("3. Back\n");
		scanf("%i", &choice);
		if (choice == 1) {
			sorterTrump(trumpVotes);
		}
		else if (choice == 2) {
			sorterObama(obamaVotes);
		}
		else if (choice == 3) {
			return;
		}
	} while (choice != 3);
}//end sorter

void sorterObama(int obamaVotes[]) {
	int switchMade = 0;
	int bottom = VOTES - 1;
	do {
		switchMade = 0;
		// bubble sorter
		for (int i = 0; i < bottom; i++) {
			if (obamaVotes[i] > obamaVotes[i + 1]) {
				int temp = obamaVotes[i];
				obamaVotes[i] = obamaVotes[i + 1];
				obamaVotes[i + 1] = temp;
				switchMade = 1;				
			} // end if
			
		}// end for
		bottom--;
	} while (switchMade == 1);
	CLS;
	
	printf("==================================\n");
	printf("||\t    Obama Votes\t\t||\n");
	printf("==================================\n");
	printf("||\t\tVotes\t\t||\n");
	printf("==================================\n");
	for (int i = 0; i < VOTES; i++) {
		printf("||\t\t%i\t\t||\n", obamaVotes[i]);
	}
	PAUSE;
}//end sorterObama

void sorterTrump(int trumpVotes[]) {
	int switchMade;
	int bottom = VOTES - 1;
	do {
		switchMade = 0;
		// bubble sorter
		for (int i = 0; i < bottom; i++) {
			if (trumpVotes[i] > trumpVotes[i + 1]) {
				int temp = trumpVotes[i];
				trumpVotes[i] = trumpVotes[i + 1];
				trumpVotes[i + 1] = temp;
				switchMade = 1;				
			} // end if
		}// end for
		bottom--;
	} while (switchMade == 1);
	CLS;
	
	printf("==================================\n");
	printf("||\t    Trump Votes\t\t||\n");
	printf("==================================\n");
	printf("||\t\tVotes\t\t||\n");
	printf("==================================\n");
	for (int i = 0; i < VOTES; i++) {
		printf("||\t\t%i\t\t||\n", trumpVotes[i]);
	}
	PAUSE;
	
} //end sorterTrump



