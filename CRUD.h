#include <stdio.h>
#include <string.h>

typedef struct {
  char name[8];
  int time;
  int seat;
  int food[20];
} schedule;

int addScore(schedule *s, int pc_seat[]);
void readScore(schedule s);
void listScore2(schedule *s[], int count);
void listScore3(int pc_seat[]);
int selectDataNo2(user *u[], int count);
void updateScore(schedule *s[], int index);
int deleteScore(schedule *s);
