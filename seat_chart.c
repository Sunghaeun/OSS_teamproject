#include <stdio.h>

int main(void){
    int seat_n=0;
    //첫째줄 시작
    for(int i=0;i<36;i++){
        printf("-");
    }
    printf("\n");
    for(int i=0;i<27;i++){
        if(i%5==0) printf("|");
        if(i%5==3) printf("%d",++seat_n);
        printf(" ");
    }
    printf("\n");
    for(int i=0;i<36;i++){
        printf("-");
    }
    //첫째줄 끝
    printf("\n");
    //왼쪽 세로 시작
    for(int j=0;j<2;j++){
        for(int i=0;i<8;i++){
            if(i%5==0) printf("|");
            if(i%5==3) printf("%d",++seat_n);
            printf(" ");
        }
        printf("\n");
        for(int i=0;i<8;i++){
            printf("-");
        }
        printf("\n");
    }
    for(int i=0;i<8;i++){
            if(i%5==0) printf("|");
            if(i%5==3) printf("%d",++seat_n);
            printf(" ");
        }
        printf("\n");
    //왼쪽 세로 끝
    for(int i=0;i<36;i++){
        printf("-");
    }
    printf("\n");
    for(int i=0;i<27;i++){
        if(i==2) printf(" ");
        if(i%5==0) printf("|");
        if(i%5==2) printf("%d",++seat_n);
        else printf(" ");
    }
    printf("\n");
    for(int i=0;i<36;i++){
        printf("-");
    }
    return 0;
}
