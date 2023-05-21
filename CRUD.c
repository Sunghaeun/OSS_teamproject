//crud기능
#include "CRUD.h" 
 
void seating_sheat(user u){
    int seat_n=0;
    //첫째줄 시작
    for(int i=0;i<36;i++){
        printf("-");
    }
    printf("\n");
    for(int i=0;i<27;i++){
        if(i%5==0) printf("|");
        if(i%5==3) {
          seat_n++;
          if(seat_n==u.seat){
            printf("X");
          } else printf("%d",seat_n);
          }
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
    printf("\n");
}

int seat_create(user *u){
    printf("이름을 입력하세요. ");
    scanf("%s",&u->name);

    printf("이용시간을 입력하세요.(시간) ");
    scanf("%d",&u->time);
    
    u->seat=1;
 
 if(&u->time > 120){
  event();
 }
    
    printf("==> 추가되었습니다!\n"); 
    return 1;
}

void seat_read(user *u){
     printf("%-6s %3d원\n",u->name,u->time);
}
//listScore2, selectDataNo2적용 잘해야됨
void listScore2(user *u[], int count){
    printf("\n No 이름  이용시간\n");
    printf("==========================================================\n");
    for(int i=0;i<count;i++){
        if(u[i]==NULL) continue;
        printf("%2d ", i+1);
        seat_read(u[i]);
    }
    printf("\n");
}
int selectDataNo2(user *u[], int count){
    int no;
    listScore2(u, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}
void seat_change(user *u){
    printf("이름을 입력하세요. ");
    scanf("%s",&u->name);

    printf("이용시간을 입력하세요. ");
    scanf("%d",&u->time);
    
    printf("==> 수정되었습니다!\n");
}
