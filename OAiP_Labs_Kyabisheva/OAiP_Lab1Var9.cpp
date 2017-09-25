#include <stdio.h> 
#include <iostream>  
#include <limits>
using namespace std;

int main()
{ 	
	system("chcp 1251");
	system("cls");
	int dm;
	float hnd = dm * 0.984252;
	float vrst = hnd * 9.52381e-5;
	//
	cout << "Введите что-то" << endl;
	cin >> dm;
	if(!dm){
		while(!(cin >> dm)){
			cout << "Ошибка ввода.Повторите попытку" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	//
	hnd = dm * 0.984252;
	cout << ("dsdsd ", hnd) << endl;
	//
	vrst = hnd * 9.52381e-5;
	cout << ("ffddfdf ", vrst) << endl;
	//
	system("pause");
	return 0;
}
