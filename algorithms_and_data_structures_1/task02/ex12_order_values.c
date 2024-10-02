#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rise(int *num1, int *num2, int *num3) {
  int storeVariable;
  
  if (*num1 == *num2 && *num2 == *num3) {
    return 1;
  } else if (*num1 <= *num2 && *num2 <= *num3) {
    return 0;
  }
  
  return 0;
}


void numReader() {
  int num1, num2, num3;
  
  printf("O primeiro número:\n");
  scanf("%d", &num1);
  
  printf("O segundo número:\n");
  scanf("%d", &num2);
  
  printf("O terceiro número:\n");
  scanf("%d", &num3);
  
  rise(&num1, &num2, &num3);
  
  printf("Variável 1: %d\nVariável 2: %d\nVariável 3: %d\n", num1, num2, num3);
  
  return;
}



int main() {
  
  
  
  return 0;
}