/*
Кябишева Александра Зауровна
Лабораторная работа №1
Вариант 9
Задание: перевести дециметры в ладони и выразить в верстах
*/
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>

void main()
{ 	
	system("chcp 1251");
	system("cls");
	int DM;
	float HND;
	float VRST;
	printf ("Введите расстояние в дециметрах \n");
	//
	if(!scanf ("%d", &DM))
	{
		while(!(scanf ("%d", &DM)))
		{
			printf ("Ошибка ввода. Повторите попыку \n");
			while (getchar () != '\n');
		}
	}
	HND = DM * 0.984252;
	printf ("Расстояние в ладонях равно %f \n", HND);
	VRST = HND * 9.52381e-5;
	printf ("Расстояние в верстах равно %f \n", VRST);
  _getch();
}
