#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
  int data;
  struct node *next;
} TypeNode;


typedef struct list {
  TypeNode *listInitial;
  TypeNode *listEnd;
  int last;
} TypeList;

//--- For the array merge sort
//int mergeSort(int*, int, int);
//int merge(int*, int, int, int);

int mergeSort(TypeList*, int, int);
int merge(TypeList*, int, int, int);

int initializeList(TypeList*);
int listIsEmpty(TypeList*);
int insertAtBeginning(TypeList*, int);
int insertAtEnd(TypeList*, int);
int insertByChoose(TypeList*, int, int);
int printList(TypeList*);
int destroyList(TypeList*);


int main() {
  int i, item, initialPosition = 1, listLength;
  int count;
  TypeList list;
  
  initializeList(&list);
  
  scanf("%d", &listLength);
  
  for (i = 1; i <= listLength; i++) {
    scanf("%d", &item);
    insertAtEnd(&list, item);
  }
  
  mergeSort(&list, initialPosition, list.last);
  
  printList(&list);
  
  count = ceil(log2(listLength));
  
  printf("%d\n", count);
  
  return 0;
}




int mergeSort(TypeList *list, int listInit, int listEnd) {
  
  if (listInit < listEnd) {
    int listMid = (listInit + listEnd) / 2;
    
    mergeSort(list, listInit, listMid);
    mergeSort(list, listMid + 1, listEnd);
    
    merge(list, listInit, listMid, listEnd);
  }
  
  return 0;
}


int merge(TypeList *list, int listInit, int listMid, int listEnd) {
  int leftListLength = listMid - listInit + 1,
      rightListLength = listEnd - listMid,
      i, j, k, sentinel = 1215752192;
  
  TypeList leftList, rightList;
  TypeNode *leftPAux, *rightPAux, *pAux;
  
  
  initializeList(&leftList);
  initializeList(&rightList);
  
  // Searching for the list initial value (left list)
  for (i = 1; i <= listInit; i++) {
    if (i == 1) {
      pAux = list->listInitial;
    } else {
      pAux = pAux->next;
    }
  }
  
  for (i = 1; i <= leftListLength; i++) {
    insertAtEnd(&leftList, pAux->data);
    
    pAux = pAux->next;
  }
  
  insertAtEnd(&leftList, sentinel);
  
  //printList(&leftList);
  
  // Searching for the list initial value (right one)
  for (j = 1; j <= listMid + 1; j++) {
    if (j == 1) {
      pAux = list->listInitial;
    } else {
      pAux = pAux->next;
    }
  }
  
  for (j = 1; j <= rightListLength; j++) {
    insertAtEnd(&rightList, pAux->data);
    
    pAux = pAux->next;
  }
  
  insertAtEnd(&rightList, sentinel);
  
  //printList(&rightList);
  
  // Searching for the initial value in the main list
  for (k = 1; k <= listInit; k++) {
    if (k == 1) {
      pAux = list->listInitial;
    } else {
      pAux = pAux->next;
    }
  }
  
  leftPAux = leftList.listInitial;
  rightPAux = rightList.listInitial;
  
  for (k = 1; k <= listEnd - listInit + 1; k++) {
    if (leftPAux->data <= rightPAux->data) {
      pAux->data = leftPAux->data;
      
      leftPAux = leftPAux->next;
      pAux = pAux->next;
    } else {
      pAux->data = rightPAux->data;
      
      rightPAux = rightPAux->next;
      pAux = pAux->next;
    }
  }
  
  destroyList(&leftList);
  destroyList(&rightList);
  
  return 0;
} 




// List functions 
int initializeList(TypeList *list) {
  list->listInitial = NULL;
  list->last = 0;
  
  return 1;
}


int listIsEmpty(TypeList *list) {
  return list->last == 0;
}


int insertAtBeginning(TypeList *list, int item) {
  TypeNode *newNode;
  
  newNode = (TypeNode*) malloc(sizeof(TypeNode));
  
  if (newNode != NULL) {
    newNode->data = item;
    newNode->next = list->listInitial;
    list->listInitial = newNode;
    
    if (list->last == 0) {
      list->listEnd = newNode;
    }
    
    list->last++;
    
    return 1;
  }
  
  return 0;
}


int insertAtEnd(TypeList *list, int item) {
  TypeNode *newNode, *pAux;
  
  if (listIsEmpty(list)) {
    insertAtBeginning(list, item);
    
    return 1;
  }
  
  newNode = (TypeNode*) malloc(sizeof(TypeNode));
  
  if (newNode != NULL) {
    pAux = list->listEnd;
    
    pAux->next = newNode;
    list->listEnd = newNode;
    
    newNode->data = item;
    newNode->next = NULL;
    
    list->last++;
    
    return 1;
  }
  
  return 0;
}


