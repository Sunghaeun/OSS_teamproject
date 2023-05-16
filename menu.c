//메뉴
#include "menu.h"

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
