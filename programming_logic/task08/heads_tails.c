#include <stdio.h>
#include <string.h>

//=== Recebedor de string.
void CoinThrow(char coinSequence[1000]) {
  fgets(coinSequence, 1000, stdin);
  
  return;
}

//==r Checando quantas vezes cara ou coroa aparecem.
void checkingResults(int *countHeads, int *countTails, int *sumHeadsTails) {
  int sumHT;
  
  char coinSequence[1000];
  
  CoinThrow(coinSequence);
  
  for (sumHT = 0; sumHT < strlen(coinSequence) - 1; sumHT++) {
    if (coinSequence[sumHT] == 'K') {
      (*countHeads)++;
    } else if (coinSequence[sumHT] == 'C') {
      (*countTails)++;
    }
  }
  
  *sumHeadsTails = sumHT;
  
  return;
}

//=== Mostrando os resultados de lançamentos, cara ou coroa.
void Printer() {
  int sum = 0, countHeads = 0, countTails = 0;
  
  checkingResults(&countHeads, &countTails, &sum);
  
  printf("Numero de lancamentos: %d\n", sum);
  printf("Quantidade de cara: %d\n", countHeads);
  printf("Quantidade de coroa: %d\n", countTails);
}


int main() {
  
  Printer();
  
  return 0;
}