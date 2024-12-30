#include <stdio.h>
#define MAX 100
int array[MAX][MAX];

 void nhapArray(int m, int n);
 void Array(int m, int n);
 void GocArray(int m, int n);
 void BienArray(int m, int n);
 void CheoChinhPhuArray(int m, int n);
 void SoNguyenTo(int m, int n);
int check = 1, derm;
  
 int main() {
 	int m, n;
  	printf("Moi ban nhap so hang cho mang: ");
  	scanf("%d", &m);
  	printf("Moi ban nhap so cot cho mang: ");
 	scanf("%d", &n);
 	

	while(1){
		printf("\n=============MENU=============\n");
		printf("1. Nhap mang\n");
		printf("2. in mang theo ma tran\n");
		printf("3. in cac phan tu o goc theo ma tran\n");
		printf("4. in cac phan tu tren duong bien theo ma tran\n");
		printf("5. in cac phan tu tren duong cheo chinh va phu theo ma tran\n");
		printf("6. in cac so nguyen to theo ma tran\n");
		printf("7. Thoat!\n");
		
	int numb;
	printf("Moi ban nhap chuc nang tuong ung: ");
	scanf("%d", &numb);
	
	switch(numb){
		case 1:
			nhapArray(m, n);
			printf("\nThuc hien thanh cong!\n");
			break;
		case 2:
			Array(m, n);
			printf("\nThuc hien thanh cong!\n");
			break;
		case 3:
			GocArray(m, n);
			printf("\nThuc hien thanh cong!\n");
			break;
		case 4:
			BienArray(m, n);
			printf("\nThuc hien thanh cong!\n");
			break;
		case 5:
			CheoChinhPhuArray(m, n);
			printf("\nThuc hien thanh cong!\n");
			break;
		case 6:
			SoNguyenTo(m, n);
			printf("\nThuc hien thanh cong!\n");
			break;
		case 7:
			printf("Thoat!\n");
			break;
		default:
			printf("Moi ban nhap dung chuc nang 1 - 7!");
	}
	if(numb == 7)
		break;
}
 	
 	return 0;
 }
 
 //1.
 void nhapArray(int m, int n){
 	for(int i = 0;i < m;i++){
	 	for(int j = 0;j < n;j++){
		 	printf("array[%d][%d] = ", i, j);
		 	scanf("%d", &array[i][j]);
		 }
	 }
	 check = 0;
	 return;
 };
 
 //2.
 void Array(int m, int n){
 	if(check){
	 	printf("Mang trong!");
	 	return;
	 }
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			printf("%d ", array[i][j]);
		 }
		 printf("\n");
	}
	return;
 };
 
 //3.
 void GocArray(int m, int n){
 	if(check){
	 	printf("Mang trong!");
	 	return;
	}
 	for(int i = 0;i < m;i++){
 		int enter = 0;
	 	for(int j = 0;j < n;j++){
	 		if((i == 0 || i == m - 1) && (j == 0 || j == n - 1)){
			 	printf("%d ", array[i][j]);
			 	enter = 1;
			}
	 	}
	 	if(enter){
		 	printf("\n");
		 }
	}
	return;
 };
 
 //4.
 void BienArray(int m, int n){
 	if(check){
	 	printf("Mang trong!");
	 	return;
	}
 	for(int i = 0;i < m;i++){
	 	for(int j = 0;j < n;j++){
	 		if(i == 0 || i == m -1 || j == 0 || j == n-1){
			 	printf("%d ", array[i][j]);
			 }
			 else{
			 	printf("  ");
			 }
	 	}
	 	printf("\n");
	}
	return;
 };
 
 //5.
 void CheoChinhPhuArray(int m, int n){
 	if(check){
		printf("Mang trong!");
	 	return;
	}
 	for(int i = 0;i < m;i++){
	 	for(int j = 0;j < n;j++){
	 		if(j == i || i + j == n-1){
			 	printf("%d ", array[i][j]);
			 }
			else{
				printf("  ");
			}
	 	}
	 	printf("\n");
	}
	return;
 };

//6. 
void SoNguyenTo(int m, int n){
	if(check){
		printf("Mang trong!");
		return;
	}
	derm = 1;
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			int kiemTra = 1;
			if(array[i][j] < 2){
				kiemTra = 0;
			}
			else{
				for(int a = 2;a * a <= array[i][j];a++){
					if(array[i][j] % a == 0){
						kiemTra = 0;
						break;
					}
				}
			}
			if(kiemTra){
				printf("%d ", array[i][j]);
				derm = 0;
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
	if(derm){
		printf("Mang khong ton tai so nguyen to!\n");
	}
	return;
}; 
