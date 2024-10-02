#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void modVariable() {
  int integer;
  float floatingPoint;
  char character;
  
  int *pInteger;
  float *pFloatingPoint;
  char *pCharacter;
  
  printf("Dê-me o inteiro: \n");
  scanf("%d", &integer);
  
  printf("Dê-me o ponto flutuante: \n");
  scanf("%f", &floatingPoint);
  
  getchar();
  printf("Dê-me o caractere: \n");
  scanf("%c", &character);
  
  printf("\nAntes:\n");
  printf("Inteiro: %d\nPonto flutuante: %.2f\nCaractere: %c\n", integer, floatingPoint, character);
  
  pInteger = &integer;
  pFloatingPoint = &floatingPoint;
  pCharacter = &character;
  
  *pInteger = 42;
  *pFloatingPoint = 42.00;
  *pCharacter = 'O';
  
  printf("\nDepois:\n");
  printf("Inteiro: %d\nPonto flutuante: %.2f\nCaractere: %c\n", integer, floatingPoint, character);
  
  return;
}




int main() {
  
  modVariable();
  
  return 0;
}