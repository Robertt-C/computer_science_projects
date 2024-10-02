#include <stdio.h>

void frac(float num, int *inteiro, float *fracNum) {
  *inteiro = (int)num;
  *fracNum = num - (*inteiro);
  
  return;
}


void imprimirNum() {
  float num, fracNum;
  int inteiro;
  
  printf("Dê-me o número flutuante:\n");
  scanf("%f", &num);
  
  frac(num, &inteiro, &fracNum);
  
  printf("Número: %.2f\nInteiro: %d\nDecimal: %.2f\n", num, inteiro, fracNum);
  
  return;
}




int main() {
  
  imprimirNum();
  
  return 0;
}