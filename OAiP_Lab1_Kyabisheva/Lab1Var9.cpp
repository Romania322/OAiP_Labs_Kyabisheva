#include <conio.h>
#include <stdio.h> 
#include <iostream> 
#include <Windows.h> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int dm;
	float hnd = dm * 0.984252;
	float vrst = hnd * 9.52381e-5;
	//�������� ����������
	cout << "������� ���������� � ����������" << endl;
	cin >> dm;
	//���������� ������ � ���������� � ����������
	hnd = dm * 0.984252;
	cout << ("���������� � ������� ����� ", hnd) << endl;
	//������� � ������ � ����� �� �����
	vrst = hnd * 9.52381e-5;
	cout << ("���������� � ������� ����� ", vrst);
	//������� � ����� � ����� �� �����
	return 0;
}