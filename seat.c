#include <stdio.h>

typedef struct{
//내용 구현 적기
}seat;

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
int start();

int main(void) {
  
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
int start(){
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
  printf(">> ");
  
  scanf("%d", &num);
  
}
