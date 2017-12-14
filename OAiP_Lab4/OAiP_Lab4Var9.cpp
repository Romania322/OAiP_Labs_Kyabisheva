/*
Кябишева Александра Зауровна
Лабораторная работа №4
Вариант 9
Задание: Написать программу, которая во вводимом с клавиатуры тексте выберет слова с нечётным количеством букв и выведет результат на экран.
Дополнения: входными данными является файл; результаты записываются в другой файл; входные данные не ограничеваются одной строкой.
*/

#define _CRT_SECURE_NO_WARNINGS 
#define MAX_LENGTH 255 
#include <stdio.h> 
#include <conio.h>
#include <locale>
#include <string.h>
#include <stdlib.h>

void findFile (FILE* OAiP_Lab4);
void handlingText (FILE* OAiP_Lab4);
int scanSpace (char* StringText);
void getWord (char* StringText, int positionSpase, int finish);
void enterWord (char* Word);
void parsingWord (char* Word);
int main ()
{
	FILE *OAiP_Lab4 = fopen ("OAiP_Lab4.txt", "r");
	FILE *Lab4_OAiP = fopen ("Lab4_OAiP.txt", "w");
	fclose (Lab4_OAiP);
	findFile (OAiP_Lab4);
	handlingText (OAiP_Lab4);
	fclose (OAiP_Lab4);
}

void findFile (FILE* OAiP_Lab4)
{
	if (OAiP_Lab4 == NULL)
	{
		printf ("Îøèáêà");
		_getch ();
		exit (0);
	}
}

void handlingText (FILE* OAiP_Lab4)
{
	char StringText [MAX_LENGTH] = "";
	while (!feof(OAiP_Lab4))
	{
		fscanf (OAiP_Lab4, "%s", StringText);
		parsingWord (StringText);
	}
}

int scanSpace (char* StringText)
{
	for (int i = 0; StringText[i]; i++)
	{
		if (StringText[i] == ' ')
			return i;
	}
	return NULL;
}

void getWord (char* StringText, int positionSpase, int finish)
{
	char* Word = (char*)calloc (positionSpase + 1, sizeof (char*));
	for (int i = 0; i < positionSpase; i++)
		Word[i] = StringText[i];
	if (finish == 0)
		parsingWord (Word);
	else
		enterWord (Word);
}

void enterWord (char* Word)
{
	if (strlen (Word) % 2 == 1)
	{
		FILE *Lab4_OAiP = fopen ("Lab4_OAiP.txt", "a");		
		fprintf (Lab4_OAiP, "%s ", Word);		
		fclose (Lab4_OAiP);	
	}
}

void parsingWord (char* Word)
{
	int length = strlen (Word);
	for (int i = 0; i < length; i++)
	{
		if (!(
			((int)Word[i] >= 65 	&& (int)Word[i] <= 90) 	|| 
			((int)Word[i] >= 97 	&& (int)Word[i] <= 122) ||
			((int)Word[i] >= 128 	&& (int)Word[i] <= 175) ||
			((int)Word[i] >= 224 	&& (int)Word[i] <= 247) ||
			((int)Word[i] < 0)
			))
			{
				getWord (Word, i, 1);
				Word = Word + i + 1;
				i = -1;
				length = strlen (Word);
			}
		if (i == length - 1)
			enterWord (Word);
	}
}
