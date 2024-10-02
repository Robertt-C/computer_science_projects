#include <stdio.h>
 
int main() {
  int matrix[1000][1000];
  int i, j, limit, num, sum, sum2;
  
//=== Inicializando a matriz. ===//
  
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      matrix[i][j] = 0;
    }
  }


//=== Preenchendo a matriz. ===//
  
  scanf("%d", &limit);
  
  for (i = 0; i < limit; i++) {
    for (j = 0; j < limit; j++) {
      scanf("%d", &num);
      matrix[i][j] = num;
    }
  }

/*  //=== Mostrando a matriz.  ===//

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

/*
  Fazendo a soma das linhas e colunas da matriz e vendo se
  elas são iguais a 1.
*/
  sum2 = 0;
  sum = 0;
  
  for (i = 0; i < limit; i++) {
    for (j = 0; j < limit; j++) {
      sum += matrix[i][j];
      sum2 += matrix[j][i];
    }
    
    if (sum == 1 && sum2 == 1) {
      if (i == limit - 1) {
        printf("verdadeiro\n");
        break;
      }
    } else {
      printf("falso\n");
      break;
    }
    
    sum = 0;
    sum2 = 0;
  }
  
  
    
/*
  0 0 1 0
  1 0 0 1
  0 1 0 0
*/

  return 0;
}