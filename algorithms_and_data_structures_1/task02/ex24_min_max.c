#include <stdio.h>

#define MAX 6 // Mude essa constante para alterar
              // a quantidade de números passados.

void preencherVetor(int vetor[]) {
  int i;
  
  printf("Dê-me %d números:\n\n", MAX);
  
  for (i = 0; i < MAX; i++) {
    printf("Número %d será:\n", i + 1);
    scanf("%d", &vetor[i]);
  }
  
  return;
}


void minMax(int vetor[], int *min, int *max) {
  int i;
  
  preencherVetor(vetor);
  
  *min = vetor[0];
  *max = vetor[0];
  for (i = 0; i < MAX; i++) {
    if (vetor[i] >= *max) {
      *max = vetor[i];
    } else if (vetor[i] <= *min) {
      *min = vetor[i];
    }
  }
  
  return;
}




int main() {
  int min, max, vetor[MAX];
  
  minMax(vetor, &min, &max);
  
  printf("\nO mínimo: %d\nO máximo: %d\n", min, max);
  
  return 0;
}