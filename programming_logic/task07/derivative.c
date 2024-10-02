#include <stdio.h>

//=== Função genérica para recebimento de valores.
int Receiver() {
  int num;
  scanf("%d", &num);
  
  return num;
}

void PolinomialConstructor() {
  int i, j, count, iCount, coefficient, equaDegree;
  float coefficientArray[10000];
  
  for (i = 0; i < 10000; i++) {
    coefficientArray[i] = 0.0;
  }
  
  equaDegree = Receiver();
  if (equaDegree < 0) {
    printf("Grau inválido\n");
    return;
  }
  
  for (i = 0; i <= equaDegree; i++) {
    coefficient = Receiver();
    coefficientArray[i] = coefficient;
  }
  
  count = equaDegree;
  for (i = 0; i <= equaDegree; i++) {
    if (i == 0) {
      printf("Equação: %.1fx^%d", coefficientArray[i], count);
      count--;
      continue;
    }
    if (coefficientArray[i] >= 0) {
      printf(" + %.1fx^%d", coefficientArray[i], count);
      count--;
    } else {
      printf(" - %.1fx^%d", -coefficientArray[i], count);
      count--;
    }
    
    if (i == equaDegree) {
      printf("\n");
    }
  }
  
  iCount = equaDegree;
  count = equaDegree;
  for (i = 0; i < iCount; i++) {
    for (j = 0; j < equaDegree; j++) {
      
      if (j == 0 && i == iCount - 1) {
        coefficientArray[j] = coefficientArray[j] * count;
        count--;
        printf("Dev %d: %.1fx^%d\n", (i + 1), coefficientArray[j], count);
        continue;
      } else if (j == 0) {
        coefficientArray[j] = coefficientArray[j] * count;
        count--;
        printf("Dev %d: Equação: %.1fx^%d", (i + 1), coefficientArray[j], count);
        continue;
      }
      
      coefficientArray[j] = coefficientArray[j] * count;
      count--;
      if (coefficientArray[j] >= 0) {
        printf(" + %.1fx^%d", coefficientArray[j], count);
      } else {
        printf(" - %.1fx^%d", -coefficientArray[j], count);
      }
      
      if (j == equaDegree - 1) {
        printf("\n");
      }
    }
    equaDegree--;
    count = equaDegree;
  }
}

int main() {
  PolinomialConstructor();
  return 0;
}