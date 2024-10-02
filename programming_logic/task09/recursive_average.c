#include <stdio.h>
 
//=== Recebedor e calculador da média aritmética.
int Average(int numbers[1000], float count, float sum) {
  float average;
  
  scanf("%d", &numbers[(int)count]);
  
  if (numbers[(int)count] != 0) {
    sum += numbers[(int)count];
    return Average(numbers, count + 1, sum);
  }
  
  average = sum / count;
  
  printf("A media aritmética dos %d valores é: %.1f\n", (int)count, average);
  
  return 0;
}
 
 
int main() {
  int numbers[1000] = {0};
  float count = 0, sum = 0;
  
  Average(numbers, count, sum);
  
  return 0;
}