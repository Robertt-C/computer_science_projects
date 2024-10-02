#include <stdio.h>
#include <stdlib.h>

int** createDynamicMatrix(int, int);
void freeMatrix(int**, int);

int main() {
  int** matrix;
  int rows, columns, i, j;
  
  printf("Dê-me o número de linhas: ");
  scanf("%d", &rows);
  printf("Dê-me o número de colunas: ");
  scanf("%d", &columns);
  printf("\n");
  
  matrix = createDynamicMatrix(columns, rows);
  
  for (j = 0; j < columns; j++) {
    for (i = 0; i < rows; i++) {
      printf("Elemento[%d][%d]: ", j+1, i+1);
      scanf("%d", &matrix[i][j]);
    }
  }
  
  printf("\n");
  
  for (j = 0; j < columns; j++) {
    for (i = 0; i < rows; i++) {
      printf("%d\t", matrix[i][j]);
      if (i == rows - 1) {
        printf("\n");
      }
    }
  }
  
  freeMatrix(matrix, rows);
  
  return 0;
}




int** createDynamicMatrix(int columns, int rows) {
  int** matrix, i;
  
  matrix = (int**)malloc(columns * sizeof(int*));
  
  for (i = 0; i < rows; i++) {
    matrix[i] = (int*)malloc(rows * sizeof(int));
  }
  
  return matrix;
}


void freeMatrix(int** matrix, int rows) {
  int i;
  
  for (i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  
  free(matrix);
  
  return;
}