#include <stdio.h>
#include <stdlib.h>


int binarySearch(int *array, int value, int startValue, int endValue, int *callsNumber);

int main() {
   /* Aloca vetor, pede as entradas e o número a ser procurado */
  int i, arrayLength, findValue, startValue = 0, endValue, callsNumber = 0, *array;
  
  scanf("%d", &arrayLength);
  array = malloc(arrayLength * sizeof(int));
  
  for(i = 0; i < arrayLength; i++) {
    scanf("%d", &array[i]);
  }
  
  scanf("%d", &findValue);
  
  endValue = arrayLength - 1;
  
  if (binarySearch(array, findValue, startValue, endValue, &callsNumber) == -1) {
    printf("%d nao foi encontrado\n", findValue);
  } else {
    printf("%d\n", callsNumber);
  }
  
  free(array);
  
  return 0;
}




int binarySearch(int *array, int value, int start, int end, int *callsNumber) {
  /* Busca um dado valor divindo o vetor diversas vezes através
     de índices */
  if (start > end) {
    return -1;
  }
  
  int mid = (start + end) / 2;
  
  if (value == array[mid]) {
    return 1;
  }
  
  if (array[mid] < value) {
    (*callsNumbers)++;
    return binarySearch(array, value, mid + 1, end, callsNumbers);
  } else {
    (*callsNumbers)++;
    return binarySearch(array, value, start, mid - 1, callsNumbers);
  }
}