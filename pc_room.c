#include <stdio.h>
#include "menu.h"
#include "other.h"
#include "CRUD.h"
//main 함수
int main(void) {
  int result = 0;
  int count = 0, menu;

  schedule *sp[20];
  int pc_seat[13] = {0};
  int *p_seat = pc_seat;

  int index = 0;

  count = file_load(sp, p_seat);
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
      orderFood(sp, count, pc_seat);
    } else if (menu == 8) {
      report_seat(sp, count, p_seat);
    } else if (menu == 9) {
      file_store(sp, count, pc_seat);
    }
  }
  printf("종료됨!\n");
  return 0;
}
