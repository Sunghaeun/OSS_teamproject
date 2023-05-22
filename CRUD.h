#include <stdio.h>
#include <string.h>

typedef struct {
  char name[8];
  int time;
  int seat;
  int food[20];
} schedule;

void seat_create(user *u);
void seat_read(user u);
void listScore2(user *u[], int count);
int selectDataNo2(user *u[], int count);
void seat_change(user *u);
void seat_delete(user *u);
