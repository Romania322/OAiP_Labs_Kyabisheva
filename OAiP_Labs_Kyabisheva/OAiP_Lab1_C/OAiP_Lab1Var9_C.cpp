/*
�������� ���������� ��������
������������ ������ �1
������� 9
�������: ��������� ��������� � ������ � �������� � �������
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
	printf ("������� ���������� � ���������� \n");
	scanf ("%d", &DM);
	//
	if(!DM)
	{
		while(!(scanf ("%d", &DM)))
		{
			printf ("������ �����. ��������� ������ \n");
			while (getchar () != '\n');
		}
	}
	HND = DM * 0.984252;
	printf ("���������� � ������� ����� %f \n", HND);
	VRST = HND * 9.52381e-5;
	printf ("���������� � ������� ����� %f \n", VRST);
	getch();
}
