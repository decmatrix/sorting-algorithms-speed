/*
	process.h
*/

/*
	Бібліотека яка займається демонстрацією сортування та розрахуванням часу
*/

/* для запобігання повторного підключення бібліотеки */
#ifndef PROCESS_H
#define PROCESS_H

/* підключаємо власні бібліотеки */
#include "arrayIO.h"
#include "menu.h"
#include "algorithms.h"
#include "elements.h"
#include "measurement.h"

/* Функція яка займається демонстрацією сортування */
void demoProcess();

/* Функція яка займається розрахуванням часу */
void calcTimeProcess();

/* Функція яка виводить назву сортвування */
void printSortName(int);

/* Функція яка виконує дії які були обрані користувачем наприклад 1 - вектор 2 - сортурувати методов вставки один */
void goDemoProc(int, int);

#endif
