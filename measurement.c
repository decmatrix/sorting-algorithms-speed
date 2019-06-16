/*
	measurement.c
*/

/*
	реалізація бібліотеки measurment.h
*/

/* підключаємо власні бібліотеки */
#include "measurement.h"

int ***A;
int *B;

/* визначемо функції які використовуються в межах цього файлу */
////////////////////////////////////////////////////////////////
/* Функція для обрахування часу роботи */
void MeasurementProcessing();
/* Функція яка заповнює масив результатів одного алгоритму, вираховує час та повертає його */
clock_t calcRes(int, int, int);
/* Функція яка заповнює, сортує і повертає час роботи для вимірювання часу */
clock_t doRes(int, int, int);
///////////////////////////////////////////////////////////////

/* Функція для обрахування часу роботи */
void MeasurementProcessing()
{
	long int Sum, Min1, Min2, Min3, Max1, Max2, Max3;
	int imin1, imin2, imin3, imax1, imax2, imax3;

	// Два перших виміри (0-й та 1-й) відкидаються
	// Серед інших елементів знаходимо три мінімальних та три максимальних
	// елементи і віднімаємо їх значення із загальної суми

	// Знаходимо мінімальний та максимальний елементи і виключаємо їх з наступних
	// пошуків, встановивши їм значення -1
	Sum = Res[2]; 
	Min1 = Res[2]; 
	Max1 = Res[2]; 
	imin1 = 2; 
	imax1 = 2;

	for (int i = 3; i < MST_NUMBER; i++)
	{
		Sum = Sum + Res[i];
		if (Res[i] > Max1) 
		{ 
			Max1 = Res[i]; 
			imax1 = i; 
		}
		else if (Res[i] < Min1) 
		{ 
			Min1 = Res[i]; 
			imin1 = i; 
		}
	}

	Res[imin1] = -1; Res[imax1] = -1;

	// Знаходимо другий мінімальний та другий максимальний елементи
	// і виключаємо їх з наступних пошуків, встановивши їм значення -1
	if (Res[2] == -1) 
	{
		Min2 = Res[3]; 
		imin2 = 3; 
	}
	else 
	{
		Min2 = Res[2]; 
		imin2 = 2; 
	}

	Max2 = Res[2]; 
	imax2 = 2;

	for (int i = 3; i < MST_NUMBER; i++)
	{
		if (Res[i] > Max2) 
		{ 
			Max2 = Res[i]; 
			imax2 = i; 
		}
		else if (Res[i]<Min2 && Res[i] != -1) 
		{ 
			Min2 = Res[i];
			imin2 = i; 
		}
	}

	Res[imin2] = -1; 
	Res[imax2] = -1;

	// Знаходимо третій мінімальний та третій максимальний елементи
	if (Res[2] == -1)
	{
		if (Res[3] == -1) 
		{ 
			Min3 = Res[4]; 
			imin3 = 4; 
		}
		else 
		{ 
			Min3 = Res[3]; 
			imin3 = 3; 
		}
	}
	else 
	{ 
		Min3 = Res[2]; 
		imin3 = 2; 
	}

	Max3 = Res[2]; 
	imax3 = 2;

	for (int i = 3; i < MST_NUMBER; i++)
	{
		if (Res[i] > Max3) 
		{ 
			Max3 = Res[i]; 
			imax3 = i; 
		}
		else if (Res[i]<Min3 && Res[i] != -1) 
		{ 
			Min3 = Res[i]; 
			imin3 = i; 
		}
	}

	// Сума всіх вимірів мінус три максимальних та три мінімальних значення буде записана до 0-го елемента масива Res
	Res[0] = (Sum - Min1 - Min2 - Min3 - Max1 - Max2 - Max3) / 20;
}

/* Функція яка заповнює масив результатів одного алгоритму, вираховує час та повертає його */
clock_t calcRes(int t_sort, int t_arr, int t_order)
{
	for (int i = 0; i < MST_NUMBER; i++)
	{
		Res[i] = doRes(t_sort, t_arr, t_order);
	}

	MeasurementProcessing();

	return Res[0];
}

