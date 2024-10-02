#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sum(int *num1, int num2) {
  
  *num1 += num2;
  
  return;
}


void numReader() {
  int num1, num2;
  
  printf("Primeiro número:\n");
  scanf("%d", &num1);
  
  printf("Segundo número:\n");
  scanf("%d", &num2);
  
  sum(&num1, num2);
  
  printf("\nPrimeiro número (modificado): %d\nSegundo número: %d\n", num1, num2);
  
  return;
}


int main() {
  
  numReader();
  
  return 0;
}