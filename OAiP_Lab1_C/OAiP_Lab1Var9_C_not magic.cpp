/*
�������� ���������� ��������
������������ ������ �1
������� 9
�������: ��������� ��������� � ������ � �������� � ������
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
	printf ("������� ���������� � ���������� \n");
	//
	if(!scanf ("%d", &DM))
	{
		while(!(scanf ("%d", &DM)))
		{
			printf ("������ �����. ��������� ������� \n");
			while (getchar () != '\n');
		}
	}
	HND = DM * 0.984252;
	printf ("���������� � ������� ����� %f \n", HND);
	VRST = HND * 9.52381e-5;
	printf ("���������� � ������� ����� %f \n", VRST);
  _getch();
}
