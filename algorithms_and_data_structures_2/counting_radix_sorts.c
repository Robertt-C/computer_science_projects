#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 255


int radixSort(char**, char**, char*, int, int);
int countingSort(char**, char**, int*, int);

int checkWordsValidity(char**, int);
int fillWords(char**, int, int);
int wordsToLower(char**, int);
int findLargestWordLength(char**, int);
int* makePositionsArray(char**, char*, int*, int , int);




//--- Radix and counting sort implementations for chars.
/*
  The first input is the words' number, then the alphabetical key in a chosen order
  and all the words separated by a space.
*/

int main() {
  int i, wordsNumber, keyLength = 27, largestWordLength;
  char **arrayWords1, **arrayWords2, *arrayKey;
  
  scanf("%d", &wordsNumber);
  
  arrayKey = (char*) malloc(keyLength * sizeof(char));
  arrayWords1 = (char**) malloc(wordsNumber * sizeof(char*));
  arrayWords2 = (char**) malloc(wordsNumber * sizeof(char*));
  
  for (i = 0; i < wordsNumber; i++) {
    arrayWords1[i] = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
    arrayWords2[i] = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
  }
  
  
  scanf("%s", arrayKey);
  
  // Rearranging the key with a blank space at the beginning.
  for (i = keyLength - 1; i > 0; i--) {
    arrayKey[i] = arrayKey[i - 1];
  }
  
  arrayKey[0] = ' ';
  
  
  // Give me all words.
  for (i = 0; i < wordsNumber; i++) {
    scanf("%s", arrayWords1[i]);
  }
  
  wordsToLower(arrayWords1, wordsNumber);
  
  /*
  if (!checkWordsValidity(arrayWords1, wordsNumber)) {
    return 0;
  }
  */
  
  for (i = 0; i < wordsNumber; i++) {
    printf("%s.\n", arrayWords1[i]);
  }
  
  largestWordLength = findLargestWordLength(arrayWords1, wordsNumber);
  
  printf("%d\n", largestWordLength);
  
  fillWords(arrayWords1, wordsNumber, largestWordLength);
  
  
  radixSort(arrayWords1, arrayWords2, arrayKey, largestWordLength, wordsNumber);
  
  
  for (i = 0; i < wordsNumber; i++) {
    printf("%s\n", arrayWords2[i]);
    
  }
  
  
  for (i = 0; i < wordsNumber; i++) {
    free(arrayWords1[i]);
  }
  
  free(arrayWords1);
  free(arrayWords2);
  free(arrayKey);
  
  return 0;
}




int radixSort(char **arrayWords1, char **arrayWords2, char *arrayKey, int largestWordLength, int wordsNumber) {
  int i, j, *wordsPosition = (int*) malloc(wordsNumber * sizeof(int));
  
  for (i = largestWordLength - 1; i >= 0; i--) {
    wordsPosition = makePositionsArray(arrayWords1, arrayKey, wordsPosition, wordsNumber, i);
    
    countingSort(arrayWords1, arrayWords2, wordsPosition, wordsNumber);
  }
  
  free(wordsPosition);
  
  return 0;
}


int countingSort(char **arrayWords1, char **arrayWords2, int *wordsPosition, int wordsNumber) {
  int i, *array3, keyLength = 27;
  
  array3 = (int*) malloc(keyLength * sizeof(int));
  
  
  for (i = 0; i < keyLength; i++) {
    array3[i] = 0;
  }
  
  for (i = 0; i < wordsNumber; i++) {
    array3[wordsPosition[i]] = array3[wordsPosition[i]] + 1;
  }
  
  for (i = 1; i < keyLength; i++) {
    array3[i] = array3[i] + array3[i - 1];
  }
  
  for (i = 0; i < keyLength; i++) {
    printf("%d", array3[i]);
  }
  
  printf("\n");
  
  for (i = wordsNumber - 1; i >= 0; i--) {
    arrayWords2[array3[wordsPosition[i]] - 1] = arrayWords1[i];
    array3[wordsPosition[i]] = array3[wordsPosition[i]] - 1;
  }
  
  
  for (i = 0; i <= wordsNumber; i++) {
    arrayWords1[i] = arrayWords2[i];
  }
  
  free(array3);
  
  return 0;
}


