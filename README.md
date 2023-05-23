# OSS_teamproject

# **💻 피시방 키오스크**
![](https://user-images.githubusercontent.com/98035984/168476870-8e309f2b-888b-443a-912e-17c2bcc9089d.png)

***

## **💻 주제**

* 다양한 기능을 한번에 키오스크에서 수행할 수있는 PC방 키오스크

***

## **💻 서비스 소개**


피시방의 자리를 보고 어디에 얼마나 사용할지 예약할 수 있는 프로그램입니다.

![image](https://github.com/Sunghaeun/OSS_teamproject/assets/130740217/814c1932-a9e3-4017-9558-eed7b18e4895)

어느 자리가 비었는지 쉽게 확인하고 간편하게 예약하세요!


![image](https://github.com/Sunghaeun/OSS_teamproject/assets/130740217/7ab0334f-74e4-4739-99b8-042b5fad6752)

3시간 이상 충전시 **⭐특별한 이벤트⭐**도 있으니 기대하세요~!

***

## 💻 메뉴

![image](https://github.com/Sunghaeun/OSS_teamproject/assets/126676826/ae3007df-ecb0-4c86-b497-a8bd9c7bb290)
1. 로그인
2. 남은자리
3. 자리이동
4. 로그아웃
5. 이름검색
6. 시간 추가
7. 음식 주문
8. 고장난 자리 신고
9. 자료 저장
0. 종료

***

## 💻 장점
* 한 기기에서 로그인, 로그아웃, 자리이동 등 많은 기능을 수행 가능하다.
* 이름 검색 기능으로 자신의 자리나 친구의 자리와 정보를 쉽게 확인 가능하다.
* 고장난 자리를 신고해서 고장난 자리도 쉽게 확인 가능하다.
* 시작할때마다 자료를 자동으로 불러와 실행 가능하다

***

## 💻 제작 동기
피시방에서 키오스크로 시간을 충전하고 남은 자리를 볼 수 있었는데 키오스크 하나로 CRUD와 그 외 많은 기능들을 실행 가능하다면 편할 것 같아 만들 게 되었다.
또한 3시간 이상 충전시 미니게임을 해서 성공시 30분 추가하는 이벤트도 넣으면 좋을 것 같아 추가하게 되었다.

***

## 💻 코드 및 기능

```markdown
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char name[8];
  int time;
  int seat;
  int food[20];
} schedule;

void seating_sheet(schedule *u[]);
int addScore(schedule *s, int pc_seat[]);
void readScore(schedule s);
void listScore2(schedule *s[], int count);
void listScore3(int pc_seat[]);
int selectDataNo2(schedule *u[], int count);
void updateScore(schedule *s[], int index, int pc_seat[]);
int deleteScore(schedule *s);
int event();
void searchFriend(schedule *s[], int count);
void timeAdd(schedule *u);
void timeAdd(schedule *u);
void report_seat(schedule *sp[], int count, int pc_seat[]);
void file_store(schedule *sp[], int count, int pc_seat[]);
int file_load(schedule *sp[], int *pc_seat);
int foodMenu();
int event();
```

***

## 💻 기능 구현

## Stack 

![image](https://github.com/Sunghaeun/OSS_teamproject/assets/130740217/1c2b59ae-68dd-4cd0-b34d-b358bfaf754b)


* ## c

## Ide 


![image](https://github.com/Sunghaeun/OSS_teamproject/assets/130740217/27e6671c-8c51-4162-9404-3ec10533e456)


* ## visual studio


## 협업도구 

![image](https://github.com/Sunghaeun/OSS_teamproject/assets/130740217/a5a6e7fa-7c5d-4c8b-af90-453aaa9683b1)

* ## Github 

![image](https://github.com/Sunghaeun/OSS_teamproject/assets/130740217/52b13f3a-b25d-4652-9659-9ca7a4d513fa)


* ## Kakaotalk 

![image](https://github.com/Sunghaeun/OSS_teamproject/assets/130740217/ffd85fef-96b3-492e-a5ac-92c845596096)


* # zoom


[home](https://github.com/Sunghaeun/OSS_teamproject/wiki)

