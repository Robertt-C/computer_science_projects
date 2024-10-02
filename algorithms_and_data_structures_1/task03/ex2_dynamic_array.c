#include <stdio.h>
#include <stdlib.h>


int* createDynamicArray(int);
void printArray(int*, int);
void freeMemory(int*);


int main() {
  int *array, arrayLength, i;
  
  printf("Dê-me o tamanho do vetor: ");
  scanf("%d", &arrayLength);
  
  //printf("%p\n", array);
  array = createDynamicArray(arrayLength);
  
  printf("\n");
  for (i = 0; i < arrayLength; i++) {
    printf("Elemento %d será: ", i);
    scanf("%d", &array[i]);
  }
  
  printf("\n");
  //printf("%p\n", array);
  printArray(array, arrayLength);
  //printf("%p\n", array);
  freeMemory(array);
  //printf("%p\n", array);
  
  return 0;
}




int* createDynamicArray(int arrayLength) {
  int *array;
  
  array = (int*)malloc(arrayLength * sizeof(int));
  
  return array;
}


void printArray(int *array, int arrayLength) {
  int i;
  
  for (i = 0; i < arrayLength; i++) {
    printf("Elemento[%d]: %d\n", i, array[i]);
  }
  
  return;
}


void freeMemory(int *array) {
  free(array);
  
  return;
}