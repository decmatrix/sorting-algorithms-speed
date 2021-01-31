/*
	algorithms.h
*/

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <time.h>
#include "elements.h"

clock_t sortSI_1_vector(const int);
clock_t sortSS_8_vector(const int);
clock_t sortShell_vector(const int);
clock_t sortQSort_vector(const int);
void QSort_vector(int, int);

clock_t sortSI_1_cube(const int, const int);
clock_t sortSS_8_cube(const int, const int);
clock_t sortShell_cube(const int, const int);
clock_t sortQSort_cube(const int, const int);
void sort_QSort_mainDiag(const int, int, int);
void sort_QSort_sideDiag(const int, const int, int, int);

#endif
