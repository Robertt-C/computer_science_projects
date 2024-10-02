#include <stdio.h>                                                                            

int main() {
  float num, storage;
  int count, limit;
  
  storage = 0;
  count = 0;
  
  scanf("%d", &limit);
  
  while (count < limit) {
    scanf("%f", &num);
    storage += num;
    count++;
  }
  
  printf("A media aritmética dos %d valores é: %.1f\n", count, storage/count);
  
  return 0;
}