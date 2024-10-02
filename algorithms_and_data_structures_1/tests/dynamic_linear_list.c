#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  char name[30];
  int number;
} personalInfo;

struct list {
  personalInfo info;
  struct list *pointer;
};

typedef struct list sublist;

typedef struct {
  sublist *firstInfo;
  int last;
} dynamicList;




int main() {
  dynamicList list;
  sublist *item1, *item2, *item3, *auxPointer;
  int i;
  
  list.firstInfo = NULL;
  list.last = 0;
  
  item1 = (sublist*) malloc(sizeof(sublist));
  
  list.firstInfo = item1;
  
  item2 = (sublist*) malloc(sizeof(sublist));
  item1->pointer = item2;
  
  item3 = (sublist*) malloc(sizeof(sublist));
  item2->pointer = item3;
  
  
  item1->info.number = 10;
  item2->info.number = 20;
  item3->info.number = 30;
  
  
  
  auxPointer = list.firstInfo;
  
  for (i = 0; i < 3; i++) {
    auxPointer = auxPointer->pointer;
    printf("%p\n", auxPointer);
    printf("%d\n", auxPointer->info.number);
  }
  
  
  return 0;
}