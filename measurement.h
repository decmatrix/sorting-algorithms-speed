/*
	measurement.h
*/

/*
	Бібліотека яка вираховує час роботи алгоритма
*/

/* для запобігання повторного підключення бібліотеки */
#ifndef MEASUREMENT_H
#define MEASUREMENT_H

/* підключаємо власні бібліотеки */
#include "elements.h"
#include "arrayIO.h"
#include "algorithms.h"

/* Функція для обрахування часу роботи */
void MeasurementProcessing();
/* Функція яка заповнює масив результатів одного алгоритму, вираховує час та повертає його */
clock_t calcRes(int, int, int);
/* Функція яка заповнює, сортує і повертає час роботи для вимірювання часу */
clock_t doRes(int, int, int);
/* Функція заповненя масиву результатів усіх варіантів вирахування */
void getRes();

#endif
