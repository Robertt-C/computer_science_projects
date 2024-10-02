#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct list {
  int num;
  struct list *pointer;
};

typedef struct list info;

int main() {
  info personalInfo;
  
  printf("%d\n", personalInfo.pointer->num);
  
  return 0;
}