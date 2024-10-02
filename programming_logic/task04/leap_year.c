#include <stdio.h>

int main() {
  int num = 0, year = 1, count = 1;
  
  scanf("%d", &num);
  
  while (count <= num) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      printf("%04d - ano:%4d", count, year);
      if (count < num) {
        printf("\n");
      }
      count++;
    }
    year += 1;
  }
  
  return 0;
}