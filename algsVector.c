/*
	algsVector.c
*/

/*
	реалізація бібліотеки algorithms.h
*/

/* підключаємо власні бібліотеки */
#include "algorithms.h"

int ***A;
int *B;


/* функція яка сортує вектор методом вставки №1 */
clock_t sortSI_1_vector(const int N)
{
	int buff;
	int j;

	clock_t start = clock();

	for (int i = 1; i < N; i++)
	{
		buff = B[i];
		j = 0;

		while (buff > B[j])
		{
			j++;
		}

		for (int k = i - 1; k >= j; k--) 
		{
			B[k + 1] = B[k];
		}

		B[j] = buff;
	}

	clock_t stop = clock();

	return (stop - start);
}

/* Функція яка сортує вектор методом вибору №8 */
clock_t sortSS_8_vector(const int N)
{
	int L, R;
	int imin, imax;
	int buff;

	clock_t start = clock();

	L = 0;
	R = N - 1;

	while (L < R)
	{
		imin = L;
		imax = L;

		for (int i = L + 1; i <= R; i++)
		{
			if (B[i] < B[imin]) 
			{ 
				imin = i; 
			}
			else if (B[i] > B[imax]) 
			{ 
				imax = i;
			} 
		}

		if (imin != L)
		{
			buff = B[imin];
			B[imin] = B[L];
			B[L] = buff;
		}

		if (imax != R)
		{
			if (imax == L)
			{
				buff = B[imin];
				B[imin] = B[R];
				B[R] = buff;
			}
			else
			{
				buff = B[imax];
				B[imax] = B[R];
				B[R] = buff;
			}
		}

		L++;
		R--;
	}

	clock_t stop = clock();

	return (stop - start);
}

/* Функція яка сортує вектор методом Шелла */
clock_t sortShell_vector(const int N)
{
	int t, j, k, buff;

	clock_t start = clock();

	if (N < 4) 
	{
		t = 1; 
	}
	else 
	{ 
		t = (int) trunc(log(N) / log(2)) - 1; 
	}

	int H[SS];

	H[t - 1] = 1;

	for (int i = t - 2; i >= 0; i--) 
	{
		H[i] = 2 * H[i + 1] + 1;
	}

	for (int l = 0; l < t; l++) 
	{
		k = H[l];
		for (int i = k; i < N; i++)
		{
			buff = B[i];
			j = i;
			while (j >= k && buff < B[j - k]) 
			{
				B[j] = B[j - k];
				j = j - k;
			}
			B[j] = buff;
		}
	}

	clock_t stop = clock();

	return (stop - start);
}

/* Функція яка сортує вектор методом Швидкого сортування */
clock_t sortQSort_vector(const int N)
{
	clock_t start = clock();

	QSort_vector(0, N - 1);

	clock_t stop = clock();

	return (stop - start);
}

/* Примітка: так як функція швидкого сортування рекурсивна
час виконня вимірюється в межах його виклику а саме у sortQSort_vector() */
//ця функція у якій алгоритм швидкого сортування
void QSort_vector(int L, int R)
{
	int i, j, x,buff;

	x = B[(L + R) / 2];
	i = L;	j = R;
	while (i <= j) 
	{
		while (B[i] < x) 
		{
			i++;
		}
		while (B[j] > x) 
		{
			j--;
		}
		if (i <= j) 
		{
			buff = B[i];
			B[i] = B[j];
			B[j] = buff;
			
			i++;
			j--;
		}
	}

	if (L < j) 
	{
		QSort_vector(L, j);
	}
	if (i < R) 
	{
		QSort_vector(i, R);
	}
}
