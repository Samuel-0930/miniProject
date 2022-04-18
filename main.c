#include <stdio.h>
#include "manager.h"

int main(){
	Product p[20];
	int count = 0, menu;

	count = loadData(p);
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
			saveData(p, count);
		}

		else if(menu == 6){
			//searchName(p, count);
		}
	}
	printf("종료됨!\n");
	return 0;

}

