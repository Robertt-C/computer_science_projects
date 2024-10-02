#include <stdio.h>

//=== Recebedor do valor que será posteriormente fatorado.
int Receiver() {
  int num;
  
  scanf("%d", &num);
  
  return num;
}

//=== Processo de fatoração do número adquirido anteriormente.
int Factorization(int num) {
  int prime, initialPrime = 2, count = 0;
  
  while (num > 1) {
    while (initialPrime <= num) {
      prime = initialPrime;
      while (num % prime == 0) {
        num = num / prime;
        count++;
      }
      initialPrime++;
    }
  }
  
  return count;
}

//=== Mostrador do número recebido do teclado e o número de fatorações possíveis dele.
void Printer(int omegaNum, int count) {
  printf("Omega(%d)=%d\n", omegaNum, count);
}


//=== Passando valor e mostrando o resultado final.
int main() {
  int omegaNum, count;
  
  omegaNum = Receiver();
  count = Factorization(omegaNum);
  
  Printer(omegaNum, count);
  
  return 0;
}