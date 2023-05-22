//crud기능
#include "CRUD.h" 
 
int addScore(schedule *s, int pc_seat[]) {
  printf("몇번 자리를 선택하시겠습니까? ");
  scanf("%d", &s->seat);
  while (pc_seat[s->seat - 1] != 0) {
  printf("그 자리는 선택 불가능합니다.\n");
  printf("몇번 자리를 선택하시겠습니까? ");
  scanf("%d", &s->seat);
}

  
  printf("\n이름은? ");
  scanf("%s", s->name);
  printf("시간은? ");
  scanf("%d", &s->time);
  return 1;
}
void readScore(schedule s) {
  printf("%5s %3d분 %3d번 좌석\n", s.name, s.time, s.seat);
}

void listScore2(schedule *s[], int count) {
  printf("\n No 이름  시간  선택 좌석\n");
  printf("==========================================================\n");
  for (int i = 0; i < count; i++) {
    if (s[i] == NULL)
      continue;
    printf("%2d ", i + 1);
    readScore(*s[i]);
  }
  printf("\n");
}
void listScore3(int pc_seat[]) {
  int j = 0;
  for (int i = 0; i < 13; i++) {
    if (pc_seat[i] != 0)
      j++;
  }
  if (j != 0) {
    printf("\n선택 불가능한 자리\n");
    printf("==========================================================\n");
    for (int i = 0; i < 13; i++) {
      if (pc_seat[i] != 0)
        printf("%d번\n", i+1);
    }
    printf("==========================================================\n");
  }
}


void updateScore(schedule *s[], int index) {
  int choice = 0;
  printf("몇번 자리를 선택하시겠습니까? ");
  scanf("%d", &choice);
  for (int i = 0; i < 15; i++) {
    if (s[i]->seat == choice) {
      printf("이미 선택된 좌석입니다!\n");
      break;
    } else {
      s[index]->seat = choice;
      printf("=> 수정성공!\n");
      break;
    }
  }
}
int deleteScore(schedule *s) {
  s->time = -1;
  printf("=> 삭제됨!\n");
}

int selectDataNo2(schedule *s[], int count) {
  int no;
  listScore2(s, count);
  printf("번호는 (취소 :0)? ");
  scanf("%d", &no);
  return no;
}
