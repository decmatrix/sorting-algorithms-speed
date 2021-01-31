/*
	array.c
*/


#include "arrayIO.h"


void inputCube();
///////////////////////////////////////////////////////////////

int ***A;
int *B;

void createArr()
{
    A =(int ***) malloc((SIZE_P)*sizeof(int **));

    for(int i=0;i<SIZE_P;i++)
    {
        A[i]=(int **) malloc(SIZE_N*sizeof(int *));
        for(int j=0;j<SIZE_N;j++)
        {
            A[i][j]=(int *) malloc(SIZE_N*sizeof(int));

        }
    }

	B = (int *)malloc((SIZE)*sizeof(int));
}

void deleteArr()
{
    for(int i=0;i<SIZE_P;i++)
    {
        for(int j=0;j<SIZE_N;j++)
        {
           free(A[i][j]);

        }
        free(A[i]);
    }
    free(A);
	
	free(B);
}

void inputCube(int mode)
{
	srand((unsigned int) time(NULL));
    
    
    if(mode == DEMO)
    {
        for (int p = 0; p < SIZE_P; p++)
        {
            for (int i = 0; i < SIZE_N; i++)
            {
                for (int j = 0; j < SIZE_N; j++)
                {
                    A[p][i][j] = rand() % 10;
                }
            }
        }
    }
    else
    {
        for (int p = 0; p < SIZE_P; p++)
        {
            for (int i = 0; i < SIZE_N; i++)
            {
                for (int j = 0; j < SIZE_N; j++)
                {
                    A[p][i][j] = rand() % (SIZE_P * 2 * SIZE_N);
                }
            }
        }   
    }
}

void inputOrderArray(int key, const int P, const int N, const int V, int mode)
{
	if (key == CUBE)
	{
		inputCube(mode); // ��������� ����� ��� ����������� �������

		for (int p = 0; p < P; p++)
		{
			for (int i = 0; i < N; i++)
			{
					A[p][i][i] = i;
					A[p][i][N - 1 - i] = i;
			}
		}
	}
	else if (key == VECTOR)
	{
		for (int i = 0; i < V; i++)
		{
			B[i] = i;
		}
	}
}

void inputBOrderArray(int key, const int P, const int N, const int V, int mode)
{
	if (key == CUBE)
	{
		inputCube(mode);

		for (int p = 0; p < P; p++)
		{
			for (int i = 0; i < N; i++)
			{
				A[p][i][i] = N - 1 - i;
				A[p][i][N - 1 - i] = N - 1 - i;
			}
		}
	}
	else if (key == VECTOR)
	{
		for (int i = 0; i < V; i++)
		{
			B[i] = V - 1 - i;
		}
	}
}

void inputROrderArray(int key, const int V, int mode)
{
	srand((unsigned int) time(NULL));

	if (key == CUBE)
	{
		inputCube(mode);
	}
	else if (key == VECTOR)
	{
    
        if(mode == DEMO)
        {
           for (int i = 0; i < V; i++)
            {
                B[i] = rand() % 10;
            } 
        }
        else
        {
            for (int i = 0; i < V; i++)
            {
                B[i] = rand() % (SIZE_P * 2 * SIZE_N);
            }   
        }
	}
}

void outputArray(int key)
{
	if (key == 1)
	{
		for (int p = 0; p < SZ_P; p++)
		{
			printf("%d) section\n\n", p);

			for (int i = 0; i < SZ_N; i++)
			{
				for (int j = 0; j < SZ_N; j++)
				{
					printf("%d ", A[p][i][j]);
				}

				printf("\n");
			}

			printf("\n");
		}
	}
	else if (key == 2)
	{
		for (int i = 0; i < SZ; i++)
		{
			printf("%d ", B[i]);
		}

		printf("\n");
	}
}

