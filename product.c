#include "product.h"

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
        printf("배송방법을 선택해주세요(1:새벽배송/ 2:택배배송)");
        scanf("%d",&p->deliver);
        p->name[strlen(p->name)-1] = '\0';
        p->explain[strlen(p->explain)-1] = '\0';
        p->weight[strlen(p->weight)-1] = '\0';
        return 1;
}//제품을 추가하는 함수

void saveProduct(Product *p){
        FILE *fp;
        fp = fopen("product.txt", "wt");
        fprintf(fp, "%s %s %s %d %d\n",p->name, p->explain, p->weight,p->price, p->deliver);
        fclose(fp);
        printf("=> 바구니에 저장되었습니다.\n");
} // 파일에 상품을 저장하는 함수

void loadProduct(Product *p){
                printf("제품명   설명\t   무게\t  가격\t  배송\n==================================\n");
        if(p->price!=-1){
                printf("%-10s %-10s %-10s %-8d ", p->name, p->explain, p->weight, p->price);
                if(p->deliver == 1) printf("새벽배송\n");
                else printf("택배배송\n");
        }
}

void bringProduct(Product *p){
        FILE *fp;
        fp = fopen("product.txt", "r");
        fscanf(fp, "%s %s %s %d %d",p->name, p->explain, p->weight,&(p->price), &(p->deliver));
        fclose(fp);
        printf("=>바구니에 담긴 상품들입니다. \n");
        loadProduct(p);
}

void searchName(Product *p){
        int*scnt =0;
        char search[20];

        printf("검색할 제품명은? ");
        scanf("%s", search);

        if(strstr(p->name, search)){
                loadProduct(p);
                scnt++;
        }
        if(scnt ==0) printf("=> 검색된 데이터가 존재하지 않습니다!\n");
}
void searchDeliver(Product *p){
        int*scnt = 0;
        int deliver;
        while(1){
                printf("원하는 배송방법은?(1:새벽배송/2:택배배송)");
                scanf("%d", &deliver);
                if(deliver==1||deliver==2) break;
                printf("Please Retry\n");
        }

        if(deliver==p->deliver){
                loadProduct(p);
                scnt++;
        }

        if(scnt ==0) printf("=> 검색된 데이터가 존재하지 않습니다!\n");
}
void searchPrice(Product *p){
        int*scnt =0;
        int price;

        printf("최대로 쓰고자 하는 비용을 입력하세요");
        scanf("%d", &price);

        if(price>(p->deliver)){
                loadProduct(p);
                scnt++;
        }
        if(scnt ==0) printf("=> 검색된 데이터가 존재하지 않습니다!\n");
}
int deleteProduct(Product *p){
        int a;
        printf("삭제하시겠습니까?(확인:1)");
        scanf("%d",&a);
        if(a!=1) return -1;
        else{
                p->price=-1;
                return 0;
        }
}

int main(void){
        Product p;
        int menu;
        while(1){
                printf("\n\n===상품관련 옵션===\n");
                printf("1.제품추가\n");
                printf("2.파일에 상품을 저장\n");
                printf("3.상품 파일가져오기\n");
                printf("4.상품 파일 목록 조회\n");
                printf("5.제품명으로 검색\n");
                printf("6.배달옵션으로 검색\n");
                printf("7.가격대 검색\n");
                printf("8.제품을 삭제\n");
                printf("0.시스템 종료\n");
                scanf("%d",&menu);

                if(menu==0){
                       printf("종료!\n");
                       break;
                }
                else if(menu==1){
                        addProduct(&p);
                }
                else if(menu==2){
                        saveProduct(&p);
                }
                else if(menu==3){
                        bringProduct(&p);
                }
                else if(menu==4){
                        loadProduct(&p);
                }
                else if(menu==5){
                        searchName(&p);
                }
                else if(menu==6){
                        searchDeliver(&p);
                }
                else if(menu==7){
                        searchPrice(&p);
                }
                else if(menu==8){
                        deleteProduct(&p);
                }
                else printf("retry\n");
        }
}
