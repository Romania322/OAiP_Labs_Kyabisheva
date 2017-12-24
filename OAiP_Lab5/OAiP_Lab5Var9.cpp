#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH_NAME 30
#define MAX_LENGTH_AUTONUM 10
#define MAX_LENGTH_NUMTECHPASS 30
#define MAX_LENGTH_BIRTHDATE 10
#define MAX_LENGTH_PHONENUMBER 18
#define MAX_LENGTH_OTDGIBDD 70

#define MAX_LENGTH 			MAX_LENGTH_NAME		+\
					MAX_LENGTH_AUTONUM	+\
					MAX_LENGTH_NUMTECHPASS	+\
					MAX_LENGTH_BIRTHDATE	+\
					MAX_LENGTH_PHONENUMBER	+\
					MAX_LENGTH_OTDGIBDD	+ 5

struct AutoOwner
{
	char Name [MAX_LENGTH_NAME];
	char AutoNum [MAX_LENGTH_AUTONUM];
	char NumTechPass [MAX_LENGTH_NUMTECHPASS];
	char Birthdate [MAX_LENGTH_BIRTHDATE];
	char PhoneNumber [MAX_LENGTH_PHONENUMBER];
	char OtdGIBDD [MAX_LENGTH_OTDGIBDD];
};

void choiceDemand(); //выбор запроса
void additionStructure (); //дополнение структурами
void inputStructure (); //ввод структур
void addWord (char *word_new, char *word);//пересахронение строки
void searchStructure (); //поиск структуры
int scanTabulation (char* StringText);
int shiftText (char *word, char *searchValue, int inquiryDemand);
void outputStructure (); //выводд структур
void streamliningStructure (); //упорядочение структур
void swap(struct AutoOwner *carStructs1, struct AutoOwner *carStructs2);

int main ()
{
	system ("chcp 1251");
	system ("cls");
	printf ("Введите номер запроса:\n");
	choiceDemand ();
	_getch ();
	return 0;
}

void choiceDemand ()
{
	printf ("1)Дополнение массива структур;\n");
	printf ("2)Поиск структуры с заданым значением;\n");
	printf ("3)Вывод структур на экран;\n");
	printf ("4)Упорядочение по заданному полю;\n");
	printf ("5)Выход из программы;\n");
	int inquiry = 0;
	scanf ("%d", &inquiry);
	switch (inquiry)
	{
	case 1:
		additionStructure ();
		break;
	case 2:
		searchStructure ();
		break;
	case 3:
		outputStructure ();
		break;
	case 4:
		streamliningStructure ();
		break;
	case 5:
		exit (0);
	default:
		exit (0);
	}
}

void additionStructure ()
{
	printf ("Введите количество структур\n");
	int numberOfStruct = 0;
	scanf ("%d", &numberOfStruct);
	int i;
	for (i = 0; i < numberOfStruct; i++)
	{
		printf ("Введите структуру № %d \n", i + 1);
		inputStructure ();
	}
}

void inputStructure ()
{
	struct 	AutoOwner owner;
	printf ("Введите имя владельца: ");
	scanf ("%s", &owner.Name);
	printf ("Введите номер машины: ");
	scanf ("%s", &owner.AutoNum);
	printf ("Введите номер техпаспорта: ");
	scanf ("%s", &owner.NumTechPass);
	printf ("Введите дата рождения: ");
	scanf ("%s", &owner.Birthdate);
	printf ("Введите номер телефона: ");
	scanf ("%s", &owner.PhoneNumber);
	printf ("Введите отделение ГИБДД: ");
	scanf ("%s", &owner.OtdGIBDD);
	FILE *OAiP_Lab5Var9 = fopen ("OAiP_Lab5Var9.txt", "a");
	if (OAiP_Lab5Var9 == NULL)
	{
		fclose (OAiP_Lab5Var9);
		OAiP_Lab5Var9 = fopen ("OAiP_Lab5Var9.txt", "w");
	}
	fprintf (OAiP_Lab5Var9, "%s\t", owner.Name);
	fprintf (OAiP_Lab5Var9, "%s\t", owner.AutoNum);
	fprintf (OAiP_Lab5Var9, "%s\t", owner.NumTechPass);
	fprintf (OAiP_Lab5Var9, "%s\t", owner.Birthdate);
	fprintf (OAiP_Lab5Var9, "%s\t", owner.PhoneNumber);
	fprintf (OAiP_Lab5Var9, "%s\n\0", owner.OtdGIBDD);
	fclose (OAiP_Lab5Var9);
}

