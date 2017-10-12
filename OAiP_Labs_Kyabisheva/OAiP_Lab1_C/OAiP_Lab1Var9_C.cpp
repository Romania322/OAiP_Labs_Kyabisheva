/*
Кябишева Александра Зауровна
Лабораторная работа №1
Вариант 9
Задание: перевести дециметры в ладони и выразить в верстах
*/
#include <conio.h>
#include <iostream>  
#include <limits>
using namespace std;

int main()
{ 	
	system("chcp 1251");
	system("cls");
	int DM;
	float HND;
	float VRST;
	printf ("Введите расстояние в дециметрах \n");
	scanf ("%d", &DM);
	//
	if(!DM)
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
	getch();
}
