#include <stdio.h>
#include <string.h>

//=== Recebedor de strings genérico e limpador do último elemento das strings.
void StringReceiver(char string0[100], char string1[100]) {
  int i;
  
  fgets(string0, 100, stdin);
  fgets(string1, 100, stdin);
  
  for (i = 0; i < strlen(string0); i++) {
    if (i == strlen(string0) - 1) {
      string0[i] = 0;
    }
  }
  
  for (i = 0; i < strlen(string1); i++) {
    if (i == strlen(string1) - 1) {
      string1[i] = 0;
    }
  }
  
  return;
}

//=== Somando os elementos de uma string qualquer.
int HashSum(char string[100]) {
  int i, sum;
  
  sum = 0;
  for (i = 0; i < strlen(string); i++) {
    sum += string[i];
  }
  
  return sum;
}

//=== Exibidor dos resultados.
void HashPrinter() {
  char string0[100], string1[100];
  
  StringReceiver(string0, string1);
  
  printf("Str1: %s - Codificaçao Hash: %d\n", string0, HashSum(string0));
  printf("Str2: %s - Codificaçao Hash: %d\n", string1, HashSum(string1));
  
  return;
}

int main() {
  
  HashPrinter();
  
  return 0;
}