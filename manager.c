#include "manager.h"

int addProduct(Product *p){
    getchar();
    printf("추가할 제품명은?");
    fgets(p->name,20,stdin);
    printf("새로운 제품의 설명은?");
    fgets(p->explain,30,stdin);
    printf("무게는?");
    fgets(p->weight,30,stdin);
    printf("가격은?");
    scanf("%d",&p->price);
    printf("배송방법을 선택해주세요(1:새벽배송/ 2: 택배배송)");
    scanf("%d",&p->deliver);
    p->name[strlen(p->name)-1] = '\0';
    p->explain[strlen(p->explain)-1] = '\0';
    p->weight[strlen(p->weight)-1] = '\0';
    return 1;
} //제품을 추가하는 함수

void loadProduct(Product* p[], int count){
       	printf("\nNo 제품명      설명\t  무게\t  가격\t  배송\n===========================================================\n");
	for(int i=0; i<count;i++){
		if(p[i]->price!=-1){
			printf("%d %-10s %-10s %-10s %-8d ",i+1,p[i]->name, p[i]->explain, p[i]->weight, p[i]->price);
			        if(p[i]->deliver==1) printf("새벽배송\n");
			        else printf("택배배송\n");
		}
	}
}
 // 파일에 상품을 저장하는 함수



void loadProduct(Product* p[], int count){
    printf("\nNo 제품명      설명\t  무게\t  가격\t  배송\n===========================================================\n");
    for(int i=0; i<count;i++){
        if(p[i]->price!=-1){
        printf("%d %-10s %-10s %-10s %-8d ",i+1,p[i]->name, p[i]->explain, p[i]->weight, p[i]->price);
        if(p[i]->deliver==1) printf("새벽배송\n");
        else printf("택배배송\n");
        }
    }   
 } //모든 제품을 출력하는 함수 

int bringProduct(Product* p[]){
	FILE *fp;
	fp= fopen("product.txt","r");
	int i=0;
	while(!feof(fp)){
	        int result = fscanf(fp, "%s %s %s %d %d\n",p[i]->name, p[i]->explain,p[i]->weight, &(p[i]->price), &(p[i]->deliver));
	        i++;
	        if(result<1) break;
       	}
	fclose(fp);
	printf("=> 바구니에 담긴 상품들입니다. \n");
	loadProduct(p,i);

	return i;
}
void searchName(Product* p[], int count){
	int scnt =0;
	char search[20];
       	printf("검색할 제품명은? ");
	scanf("%s", search);

	printf("\nNo 제품명      설명\t  무게\t  가격\t  배송\n===========================================================\n");
	for(int i=0; i<count;i++){
		if(strstr(p[i]->name, search)&&p[i]->price !=-1){
			printf("%d %-10s %-10s %-10s %-8d ",i+1,p[i]->name, p[i]->explain, p[i]->weight, p[i]->price);
			if(p[i]->deliver==1) printf("새벽배송\n");
			else printf("택배배송\n");
			scnt++;
		}
	}
}
//파일에서 정보를 가져오는 함수

 //제품명을 찾는 함수

 //배달법을 통해 검색하는 함수

 //가격을 통해 검색하는 함수

 //주문하지 않을 제품을 삭제하는 기능 주문하지 않을 시 (return -1)
