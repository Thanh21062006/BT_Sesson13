#include <stdio.h>
const int maxSize = 100;
int array[maxSize], size = 0, check = 1, value;
char kyTu;

void nhapMang();
void inMang();
void themPhanTu();
void suaPhanTu();
void xoaPhanTu();
void sapXepPhanTu();
void tinKiemPhanTu();

int main() {
	while(1){
		printf("\n==============MENU=============\n");
		printf("1. Nhap mang\n");
		printf("2. In mang\n");
		printf("3. Them phan tu\n");
		printf("4. Sua phan tu\n");
		printf("5. Xoa phan tu\n");
		printf("6. Sap xep phan tu\n");
		printf("7. Tim kiem phan tu\n");
		printf("8. Thoat!\n");
		
		int number;
		printf("\nMoi ban chon chuc nang tuong ung: ");
		scanf("%d", &number);
		
		switch(number){
			case 1:
				nhapMang();
				break;
			case 2:
				inMang();
				break;
			case 3:
				themPhanTu();
				break;
			case 4:
				suaPhanTu();
				break;
			case 5:
				xoaPhanTu();
				break;
			case 6:
				sapXepPhanTu();
				break;
			case 7:
				tinKiemPhanTu();
				break;
			case 8:
				printf("Thoat!\n");
				break;
			default:
				printf("Moi ban nhap dung chuc nang trong MENU 1-8!");
		}
		if(number == 8)
		break;
	}
	return 0;
}

void nhapMang(){
	printf("Moi ban nhap vao do dai cua mang: ");
	scanf("%d", &size);
	
	for(int i = 0;i < size;i++){
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
	check = 0;
	printf("Nhap mang thanh cong!\n");
	return;
};

void inMang(){
	if(check){
		printf("Mang trong!");
		return;
	}
	printf("array[%d] = ",size);
	for(int i = 0;i < size;i++){
		printf("%d ", array[i]);
	}
	printf("\nIn mang thanh cong!");
	return;
};

void themPhanTu(){
	int n;
	printf("Moi ban nhap vao vi tri muon them: ");
	scanf("%d", &n);
	printf("Moi ban nhap vao gia tri can them: ");
	scanf("%d", &value);
	
	if(n < 0){
		n = 0;
	}
	else if(n > size){
		n = size;
	}
	
	for(int i = size;i > n;i--){
		array[i] = array[i-1];
	}
	check = 0;
	array[n] = value;
	size++;
	printf("Them thanh cong!");
	
	return;
};

void suaPhanTu(){
	if(check){
		printf("Mang chua co phan tu!");
		return;
	}
	int fix;
	printf("Moi ban nhap vao vi tri can sua: ");
	scanf("%d", &fix);
	printf("Moi ban nhap vao gia tri can sua: ");
	scanf("%d", &value);
	
	if(fix < 0 || fix > size){
		printf("Vi tri khong hop le!");
		return;
	}
	else{
		array[fix] = value;
	}
	printf("Sua thanh cong!");
	return;
};

void xoaPhanTu(){
	if(check){
		printf("Mang chua co phan tu!");
		return;
	}
	int delet;
	printf("Moi ban nhap nhap vi tri can xoa!");
	scanf("%d", &delet);
	
	if(delet < 0 || delet > size){
		printf("Vi tri khong hop le!");
		return;
	}
	else{
		for(int i = delet;i < size;i++){
			array[i] = array[i+1];
		}
		size--;
	}
	printf("Xoa thanh cong!");
	return;
};

void sapXepPhanTu(){
	if(check){
		printf("Mang chua co phan tu!");
		return;
	}
	while(1){
		printf("a. Giam dan\n");
		printf("b. Tang dan\n");
		
		printf("Moi ban chon a or b: ");
		scanf(" %c", &kyTu);
		
		switch(kyTu){
			case 'a':
				for(int i = 0;i < size - 1;i++){
					for(int j = 0;j < size - i - 1;j++){
						if(array[j] < array[j+1]){
							int temp = array[j];
							array[j] = array[j+1];
							array[j+1] = temp;
						}
					}
				}
				printf("Thuc hien thanh cong!\n");
				return;
			case 'b':
				for(int i = 0;i < size - 1;i++){
					for(int j = 0;j < size - i - 1;j++){
						if(array[j] > array[j+1]){
							int temp = array[j];
							array[j] = array[j+1];
							array[j+1] = temp;
						}
					}
				}
				printf("Thuc hien thanh cong!\n");
				return;
			default:
				printf("\nChuc nang khong ton tai moi ban chon lai!\n");	
		}
	}
};

void tinKiemPhanTu(){
	if(check){
		printf("Mang chua co phan tu!");
		return;
	}
	while(1){
		printf("a. Tim kiem tuyen tinh\n");
		printf("b. Tim kiem nhi phan\n");
		
		printf("Moi ban chon a or b: ");
		scanf(" %c", &kyTu);
		printf("Moi nhap vao gia tri can tim: ");
		scanf("%d", &value);
		int count;
		
		switch(kyTu){
			case 'a':
				count = 0;
				for(int i = 0;i < size;i++){
					if(array[i] == value){
						printf("array[%d] ",i);
						count++;
					}
				}
				if(count == 0){
					printf("Phan tu %d khong ton tai trong mang!\n", value);
				}
				return;
			case 'b':
				sapXepPhanTu();
				int start = 0, end = size - 1;
				count = 0;
				while(start <= end){
					int mid = (start + end)/2;
					if(array[mid] == value){
						printf("array[%d] ", mid);
						count++;
						break;
					}
					else if(array[mid] < value){
						start = mid +1;
					}else{
						end = mid - 1;
					}
				}
				if(count == 0){
					printf("Phan tu %d khong ton tai trong mang!\n", value);
				}
				return;
		}
	}
	return;
};
