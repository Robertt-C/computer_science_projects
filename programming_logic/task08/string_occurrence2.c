#include <stdio.h>
#include <string.h>

//=== Recebendo strings
void StringReceiver(char string0[1000], char string1[1000]) {
  
  fgets(string0, 1000, stdin);
  fgets(string1, 1000, stdin);
  
  return;
}

//=== Checando a quantidade de ocorrências da string1 na string0
int CheckingOccurrence() {
  char string0[1000], string1[1000];
  int i, j, count, realCount;
  
  StringReceiver(string0, string1);
  
  realCount = 0;
  count = 0;
  for (i = 0; i < strlen(string0) - 1; i++) {
    for (j = 0; j < strlen(string1) - 1; j++) {
      
      if (string0[i + j] == string1[j]) {
        count++;
      }
      
      if (count == strlen(string1) - 1) {
        realCount++;
        i += (strlen(string1) - 1);
      }
      
    }
    count = 0;
  }
  
  return realCount;
}

//=== Exibidor da quantidade de ocorrências.
void OccurrencePrinter() {
  int occurrence;
  
  occurrence = CheckingOccurrence();
  
  printf("Número de ocorrência: %d\n", occurrence);
  
  return;
}



int main() {
  
  OccurrencePrinter();
  
  return 0;
}