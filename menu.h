/*
	menu.h
*/

/*
	Бібліотека у якій розташовані функції меню
*/

/* для запобігання повторного підключення бібліотеки */
#ifndef MENU_H
#define MENU_H

/* підключаємо власні бібліотеки */
#include "arrayIO.h"
#include "elements.h"
#include "process.h"

/* Функція головного меню */
void mainMenu();

/*  Функція у якій можна обрати тип сортування */
int typeSorting();

/* Функція у якій можна обрати тип масиву (куб чи вектор) */
int typeArray();

/* Функція у який можна вибрати тип впорядкованості масиву */
void typeOrderArray(int);

/* Функція яка виводить вікно help */
void helpWindow();


#endif
