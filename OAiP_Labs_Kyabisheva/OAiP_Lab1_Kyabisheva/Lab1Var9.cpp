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
	//�������� ����������
	cout << "������� ���������� � ����������" << endl;
	cin >> dm;
	//���������� ����� � ���������� � ����������
	if (!dm) {
		while (!(cin >> dm)) {
			cout << "������ �����. ��������� �������" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	//������������� ������������ ������
	hnd = dm * 0.984252;
	cout << ("���������� � ������� ����� ", hnd) << endl;
	//������� � ������ � ����� �� �����
	vrst = hnd * 9.52381e-5;
	cout << ("���������� � ������ ����� ", vrst) << endl;
	//������� � ����� � ����� �� �����
	system("pause");
	return 0;
}