int insertByChoose(TypeList *list, int item, int position) {
  TypeNode *newNode, *pAux;
  int i;
  
  if (listIsEmpty(list)) {
    insertAtBeginning(list, item);
    
    return 1;
  } else if (position == list->last + 1) {
    insertAtEnd(list, item);
    
    return 1;
  } else {
    
    newNode = (TypeNode*) malloc(sizeof(TypeNode));
    
    pAux = list->listInitial;
    
    if (newNode != NULL) {
      for (i = 2; i < position; i++) {
        if (pAux->next != NULL) {
          pAux = pAux->next;
        }
      }
    }
    
    newNode->next = pAux->next;
    pAux->next = newNode;
    
    list->last++;
    
    return 1;
  }
  
  return 0;
}


int printList(TypeList *list) {
  TypeNode *pAux;
  int i;
  
  if (!listIsEmpty(list)) {
    printf("\n");
    
    pAux = list->listInitial;
    for (i = 1; i <= list->last; i++) {
      printf("%d ", pAux->data);
      pAux = pAux->next;
    }
    
    printf("\n");
    
    return 1;
  }
  
  
  return 0;
}


int destroyList(TypeList *list) {
  TypeNode *pAux1, *pAux2;
  
  if (!listIsEmpty(list)) {
    pAux1 = list->listInitial;
    pAux2 = pAux1->next;
    
    while (pAux1->next != NULL) {
      free(pAux1);
      pAux1 = pAux2;
      pAux2 = pAux1->next;
    }
    
    free(pAux1);
    
    list->listInitial = NULL;
    list->last = 0;
    
    return 1;
  }
  
  return 0;
}




/*
int main() {
  int i, arrayLength, *array;
  
  scanf("%d", &arrayLength);
  
  array = malloc(arrayLength * sizeof(int));
  
  for (i = 0; i < arrayLength; i++) {
    array[i] = arrayLength - i;
  }
  
  for (i = 0; i < arrayLength; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");
  
  mergeSort(array, 0, arrayLength - 1);
  
  
  for (i = 0; i < arrayLength; i++) {
    printf("%d ", array[i]);
  }
  
  printf("\n");
  
  free(array);
  
  return 0;
}
*/



/*
int mergeSort(int *array, int arrayInit, int arrayEnd) {
  
  if (arrayInit < arrayEnd) {
    int arrayMid = (arrayInit + arrayEnd) / 2;
    
    mergeSort(array, arrayInit, arrayMid);
    mergeSort(array, arrayMid + 1, arrayEnd);
    
    merge(array, arrayInit, arrayMid, arrayEnd);
  }
  
  return 0;
}


int merge(int *array, int arrayInit, int arrayMid, int arrayEnd) {
  int leftArrayLength = arrayMid - arrayInit + 1,
      rightArrayLength = arrayEnd - arrayMid,
      
      *leftArray, *rightArray,
      i, j, k;
   
  
  leftArray = malloc((leftArrayLength + 1) * sizeof(int));
  rightArray = malloc((rightArrayLength + 1) * sizeof(int));
  
  for (i = 0; i < leftArrayLength; i++) {
    leftArray[i] = array[arrayInit + i];
  }
  
  for (j = 0; j < rightArrayLength; j++) {
    rightArray[j] = array[arrayMid + j + 1];
  }
  
  
  leftArray[leftArrayLength] = 1215752192;
  rightArray[rightArrayLength] = 1215752192;
  
  i = 0;
  j = 0;
  
  for (k = arrayInit; k < arrayEnd + 1; k++) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i++;
    } else {
      array[k] = rightArray[j];
      j++;
    }
  }
  
  free(leftArray);
  free(rightArray);
  
  return 0;
}
*/


/*
int merge(int *array, int arrayInit, int arrayMid, int arrayEnd) {
  int i, leftArrayLength = (arrayMid - arrayInit) + 1,
      rightArrayLength = arrayEnd - arrayMid,
      
      *leftArray, *rightArray;
      
  leftArray = malloc((leftArrayLength - 1) * sizeof(int));
  rightArray = malloc((rightArrayLength - 1) * sizeof(int));
  
  for (i = 0; i < leftArrayLength; i++) {
    leftArray[i] = array[arrayInit + i];
  }
  
  for (i = 0; i < rightArrayLength; i++) {
    rightArray[i] = array[arrayMid + i + 1];
  }
  
  printf("1: ");
  for (i = 0; i < leftArrayLength; i++) {
    printf("%d ", leftArray[i]);
  }
  
  printf("\n");
  
  printf("2: ");
  for (i = 0; i < rightArrayLength; i++) {
    printf("%d ", rightArray[i]);
  }
  
  printf("\n");
  
  
  i = 0;
  int j = 0;
  int k = arrayInit;
  
  
  while (i < leftArrayLength && j < rightArrayLength) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i++;
    } else {
      array[k] = rightArray[j];
      j++;
    }
    k++;
  }
  
  while (i < leftArrayLength) {
    array[k] = leftArray[i];
    i++;
    k++;
  }
  
  while (j < rightArrayLength) {
    array[k] = rightArray[j];
    j++;
    k++;
  }
  
  
  free(leftArray);
  free(rightArray);
  
  return 0;
}  */