/* 
	menu.c
*/


#include "menu.h"

void mainMenu()
{
	while (1)
	{
		system("clear");
		printf("LOADING...\n");

		system("clear");
		printf("===WHAT DO YOU WANT TO DO?===\n");
		printf("1) Show sorting\n");
		printf("2) Calculate the time of sorting\n");
		printf("3) Help\n");
		printf("4) Exit ==>\n");
		printf("\n\n\n\n*press 1-5\n");

		char input = getch_l();

		switch (input)
		{
		case '1':
			demoProcess();
			break;
		case '2':
			calcTimeProcess();
			break;
		case '3':
			helpWindow();
			break;
		case '4':
			{ deleteArr(); exit(EXIT_SUCCESS);}
		}
	}
}

int typeSorting()
{
	while (1)
	{
		system("clear");
		printf("LOADING...\n");

		system("clear");
		printf("===SELECT TYPE OF SORTING===\n");
		printf("1) Sort-Insertion #1\n");
		printf("2) Sort-Selection #8\n");
		printf("3) Shell-Sorting\n");
		printf("4) Quick-Sorting\n");
		printf("5) Exit ==>\n");

		char input = getch_l();

		switch (input)
		{
		case '1':
			return SI_1;
			break;
		case '2':
			return SS_8;
			break;
		case '3':
			return SHELL;
			break;
		case '4':
			return QS;
			break;
		case '5':
		{
			deleteArr(); exit(EXIT_SUCCESS);
			return 0;
		}
		}
	}
}


int typeArray()
{
	while (1)
	{
		system("clear");
		printf("LOADING...\n");

		system("clear");
		printf("===SELECT AN ARRAY TYPE===\n");
		printf("1) Cube\n");
		printf("2) Vector\n");
		printf("3) Exit ==>\n");

		char input = getch_l();

		switch (input)
		{
		case '1':
		{
			typeOrderArray(CUBE);
			return CUBE;
		}
		case '2':
		{
			typeOrderArray(VECTOR);
			return VECTOR;
		}
		case '3':
		{
			deleteArr(); exit(EXIT_SUCCESS);
			return 0; 
		}
		}
	}
}

void typeOrderArray(int key)
{
	system("clear");
	printf("LOADING...\n");

	system("clear");
	printf("===SELECT THE ORDER TYPE===\n");
	printf("1) Ordered\n");
	printf("2) Backordered\n");
	printf("3) Randomly ordered\n");
	printf("4) Exit ==>\n");

	char input = getch_l();

	switch (input)
	{
	case '1':
		inputOrderArray(key, SZ_P, SZ_N, SZ, DEMO);
		break;
	case '2':
		inputBOrderArray(key, SZ_P, SZ_N, SZ, DEMO);
		break;
	case '3':
		inputROrderArray(key, SZ, DEMO);
		break;
	case '4':
		{ deleteArr(); exit(EXIT_SUCCESS);}
	}
}

void helpWindow()
{
	system("clear");
	printf("LOADING...\n");

	system("clear");
	printf("===HELP WINDOW===\n");
	printf("This program is designed to sort diagonals of cubes and vectors,\n");
	printf("as well as calculate the time of the algorithm's running time.\n");
	printf("Author of the program: Sokolovsky Bogdan FPM KV-73\n");
	printf("All questions ==> Gauss.falcon@gmail.com <==\n");
	printf("\n\n\nPress key ...\n");

	getch_l();
}
