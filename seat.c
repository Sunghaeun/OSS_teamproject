#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char name[20];
  int time;
  int food;
  int seat;
} seat;

void seating_sheat(seat u) {
  int seat_n = 0;
  //첫째줄 시작
  for (int i = 0; i < 36; i++) {
    printf("-");
  }
  printf("\n");
  for (int i = 0; i < 27; i++) {
    if (i % 5 == 0)
      printf("|");
    if (i % 5 == 3) {
      seat_n++;
      if (seat_n == u.seat) {
        printf("X");
      } else
        printf("%d", seat_n);
    }
    printf(" ");
  }
  printf("\n");
  for (int i = 0; i < 36; i++) {
    printf("-");
  }
  //첫째줄 끝
  printf("\n");
  //왼쪽 세로 시작
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 8; i++) {
      if (i % 5 == 0)
        printf("|");
      if (i % 5 == 3)
        printf("%d", ++seat_n);
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
    if (i % 5 == 3)
      printf("%d", ++seat_n);
    printf(" ");
  }
  printf("\n");
  //왼쪽 세로 끝
  for (int i = 0; i < 36; i++) {
    printf("-");
  }
  printf("\n");
  for (int i = 0; i < 27; i++) {
    if (i == 2)
      printf(" ");
    if (i % 5 == 0)
      printf("|");
    if (i % 5 == 2)
      printf("%d", ++seat_n);
    else
      printf(" ");
  }
  printf("\n");
  for (int i = 0; i < 36; i++) {
    printf("-");
  }
  printf("\n");
}

int seat_create(seat *u) {

  printf("이름을 입력하세요. ");
  scanf("%s", u->name);

  printf("이용시간을 입력하세요. (분)");
  scanf("%d", &u->time);

  if (u->time > 180) {
    int event_time = event();
    u->time += event_time;
  }

  printf("==> 총 %d분추가되었습니다!\n", u->time);
  return 1;
}

void seat_read(seat *u) { printf("%-6s %3d원\n", u->name, u->time); }
// listScore2, selectDataNo2적용 잘해야됨
void listScore2(seat *u[], int count) {
  printf("\n No 이름  이용시간\n");
  printf("==========================================================\n");
  for (int i = 0; i < count; i++) {
    if (u[i] == NULL)
      continue;
    printf("%2d ", i + 1);
    seat_read(u[i]);
  }
  printf("\n");
}
int selectDataNo2(seat *u[], int count) {
  int no;
  listScore2(u, count);
  printf("번호는 (취소 :0)? ");
  scanf("%d", &no);
  return no;
}
void seat_change(seat *u) {
  printf("이름을 입력하세요. ");
  scanf("%s", u->name);

  printf("이용시간을 입력하세요. ");
  scanf("%d", &u->time);

  printf("==> 수정되었습니다!\n");
}

void seat_delete(seat *u) {
  u->time = -1;
  printf("==> 삭제되었습니다!\n");
}

void searchName(seat *u[], int count) {
  char name[20];
  printf("찾으시는 사용자의 이름을 입력하세요: ");
  scanf("%s", name);

  int found = 0;
  printf("\n No 이름  이용시간\n");
  printf("==========================================================\n");
  for (int i = 0; i < count; i++) {
    if (u[i] != NULL && strcmp(u[i]->name, name) == 0) {
      printf("%2d ", i + 1);
      seat_read(u[i]);
      found = 1;
    }
  }
  printf("\n");

  if (!found) {
    printf("일치하는 사용자를 찾을 수 없습니다.\n");
  }
}

