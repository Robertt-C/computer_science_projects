#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void arrayElementDouble() {
  int array[5];
  int i;
  
  for (i = 0; i < 5; i++) {
    scanf("%d", array+i);
  }
  
  for (i = 0; i < 5; i++) {
    printf("Dobro do elemento %d é: %d\n", *(array+i), *(array+i) * 2);
  }
  
  return;
}




int main() {
  
  arrayElementDouble();
  
  return 0;
}