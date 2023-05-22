#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char name[8];
  int time;
  int seat;
  int food[20];
} schedule;

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

int selectMenu() {
  int menu;
  printf("\n*** 점수계산기 ***\n");
  printf("1. 로그인C\n");
  printf("2. 남은자리조회R\n");
  printf("3. 자리이동U\n");
  printf("4. 로그아웃D\n");
  printf("5. 이름검색\n");
  printf("6. 시간 추가\n");
  printf("7. 음식 주문\n");
  printf("8. 고장난 자리 신고\n");
  printf("9. 자료 저장\n");
  // 입력받은 좋아하는 장르 기반으로 추천
  printf("0. 종료\n");
  printf("=> 원하는 메뉴는? ");
  ;
  scanf("%d", &menu);
  return menu;
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

void saveData(schedule *s[], int count) {
  FILE *fp;
  fp = fopen("test.txt", "wt");
  for (int i = 0; i < count; i++) {
    if (s[i]->time == -1)
      continue;
    fprintf(fp, "%s %d\n", s[i]->name, s[i]->time);
  }
  fclose(fp);
  printf("=> 저장됨!\n");
}

int loadData(schedule *s[]) {
  int count = 0, i = 0;
  FILE *fp;
  fp = fopen("test.txt", "rt");
  for (int i = 0; i < 100; i++) {
    s[i] = (schedule *)malloc(sizeof(schedule));
    if (feof(fp))
      break;
    fscanf(fp, "%s", s[i]->name);
    fscanf(fp, "%d", &s[i]->time);
    count++;
  }
  if (count == 1) {
    printf("=> 파일없음\n");
  } else
    printf("=> 로딩 성공! \n");
  fclose(fp);

  return i;
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
}int foodMenu() {
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

void orderFood(schedule *sp[], int count) {
  int seatNo;
  printf("음식을 주문할 사용자의 좌석 번호를 입력하세요: ");
  scanf("%d", &seatNo);

  if (seatNo < 1 || seatNo > count || sp[seatNo - 1] == NULL) {
    printf("잘못된 좌석 번호입니다. 다시 입력하세요.\n");
    return;
  }

  int food = foodMenu();

  for (int i = 0; i < 20; i++) {
    sp[seatNo - 1]->food[i] = (i == food - 1) ? 1 : 0;
  }

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

void file_store(schedule *sp[], int count) {
  FILE *fp = fopen("data.txt", "w");

  if (fp == NULL) {
    printf("파일을 열 수 없습니다.\n");
    return;
  }

  for (int i = 0; i < count; i++) {
    if (sp[i] != NULL) {
      fprintf(fp, "%s %d %d %d\n", sp[i]->name, sp[i]->time, sp[i]->food,
              sp[i]->seat);
    }
  }

  fclose(fp);
  printf("데이터가 저장되었습니다.\n");
}

int file_load(schedule *sp[]) {
  FILE *fp = fopen("data.txt", "r");

  if (fp == NULL) {
    printf("파일을 열 수 없습니다.\n");
    return 0;
  }

  int count = 0;

  while (!feof(fp)) {
    sp[count] = (schedule *)malloc(sizeof(schedule));
    fscanf(fp, "%s %d %d %d", sp[count]->name, &(sp[count]->time),
           &(sp[count]->food), &(sp[count]->seat));
    count++;
  }

  fclose(fp);
  printf("데이터가 로드되었습니다.\n");

  return count;
}


int main(void) {
  int result = 0;
  int count = 0, menu;

  schedule *sp[20];
  int pc_seat[13] = {0};
  int *p_seat = pc_seat;

  int index = 0;

  count = loadData(sp);
  index = count;

  while (1) {
    menu = selectMenu();
    if (menu == 0)
      break;
    if (menu == 1) {
      seating_sheet(sp);
      sp[index] = (schedule *)malloc(sizeof(schedule));
      count += addScore(sp[index++], pc_seat);
    } else if (menu == 2) {
      seating_sheet(sp);
      if (count > 0)
        listScore2(sp, count);
      else
        printf("데이터가 없습니다.\n");
        listScore3(pc_seat);
    } else if (menu == 3) {
      int no = selectDataNo2(sp, count);
      if (no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      updateScore(sp, no - 1);
    } else if (menu == 4) {
      int no = selectDataNo2(sp, count);
      if (no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      int deleteok;
      printf("정말로 삭제하시겠습니까? (삭제 : 1)");
      scanf("%d", &deleteok);
      if (deleteok == 1) {
        if (sp[no - 1])
          free(sp[no - 1]);
        sp[no - 1] = NULL;
        count--;
      }
    } else if (menu == 5) {
      searchFriend(sp, count);
    } else if (menu == 6) {
      int no = selectDataNo2(sp, count);
      if (no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      timeAdd(sp[no - 1]);
    } else if (menu == 7) {
      orderFood(sp, count);
    } else if (menu == 8) {
      report_seat(sp, count, pc_seat);
    } else if (menu == 9) {
      saveData(sp, count);
    }
  }
  printf("종료됨!\n");
  return 0;
}
