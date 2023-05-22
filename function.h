#include <stdio.h>
#include <string.h>

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
int selectDataNo2(user *u[], int count);
void updateScore(schedule *s[], int index);
int deleteScore(schedule *s);
int event();
void searchFriend(schedule *s[], int count);
void timeAdd(schedule *u);
void timeAdd(schedule *u);
void report_seat(schedule *sp[], int count, int pc_seat[]);
void file_store(schedule *sp[], int count, int pc_seat[]);
int file_load(schedule *sp[], int *pc_seat);
