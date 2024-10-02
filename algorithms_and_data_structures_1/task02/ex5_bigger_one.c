#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void checkingSizes(int *num1, int *num2) {
  int numStorage;
  
  if (*num1 > *num2) {
    return;
  } else {
    numStorage = *num1;
    *num1 = *num2;
    *num2 = numStorage;
  }
  
  return;
}


void numberReader() {
  int num1, num2;
  
  printf("Dê-me o primeiro número:\n");
  scanf("%d", &num1);
  
  printf("Dê-me o segundo número:\n");
  scanf("%d", &num2);
  
  checkingSizes(&num1, &num2);
  
  printf("\nValor da primeira variável (maior): %d\n", num1);
  printf("Valor da segunda variável (menor): %d\n", num2);
  
  return;
}




int main() {
  
  numberReader();
  
  return 0;
}