#include <stdio.h>

void array(int m, int n);

int main() {
	int a, b;
	printf("Moi ban nhap vao so hang cua mang: ");
	scanf("%d", &a);
	printf("Moi ban nhap vao so cot cua mang: ");
	scanf("%d", &b);
	
	array(a, b);
		
	return 0;
}

void array(int m, int n){
	int array[m][n];
	printf("\n");
	for(int i = 0;i < sizeof(array)/sizeof(array[0]);i++){
		for(int j = 0;j < sizeof(array[0])/sizeof(int);j++){
			printf("array[%d][%d] = ", i, j);
			scanf("%d", &array[i][j]);
		}
	}
	
	printf("\n");
	for(int i = 0;i < sizeof(array)/sizeof(array[0]);i++){
		for(int j = 0;j < sizeof(array[0])/sizeof(int);j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	return;
};
