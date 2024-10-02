#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void evenElementAddress() {
  int array[5];
  int i;
  
  for (i = 0; i < 5; i++) {
    scanf("%d", array+i);
  }
  
  for (i = 0; i < 5 ; i++) {
    if (array[i] % 2 == 0) {
      printf("Endereço de (%d): %p\n", *(array+i), &array[i]);
    }
  }
  
  return;
}




int main() {
  
  evenElementAddress();
  
  return 0;
}