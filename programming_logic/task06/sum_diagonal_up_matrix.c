#include <stdio.h>

int main() {
  int matrix[1000][1000];
  int i, j, k, limit, num, sum;
  
//=== Inicializando a matriz. ===//
  
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      matrix[i][j] = 0;
    }
  }

/*  Visualizar a matriz em 0s.
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      if (j == 999) {
        printf("%d\n", matrix[i][j]);
      } else {
        printf("%d", matrix[i][j]);
      }
    }
  }
*/

//=== Preenchendo a matriz. ===//

  scanf("%d", &limit);
  
  for (i = 0; i < limit; i++) {
    for (j = 0; j < limit; j++) {
      scanf("%d", &num);
      matrix[i][j] = num;
    }
  }

/*  //=== Mostrando a matriz ===//

  for (i = 0; i < limit; i++) {
    for (j = 0; j < limit; j++) {
      if (j == limit - 1) {
        printf("%d\n", matrix[i][j]);
      } else {
        printf("%d", matrix[i][j]);
      }
    }
  }
*/

//=== Tratando da soma da diagonal principal e elementos acima dela. ===//

  sum = 0;
  k = 0;
  j = limit;
  
  for (i = 0; i < limit; i++) {
    while (j > k) {
      sum += matrix[i][j-1];
      j--;
    }
    j = limit;
    k++;
  }
  
  printf("%d\n", sum);
  
  return 0;
}

/*
    00 01 02 03 04
    10 11 12 13 14
    20 21 22 23 24
    30 31 32 33 34
    40 41 42 43 44
*/