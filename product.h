#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
        char name[20];
        char explain[30];
        char weight [20];
        int price;
        int deliver;
} Product;


int addProduct(Product *p);//제품을 추가하는 함수
void saveProduct(Product *p);//파일에 상품을 저장하는 함수
void loadProduct(Product *p);//모든 제품을 출력하는 함수
void bringProduct(Product*p);//파일에서 정보를 가져오는 함수
void searchName(Product *p);//이름으로 검색하는 함수
void searchDeliver(Product *p);//배달방식으로 검색하는 함수
void searchPrice(Product *p);//가격으로 검색하는 함수
int deleteProduct (Product *p);//삭제하는 함수(price = -1)



