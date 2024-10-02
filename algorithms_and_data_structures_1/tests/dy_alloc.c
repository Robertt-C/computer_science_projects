#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void mallocTest() {
  int *vetor, i, length, value;
  
  printf("Dê-me o tamanho do vetor de inteiros:\n");
  scanf("%d", &length);
  
  vetor = malloc(length * sizeof(int)); //aloca espaço para vetor de 20 inteiros
  
  for (i = 0; i < length; i++) {
    printf("Dê-me o elemento[%d]: ", i);
    
    //scanf("%d", &value);
    //vetor[i] = value;
    scanf("%d", vetor+i);
    
    printf("Valor[%d]: %d\n", i, vetor[i]);
  }
  
  free(vetor);
  
  return;
}


void callocTest() {
  char *nome;
  
  nome = malloc(100);
  
  free(nome);
  // nome = calloc(100, sizeof(char));
  
  return;
}


void mallocMatrix() {
  int **matrix, i;
  
  matrix = (int**)malloc(5*sizeof(int*));
  
  for (i = 0; i < 5; i++) {
    matrix[i] = (int*)malloc(5*sizeof(int));
  }
  
  for (i = 0; i < 5; i++) {
    free(matrix[i]);
  }
  
  free(matrix);
  
  return;
}


void matrix3D(int ***matrix, int length) {
  int i, j;
  
  matrix = (int***)malloc(length * sizeof(int**));
  
  for (i = 0; i < length; i++) {
    matrix[i] = (int**)malloc(length * sizeof(int*));
    for (j = 0; j < length; j++) {
      matrix[i][j] = (int*)malloc(length * sizeof(int));
    }
  }
  
  return;
}


int main() {
  int ***D, i, j, k, length;
  
  printf("Array length:\n");
  scanf("%d", &length);
  
  matrix3D(D, length);
  
  for (i = 0; i < length; i++) {
    for (j = 0; j < length; j++) {
      for (k = 0; k < length; k++) {
        D[i][j][k] = i;
        printf("Element at index [%d][%d][%d]: %d\n", i, j, k, D[i][j][k]);
      }
    }
  }
  
  return 0;
}