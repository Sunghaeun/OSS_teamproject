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

void seat_read(user *u){
     printf("%-6s %3d원\n",u->name,u->time);
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
