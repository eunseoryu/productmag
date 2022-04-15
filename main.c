#include "manager.h"


int main(void){
    Product* p [50];
    int menu;
    int count =0;
    while(1){

        printf("\n\n===상품관련 옵션====\n");
        printf("1.제품 추가\n");
        printf("2.파일에 상품을 저장\n");
        printf("3.상품파일 가져오기\n");
        printf("4.제품 목록\n");
        printf("5.제품명으로 검색\n");
        printf("6.배달옵션으로 검색\n");
        printf("7.가격대 검색\n");
        printf("8.제품을 삭제\n");
        printf("0. 종료\n");
        #ifdef DEBUG
            printf("(debug) count: %d\n", count);
        #endif
        scanf("%d", &menu);
        if(menu==0) break;
        if(menu==1){
            p[count] = (Product*) malloc(sizeof(Product));
            int n1 = addProduct(p[count]);
            if(n1==1) printf("=>상품이 추가되었습니다.\n");
            count++;
        }
        else if(menu==2){
            saveProduct(p, count);
        }
        else if(menu==3){
            int n3 = bringProduct(p);
            count =n3;
        }
        else if(menu==4){
            loadProduct(p, count);   
        }
        else if(menu==5){
            searchName(p, count);
        }
        else if(menu==6){
            searchdeliver(p, count);
        }
        else if(menu==7){
            searchprice(p, count);
        }
        else if(menu==8){
            int num, n8;
            printf("삭제할 제품 번호를 입력해주세요 >");
            scanf("%d",&num);
            if(num<=count){
                n8 = deleteProduct(p[num-1]);
            } else{
                printf("=>존재하지 않는 제품 번호입니다!!");
            }
            if(n8==0) printf("삭제되었습니다.\n");
           
        }
        else break;
        
    }
    

}
