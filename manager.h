#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char name[20];      //제품명
    char explain[30];   //설명
    char weight [20];   //중량
    int price;          //판매가격
    int deliver;        //배송방법(1:새벽배송/ 2: 택배배송)
    
} Product;


int addProduct(Product *p);//제품을 추가하는 함수
void saveProduct(Product *p[], int count); // 파일에 상품을 저장하는 함수
void loadProduct(Product* p[], int count);//모든 제품을 출력하는 함수 
int bringProduct(Product* p[]);
void searchName(Product*p[], int count);//제품명을 찾는 함수
void searchdeliver(Product* p[], int count);//배달법을 통해 검색하는 함수
void searchprice(Product* p[], int count);//가격을 통해 검색하는 함수
int deleteProduct(Product *p);//주문하지 않을 제품을 삭제하는 기능 주문하지 않을 시 (return -1)
