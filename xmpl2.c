#include <stdio.h>
#include <dos.h>

void interrupt(*Int0Save) (void);

void interrupt Func_Handler(void) { printf("C: zero divide!!!\n"); }

void main(void) {
	int x, y;
	printf("enter two numbers:");
	scanf("%d%d", &x, &y);
	Int0Save = getvect(0);
	setvect(0, Func_Handler);
	printf("%d/%d=%.2f\n", x, y, (float)x / y);
	setvect(0, Int0Save);
	printf("Finish");
}
