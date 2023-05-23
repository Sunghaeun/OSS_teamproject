//crud외 다른 기능
#include "function.h"
#include "menu.h"

int event() {
  int answer;
  int guess;
  int event_time = 0;

  srand(time(NULL));
  answer = rand() % 3 + 1;

  printf("1, 2, 3 중 하나의 숫자를 선택하세요: ");
  scanf("%d", &guess);

  if (guess == answer) {
    printf("정답!\n");
    printf("30분 추가~!");
    event_time += 30;
  } else {
    printf("실패ㅠㅠ\n");
  }

  return event_time;
}
void seating_sheet(schedule *u[]) {
  int seat_n = 0;
  int check = 0;
  // 첫째줄 시작
  for (int i = 0; i < 36; i++) {
    printf("-");
  }
  printf("\n");
  for (int i = 0; i < 27; i++) {
    if (i % 5 == 0)
      printf("|");
    if (i % 5 == 3) {
      seat_n++;
      printf("%d", seat_n);
    }
    printf(" ");
  }
  printf("\n");
  for (int i = 0; i < 36; i++) {
    printf("-");
  }
  // 첫째줄 끝
  printf("\n");
  // 왼쪽 세로 시작
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 8; i++) {
      if (i % 5 == 0)
        printf("|");
      if (i % 5 == 3) {
        seat_n++;
        
        printf("%d", seat_n);
      }
      printf(" ");
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
      printf("-");
    }
    printf("\n");
  }
  for (int i = 0; i < 8; i++) {
    if (i % 5 == 0)
      printf("|");
    if (i % 5 == 3) {
      seat_n++;
      
        printf("%d", seat_n);
    }
    printf(" ");
  }
  printf("\n");
  // 왼쪽 세로 끝
  for (int i = 0; i < 36; i++) {
    printf("-");
  }
  printf("\n");
  for (int i = 0; i < 27; i++) {
    if (i == 2)
      printf(" ");
    if (i % 5 == 0)
      printf("|");
    if (i % 5 == 2) {
      seat_n++;
      
        printf("%d", seat_n);
    } else
      printf(" ");
  }
  printf("\n");
  for (int i = 0; i < 36; i++) {
    printf("-");
  }
  printf("\n");
}
 
int addScore(schedule *s, int pc_seat[]) {
  int time;
  do {
    int i=0;
    printf("몇 번 자리를 선택하시겠습니까? ");
    scanf("%d", &(s->seat));
    for (int i = 0; i < 15; i++) {
      if (pc_seat[i] == s->seat) {
        printf("이미 선택된 좌석입니다!\n");
        i++;
        break;
      }
      if(i!=0)  continue;
    }
    if (pc_seat[s->seat - 1] != 0) {
      printf("그 자리는 선택 불가능합니다.\n");
      continue;
    }
    break;
  } while (1);

  printf("\n이름은? ");
  scanf("%s", s->name);
  printf("시간은?(분) ");
  scanf("%d", &(s->time));
  
  if(s->time>180)    s->time += event();
  s->food = 0;
  
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


void updateScore(schedule *s[], int index, int pc_seat[]) {
  int choice = 0;
  printf("몇번 자리를 선택하시겠습니까? ");
  scanf("%d", &choice);
  while(pc_seat[choice-1]!=0){
    printf("사용 불가능한 자리입니다\n");
    printf("다시 선택하세요");
    scanf("%d", &choice);
  }
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
void searchFriend(schedule *s[], int count) {
  int scnt = 0;
  char search[20];

  printf("검색할 이름? ");
  scanf("%s", search);

  printf("\n No 이름  시간\n");
  printf("==========================================================\n");
  for (int i = 0; i < count; i++) {
    if (s[i] == NULL)
      continue;
    if (strstr(s[i]->name, search)) {
      printf("%2d ", i + 1);
      readScore(*s[i]);
      scnt++;
    }
  }
  if (scnt == 0)
    printf("=> 검색된 데이터 없음!");
  printf("\n");
}

void timeAdd(schedule *u) {
  int p_time;
  printf("현재 사용 시간은 %d 입니다.\n", u->time);
  printf("추가이용시간을 입력하세요. ");
  scanf("%d", &p_time);
  u->time += p_time;

  printf("==> 추가되었습니다!\n");
}

void orderFood(schedule *sp[], int count, int pc_seat[]) {
  int seatNo;
  printf("음식을 주문할 사용자의 좌석 번호를 입력하세요: ");
  scanf("%d", &seatNo);

  if (seatNo < 1 || seatNo > 13 || pc_seat[seatNo-1]!=0) {
    printf("잘못된 좌석 번호입니다. 다시 입력하세요.\n");
    scanf("%d", &seatNo);
  }

  int food = foodMenu();

  sp[seatNo - 1]->food;
  

  printf("음식이 주문되었습니다!\n");
}


void report_seat(schedule *sp[], int count, int pc_seat[]) {
  int seatNo;
  printf("고장난 좌석의 번호를 입력하세요: ");
  scanf("%d", &seatNo);

  if (seatNo < 1 || seatNo > 13|| pc_seat[seatNo - 1]!=0) {
    printf("잘못된 좌석 번호입니다. 다시 입력하세요.\n");
  }

  pc_seat[seatNo-1] = -1;

  printf("고장난 좌석이 신고되었습니다!\n");
}

void file_store(schedule *sp[], int count, int pc_seat[]) {
  FILE *fp = fopen("data.txt", "wt");
  if (fp == NULL) {
    printf("파일을 열 수 없습니다.\n");
    return;
  }

  fprintf(fp, "%d\n", count);  // 스케줄 개수 저장

  // 스케줄 데이터 저장
  for (int i = 0; i < count; i++) {
    fprintf(fp, "%s %d %d", sp[i]->name, sp[i]->time, sp[i]->seat);
    //for (int j = 0; j < 20; j++) {
      fprintf(fp, " %d", sp[i]->food);
    //}
    fprintf(fp, "\n");
  }

  // pc_seat 배열 저장
  for (int i = 0; i < 13; i++) {
    fprintf(fp, "%d ", pc_seat[i]);
  }
  fprintf(fp, "\n");

  fclose(fp);
}

int file_load(schedule *sp[], int *pc_seat) {
  FILE *fp = fopen("data.txt", "rt");
  if (fp == NULL) {
    printf("파일을 열 수 없습니다.\n");
    return 0;
  }

  int count;
  fscanf(fp, "%d", &count);  // 스케줄 개수 읽기

  for (int i = 0; i < count; i++) {
    sp[i] = malloc(sizeof(schedule));
    //sp[i]->name = malloc(50 * sizeof(char));
    fscanf(fp, "%s %d %d", sp[i]->name, &(sp[i]->time), &(sp[i]->seat));
    for (int j = 0; j < 20; j++) {
      fscanf(fp, "%d", &(sp[i]->food));
    }
  }

  // pc_seat 배열 읽기
  for (int i = 0; i < 13; i++) {
    fscanf(fp, "%d", &(pc_seat[i]));
  }

  fclose(fp);
  printf("데이터를 로드했습니다.\n");
  return count;
}

int foodMenu() {
  int num;

  printf("*******oss피시방음식*******\n");
  printf("1. 라면 - 4000원\n");
  printf("2. 짜장면 - 4000원\n");
  printf("3. 짬뽕 - 4000원\n");
  printf("4. 볶음밥 - 4000원\n");
  printf("원하는 번호는? ");
  scanf("%d", &num);

  while (num < 1 || num > 4) {
    printf("다시 입력하세요> ");
    scanf("%d", &num);
  }

  return num;
}
