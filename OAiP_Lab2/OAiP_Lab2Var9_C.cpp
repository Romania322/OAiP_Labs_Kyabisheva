/*
Кябишева Александра Зауровна
Лабораторная работа №2
Вариант 9
Задание: Написать программу, которая выводит на экран простые числа. Массив и его длина вводится пользователем.
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 		
#include <conio.h> 		
#include <stdlib.h>		

int verificationSizeOfArray();
int verificationArray(int*array, int sizeOfArray);
int main() {
	system("chcp 1251");
	system("cls");
	int sizeOfArray;
	printf("Введите размер массива ");
	sizeOfArray = verificationSizeOfArray();
	int *array = (int*)malloc(sizeOfArray * sizeof(int));
	for (int i = 0; i < sizeOfArray; i++) {
		printf("Введите %d Элемент массива ", i + 1);
		array[i] = verificationSizeOfArray();
	}
	verificationArray(array, sizeOfArray); 
	_getch();
	return 0;
}
int verificationSizeOfArray() {
	int number;
	while (!scanf("%d", &number)) {
		printf("Ошибка ввода. Повторите попытку ");
		while (getchar() != '\n');
	}
	if (getchar() != '\n') {
		printf("Ошибка ввода. Повторите попытку ");
		number = verificationSizeOfArray();
	}
	return number;
}
int verificationArray(int*array, int sizeOfArray) {
	int i;
	for (int i = 0; i < sizeOfArray; i++) {		
 		if (abs(array[i]) <= 3) {		
 			printf ("%d ", array[i]);		
 		}		
 		else {		
 			for (int j = 2; j < array[i]; j++) {		
 				if (array[i] % j == 0) {		
 					break;		
 				}		
 				if (j == array[i] - 1) {		
 					printf ("%d ", array[i]);		
 				}		
 			}		
 		}		
 	}
	 return 0;		
}
