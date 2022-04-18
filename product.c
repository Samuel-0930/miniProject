#include <stdio.h>
#include <stdlib.h>
#include "product.h"

void addProduct(Product *p, int n){
	printf("제품명? ");
	scanf(" %[^\n]s", p[n].name);
	printf("제품설명? ");
	scanf(" %[^\n]s", p[n].script);
	printf("중량? ");
	scanf("%s", p[n].weight);
	printf("판매가격? ");
	scanf("%d", &p[n].price);
	printf("배송방법? ");
	scanf("%d", &p[n].delivery);
}

void readProduct(Product *p, int n){
	for(int i = 0; i < n; i++){
	printf("%d번.\n",i + 1);
	printf("제품명: %s\n", p[i].name);
	printf("설명: %s\n", p[i].script);
	printf("무게: %s\n", p[i].weight);
	printf("가격: %d\n", p[i].price);
	printf("배송방법: %d\n", p[i].delivery);
	printf("\n\n");
	}
}

void updateProduct(Product *p, int n){
	int num;
	readProduct(p, n);
	printf("번호는 (취소 : 0)? ");
	scanf("%d", &num);

	if(num == 0) return;
	else addProduct(p, num - 1);	
}

void deleteProduct(Product *p, int n){
	int num;
	readProduct(p, n);
	printf("번호는 (취소 : 0)? ");
	scanf("%d", &num);

	int check;

	printf("정말로 삭제하시겠습니까?(삭제 : 1)");
	scanf("%d", &check);

	if(check == 1){
		for(int i = num; i < n; i++){
			p[i - 1] = p[i];
		}
	}

	else{
		return;
	}
}

void saveData(Product *p){
	FILE *fp;
	fp = fopen("product.txt","wt");

	fprintf(fp, "%s %s %s %d %d\n", p->name, p->script, p->weight, p->price, p->delivery);
	
	fclose(fp);
	printf("\n=> 저장됨!");
}

Product* loadData(Product *p){
	int i = 0;
	FILE *fp;
	if(fp = fopen("product.txt","rt")){
		printf("\n=> 로딩 성공!\n");
	}

	else{
		printf("\n=> 파일 없음\n");
		return 0;
	}

	for(; i < 100; i++){
		fscanf(fp, "%s", p->name);
		if(feof(fp)) break;
		fscanf(fp, "%s", p->script);
		fscanf(fp, "%s", p->weight);
		fscanf(fp, "%d", &p->price);
		fscanf(fp, "%d", &p->delivery);
	}

	fclose(fp);
	return p;
}

int selectMenu(){
	int menu;
	printf("\n***Product***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	return menu;
}

int main(){
	Product p[20];
	int count = 0, menu;

	//p = loadData(p);
	while(1){
		menu = selectMenu();
		if(menu == 0)
			break;
		if(menu == 1){
			readProduct(p, count);	
		}
		else if(menu == 2){
			addProduct(p, count);
			printf("=> 추가됨!\n");
			count++;
		}
		else if(menu == 3){
			updateProduct(p, count);
			printf("=> 수정됨!\n");
		}
		else if(menu == 4){
			deleteProduct(p, count);
			count--;

		}
		else if(menu == 5){
			saveData(p);
		}
	}
	printf("종료됨!\n");
	return 0;

}

