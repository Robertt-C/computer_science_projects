#include <stdio.h>
#include <stdlib.h>


int* bubbleSort(int*, int);
int compareArrays(int*, int*, int);

int main() {
  int i, dosesNumber, *microorganismesNumberArr, *dosesPotencyArr;
  
  scanf("%d", &dosesNumber);
  
  microorganismesNumberArr = malloc(dosesNumber * sizeof(int));
  dosesPotencyArr = malloc(dosesNumber * sizeof(int));
  
  
  for (i = 0; i < dosesNumber; i++) {
    scanf("%d", &microorganismesNumberArr[i]);
  }
  
  for (i = 0; i < dosesNumber; i++) {
    scanf("%d", &dosesPotencyArr[i]);
  }
  
  
  microorganismesNumberArr = bubbleSort(microorganismesNumberArr, dosesNumber);
  dosesPotencyArr = bubbleSort(dosesPotencyArr, dosesNumber);
  
  
  if (compareArrays(microorganismesNumberArr, dosesPotencyArr, dosesNumber)) {
    printf("sim\n");
  } else {
    printf("nao\n");
  }
  
  
  free(microorganismesNumberArr);
  free(dosesPotencyArr);
  
  return 0;
}




int* bubbleSort(int *array, int arrayLength) {
  /* Implementa o método de organização bubble sort */
  int i, j, aux;
  
  for (i = 0; i < arrayLength - 1; i++) {
    for (j = 0; j < arrayLength - 1 - i; j++) {
      if (array[j] > array[j+1]) {
        aux = array[j];
        array[j] = array[j+1];
        array[j+1] = aux;
      }
    }
  }
  
  return array;
}


int compareArrays(int *array1, int *array2, int arrayLength) {
  int i;
  
  for (i = 0; i < arrayLength; i++) {
    if (array2[i] < array1[i]) {
      return 0;
    }
  }
  
  return 1;
}