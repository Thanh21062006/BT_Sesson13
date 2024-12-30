#include <stdio.h>

int commonFactor(int a, int b);

int main() {
	int x = 15, y = 18;
	printf("Uoc chung lon nhat cua %d va %d la: %d", x, y, commonFactor(x, y));
	
	return 0;
}

int commonFactor(int a, int b){
	int common = 0;
	for(int i = 1;i <= a;i++){
		if(a % i == 0 && b % i == 0){
			common = i;
		}
	}
	return common;
};
