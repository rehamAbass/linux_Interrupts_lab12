#include<stdio.h>
#include<dos.h>

volatile int Ctrl_Break_Flag;

void interrupt(*Int27Save)(void);

void interrupt Ctrl_Break_Handler(void) {
	Ctrl_Break_Flag = 1;
	printf("C: Ctrl-Break has been pressed.\n");
}

void main() {
	Int27Save = getvect(27);
	setvect(27, Ctrl_Break_Handler);
	printf(“C: Press Ctrl_Break to continue.\n”);

	Ctrl_Break_Flag = 0;
	while (Ctrl_Break_Flag == 0)
		;
	printf(“C: Terminating…\n”);
	setvect(27, Int27Save);
}
