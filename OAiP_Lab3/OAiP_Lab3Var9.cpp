#define _CRT_SECURE_NO_WARNINGS 
#define MAX_LENGTH 255 
#include <stdio.h> 
#include <conio.h>
#include <locale>
#include <string.h>
#include <stdlib.h>

void handlindText (char* StringText);
int scanSpace (char* StringText);
void getWord (char* StringText, int positionSpase, int finish);
void enterWord (char* Word);
void parsingWord (char* Word);
int main ()
{
	system ("chcp 1251");		
	system ("cls"); 	
	printf ("¬ведите текст \n");
	char StringText [MAX_LENGTH] = "";
	fgets (StringText, MAX_LENGTH, stdin);
	handlindText (StringText);
	_getch();
	return 0;
}

void handlindText (char* StringText)
{
	int positionSpase;
	while (scanSpace (StringText) != NULL)
	{
		positionSpase = scanSpace (StringText);
		getWord (StringText, positionSpase, 0);
		StringText = StringText + positionSpase + 1;
	}
	getWord (StringText , strlen (StringText), 0);
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
		printf ("%s ", Word);
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
