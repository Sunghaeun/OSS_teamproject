#include <stdio.h>
#include <string.h>

typedef struct{
  char name[20];
  int time;
  int seat[10]={0}; 
}user;

void seat_create();
void seat_read();
void seat_change();
void seat_delete();
