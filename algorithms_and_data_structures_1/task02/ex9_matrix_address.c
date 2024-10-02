#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void matrixAddress() {
  float matrix[3][3] = {0};
  int i, j;
  
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 3; i++) {
      printf("Endereço[%d,%d]: %p\n", (j + 1), (i + 1), &matrix[i][j]);
    }
  }
  
  return;
}




int main() {
  
  matrixAddress();
  
  return 0;
}