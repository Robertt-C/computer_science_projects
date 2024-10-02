#include <stdio.h>                                                                                                                                                     

int main() {
  int matrix[1000][1000];
  int i, j, num, sum, matrixNum, pointNum, matrixLimit, pointLimit;
  
//=== Inicializando o vetor. ===//
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      matrix[i][j] = 0;
    }
  }
  
//=== Criando o vetor. ===//
  scanf("%d", &matrixLimit);
  
  for (i = 0; i < matrixLimit; i++) {
    for (j = 0; j < matrixLimit; j++) {
      scanf("%d", &num);
      matrix[i][j] = num;
    }
  }
  
//=== Somando os pontos desejados ===//
  scanf("%d", &pointLimit);
  
  j = 0;
  sum = 0;
  for (i = 0; i < pointLimit; i++) {
    scanf("%d", &pointNum);
    
    while (pointNum >= matrixLimit) {
      pointNum -= matrixLimit;
      j++;
    }
    
    sum += matrix[j][pointNum];
    
    j = 0;
  }
  
  printf("%d\n", sum);
  
  return 0;
}