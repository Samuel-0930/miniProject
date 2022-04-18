#include <stdio.h>

typedef struct _product{
	char name[20];
	char script[100];
	char weight[10];
	int price;
	int delivery;
} Product;

void addProduct(Product *, int);
void readProduct(Product *, int);
void updateProduct(Product *, int);
void deleteProduct(Product *, int);
void saveData(Product *, int);
int loadData(Product *);
void searchName(Product *, int);
int selectMenu();
