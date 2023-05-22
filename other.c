//crud외 다른 기능
#include "other.h"
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
    for (int j = 0; j < 20; j++) {
      fprintf(fp, " %d", sp[i]->food[j]);
    }
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
      fscanf(fp, "%d", &(sp[i]->food[j]));
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
