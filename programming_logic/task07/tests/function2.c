#include <stdio.h>

int receiver() {
  int num;
  
  scanf("%d", &num);
  
  return num;
}


int main() {
  int num;
  
  num = receiver();
  
  
  printf("%d", num);
  
}