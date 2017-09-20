#include <iostream> 
#include <stdio.h> 
#include <Windows.h> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//использование русского языка в тексте программы
	int dm;
	int hnd = dm * 0, 984252;
	float vrst = hnd * 9, 52381e-5;
	//введение переменных
	cout « ("Введите расстояние в дециметрах \n");
	cin » dm;
	//считывание длинны в дециметрах с клавиатуры
	hnd = dm * 0, 984252;
	cout « ("Расстояние в ладонях равно ", hnd) « endl;
	//перевод в ладони и вывод на экран
	vrst = hnd * 9, 52381e-5;
	cout « ("Расстояние в верстах равно ", vrst);
	//перевод в вёрсты и вывод на экран
	return 0;
}
