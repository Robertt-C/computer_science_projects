#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void variableChanger(int *num1, int *num2) {
  int numStorage;
  
  numStorage = *num1;
  *num1 = *num2;
  *num2 = numStorage;
  
  return;
}


void variablesPlace() {
  int num1, num2;
  
  printf("Dê-me o primeiro número:\n");
  scanf("%d", &num1);
  
  printf("Dê-me o segundo número:\n");
  scanf("%d", &num2);
  
  printf("\nAntes da função alteradora:\n");
  printf("Número 1: %d\nNúmero 2: %d\n\n", num1, num2);
  
  variableChanger(&num1, &num2);
  
  printf("Depois da função alteradora:\n");
  printf("Número 1: %d\nNúmero 2: %d\n", num1, num2);
  
  return;
}




int main() {
  
  variablesPlace();
  
  return 0;
}