// It makes an array with the number of each letter position in the key.
int* makePositionsArray(char **arrayWords1, char *arrayKey, int *wordsPosition, int wordsNumber, int matrixLayer) {
  int i, j;
  
  for (i = 0; i < wordsNumber; i++) {
    for (j = 0; j < strlen(arrayKey); j++) {
      if (arrayWords1[i][matrixLayer] == arrayKey[j]) {
        wordsPosition[i] = j;
        break;
      }
    }
  }
  
  return wordsPosition;
}


int findLargestWordLength(char **arrayWords, int wordsNumber) {
  int i, largestWordLength;
  
  largestWordLength = strlen(arrayWords[1]);
  
  for (i = 0; i < wordsNumber; i++) {
    if (largestWordLength < strlen(arrayWords[i])) {
      largestWordLength = strlen(arrayWords[i]);
    }
  }
  
  return largestWordLength;
}


// Fill all words with blank spaces until the same length of the largest one.
int fillWords(char **arrayWords, int wordsNumber, int largestWordLength) {
  int i, j;
  
  for (i = 0; i < wordsNumber; i++) {
    for (j = strlen(arrayWords[i]); j < largestWordLength; j++) {
      arrayWords[i][j] = ' ';
    }
    
    arrayWords[i][j] = '\0';
  }
  
  return 0;
}


int wordsToLower(char **arrayWords, int wordsNumber) {
  int i, j;
  
  for (i = 0; i < wordsNumber; i++) {
    for (j = 0; j < strlen(arrayWords[i]); j++) {
      arrayWords[i][j] = tolower(arrayWords[i][j]);
    }
  }
  
  return 0;
}

/*
// Checking words validity based on: the word must be made with alphabetical letters, upper and lower cases, only
int checkWordsValidity(char **arrayWords, int wordsNumber) {
  int i, j;
  
  for (i = 1; i <= wordsNumber; i++) {
    for (j = 0; j < strlen(arrayWords[i]); j++) {
      
      if (arrayWords[i][j] < 'a' || arrayWords[i][j] > 'z') {
        printf("A palavra %s eh invalida", arrayWords[i]);
        
        return 0;
      }
    }
  }
  
  return 1;
}
*/




