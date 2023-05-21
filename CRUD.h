#include <stdio.h>
#include <string.h>

typedef struct{
  char name[20];
  int time;
  int seat=0;
  char food[20];
  //좋아하는 게임 장르나 나이를 입력 받아서 10시 이후까지 이용 예정이라면 금지 메세지 띄우기
}user; 

void seat_create(user *u);
void seat_read(user u);
void listScore2(user *u[], int count);
int selectDataNo2(user *u[], int count);
void seat_change(user *u);
void seat_delete(user *u);
