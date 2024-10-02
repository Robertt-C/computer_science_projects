#include <stdio.h>
#include <stdlib.h>

#define NOT_USED -1
#define REMOVED -2

// hash functions 1 and 2 are hashFunction auxiliaries.

int insertOpenHash(int *array, int value, int arrayLength);
int removeHash(int *array, int toRemove, int arrayLength);
int searchOpenHash(int *array, int value, int arrayLength);

int hashFunction(int, int, int);
int auxHashFunction1(int, int);
int auxHashFunction2(int, int);




int main() {
  int i, searchValue, indexSearchValue, insertValue, arrayLength, *hashArray;
  
  // Build up the array with a prime number as arrayLength
  
  scanf("%d", &arrayLength);
  
  hashArray = (int*) malloc(arrayLength * sizeof(int));
  
  
  // Fill it with marker NOT_USED
  
  for (i = 0; i < arrayLength; i++) {
    hashArray[i] = NOT_USED;
  }
  
  
  // inserting a series of numbers using hash function.
  // Input ends with -1
  
  scanf("%d", &insertValue);
  
  while (insertValue >= 0) {
    insertOpenHash(hashArray, insertValue, arrayLength);
    
    scanf("%d", &insertValue);
  }
  
  
  // Value for searching. If it exists, remove all occurrences,
  // if it doesn't, print a not found message.
  
  scanf("%d", &searchValue);
  
  if (searchOpenHash(hashArray, searchValue, arrayLength) == -1) {
    printf("Valor nao encontrado\n");
  } else {
    removeHash(hashArray, searchValue, arrayLength);
  }
  
  
  // Printing the list
  
  for (i = 0; i < arrayLength; i++) {
    if (hashArray[i] == -1) {
      printf("\\ ");
    } else if (hashArray[i] == -2) {
      printf("D ");
    } else {
    printf("%d ", hashArray[i]);
    }
  }
  
  printf("\n");
  
  
  free(hashArray);
  
  return 0;
}




int auxHashFunction1(int value, int arrayLength) {
  return (value % arrayLength);
}


int auxHashFunction2(int value, int arrayLength) {
  return 1 + (value % (arrayLength - 1));
}


int hashFunction(int value, int i, int arrayLength) {
  return ((auxHashFunction1(value, arrayLength) + (i * auxHashFunction2(value, arrayLength))) % arrayLength);
}


int searchOpenHash(int *hashArray, int value, int arrayLength) {
  int i = 0, j;
  
  do {
    j = hashFunction(value, i, arrayLength);
    
    if (hashArray[j] == value) {
      return j;
    }
    
    i++;
  } while ((hashArray[j] != NOT_USED) || (i != arrayLength));
  
  return NOT_USED;
}


int insertOpenHash(int *hashArray, int value, int arrayLength) {
  int i = 0, j;
  
  do {
    j = hashFunction(value, i, arrayLength);
    
    if (hashArray[j] == NOT_USED) {
      hashArray[j] = value;
      
      return j;
    }
    
    i++;
  } while (i != arrayLength);
  
  return 0;
}


int removeHash(int *hashArray, int toRemove, int arrayLength) {
  int i;
  
  for (i = 0; i < arrayLength; i++) {
    if (hashArray[i] == toRemove) {
      hashArray[i] = REMOVED;
    }
  }
  
  return 0;
}