/*
Кябишева Александра Зауровна
Лабораторная работа №1
Вариант 9
Задание: Перевести дециметры в ладони и вёрсты
*/
#include <stdio.h> 
#include <iostream>  
#include <limits>
using namespace std;

int main()
{ 	
	system("chcp 1251");
	system("cls");
	int dm;
	float hnd;
	float vrst;
	//Введение переменных
	cout << "Введите расстояние в дециметрах" << endl;
	cin >> dm;
	//Считывание длинны в дециметрах с клавиатуры
	if(!dm)
	{
		while(!(cin >> dm))
		{
			cout << "Ошибка ввода.Повторите попытку" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	//Распознавание некоректных данных
	hnd = dm * 0.984252;
	cout << ("Расстояние в ладонях равно ", hnd) << endl;
	//Перевод в ладони и вывод на экран
	vrst = hnd * 9.52381e-5;
	cout << ("Расстояние в верстах равно ", vrst) << endl;
	//Перевод в версты и вывод на экран
	system("pause");
	return 0;
}
