/*
�������� ���������� ��������
������������ ������ �2
������� 9
�������: �������� ���������, ������� ������� �� ����� ������� �����. ������ � ��� ����� �������� �������������.
*/
#define _CRT_SECURE_NO_WARNINGS 
 #include <stdio.h> 		
 #include <conio.h> 		
 #include <stdlib.h>		
 		
 void function(int*address);
 int main () {		
 		
 	system("chcp 1251");		
 	system("cls"); 		
 	int size_of_array;	 		
 	printf("������� ������ ������ ");
 	function(&size_of_array);		
 	while (!(size_of_array > 0)) {		
 		function(&size_of_array);		
 	}		 		
 	int *array = (int*)malloc(size_of_array * sizeof(int));	 		
 	for (int i = 0; i < size_of_array; i++) {		
 		printf("������� %d ������� ������� ", i + 1);		
 		function(&array[i]);		
 	} 		
 	for (int i = 0; i < size_of_array; i++) {		
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
	 return 0;		
 }	 		
 void function(int*address) {		
 	int nmbr;		
 		while (!scanf("%d", &nmbr)) {		
 			printf("������ �����. ��������� ������� ");		
 			while (getchar() != '\n');		
 		}		
 	if (getchar() != '\n') {		
 		printf("������ �����.��������� ������� ");		
 		function(&nmbr);		
 	}		
 	*address = nmbr;		
}