void searchStructure ()
{
	printf ("Выберите параметр поиска");
	printf ("1) Имя\n");
	printf ("2) Номер машины\n");
	printf ("3) Номер техпаспорта\n");
	printf ("4) Дата рождения\n");
	printf ("5) Номер телефона\n");
	printf ("6) Отделение ГИБДД\n");
	int inquiryDemand = 0;
	scanf ("%d", &inquiryDemand);
	printf ("Введите значение\n");
	char searchValue [MAX_LENGTH_OTDGIBDD];
	scanf ("%s", &searchValue);
	char scanStruct [MAX_LENGTH];
	FILE *file = fopen ("OAiP_Lab5Var9.txt", "r");
	while (fgets (scanStruct, MAX_LENGTH, file) != NULL)
	{
		char scanStruct2 [MAX_LENGTH];
		addWord(scanStruct2, scanStruct);
		int i;
		if (shiftText (scanStruct2, searchValue, inquiryDemand) == 1)
		{
			printf ("%s", scanStruct);
		}
	}
	fclose (file);
}

int shiftText (char *word, char *searchValue, int inquiryDemand)
{
	int i;
	for (i = 0; i < (inquiryDemand - 1); i++)
	{
		word = word + scanTabulation (word) + 1;
	}
	int length = strlen (searchValue);
	for (i = 0; i < length - 1; i++)
	{
		if (searchValue [i] != word [i]) break;
	}
	if (i == (length - 1))
	{
		return 1;
	}
	return 0;
}

void addWord(char *word_new, char *word)
{
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		word_new [i] = '\0';
	}
	int length = strlen (word);
	for (int i = 0; i < length; i++)
	{
		word_new [i] = word [i];
	}
}

int scanTabulation (char* StringText)
{
	for (int i = 0; StringText [i]; i++)
	{
		if (StringText [i] == '\t')
			return i;
	}
	return NULL;
}

void outputStructure ()
{
	FILE *OAiP_Lab5Var9 = fopen ("OAiP_Lab5Var9.txt", "r");
	if (OAiP_Lab5Var9 == NULL)
	{
		printf ("Файл не найден/n");
	}
	else
	{
		char stringStruct [MAX_LENGTH];
		for (int i = 0; i < MAX_LENGTH; i++)
		{
			stringStruct [i] = '\0';
		}
		while (fgets (stringStruct, MAX_LENGTH, OAiP_Lab5Var9) != NULL)
		{
			printf ("%s", stringStruct);
		}
	}
	fclose(OAiP_Lab5Var9);
}

void streamliningStructure()
{
	FILE *OAiP_Lab5Var9 = fopen ("OAiP_Lab5Var9.txt", "rt");
	if (OAiP_Lab5Var9 == NULL)
	{
		printf ("Ошибка");
	}
	else 
	{
		struct AutoOwner carStruct;
		int schet = 1;
		int nameLength = 0;
		while (!feof (OAiP_Lab5Var9))
		{
			fscanf(OAiP_Lab5Var9 , "%s %s %s %s %s %s", carStruct.Name, carStruct.AutoNum, carStruct.NumTechPass,
				carStruct.Birthdate, carStruct.PhoneNumber, carStruct.OtdGIBDD);
			schet++;
		}
		rewind(OAiP_Lab5Var9);
		struct AutoOwner *carStructs = (struct AutoOwner*)calloc(schet , sizeof(struct AutoOwner));
		for (int i = 0; i < schet; i++)
		{
			fscanf(OAiP_Lab5Var9, "%s %s %s %s %s %s", carStructs[i].Name, carStructs[i].AutoNum, carStructs[i].NumTechPass,
				carStructs[i].Birthdate, carStructs[i].PhoneNumber, carStructs[i].OtdGIBDD);
			if (strlen(carStructs[i].Name) > nameLength)
			{
				nameLength = strlen(carStructs[i].Name);
			}
		}	
		for (int k = 0; k < nameLength; k++)
			for (int i = 0; i < schet; i++)
				for (int j = 0; j < schet - i - 1; j++)
				{
					if ((int)carStructs[j].Name[k] && (int)carStructs[j + 1].Name[k])
					{
						if (k == 0)
						{
							if ((int)carStructs[j].Name[k] > (int)carStructs[j + 1].Name[k]) {
								swap(&carStructs[j], &carStructs[j + 1]);
							}
						}
						else
						{
							if (((int)carStructs[j].Name[k] >(int)carStructs[j + 1].Name[k]) &&((int)carStructs[j].Name[k - 1] == (int)carStructs[j + 1].Name[k -1]))
								swap(&carStructs[j], &carStructs[j + 1]);
						}
					}
				}
		FILE *OAiP_Lab5vAR9_new = fopen("OAiP_Lab5vAR9_new.txt", "w");
		for (int i = 0; i < schet; i++)
			fprintf(OAiP_Lab5vAR9_new, "%s\t%s\t%s\t%s\t%s\t%s\n\0", carStructs[i].Name, carStructs[i].AutoNum, carStructs[i].NumTechPass,
				carStructs[i].Birthdate, carStructs[i].PhoneNumber, carStructs[i].OtdGIBDD);
	}
}

void swap(struct AutoOwner *carStructs1, struct AutoOwner *carStructs2) 
{
	struct AutoOwner buff = *carStructs1;
	*carStructs1 = *carStructs2;
	*carStructs2 = buff;
}
