#include <stdio.h>

int Test(int i) {
  
  printf("%d", i);
  
  return Test(i + 1);
}


int main() {
  int num = 0;
  
  Test(num);
  
  return 0;
}