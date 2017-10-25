#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h>

void fncshn(int*address);

void main() {

	system("chcp 1251");
	system("cls");

	int sz;

	printf("Введите размер масива ");
	fncshn(&sz);
	while (!(sz > 0)) {
		fncshn(&sz);
	}

	int *array = (int*)malloc(sz * sizeof(int));

	for (int i = 0; i < sz; i++) {
		printf("Введите %d элемент массива ", i + 1);
		fncshn(&array[i]);
	}

	for (int i = 0; i < sz; i++) {
		if(abs(array[i])<=3){
			printf("%d ", array[i]);
		}
		else {
			for (int j = 2; j < array[i]; j++) {
				if (array[i] % j == 0) {
					break;
				}
				if (j == array[i] - 1) {
					printf("%d ", array[i]);
				}
			}
		}
	}
	_getch();
}

void fncshn(int*address) {
	int nmbr;
		while (!scanf("%d", &nmbr)) {
			printf("Ошибка ввода. Повторите попытку ");
			while (getchar() != '\n');
		}
	if (getchar() != '\n') {
		printf("Ошибка ввода.Повторите попытку: ");
		fncshn(&nmbr);
	}
	*address = nmbr;
}