/*
//--- Radix and Counting sorts for integers.

int countingSort(int*, int*, int, int);
int findLargest(int*, int);

int radixSort(int**, int**, int, int);
int countingSortRadix(int**, int**, int, int, int);
int findLargestRadix(int**, int, int);




int main() {
  int i, j, largestValue, numberLength, arrayLength, *array1, *array2, **pArray1, **pArray2;
  
  scanf("%d", &arrayLength);
  scanf("%d", &numberLength);
  
  pArray1 = (int**) malloc((arrayLength + 1) * sizeof(int*));
  pArray2 = (int**) malloc((arrayLength + 1) * sizeof(int*));
  
  for (i = 0; i <= arrayLength; i++) {
    pArray1[i] = (int*) malloc(numberLength * sizeof(int));
    pArray2[i] = (int*) malloc(numberLength * sizeof(int));
  }
  
  
  for (i = 1; i <= arrayLength; i++) {
    for (j = 0; j < numberLength; j++) {
      scanf("%d", &pArray1[i][j]);
    }
  }
  
  printf("\npArray1: \n");
  for (i = 1; i <= arrayLength; i++) {
    for (j = 0; j < numberLength; j++) {
      printf("%d", pArray1[i][j]);
    }
    
    printf("\n");
  }
  
  
  radixSort(pArray1, pArray2, arrayLength, numberLength);
  
  
  printf("\npArray2: \n");
  for (i = 1; i <= arrayLength; i++) {
    for (j = 0; j < numberLength; j++) {
      printf("%d", pArray1[i][j]);
    }
    
    printf("\n");
  }
  
  
  for (i = 0; i < arrayLength; i++) {
    free(pArray1[i]);
    free(pArray2[i]);
  }
  
  free(pArray1);
  free(pArray2);
  
  return 0;
}




// Radix sort implementation.
int radixSort(int **pArray1, int **pArray2, int pArray1Length, int numberLength) {
  int k, largestValue;
  
  for (k = numberLength - 1; k >= 0; k--) {
    largestValue = findLargestRadix(pArray1, pArray1Length, k);
    countingSortRadix(pArray1, pArray2, largestValue, pArray1Length, k);
  }
  
  return 0;
}


int countingSortRadix(int **pArray1, int **pArray2, int largestValue, int pArray1Length, int z) {
  int i, j, q, *array3;
  
  array3 = (int*) malloc((largestValue + 1) * sizeof(int));
  
  for (i = 0; i <= largestValue; i++) {
    array3[i] = 0;
  }
  
  for (j = 1; j <= pArray1Length; j++) {
    array3[pArray1[j][z]] = array3[pArray1[j][z]] + 1;
  }
  
  for (i = 1; i <= largestValue; i++) {
    array3[i] = array3[i] + array3[i - 1];
  }
  
  for (j = pArray1Length; j >= 1; j--) {
    pArray2[array3[pArray1[j][z]]] = pArray1[j];
    array3[pArray1[j][z]] = array3[pArray1[j][z]] - 1;
  }
  
  
  for (i = 1; i <= pArray1Length; i++) {
    pArray1[i] = pArray2[i];
  }
  
  free(array3);
  
  return 0;
}


int findLargestRadix(int **pArray, int pArrayLength, int z) {
  int i, largestValue;
  
  largestValue = pArray[1][z];
  
  for (i = 1; i <= pArrayLength; i++) {
    if (largestValue < pArray[i][z]) {
      largestValue = pArray[i][z];
    }
  }
  
  return largestValue;
}
*/




/*
int main() {
  int i, j, largestValue, numberLength, arrayLength, *array1, *array2, **pArray1, **pArray2;
  
  scanf("%d", &arrayLength);
  
  array1 = (int*) malloc((arrayLength + 1) * sizeof(int));
  array2 = (int*) malloc((arrayLength + 1) * sizeof(int));
  
  
  for (i = 1; i <= arrayLength; i++) {
    scanf("%d", &array1[i]);
  }
  
  largestValue = findLargest(array1, arrayLength);
  
  countingSort(array1, array2, largestValue, arrayLength);
  
  for (i = 1; i <= arrayLength; i++) {
    printf("%d ", array2[i]);
  }
  
  printf("\n");
  
  free(array1);
  free(array2);
  
  return 0;
}




int countingSort(int *array1, int *array2, int largestValue, int array1Length) {
  int i, j, *array3;
  
  array3 = (int*) malloc((largestValue + 1) * sizeof(int));
  
  for (i = 0; i <= largestValue; i++) {
    array3[i] = 0;
  }
  
  for (j = 1; j <= array1Length; j++) {
    array3[array1[j]] = array3[array1[j]] + 1;
  }
  
  for (i = 1; i <= largestValue; i++) {
    array3[i] = array3[i] + array3[i - 1];
  }
  
  for (j = array1Length; j >= 1; j--) {
    array2[array3[array1[j]]] = array1[j];
    array3[array1[j]] = array3[array1[j]] - 1;
  }
  
  free(array3);
  
  return 0;
}


int findLargest(int *array, int arrayLength) {
  int i, largestValue;
  
  largestValue = array[1];
  
  for (i = 1; i <= arrayLength; i++) {
    if (largestValue < array[i]) {
      largestValue = array[i];
    }
  }
  
  return largestValue;
}
*/