/* Функція яка заповнює, сортує і повертає час роботи для вимірювання часу */
clock_t doRes(int t_sort, int t_arr, int t_order)
{
	clock_t resault = 0;

	switch (t_order)
	{
	case ORDER: inputOrderArray(t_arr, SIZE_P, SIZE_N, SIZE, NO_DEMO);
		break;
	case B_ORDER: inputBOrderArray(t_arr, SIZE_P, SIZE_N, SIZE, NO_DEMO);
		break;
	case R_ORDER: inputROrderArray(t_arr, SIZE, NO_DEMO);
	}

	if (t_arr == CUBE)
	{
		switch (t_sort)
		{
		case SI_1: resault = sortSI_1_cube(SIZE_P, SIZE_N);
			break;
		case SS_8: resault = sortSS_8_cube(SIZE_P, SIZE_N);
			break;
		case SHELL: resault = sortShell_cube(SIZE_P, SIZE_N);
			break;
		case QS: resault = sortQSort_cube(SIZE_P, SIZE_N);
			break;
		}
	}
	else if (t_arr == VECTOR)
	{
		switch (t_sort)
		{
		case SI_1: resault = sortSI_1_vector(SIZE);
			break;
		case SS_8: resault = sortSS_8_vector(SIZE);
			break;
		case SHELL: resault = sortShell_vector(SIZE);
			break;
		case QS: resault = sortQSort_vector(SIZE);
			break;
		}
	}

	return resault;
}

/* Функція заповненя масиву результатів усіх варіантів вирахування */
void getRes()
{
	/* Тут ми отримуємо результати усього пакетного режиму для виводу у таблицю */
	res_t[0] = (float) calcRes(SI_1, CUBE, ORDER);	res_t[16] = (float) (calcRes(SS_8, VECTOR, B_ORDER) * 2 * SIZE_P);
	res_t[1] = (float) calcRes(SI_1, CUBE, B_ORDER);	res_t[17] = (float) (calcRes(SS_8, VECTOR, R_ORDER) * 2 * SIZE_P);
	res_t[2] = (float) calcRes(SI_1, CUBE, R_ORDER);	res_t[18] = (float) (calcRes(SHELL, VECTOR, ORDER) * 2 * SIZE_P);
	res_t[3] = (float) calcRes(SS_8, CUBE, ORDER);	res_t[19] = (float) (calcRes(SHELL, VECTOR, B_ORDER) * 2 * SIZE_P);
	res_t[4] = (float) calcRes(SS_8, CUBE, B_ORDER);	res_t[20] = (float) (calcRes(SHELL, VECTOR, R_ORDER) * 2 * SIZE_P);
	res_t[5] = (float) calcRes(SS_8, CUBE, R_ORDER);	res_t[21] = (float) (calcRes(QS, VECTOR, ORDER) * 2 * SIZE_P);
	res_t[6] = (float) calcRes(SHELL, CUBE, ORDER);	res_t[22] = (float) (calcRes(QS, VECTOR, B_ORDER) * 2 * SIZE_P);
	res_t[7] = (float) calcRes(SHELL, CUBE, B_ORDER);	res_t[23] = (float) (calcRes(QS, VECTOR, R_ORDER) * 2 * SIZE_P);
	res_t[8] = (float) calcRes(SHELL, CUBE, R_ORDER);
	res_t[9] = (float) calcRes(QS, CUBE, ORDER);
	res_t[10] = (float) calcRes(QS, CUBE, B_ORDER);
	res_t[11] = (float) calcRes(QS, CUBE, R_ORDER);
	res_t[12] = (float) (calcRes(SI_1, VECTOR, ORDER) * 2 * SIZE_P);
	res_t[13] = (float) (calcRes(SI_1, VECTOR, B_ORDER) * 2 * SIZE_P);
	res_t[14] = (float) (calcRes(SI_1, VECTOR, R_ORDER) * 2 * SIZE_P);
	res_t[15] = (float) (calcRes(SS_8, VECTOR, ORDER) * 2 * SIZE_P);
}
