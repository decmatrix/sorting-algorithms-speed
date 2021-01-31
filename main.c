/*
	main.c
*/

#include "menu.h"
#include "arrayIO.h"

int ***A;
int *B;

int main(void)
{
	createArr();
	deleteArr();
	
	createArr();
	
	mainMenu();

	deleteArr();

	return 0;
}
