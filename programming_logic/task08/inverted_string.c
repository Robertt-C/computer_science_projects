#include <stdio.h>
#include <string.h>

//=== Recebedor de string genérico.
void StringReceiver(char string[1000]) {
  
  fgets(string, 1000, stdin);
  
  return;
}

//=== Invertendo os elementos de um vetor.
void InvertedString(char string[1000]) {
  int i, getFirstCharacter, getLastCharacter;
  
  StringReceiver(string);
  
  for (i = 0; i < (strlen(string) - 1) / 2; i++) {
    getFirstCharacter = string[i];
    getLastCharacter = string[strlen(string) - 2 - i];
    
    string[i] = getLastCharacter;
    string[strlen(string) - 2 - i] = getFirstCharacter;
  }
  
  return;
}

//=== Exibindo o vetor modificado.
void StringPrinter() {
  char string[1000];
  
  InvertedString(string);
  
  printf("%s\n", string);
}



int main() {
  
  StringPrinter();
  
  return 0;
}