#include <stdio.h>

typedef struct{
  char name[20];
  int time;
  seat s; 
}user;

void seat_create();
void seat_read();
void seat_change();
void seat_delete();
void searchName();
void timeAdd();
void orderFood();
void report_seat();
void event();
void file_store();
int file_import();
int menu();

int main(void) {
  file_import();
  
  int menu = start();
  
  which(menu){
    case 0: 
      file_store();
      return 0;
    
    case 1:
      seat_create();
      break;
    
    case 2:
      seat_read();
      break;
    
    case 3:
      seat_change();
      break;
    
    case 4:
      seat_delete();
      break;
    
    case 5:
      searchName();
      break;
    
    case 6:
      timeAdd();
      break;
    
    case 7:
      orderFood();
      break;
    
    case 8:
      report_seat();
      break;
    
    default:
     break;
  }
  return 0;
}


void seat_create(){
}
void seat_read(){
}
void seat_change(){
}
void seat_delete(){
}
void searchName(){
}
void timeAdd(){
}
void orderFood(){
}
void report_seat(){
}
void event(){
  
}
void file_store(){
}
int file_import(){
}
int menu(){
  /*Create 자리 생성
들어가면 잔여 좌석 바로 보이도록 (반복문으로 생성)
들어가야 할 내용: 이름, 사용시간, 자리선택
Read 잔여 자리 여부 확인
Update 자리변경
Delete 자리삭제
이름검색
시간 추가
음식 주문
고장난 자리 신고
*/
  int num;
  
 printf("*******oss피시방*******\n");
  printf("1. 로그인\n");
  printf("2. 남은자리\n");
  printf("3. 자리이동\n");
  pritnf("4. 로그아웃\n");
  printf("5. 이름검색\n");
  printf("6. 시간 추가\n");
  printf("7. 음식 주문\n");
  printf("8. 고장난 자리 신고\n");
  printf("0. 종료\n");
  printf(">> ");
  
  scanf("%d", &num);
  
  while(num<0||num>8){
    printf("메뉴에 없는 번호 입니다. 다시 입력하세요\n");
    printf(">> ");
    scanf("%d", &num);
  }
  
  return num;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char name[20];
  int time;
  int seat; 
  char food[20];
  //좋아하는 게임 장르나 나이를 입력 받아서 10시 이후까지 이용 예정이라면 금지 메세지 띄우기
}user;

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

    printf("이용시간을 입력하세요. ");
    scanf("%d",&u->time);
    
    u->seat=1;
     
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

/*void seat_delete(user *u){
    u->time=-1;
    u->seat=0;
    printf("==> 삭제되었습니다!\n");
    return 0;
}*/

void searchName(){

}
void timeAdd(){
}
void orderFood(){
}
void report_seat(){
}
void event(){
  
}
void file_store(user *u[], int count){

}
int file_load(user *u[]){

}
int selectMenu(){
    int num;
    
    printf("*******oss피시방*******\n");
    printf("1. 로그인C\n");
    printf("2. 남은자리R\n");
    printf("3. 자리이동U\n");
    printf("4. 로그아웃D\n");
    printf("5. 이름검색\n");
    printf("6. 시간 추가\n");
    printf("7. 음식 주문\n");
    printf("8. 고장난 자리 신고\n");
    printf("9. 자료 저장\n");
    // 입력받은 좋아하는 장르 기반으로 추천
    printf("0. 종료\n");
    printf(">> ");
    
    scanf("%d", &num);
    
    while(num<0||num>8){
      printf("메뉴에 없는 번호 입니다. 다시 입력하세요\n");
      printf(">> ");
      scanf("%d", &num);
    }
    
    return num;
}

int main(void) {
  int count=0, menu;

    user *u[100];
    int index=0;

    //count = file_load(u);
    index=count;

    while(1){
        menu=selectMenu();
        if(menu==0) break;
        if(menu==1){
            //u[index]=(user *)malloc(sizeof(user));
            seating_sheat(*u[index]);
            count+=seat_create(u[index++]);
        } 
        else if (menu==2){ 
          printf("%d",count);
            if(count>0) {
              seating_sheat(*u[index]);
              listScore2(u, index);
              }
            else printf("데이터가 없습니다.\n");
        }
        else if (menu==3) {
            int no= selectDataNo2(u,index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
                seat_change(u[no-1]);
        }
        else if (menu==4) {
            int no= selectDataNo2(u,index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)");
            scanf("%d", &deleteok);
            if(deleteok==1){
                if(u[no-1]) free(u[no-1]);
                u[no-1] = NULL;
                count --;
            } //Delete기능 없이도 가능
        } else if(menu==5){
          //이름검색
            searchName(u, index);
        } else if(menu==6){
          //시간 추가
            timeAdd();
        } else if(menu==7){
          //음식 주문
            orderFood();
        } else if(menu==8){
          //고장난 자리 신고
            report_seat();
        } else if(menu==9){
          //저장
            file_store(u, index);
        }
    } 
  printf("종료되었습니다!\n");
  return 0; 
}

*/
