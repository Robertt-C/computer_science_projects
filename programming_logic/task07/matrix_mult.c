#include <stdio.h>

//=== Recebedor de números genérico.
int Receiver() {
  int num;
  
  scanf("%d", &num);
  
  return num;
}

/*=== Em caso de não compatibilidade com a regra de multiplicação de matrizes...
      Um aviso.
*/
int Flag(int orderA1, int orderB0) {
  if (orderA1 != orderB0) {
    printf("Não é possível realizar a operação, pois as matrizes não seguem a regra MxN, NxO = MxO.\n");
    return 1;
  } 
  return 0;
}

//=== Inicializadores e criadores das matrizes.
void MatrixA(int orderA0, int orderA1, int matrixA[500][500]) {
  int i, j;
  
  for (i = 0; i < orderA0; i++) {
      for (j = 0; j < orderA1; j++) {
        matrixA[i][j] = 0;
        scanf("%d", &matrixA[i][j]);
      }
    }
  
  return;
}

void MatrixB(int orderB0, int orderB1, int matrixB[500][500]) {
  int i, j;
  
  for (i = 0; i < orderB0; i++) {
    for (j = 0; j < orderB1; j++) {
      matrixB[i][j] = 0;
      scanf("%d", &matrixB[i][j]);
    }
  }
  
  return;
}

void MatrixResult(int orderA0, int orderB0, int orderB1, int matrixA[500][500], int matrixB[500][500], int matrixResult[500][500]) {
  int i, j, k;
  
  for (i = 0; i < orderA0; i++) {
    for (j = 0; j < orderB1; j++) {
      matrixResult[i][j] = 0;
      for (k = 0; k < orderB0; k++) {
        matrixResult[i][j] += matrixA[i][k]*matrixB[k][j];
      }
    }
  }
  
  return;
}

/*
    A1      B1
 A0 1 2  B0 1 2   (1 * 1) + (3 * 2) | (1 * 2) + (2 * 4)
    3 4     3 4   (3 * 1) + (4 * 3) | (3 * 2) + (4 * 4)
*/

//=== Mostrador das matrizes A, B e resultante.
void MatrixPrinter(int orderA0, int orderA1, int orderB0, int orderB1, int matrixA[500][500], int matrixB[500][500], int matrixResult[500][500]) {
  int i, j;
  
  printf("Matriz 1 (%dx%d)\n", orderA0, orderA1);
  for (i = 0; i < orderA0; i++) {
    for (j = 0; j < orderA1; j++) {
      if (j == orderA1 - 1) {
        printf("%d\n", matrixA[i][j]);
      } else {
        printf("%d\t", matrixA[i][j]);
      }
    }
  }
  
  //printf("\n");
  
  printf("Matriz 2 (%dx%d)\n", orderB0, orderB1);
  for (i = 0; i < orderB0; i++) {
    for (j = 0; j < orderB1; j++) {
      if (j == orderB1 - 1) {
        printf("%d\n", matrixB[i][j]);
      } else {
        printf("%d\t", matrixB[i][j]);
      }
    }
  }
  
  //printf("\n");
  
  printf("Matriz 1 * Matriz 2 (%dx%d)\n", orderA0, orderB1);
  for (i = 0; i < orderA0; i++) {
    for (j = 0; j < orderB1; j++) {
      if (j == orderB1 - 1) {
        printf("%d\n", matrixResult[i][j]);
      } else {
        printf("%d\t", matrixResult[i][j]);
      }
    }
  }
}

int main() {
  int orderA0, orderA1, orderB0, orderB1;
  int matrixA[500][500], matrixB[500][500], matrixResult[500][500];
  
  orderA0 = Receiver();
  orderA1 = Receiver();
  orderB0 = Receiver();
  orderB1 = Receiver();
  
  MatrixA(orderA0, orderA1, matrixA);
  MatrixB(orderB0, orderB1, matrixB);
  MatrixResult(orderA0, orderB0, orderB1, matrixA, matrixB, matrixResult);
  
  if (Flag(orderA1, orderB0)) {
    return 0;
  }
  
  MatrixPrinter(orderA0, orderA1, orderB0, orderB1, matrixA, matrixB, matrixResult);
  
  return 0;
}