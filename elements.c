/*
	elements.c
*/

/*
	реалізація бібліотеки elements.h
*/

/* подключаем собственные библиотеки */
#include "elements.h"

/* динамічні масиви для сортування */
//int ***A; //динамічний трьохвимірний масив
//int *B; //динамічний масив

/* масив для отримання 28 значень часу сортування, щоб знайти середнє значення */
clock_t Res[MST_NUMBER];

/* масив отриманих результатів в результаті вирахування кожного варіанту */
float res_t[RES_SZ];

/* Функція яка замінює функція getch() у виндовс (код брався з інтернету) */
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
