#include <stdio.h>

int main() {
  float income;
  
  scanf("%f", &income);
  
  if (income <= 1903.98) {
    printf("Isento\n");
  } else if (income <= 2826.65) {
    printf("R$%.2f\n", (income*0.075) - 142.80);
  } else if (income <= 3751.05) {
    printf("R$%.2f\n", (income*0.15) - 354.80);
  } else if (income <= 4664.68) {
    printf("R$%.2f\n", (income*0.225) - 636.13);
  } else {
    printf("R$%.2f\n", (income*0.275) - 869.36);
  }
  
  return 0;
}