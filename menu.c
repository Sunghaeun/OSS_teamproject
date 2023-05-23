//메뉴
#include "menu.h"

int selectMenu() {
  int menu;
  printf("\n*** 점수계산기 ***\n");
  printf("1. 로그인C\n");
  printf("2. 정보조회R\n");
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

