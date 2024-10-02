#include <stdio.h>                                                                                                                                          

//=== Calculating value readjustment.
int main() {
  int payment, increasePercentage;
  
  scanf("%d %d", &payment, &increasePercentage);
  float toReceive = payment * increasePercentage / 100 + payment;
  printf("O reajuste salarial de %d%c é: R$%0.2f\n", increasePercentage, 37, toReceive);
  return 0;
}