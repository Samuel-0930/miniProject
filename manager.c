#include <stdio.h>
#include <stdlib.h>
#include "manager.h"
//#define DEBUG
#define DPRINT printf

void addProduct(Product *p, int n){
	printf("제품명? ");
	scanf(" %[^\n]s", p[n].name);
#ifdef DEBUG
	DPRINT("%s\n", p[n].name);
#endif
	printf("제품설명? ");
	scanf(" %[^\n]s", p[n].script);
#ifdef DEBUG
	DPRINT("%s\n", p[n].script);
#endif
	printf("중량? ");
	scanf("%s", p[n].weight);
#ifdef DEBUG
	DPRINT("%s\n", p[n].weight);
#endif
	printf("판매가격? ");
	scanf("%d", &p[n].price);
#ifdef DEBUG
	DPRINT("%d\n", p[n].price);
#endif
	printf("배송방법? ");
	scanf("%d", &p[n].delivery);
#ifdef DEBUG
	DPRINT("%d\n", p[n].delivery);
#endif
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
#ifdef DEBUG
	DPRINT("%s\n", p[num-1].name);
#endif
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

void saveData(Product *p, int count){
	FILE *fp;
	fp = fopen("product.txt","wt");
	
	for(int i = 0; i < count; i++){
	fprintf(fp, "%s %s %s %d %d\n", p[i].name, p[i].script, p[i].weight, p[i].price, p[i].delivery);
	}
	
	fclose(fp);
	printf("\n=> 저장됨!");
}

int loadData(Product *p){
	int i = 0;
	FILE *fp;
	if((fp = fopen("product.txt","rt"))){
		printf("\n=> 로딩 성공!\n");
	}

	else{
		printf("\n=> 파일 없음\n");
		return 0;
	}

	for(; i < 100; i++){
		fscanf(fp, "%s", p[i].name);
		if(feof(fp)) break;
		fscanf(fp, "%s", p[i].script);
		fscanf(fp, "%s", p[i].weight);
		fscanf(fp, "%d", &p[i].price);
		fscanf(fp, "%d", &p[i].delivery);
	}

	fclose(fp);
	return i;
}

int selectMenu(){
	int menu;
	printf("\n***Product***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 저장\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	return menu;
}

