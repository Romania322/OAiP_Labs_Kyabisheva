/*
����� ��� �
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {

	system("chcp 1251");
	system("cls");

	int size,count;

	printf("\t\t������ , ����� ���������� � 7 ������ ���\n\n");
	printf("������� ����������� ��������� �������: ");
	if (!scanf("%d",&size))
		while (!scanf("%d", &size)) {
			printf("������ �����.��������� �������: ");
			while (getchar() != '\n');
		}
	while (getchar() != '\n');

	int*array = malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++) {
		printf("������� %d ������� �������: ",i+1);
		if (!scanf("%d", &array[i]))
			while (!scanf("%d", &array[i])) {
				printf("������ �����.��������� ������� ����� %d ��������: ",i+1);
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
			��� ��� �������� ���
			if(!count){
				printf("%d ", array[i]);
			}
			*/
		}
	}

	_getch();
}