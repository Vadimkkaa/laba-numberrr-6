#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<time.h>
int main() {
	int i, j;
	int n, w;
	int** a, ** b;
	int sum = 0, sum1 = 0, sum2 = 0;
	int drop=0,p=0;
	int win=0;
	shell:
	printf("Vvedite razmer:\n");
	scanf_s("%d", &n);
	if (n < 1) {
		printf("You gave me the wrong number-try again\n");  // 
		goto shell;
	}
	a = (int**)malloc(n * sizeof(int*));
    srand(time(NULL));                    //��� ���������� �������
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));  //
        for (j = 0; j < n; j++) {
			a[i][j] = rand() % 3 - 0;    // ������� ��������� �������� �� 0 �� 2 
			if (i == j)
				a[i][j] = 0;           //����� ����� ������� ��������� ���� 0
		}
	}
	printf("Your first array:\n");
    for (i = 0; i < n; i++) {

	  for (j = 0; j < n; j++) {

		 printf("%d ", a[i][j]);
	  }
	   printf("\n");
    }
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++){
			if (a[i][j]== 2) {              
				sum++;
			}
			if (a[i][j] == 0) {              
				sum1++;
			}
			

		}
		if (sum > sum1) {              // ���� 2 ������ ��� 0 ����� ..
			sum2++;
		}
		if (sum > (n / 2)) {           // ���� 2 ������ �������� ���� ���� � ������ �����..
			win++;
		}

		sum = 0;
		sum1 = 0;
	}
	printf("Answer for point a is %d", sum2);
	shelve:
	printf("\n\nEnter the array 2 size: \n");
	scanf_s("%d", &w);
	if (w < 1) {
		printf("Wrong number-please,try again\n");
			goto shelve;
	}
	b = (int**)malloc(w*sizeof(int*));

	for (i = 0; i < w; i++) {

		b[i] = (int*)malloc(w*sizeof(int));

		for (j = 0; j < w; j++) {

			b[i][j] = rand() % 3 - 0;
		}
	}
	printf("\nYour 2 array is\n");
	for (i = 0; i < w; i++) {
		for (j = 0; j < w; j++) {
			printf("%d ", b[i][j]);
		} 
		printf("\n");
	}
	printf("Team's numbers for point b\n");
	for (i = 0; i < w; i++) {
		for (j = 0; j < w; j++) {
			if (b[i][j] == 0) {
				drop++;
			}
		}
		if (drop == 0) {                          //drop ���������� ������ ���� ���� 0 � ������(�� ���� ���� ���� ���� ��������) 
			                                      //��������� ���������� drop==���� ���������� � ���� �������
			printf("%d ", i); 
			p = 1;
		}
		
		drop = 0;
	}
	if (p == 0) {
		printf("Sorry,no team's like you wish\n");
	}
	printf("\n\n");
	if (win != 0) {
		printf("At least one team for point c exists");     //win ���������� ������ ���� 2 ���� ���� ��� ������ ��������,� � win �� ��� ���� 1 � ��������� ������ 
	}
	else printf("No team's for point c");
	printf("\n\n");
	for (i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	for (i = 0; i < w; i++) {
		free(b[i]);
	}
	free(b);
	return 0;
}

