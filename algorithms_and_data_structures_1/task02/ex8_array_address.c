#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void arrayAddress() {
  float array[10] = {0};
  int i;
  
  for (i = 0; i < 10; i++) {
    printf("Endereço[%d]: %p\n", (i + 1), array+i);
  }
  
  return;
}




int main() {
  
  arrayAddress();
  
  return 0;
}