#include <stdio.h>
#include <string.h>

typedef struct{
  char name[20];
  int time;
  int seat=0;
}user;

void seat_create(user *u);
void seat_read(user u);
void listScore2(user *u[], int count);
int selectDataNo2(user *u[], int count);
void seat_change(user *u);
void seat_delete(user *u);
