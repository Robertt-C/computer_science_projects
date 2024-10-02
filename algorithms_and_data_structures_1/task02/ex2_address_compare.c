#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addressCompare() {
  int num1, num2, *pNum1, *pNum2;
  
  pNum1 = &num1;
  pNum2 = &num2;
  
  printf("Endereço de num1: %p\nEndereço de num2: %p\n\n", pNum1, pNum2);
  
  if (pNum1 > pNum2) {
    printf("Maior: %p", pNum1);
  } else {
    printf("Maior: %p", pNum2);
  }
  
  return;
}




int main() {
  
  addressCompare();
  
  return 0;
}