#include <stdio.h>

void ArrayInit() {
  int i = 0, j = 1;
  
  if (i != j) {
    printf("dd");
    return ArrayInit();
  }
  
}

int main() {
  
  ArrayInit();
  return 0;
}