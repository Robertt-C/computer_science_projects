#include <stdio.h>

int main() {
  int num1, num2, num3;
  
  scanf("%d %d %d", &num1, &num2, &num3);
  
// Finding minimum  
  if (num1 < num2 && num1 < num3) {
    printf("%d ", num1);
  } else if (num2 < num3) {
    printf("%d ", num2);
  } else {
    printf("%d ", num3);
  }
  
// Finding the middle one 
  if (num2 > num1 && num1 > num3 || num3 > num1 && num1 > num2) {
      printf("%d ", num1);
  } else if (num1 > num2 && num2 > num3 || num3 > num2 && num2 > num1) { 
      printf("%d ", num2);
  } else {
      printf("%d ", num3);
  }
  
// Finding maximum
  if (num1 > num2 && num1 > num3) {
    printf("%d\n", num1);
  } else if (num2 > num3) {
    printf("%d\n", num2);
  } else {
    printf("%d\n", num3);
  }
  
  return 0;
}