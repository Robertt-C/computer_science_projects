#include <stdio.h>
#include <stdlib.h>

void getArrayValues(int*, int);


int main() {
  int *array, arrayLength, i;
  
  printf("Dê-me o tamanho do vetor: ");
  scanf("%d", &arrayLength);
  printf("\n");
  
  array = (int*)malloc(arrayLength * sizeof(int));
  
  getArrayValues(array, arrayLength);
  
  printf("\n");
  for (i = 0; i < arrayLength; i++) {
    printf("Elemento[%d]: %d\n", i, array[i]);
  }
  
  free(array);
  
  return 0;
}




void getArrayValues(int *array, int arrayLength) {
  int i;
  
  for (i = 0; i < arrayLength; i++) {
    printf("Elemento %d será: ", i);
    scanf("%d", &array[i]);
  }
  
  return;
}