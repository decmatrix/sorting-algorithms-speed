/*
	algsCube.c
*/

/*
	реалізація бібліотеки algorithms.h
*/

/* підключаємо власні бібліотеки */
#include "algorithms.h"

int ***A;
int *B;

/* функція яка сортує куб методом вставки №1 */
clock_t sortSI_1_cube(const int P, const int N)
{
	int buff;
	int j;

	clock_t start = clock();

	for (int p = 0; p < P; p++)
	{
		for (int i = 1; i < N; i++)
		{
			buff = A[p][i][i];
			j = 0;

			while (buff > A[p][j][j]) 
			{
				j++;
			}
			for (int k = i - 1; k >= j; k--) 
			{
				A[p][k + 1][k + 1] = A[p][k][k];
			}

			A[p][j][j] = buff;
		}
	}

	for (int p = 0; p < P; p++)
	{
		for (int i = 1; i < N; i++)
		{
			buff = A[p][i][N - 1 - i];
			j = 0;

			while (buff > A[p][j][N - 1 - j]) 
			{
				j++; 
			}
			for (int k = i - 1; k >= j; k--) 
			{
				A[p][k + 1][N - 1 - (k + 1)] = A[p][k][N - 1 - k];
			}

			A[p][j][N - 1 - j] = buff;
		}
	}



	clock_t stop = clock();

	return (stop - start);
}

/* Функція яка сортує куб методом вибору №8 */
clock_t sortSS_8_cube(const int P, const int N)
{
	int L, R;
	int imin, imax;
	int buff;

	clock_t start = clock();

	for (int p = 0; p < P; p++)
	{

		L = 0;
		R = N - 1;

		while (L < R)
		{
			imin = L;
			imax = L;

			for (int i = L + 1; i <= R; i++)
			{
				if (A[p][i][i] < A[p][imin][imin]) 
				{
					imin = i;
				}
				else if (A[p][i][i] > A[p][imax][imax]) 
				{
					imax = i;
				}
			}

			if (imin != L)
			{
				buff = A[p][imin][imin];
				A[p][imin][imin] = A[p][L][L];
				A[p][L][L] = buff;
			}

			if (imax != R)
			{
				if (imax == L)
				{
					buff = A[p][imin][imin];
					A[p][imin][imin] = A[p][R][R];
					A[p][R][R] = buff;
				}
				else
				{
					buff = A[p][imax][imax];
					A[p][imax][imax] = A[p][R][R];
					A[p][R][R] = buff;
				}
			}

			L++;
			R--;
		}
	}

	for (int p = 0; p < P; p++)
	{

		L = 0;
		R = N - 1;

		while (L < R)
		{
			imin = L;
			imax = L;

			for (int i = L + 1; i <= R; i++)
			{
				if (A[p][i][N - 1 - i] < A[p][imin][N - 1 - imin])
				{ 
					imin = i;
				}
				else if (A[p][i][N - 1 - i] > A[p][imax][N - 1 - imax]) 
				{
					imax = i;
				}
			}

			if (imin != L)
			{
				buff = A[p][imin][N - 1 - imin];
				A[p][imin][N - 1 - imin] = A[p][L][N - 1 - L];
				A[p][L][N - 1 - L] = buff;
			}

			if (imax != R)
			{
				if (imax == L)
				{
					buff = A[p][imin][N - 1 - imin];
					A[p][imin][N - 1 - imin] = A[p][R][N - 1 - R];
					A[p][R][N - 1 - R] = buff;
				}
				else
				{
					buff = A[p][imax][N - 1 - imax];
					A[p][imax][N - 1 - imax] = A[p][R][N - 1 - R];
					A[p][R][N - 1 - R] = buff;
				}
			}

			L++;
			R--;
		}
	}


	clock_t stop = clock();

	return (stop - start);
}


/* Функція яка сортує куб методом Шелла */
clock_t sortShell_cube(const int P, const int N)
{
	int t, j, k, buff;

	clock_t start = clock();

	for (int p = 0; p < P; p++)
	{
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
				buff = A[p][i][i];
				j = i;
				while (j >= k && buff < A[p][j - k][j - k]) 
				{
					A[p][j][j] = A[p][j - k][j - k];
					j = j - k;
				}
				A[p][j][j] = buff;
			}
		}
	}

	for (int p = 0; p < P; p++) 
	{
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

		for (int i = t - 2; i >= 0; i--) {
			H[i] = 2 * H[i + 1] + 1;
		}
		for (int l = 0; l < t; l++) {
			k = H[l];
			for (int i = k; i < N; i++) {
				buff = A[p][i][N - 1 - i];
				j = i;
				while (j >= k && buff < A[p][j - k][N - 1 - j + k]) {
					A[p][j][N - 1 - j] = A[p][j - k][N - 1 - j + k];
					j = j - k;
				}
				A[p][j][N - 1 - j] = buff;
			}
		}
	}


	clock_t stop = clock();

	return (stop - start);
}

/* Функція яка сортує куб методом Швидкого сортування */
clock_t sortQSort_cube(const int P, const int N)
{
	clock_t start = clock();

	for (int p = 0; p < P; p++)
	{
		sort_QSort_mainDiag(p, 0, N - 1);
	}

	for (int p = 0; p < P; p++)
	{
		sort_QSort_sideDiag(N, p, 0, N - 1);
	}

	clock_t stop = clock();

	return (stop - start);
}

/* Функції які сортують діагоналі роздільно швидким сортуванням */
//////////////////////////////////////////////////
//сортуємо головну діагональ швидким сортуванням
void sort_QSort_mainDiag(const int p, int L, int R)
{
	int i, j, x, buff;

	x = A[p][(L + R) / 2][(L + R) / 2];
	i = L;	j = R;
	while (i <= j)
	{
		while (A[p][i][i] < x) 
		{
			i++;
		}
		while (A[p][j][j] > x) 
		{
			j--;
		}
		if (i <= j) 
		{
			buff = A[p][i][i];
			A[p][i][i] = A[p][j][j];
			A[p][j][j] = buff;

			i++;
			j--;
		}
	}

	if (L < j) 
	{
		sort_QSort_mainDiag(p, L, j);
	}
	if (i < R) 
	{
		sort_QSort_mainDiag(p, i, R);
	}
}

//сортуємо побічну діагональ швидким сортуванням
void sort_QSort_sideDiag(const int n, const int p, int L, int R)
{
	int i, j, x, buff;

	x = A[p][(L + R) / 2][n - 1 - (L + R) / 2];
	i = L;	j = R;
	while (i <= j) 
	{
		while (A[p][i][n - 1 - i] < x)
		{
			i++;
		}
		while (A[p][j][n - 1 - j] > x) 
		{
			j--;
		}
		if (i <= j) 
		{
			buff = A[p][i][n - 1 - i];
			A[p][i][n - 1 - i] = A[p][j][n - 1 - j];
			A[p][j][n - 1 - j] = buff;

			i++;
			j--;
		}
	}

	if (L < j) 
	{
		sort_QSort_sideDiag(n, p, L, j);
	}
	if (i < R) 
	{
		sort_QSort_sideDiag(n, p, i, R);
	}
}
//////////////////////////////////////////////////
