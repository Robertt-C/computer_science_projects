#include <stdio.h>


int Test(int num) {
  if (num == 10) {
    printf("Base case\n");
    return -1;
  } else {
    printf("Resursive function on: %d\n", num);
    Test(num + 1);
    printf("Resursive function on: %d\n", num);
  }
  
  return 0;
}



int main() {
  int num = 0;
  
  Test(num);
  
  return 0;
}