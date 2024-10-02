#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char letter;
  int number;
} typeKey;

typedef struct {
  typeKey keys[100];
} typeList;


int parent(int);
int findLeftChild(int);
int findRightChild(int);

int maxHeapfy(char**, int, int, typeList, int);
int buildMaxHeap(char**, int, typeList, int);
int heapsort(char**, int, typeList, int);

int checkWordsValidity(char**, char*, int);
void swap(char**, int, int);
void createKey(typeList*, char*, int);
int compareNodes(char*, char*, typeList, int);




int main() {
  int i, wordsNumber, keyLength;
  char *arrayKey, **arrayWords;
  typeList keyList;
  
  
  scanf("%d %d", &wordsNumber, &keyLength);
  
  arrayWords = (char**) malloc((wordsNumber + 1) * sizeof(char*));
  arrayKey = (char*) malloc(keyLength * sizeof(char));
  
  scanf("%s", arrayKey);
  
  createKey(&keyList, arrayKey, keyLength);
  
  
  for (i = 0; i <= wordsNumber; i++) {
    // pneumoultramicroscopicossilicovulcanoconiótico
    arrayWords[i] = (char*) malloc(32 * sizeof(char));
    
    if (i == 0) {
      continue;
    }
    
    scanf("%s", arrayWords[i]);
  }
  
  
  if (!checkWordsValidity(arrayWords, arrayKey, wordsNumber)) {
    return 0;
  }
  
  heapsort(arrayWords, wordsNumber, keyList, keyLength);
  
  for (i = 1; i <= wordsNumber; i++) {
    if (i == wordsNumber) {
      printf("%s", arrayWords[i]);
      break;
    }
    
    printf("%s ", arrayWords[i]);
  }
  
  
  
  
  for (i = 0; i <= wordsNumber; i++) {
    free(arrayWords[i]);
  }
  
  free(arrayWords);
  free(arrayKey);
  
  return 0;
}




int parent(int index) {
  return (index / 2);
}


int findLeftChild(int index) {
  return (2 * index);
}


int findRightChild(int index) {
  return ((2 * index) + 1);
}


int maxHeapfy(char **array, int index, int arrayLength, typeList list, int keyLength) {
  int leftChild, rightChild, largest;
  
  leftChild = findLeftChild(index);
  rightChild = findRightChild(index);
  
  if ((leftChild <= arrayLength) && (compareNodes(array[leftChild], array[index], list, keyLength))/*array[leftChild] > array[index]*/) {
    largest = leftChild;
  } else {
    largest = index;
  }
  
  if ((rightChild <= arrayLength) && (compareNodes(array[rightChild], array[largest], list, keyLength))/*array[rightChild] > array[largest]*/) {
    largest = rightChild;
  }
  
  
  if (largest != index) {
    swap(array, largest, index);
    maxHeapfy(array, largest, arrayLength, list, keyLength);
  }
}


int buildMaxHeap(char **array, int arrayLength, typeList list, int keyLength) {
  int i;
  
  for (i = (arrayLength / 2); i >= 1; i--) {
    maxHeapfy(array, i, arrayLength, list, keyLength);
  }
}


int heapsort(char **array, int arrayLength, typeList list, int keyLength) {
  int i;
  
  buildMaxHeap(array, arrayLength, list, keyLength);
  
  for (i = arrayLength; i >= 2; i--) {
    swap(array, 1, i);
    arrayLength--;
    maxHeapfy(array, 1, arrayLength, list, keyLength);
  }
}


void swap(char **array, int index1, int index2) {
  char *swapAux;
  
  swapAux = array[index1];
  array[index1] = array[index2];
  array[index2] = swapAux;
}


// Checking words validity based on: the word has to be made of key letters.
int checkWordsValidity(char **arrayWords, char *arrayKey, int wordsNumber) {
  int i, j, k, count = 0;
  
  for (i = 1; i <= wordsNumber; i++) {
    for (j = 0; j < strlen(arrayWords[i]); j++) {
      for (k = 0; k < strlen(arrayKey); k++) {
        if (arrayWords[i][j] == arrayKey[k]) {
          count++;
          break;
        }
      }
      
      if ((count - j) == 0) {
        printf("A palavra %s eh invalida", arrayWords[i]);
        return 0;
      }
    }
    
    count = 0;
  }
  
  return 1;
}

// Create key based on arrayKey with a number of priority.
void createKey(typeList *list, char *arrayKey, int keyLength) {
  int i;
  
  for (i = 0; i < keyLength; i++) {
    list->keys[i].letter = arrayKey[i];
    list->keys[i].number = i;
  }
}

// Compare each letter of two words to see which is larger.
int compareNodes(char *node1, char *node2, typeList list, int keyLength) {
  int i, j, node1Number = 0, node2Number = 0,
      node1Length = strlen(node1), node2Length = strlen(node2);
  /*
  if (node1Length <= node2Length) {
    smallestWordLength = node1Length;
  } else {
    smallestWordLength = node2Length;
  }*/
  
  
  for (i = 0; i < keyLength; i++) {
    for (j = 0; j < keyLength; j++) {
      if (list.keys[j].letter == node1[i]) {
        node1Number = list.keys[j].number;
      }
      
      if (list.keys[j].letter == node2[i]) {
        node2Number = list.keys[j].number;
      }
    }
    
    
    if (node1Number > node2Number) {
      return 1;
    } else if (node1Number < node2Number) {
      return 0;
    }
    
    if (i == keyLength - 1) {
      if (node1Length > node2Length) {
        return 1;
      } else {
        return 0;
      }
    }
  }
  
  return 0;
}








//--- Heapsort for int array.
/*
int parent(int);
int findLeftChild(int);
int findRightChild(int);

int maxHeapfy(int*, int, int);
int buildMaxHeap(int*, int);
int heapsort(int*, int);

void swap(int*, int, int);


int main() {
  int i, arrayLength, *array;
  
  scanf("%d", &arrayLength);
  
  array = (int*) malloc((arrayLength + 1) * sizeof(int));
  
  for (i = 1; i <= arrayLength; i++) {
    scanf("%d", &array[i]);
  }
  
  heapsort(array, arrayLength);
  
  for (i = 1; i <= arrayLength; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");

  return 0;
}




int parent(int index) {
  return (index / 2);
}


int findLeftChild(int index) {
  return (2 * index);
}


int findRightChild(int index) {
  return ((2 * index) + 1);
}


int maxHeapfy(int *array, int index, int arrayLength) {
  int leftChild, rightChild, largest;
  
  leftChild = findLeftChild(index);
  rightChild = findRightChild(index);
  
  if ((leftChild <= arrayLength) && (array[leftChild] > array[index])) {
    largest = leftChild;
  } else {
    largest = index;
  }
  
  if ((rightChild <= arrayLength) && (array[rightChild] > array[largest])) {
    largest = rightChild;
  }
  
  
  if (largest != index) {
    swap(array, largest, index);
    maxHeapfy(array, largest, arrayLength);
  }
}


int buildMaxHeap(int *array, int arrayLength) {
  int i;
  
  for (i = (arrayLength / 2); i >= 1; i--) {
    maxHeapfy(array, i, arrayLength);
  }
}


int heapsort(int *array, int arrayLength) {
  int i;
  
  buildMaxHeap(array, arrayLength);
  
  for (i = arrayLength; i >= 2; i--) {
    swap(array, 1, i);
    arrayLength--;
    maxHeapfy(array, 1, arrayLength);
  }
}


void swap(int *array, int index1, int index2) {
  int swapAux;
  
  swapAux = array[index1];
  array[index1] = array[index2];
  array[index2] = swapAux;
}
*/