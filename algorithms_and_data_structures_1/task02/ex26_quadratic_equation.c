#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2) {
  float delta;
  int cont = 0;
  
  delta = pow(B, 2) - 4 * A * C;
  
  if (A == 0) {
    cont = 1;
    *X1 = -C/B;
    printf("\nCoeficiente A é 0 e essa é uma equação do primeiro grau.\nx: %.2f\n", *X1);
  } else if (delta > 0) {
    *X1 = (-B + sqrt(delta)) / (2 * A);
    *X2 = (-B - sqrt(delta)) / (2 * A);
    printf("\nDelta é maior que 0 e existem duas raízes reais diferentes.\nx1: %.2f\nx2: %.2f\n", *X1, *X2);
    cont = 2;
  } else if (delta == 0) {
    *X1 = -B / (2 * A);
    *X2 = -B / (2 * A);
    printf("\nDelta é 0 e existem duas raízes reais iguais.\nx1: %.2f\nx2: %.2f\n", *X1, *X2);
    cont = 2;
  } else {
    printf("Não existem raízes reais\n");
  }
  
  return cont;
}




int main() {
  float a, b, c, x1, x2;
  
  printf("Dê-me a:\n");
  scanf("%f", &a);
  
  printf("Dê-me b:\n");
  scanf("%f", &b);
  
  printf("Dê-me c:\n");
  scanf("%f", &c);
  
  raizes(a, b, c, &x1, &x2);
  
  return 0;
}