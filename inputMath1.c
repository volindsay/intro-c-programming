///////////////////////////////////////////////////////////////
//											                 //
// Project Name: Simple Math Calculator                      //
// Written By: Vincent Lindsay                               //
// Date Written: 05/18/18                                    //
// Purpose: To write a program that does simple calculations //
//          of arithmetic operators and prints to screen.    //
//															 //
///////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define PAUSE system("pause")

main() {

	//Variables defined here
	int num1;
	int num2;
	int result;
	int mresult;
	int dresult;

	printf("\t\t\t\t\t\tWelcome to my program!\n\n\n");
	
	// INPUT
	printf("Please provide me with a number:   \t\t\t");
	scanf("%i", &num1);
	
	printf("\nPlease provide me with a second number not > 0: \t");
	scanf("%i", &num2);

	// PROCESS
	result = num1 + num2;
	mresult = num1 * num2;
	dresult = num1 / num2;

	// OUTPUT

	printf("When I add your numbers, the sum is: %i\n", result);
	printf("When I multiply your numbers, the sum is: %i\n", mresult);
	printf("When I divide your numbers, the sum is: %i\n", dresult);
	PAUSE; 

	return 0; 
}
