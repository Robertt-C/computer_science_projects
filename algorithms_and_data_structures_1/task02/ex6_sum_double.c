#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sumDouble(int *num1, int *num2) {
  int sum;
  
  *num1 *= 2;
  *num2 *= 2;
  
  sum = *num1 + *num2;
  
  return sum;
}


void numReader() {
  int num1, num2;
  
  printf("Primeiro número:\n");
  scanf("%d", &num1);
  
  printf("Segundo número:\n");
  scanf("%d", &num2);
  
  
  printf("\nA soma de seus dobros é: %d\n", sumDouble(&num1, &num2));
  
  return;
}




int main() {
  
  numReader();
  
  return 0;
}