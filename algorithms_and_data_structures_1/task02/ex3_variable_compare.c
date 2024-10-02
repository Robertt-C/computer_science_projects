#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void variableCompare() {
  int num1, num2, *pNum1, *pNum2;
  
  printf("Dê-me o primeiro inteiro:\n");
  scanf("%d", &num1);
  
  printf("Dê-me o segundo inteiro:\n");
  scanf("%d", &num2);
  
  pNum1 = &num1;
  pNum2 = &num2;
  
  if (pNum1 > pNum2) {
    printf("\nConteúdo do maior endereço: %d\n", num1);
  } else {
    printf("\nConteúdo do maior endereço: %d\n", num2);
  }
  
  return;
}




int main() {
  
  variableCompare();
  
  return 0;
}