void timeAdd(seat *u[], int count) {
  int seatNo;
  printf("이용시간을 추가할 사용자의 좌석 번호를 입력하세요: ");
  scanf("%d", &seatNo);

  if (seatNo < 1 || seatNo > count || u[seatNo - 1] == NULL) {
    printf("잘못된 좌석 번호입니다. 다시 입력하세요.\n");
    return;
  }

  int additionalTime;
  printf("추가할 이용시간을 입력하세요: ");
  scanf("%d", &additionalTime);

  u[seatNo - 1]->time += additionalTime;

  printf("이용시간이 추가되었습니다!\n");
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

void orderFood(seat *u[], int count) {
  int seatNo;
  printf("음식을 주문할 사용자의 좌석 번호를 입력하세요: ");
  scanf("%d", &seatNo);

  if (seatNo < 1 || seatNo > count || u[seatNo - 1] == NULL) {
    printf("잘못된 좌석 번호입니다. 다시 입력하세요.\n");
    return;
  }

  int food = foodMenu();

  u[seatNo - 1]->food = food;

  printf("음식이 주문되었습니다!\n");
}

void report_seat(seat *u[], int count) {
  int seatNo;
  printf("고장난 좌석의 번호를 입력하세요: ");
  scanf("%d", &seatNo);

  if (seatNo < 1 || seatNo > count || u[seatNo - 1] == NULL ||
      u[seatNo - 1]->seat == -1) {
    printf("잘못된 좌석 번호입니다. 다시 입력하세요.\n");
    return;
  }

  u[seatNo - 1]->seat = -1;

  printf("고장난 좌석이 신고되었습니다!\n");
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
void file_store(seat *u[], int count) {
  FILE *fp = fopen("data.txt", "w");

  if (fp == NULL) {
    printf("파일을 열 수 없습니다.\n");
    return;
  }

  for (int i = 0; i < count; i++) {
    if (u[i] != NULL) {
      fprintf(fp, "%s %d %d %d\n", u[i]->name, u[i]->time, u[i]->food,
              u[i]->seat);
    }
  }

  fclose(fp);
  printf("데이터가 저장되었습니다.\n");
}

int file_load(seat *u[]) {
  FILE *fp = fopen("data.txt", "r");

  if (fp == NULL) {
    printf("파일을 열 수 없습니다.\n");
    return 0;
  }

  int count = 0;

  while (!feof(fp)) {
    u[count] = (seat *)malloc(sizeof(seat));
    fscanf(fp, "%s %d %d %d", u[count]->name, &(u[count]->time),
           &(u[count]->food), &(u[count]->seat));
    count++;
  }

  fclose(fp);
  printf("데이터가 로드되었습니다.\n");

  return count;
}

int selectMenu() {
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

  while (num < 0 || num > 8) {
    printf("메뉴에 없는 번호 입니다. 다시 입력하세요\n");
    printf(">> ");
    scanf("%d", &num);
  }

  return num;
}

int main(void) {
  int count = 0, menu;

  seat *u[13];
  int index = 0;

  // count = file_load(u);
  index = count;

  while (1) {
    menu = selectMenu();
    if (menu == 0)
      break;
    if (menu == 1) {
      // u[index]=(user *)malloc(sizeof(user));
      printf("사용하실 좌석을 입력하세요. ");
      // scanf("%d", &index);
      seating_sheat(*u[index]);
      count += seat_create(u[index++]);
    } else if (menu == 2) {
      printf("%d", count);
      if (count > 0) {
        seating_sheat(*u[index]);
        listScore2(u, index);
      } else
        printf("데이터가 없습니다.\n");
    } else if (menu == 3) {
      int no = selectDataNo2(u, index);
      if (no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      seat_change(u[no - 1]);
    } else if (menu == 4) {
      int no = selectDataNo2(u, index);
      if (no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      int deleteok;
      printf("정말로 삭제하시겠습니까? (삭제 : 1)");
      scanf("%d", &deleteok);
      if (deleteok == 1) {
        if (u[no - 1])
          free(u[no - 1]);
        u[no - 1] = NULL;
        count--;
      } // Delete기능 없이도 가능
    } else if (menu == 5) {
      //이름검색
      searchName(u, index);
    } else if (menu == 6) {
      //시간 추가
      timeAdd(u, index);
    } else if (menu == 7) {
      //음식 주문
      orderFood(u, index);
    } else if (menu == 8) {
      //고장난 자리 신고
      report_seat(u, index);
    } else if (menu == 9) {
      //저장
      file_store(u, index);
    }
  }
  printf("종료되었습니다!\n");
  return 0;
}



