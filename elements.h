/*
	elements.h
*/

#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include <termios.h>
#include <unistd.h>

int getch_l();

#define SIZE_P 32
#define SIZE_N 625

#define SZ_P 3
#define SZ_N 5

#define SIZE 625

extern int ***A;
extern int *B;

#define SZ 10

#define DEMO 1
#define NO_DEMO 0

#define VECTOR 2
#define CUBE 1

#define SI_1 1 
#define SS_8 2 
#define SHELL 4
#define QS 3 

#define ORDER 1 
#define B_ORDER 2 
#define R_ORDER 3 


#define SS 2000

#define MST_NUMBER 28

extern clock_t Res[MST_NUMBER];

#define RES_SZ 24

extern float res_t[RES_SZ];

#endif
