#include <stdio.h>
#include <string.h>

#define MAX 100

struct info {
  char nome[MAX];
  int ra;
  float nota;
  int frequencia;
};


void stringCompare() {
  char string1[10], string2[20] = {"ajej"};
  
  printf("%s\n", string2);
  
  scanf("%s", string1);
  scanf("%s", string2);
  
  if (strcmp(string1, string2) == 0) {
    printf("Iguais\n");
  } else {
    printf("Não iguais");
  }
  
  return;
}

void checkingStruct() {
  struct info personalInfo[MAX] = {0};
  char cleaner[1] = {""};
  
  printf("1: %s\n", personalInfo[0].nome);
  
  scanf("%s", personalInfo[0].nome);
  
  printf("2: %s\n", personalInfo[0].nome);
  
  strcpy(personalInfo[0].nome, cleaner);
  
  printf("3: %s\n", personalInfo[0].nome);
  
  return;
}



int main() {
  struct info personalInfo[MAX] = {0};
  char cleaner[1] = {""};
  
  if (strcmp(personalInfo[0].nome, cleaner) == 0) {
    printf("Mesma coisa\n");
  }
  
  personalInfo[0].nota = 0.0;
  
  printf("%f\n", personalInfo[0].nota);
  
  return 0;
}