#include <stdio.h>

int main() {
  float num, storage;
  int count;
  
  storage = 0;
  count = 0;
  
  while (count == count) {
    scanf("%f", &num);
    storage += num;
    count++;
    if (num == 0) {
      count--;
      break;
    }
  }
  
  printf("A media aritmética dos %d valores é: %.1f\n", count, storage/count);
  
  return 0;
}