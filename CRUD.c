//crud기능
#include "CRUD.h" 
 
void seat_create(user *u){
    printf("이름을 입력하세요. ");
    scanf("%d",&u->name);

    printf("아용시간을 입력하세요. ");
    scanf("%d",&u->time);
    
    u->seat=1;
     
    printf("==> 추가되었습니다!\n"); 
    return 1;
}

void seat_read(user u){
     printf("%-6s %3d원\n",u.name,u.time);
}
//listScore2, selectDataNo2적용 잘해야됨
void listScore2(user *u[], int count){
    printf("\n No 이름  이용시간\n");
    printf("==========================================================\n");
    for(int i=0;i<count;i++){
        if(u[i]==NULL) continue;
        printf("%2d ", i+1);
        seat_read(*u[i]);
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
    scanf("%d",&u->name);

    printf("이용시간을 입력하세요. ");
    scanf("%d",&u->time);
    
    printf("==> 수정되었습니다!\n");
    return 1;
}

void seat_delete(user *u){
    u->time=-1;
    u->seat=0;
    printf("==> 삭제되었습니다!\n");
    return 0;
}
