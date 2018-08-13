///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
////                                                                           ////
////                           PLAYING WITH LETTERS                            ////
////                                                                           ////
////              Written by: Vincent Lindsay                                  ////
////                                                                           ////
////              Written on: 07.15.18                                         ////
////                                                                           ////
////              Purpose   : This program was created to show off             ////
////                          the usage of functions and arrays                ////
////                          to save, recall and manipulate a word            ////
////                          input by the user.                               ////
////                                                                           ////
////                                                                           ////
////                                                                           ////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define CLS system("cls")
#define SIZE 20
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void backwardsWord(char myWord[]);
void getWord(myWord);
void upsideDownVerticalWord(char myWord[], int i);
void verticalWord(char myWord[], int i);


main() {

	char myWord[SIZE];
	int i = 0;
	getWord(myWord);
	
	backwardsWord(myWord, i);
	
	verticalWord(myWord, i);
	
	upsideDownVerticalWord(myWord, i);
	
	PAUSE;
	return 0;
} //end main 
void backwardsWord(char myWord[]) {
	
	int i; 
	printf("The word backwards is: ");
	for (i = strlen(myWord) - 1; i >= 0; i--)
		printf("%c", myWord[i]);
	printf("\n");
	return; 
}//end backwardsWord

void getWord(myWord) {
	printf("Please provide a word: ");
	gets(myWord);
	printf("\n\nThe word is: %s\n\n", myWord);
	return;
} //end getWord

void upsideDownVerticalWord(char myWord[], int i) {
	printf("\n\nThe word upside down vertical is: \n");
	for (i = strlen(myWord) - 1; i >= 0; i--) {
		printf("%c\n", toupper(myWord[i]));
	}
	printf("\n");
} // end upsideDownVerticalWord

void verticalWord(char myWord[], int i) {
	printf("\n\nThe word vertical is: \n");
	for (i = 0; i < strlen(myWord); i++) {
		printf("%c\n", toupper(myWord[i]));
	}
	printf("\n");
} // end verticalWord
