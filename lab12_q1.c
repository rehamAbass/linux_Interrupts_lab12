//////////////////////////////////////////////////////////////////////////////////////////
//
//		 Handling Interrupts 
//		 Lab 12 Q.1 
//		 Name :		"REHAM ABASS "	
//		 Date : 	 30/ 06/2019
//
#include <stdio.h> 				//Library for INput\Output
#include <dos.h>				//Library for Interrupts and IRS -Routens which are handling them
//
//	Defining global int number of presses N is counter
volatile int N;					// "volatile" means for the use of " IRS ".
//
//	Defining type of interrupt :  Int9 - for keyboard Presses
void interrupt (*Int9Save)(void); 
//
//	Our Function - which gonna Handle the Expected Interrupt of Keyboard Input Type:
//	Call my function "N" times :
//	Each time must decrease  N then call the Int9Save(), which really handle the interrupt
//	
void interrupt my_Handler(void){	
	N--;						//	counting expecting presses from N-- to 0 
	Int9Save();					//	the Interrupt function itself !!
} 
//////////////////////////////////////////////////////////////////////////////////////
void main(void) 
{
	printf("\nInsert N: ");		//	First gonna scan the number of interrupts = N
	scanf("%d", &N);			//	Just here I'm allowed to use "SCANF"
	
	Int9Save = getvect(9);		//	type of expecting Interrupt
	
	printf("again reham\n");
	
	setvect(9, my_Handler); 	//	before performing the interrupt, call my functoin
	
	while(N > 0);				//	loop waiting for  "N" Interrupts\pesses , until N = 0.
	
	setvect(9, Int9Save);  		//	Handle Enter Interrupt- last press 
	
	printf("END\n");			//	Finish waiting for Interrupts to occur
} 
