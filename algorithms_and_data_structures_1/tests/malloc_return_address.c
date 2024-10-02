#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void dyArray(int *pointer) {
  int i;
  
  for (i = 0; i < 10; i++) {
    scanf("%d", &pointer[i]);
    printf("pointer[%d]: %d\n", i, pointer[i]);
  }
  
  printf("\n");
  
  return;
}


int main() {
  int *pointer, i;
  
  printf("%p\n\n", pointer);
  
  for (i = 0; i < 20; i++) {
    printf("%p || content: %d\n", pointer+i, *(pointer+i));
  }
  
  pointer = (int*)malloc(20 * sizeof(int));
  
  printf("\n");
  
  printf("%p\n\n", pointer);
  
  for (i = 0; i < 20; i++) {
    printf("%p || content: %d\n", pointer+i, *(pointer+i));
  }
  
  /*
  int *array, i, **pArray;
  
  pArray = &array;
  
  printf("Array length: ");
  scanf("%d", &i);
  
  printf("array address before malloc: %p\n", array);
  printf("pArray: %p\n", pArray);
  
  array = (int*) malloc(i * sizeof(int));
  
  printf("array address after malloc: %p\n", array);
  printf("pArray: %p\n", pArray);
  */
  
  return 0;
}