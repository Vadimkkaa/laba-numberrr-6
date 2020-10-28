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
    srand(time(NULL));                    //для Настоящего Рандома
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));  //
        for (j = 0; j < n; j++) {
			a[i][j] = rand() % 3 - 0;    // забиваю рандомные значения от 0 до 2 
			if (i == j)
				a[i][j] = 0;           //чтобы числа главной диагонали были 0
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
		if (sum > sum1) {              // если 2 больше чем 0 тогда ..
			sum2++;
		}
		if (sum > (n / 2)) {           // если 2 больше половины всех цифр в строке тогда..
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
		if (drop == 0) {                          //drop увеличится только если есть 0 в строке(то есть есть хоть один проигрыш) 
			                                      //отсуствие увеличения drop==нету проигрышей у этой команды
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
		printf("At least one team for point c exists");     //win изменяется только если 2 хоть один раз больше половины,т е win бы уже стал 1 в противном случае 
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

