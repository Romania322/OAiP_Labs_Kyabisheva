/*
Спешл фор ю
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {

	system("chcp 1251");
	system("cls");

	int size,count;

	printf("\t\tБугага , добро пожаловать в 7 кругов ада\n\n");
	printf("Введите колличество элементов массива: ");
	if (!scanf("%d",&size))
		while (!scanf("%d", &size)) {
			printf("Ошибка ввода.Повторите попытку: ");
			while (getchar() != '\n');
		}
	while (getchar() != '\n');

	int*array = malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++) {
		printf("Введите %d элемент массива: ",i+1);
		if (!scanf("%d", &array[i]))
			while (!scanf("%d", &array[i])) {
				printf("Ошибка ввода.Повторите попытку ввода %d элемента: ",i+1);
				while (getchar() != '\n');
			}
		while (getchar() != '\n');
	}

	for (int i = 0; i < size; i++) {
		if (array[i] == 0 || abs(array[i]) == 1 || abs(array[i]) == 2) {
			printf("%d ", array[i]);
		}
		else {
			count = 0;
			for (int j = 2; j < (array[i] / 2) + 1; j++) {
				if (array[i] % j == 0) {
					count = 1;
					break;
				}
			}
			!count ? printf("%d ", array[i]) : printf("") ;
			/*
			Или это выглядит так
			if(!count){
				printf("%d ", array[i]);
			}
			*/
		}
	}

	_getch();
}