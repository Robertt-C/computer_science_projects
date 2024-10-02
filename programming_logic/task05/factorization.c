#include <stdio.h>

int main() {
  int num, omegaNum, prime, count = 0, numi = 2;
  
/*
  Pedindo um número inicial.
*/
  scanf("%d", &num);
  
  omegaNum = num;
  
/*
  Enquanto esse número for maior que 1 vamos fatorando-o
  em fatores primos e contando quantas vezes ele é dividido.
*/
  while (num > 1) {
    while (numi <= num) {
      prime = numi;
      while (num % prime == 0) {
        num = num / prime;
        count++;
      }
      numi++;
    }
  }
  printf("Omega(%d)=%d\n", omegaNum, count);
  return 0;
}