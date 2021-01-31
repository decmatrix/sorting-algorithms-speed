/*
	elements.c
*/

#include "elements.h"


clock_t Res[MST_NUMBER];


float res_t[RES_SZ];

int getch_l()
{
	struct termios oldt, newt;
	int ch;

	tcgetattr( STDIN_FILENO, &oldt );

	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );

	tcsetattr( STDIN_FILENO, TCSANOW, &newt );

	ch = getchar();

	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	
	return ch;
}
