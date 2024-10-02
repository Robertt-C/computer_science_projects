#include <stdio.h>

void test(int array[100]) {
  int i;
  
  for (i = 0; i < 100; i++) {
    array[i] = i;
  }
}


int main() {
  int array[100];
  
  test(array);
  
  printf("%d", array[30]);
  
  return 0;
}