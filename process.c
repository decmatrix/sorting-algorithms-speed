/*
	process.c
*/

#include "process.h"

void demoProcess()
{
	int key_sorting = typeSorting();
	int key_array = typeArray();

	system("clear");
	printf("LOADING...\n");

	system("clear");
	printSortName(key_sorting);

	printf("\n==========ARRAY BEFORE==========\n\n");
	outputArray(key_array);
	printf("\n================================\n");

	goDemoProc(key_array, key_sorting);

	printf("\n\n==========ARRAY AFTER===========\n\n");
	outputArray(key_array);
	printf("\n================================\n");
	
	printf("\nPress key...");
	getch_l();
}

void calcTimeProcess()
{
	system("clear");
	printf("LOADING...\n");

	getRes();
	
	int sz_p = SIZE_P;
	int sz_n = SIZE_N;
	int sz = SIZE;

	system("clear");
	printf("CUBE: A[%d][%d][%d]\n", sz_p, sz_n, sz_n);
	printf("╔═════════════════════╦════════════════════╦═══════════════════════════╦════════════════════╗\n");
	printf("║                     ║       ORDER        ║       RANDOMLY ORDER      ║      BACK ORDER    ║\n");
	printf("╠═════════════════════╬════════════════════╬═══════════════════════════╬════════════════════╣\n");
	printf("║ SORT INSERTION #1   ║  %10.2f        ║      %10.2f           ║   %10.2f       ║\n", res_t[0], res_t[2], res_t[1]);
	printf("╠═════════════════════╬════════════════════╬═══════════════════════════╬════════════════════╣\n");
	printf("║ SORT SELECTION #8   ║  %10.2f        ║      %10.2f           ║   %10.2f       ║\n", res_t[3], res_t[5], res_t[4]);
	printf("╠═════════════════════╬════════════════════╬═══════════════════════════╬════════════════════╣\n");
	printf("║ SORT SHELL          ║  %10.2f        ║      %10.2f           ║   %10.2f       ║\n", res_t[6], res_t[8], res_t[7]);
	printf("╠═════════════════════╬════════════════════╬═══════════════════════════╬════════════════════╣\n");
	printf("║ QUICK SORT          ║  %10.2f        ║      %10.2f           ║   %10.2f       ║\n", res_t[9], res_t[11], res_t[10]);
	printf("╚═════════════════════╩════════════════════╩═══════════════════════════╩════════════════════╝\n");
	printf("\n\n");
	printf("VECTOR: B[%d]\n", sz);
	printf("╔═════════════════════╦════════════════════╦═══════════════════════════╦════════════════════╗\n");
	printf("║                     ║       ORDER        ║       RANDOMLY ORDER      ║      BACK ORDER    ║\n");
	printf("╠═════════════════════╬════════════════════╬═══════════════════════════╬════════════════════╣\n");
	printf("║ SORT INSERTION #1   ║  %10.2f        ║      %10.2f           ║   %10.2f       ║\n", res_t[12], res_t[14], res_t[13]);
	printf("╠═════════════════════╬════════════════════╬═══════════════════════════╬════════════════════╣\n");
	printf("║ SORT SELECTION #8   ║  %10.2f        ║      %10.2f           ║   %10.2f       ║\n", res_t[15], res_t[17], res_t[16]);
	printf("╠═════════════════════╬════════════════════╬═══════════════════════════╬════════════════════╣\n");
	printf("║ SORT SHELL          ║  %10.2f        ║      %10.2f           ║   %10.2f       ║\n", res_t[18], res_t[20], res_t[19]);
	printf("╠═════════════════════╬════════════════════╬═══════════════════════════╬════════════════════╣\n");
	printf("║ QUICK SORT          ║  %10.2f        ║      %10.2f           ║   %10.2f       ║\n", res_t[21], res_t[23], res_t[22]);
	printf("╚═════════════════════╩════════════════════╩═══════════════════════════╩════════════════════╝\n");
	printf("\n\nPress key...");

	getch_l();
}


void goDemoProc(int arr_key, int s_key)
{
	if (arr_key == 1)
	{
		switch (s_key)
		{
		case 1:
			sortSI_1_cube(SZ_P, SZ_N);
			break;
		case 2:
			sortSS_8_cube(SZ_P, SZ_N);
			break;
		case 3:
			sortShell_cube(SZ_P, SZ_N);
			break;
		case 4:
			sortQSort_cube(SZ_P, SZ_N);
			break;
		}
	}
	else if (arr_key == 2)
	{
		switch (s_key)
		{
		case 1:
			sortSI_1_vector(SZ);
			break;
		case 2:
			sortSS_8_vector(SZ);
			break;
		case 3:
			sortShell_vector(SZ);
			break;
		case 4:
			sortQSort_vector(SZ);
			break;
		}
	}
}

void printSortName(int key)
{
	switch (key)
	{
	case SI_1: printf("SORT INSERTION #1\n");
		break;
	case SS_8: printf("SORT SELECTION #8\n");
		break;
	case SHELL: printf("SHELL SORTING\n");
		break;
	case QS: printf("QUICK SORT\n");
	}
}
