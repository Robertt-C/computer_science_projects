#include <stdio.h>
#include <stdlib.h>

int negativos(float *vetor, int N) {
  int i;
  
  printf("\n");
  
  for (i = 0; i < N; i++) {
    printf("Dê-me o número da posição: %d\n", i);
    scanf("%f", vetor+i);
  }
  
  printf("\n");
  
  for (i = 0; i < N; i++) {
    if (*(vetor+i) * (-1) > 0) {
      printf("Número na posição[%d]: %.2f\n", i, *(vetor+i));
    }
  }
  
  return 0;
}




int main() {
  float *vetor;
  int tamanhoArray;
  
  printf("Tamanho do vetor?:\n");
  scanf("%d", &tamanhoArray);
  
  vetor = malloc(tamanhoArray * sizeof(float));
  
  negativos(vetor, tamanhoArray);
  
  return 0;
}