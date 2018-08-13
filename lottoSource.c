/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//                           VALENCIA LOTTO!                               //
//                                                                         //
//              Written by: Vincent Lindsay                                //
//              Written on: 06.17.18                                       //
//              Purpose   : To create a lottery program that will          //
//                          have the user input their favorite             //
//                          number and check to see how much they          //
//                          won in a lotto scenario.                       //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS   // scan without errors
#define PAUSE system("pause")     // Setup a pause shorthand
#define CLS   system("cls")       // setup a clear screen shorthand
#define FLUSH myFlush()           // flush the keyboard buffer 
#include <stdio.h>                // load the standard input output header file
#include <stdlib.h>               // load the standard library header file
#include <conio.h>                // to allow for colors


void myFlush() {                  // code for the keyboard flush
	while (getchar() != '\n');
} // end myFlush
main() {

	// variables
	int i;                               // counter variable
	int lottoNum;                        // random lotto number 
	int userNum = 0;                     // user chosen number
	int winnings = 0;                    // users winnings
	int bank = 365;                      // users bank account
	int const WIN = 500;                 // winnings per win
	int winCount = 0;                    // amount of times user won
	int ticketCount = 0;                 // amount of tickets bought
	int moneySpent = 0;                  // money spent on tickets
	int earnings = 0;                    // earnings from playing
	char again = 'N';                    // perform again
	 srand(time(NULL));                  // seed the random generator 

	
	// [I]nput
	
		
		system("COLOR C");                              // change the color of the text to the hexadecimal value

		printf("\n\t\t\tVALENCIA LOTTO!\n");            // welcome
		printf("\n\n\n");
		PAUSE;                                          // pause the screen so the information is viewable
		CLS;                                            // clear the screen
	do {       
		winnings = 0;
		earnings = 0;
		moneySpent = 0;
		ticketCount = 0;
		winCount = 0;
		CLS;
		system("COLOR F");                                                                             // change the color again
		printf("You have $%i to spend on a years worth of lotto tickets.\n", bank);                    // inform user
		do {
			printf("Let's get your favorite 3 digit number to use for the lotto all year long: ");     // request lotto number
			scanf("%i", &userNum);                                                                     // scan for value
			if (userNum < 000 || userNum > 999) {                                           // if the user does not input properly perform this check
				printf("Make sure you entering a value between 000 and 999!\n\n");          // inform the user they did wrong. 
				PAUSE;                                                                      // pause so the user can see the issue

				printf("\n\n");                                                             // spacing for the loop to start again. 
			} //end if
		} while (userNum < 000 || userNum > 999);                                           // do this again when the number is below 0 and above 999

		CLS;
		// [P]rocess

		for (i = 0; i < 365; i++) {                                                         // for loop; start i at 0, while it is lower than 365, perform whats under. 
			                                                                                // Each loop increase the amount i is worth. 
			
			lottoNum = (rand() % 999)+1;                                                     // lottoNum gets a random number from 0 - 999  
			ticketCount++;                                                                  // increase the value of ticketCount by 1
			bank--;                                                                         // decrease the value of bank variable by 1 
			if (lottoNum == userNum) {                                                      // if the lottoNum is equal to userNum
				bank = bank + WIN;                                                          // bank get bank + WIN constant
				winCount++;                                                                 // increase winCount
			} // end if
		} // end for loop

		winnings = winCount * WIN;                                                          // calculations for winnings
		moneySpent = ticketCount;                                                           // set moneyspent to ticketcount
		earnings = winnings - moneySpent;                                                   // earnings calculation
		// [O]utput
		printf("The number you chose for your year of tickets was: %i\n", userNum);
		if (winCount > 0) {                                                                 // if the wincount is greater than 0 output the following
			system("COLOR A");                                                              // change the color of the text
			printf("\nWINNER!!!WINNER!!!WINNER!!!WINNER!!!WINNER!!!WINNER!!!WINNER!!!\n");
			printf("WINNER!!!                                             WINNER!!!\n");
			printf("WINNER!!!         You won %i times!                    WINNER!!!\n", winCount);
			printf("WINNER!!!         You won $%i!                       WINNER!!!\n", winnings);
			printf("WINNER!!!         Your bank account has: $%i\t      WINNER!!!\n", bank);
			printf("WINNER!!!                                             WINNER!!!\n");
			printf("WINNER!!!WINNER!!!WINNER!!!WINNER!!!WINNER!!!WINNER!!!WINNER!!!\n\n");
		}else {                                                                             // if false do the text below
			system("COLOR C");                                                              // change the color of the text
			printf("\nLOSER!LOSER!LOSER!LOSER!LOSER!LOSER!LOSER!LOSER!LOSER!\n");
			printf("LOSER!                                          LOSER!\n");
			printf("LOSER!            You won %i times!              LOSER!\n", winCount);
			printf("LOSER!            You won NOTHING!              LOSER!\n", winnings);
			printf("LOSER!            Your bank account has: $%i\tLOSER!\n", bank);
			printf("LOSER!                                          LOSER!");
			printf("\nLOSER!LOSER!LOSER!LOSER!LOSER!LOSER!LOSER!LOSER!LOSER!\n\n");
		}//end else
		printf("You spent $%i on %i tickets.\n\n", moneySpent, ticketCount);                 // output results
		printf("Your total winnings earned after ticket expense is: $%i\n\n", earnings);
		if (bank < 1) {                                                      
			// if the earnings are less than $1, output this. 
			printf("You need to get a hold of your life and finances. The first step to recovery is admitting you have an issue.\n");
			printf("Please give a call to 1-800-522-4700 to speak with a representative of the National Problem Gambling Helpline.\n\n");
		}else{
			printf("You're doing aweseome!\n\n");                                            // output if above is false
		}
		printf("Would you like to buy some more tickets [Y/N]: ");                          // repeat?
		scanf(" %c", &again); FLUSH; 
	} while (toupper(again) == 'Y');                                                        // end do while loop unless Y option is selected above
	CLS;
	system("COLOR F");                                                                      // change system color back to white
	printf("\n\n\n\t\t\t\t\tThanks for playing the VALENCIA LOTTO!!!");                   
	printf("\n\n\t\t\t\t\t\tUntil next time.\n\n\n");
	PAUSE;
} // end of main