#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  int year;
  int month;
  int day;
} date;

typedef struct {
  char name[MAX];
  date birthday;
  int id;
} personalInfo;


void getUserData(personalInfo*);
void printUserData(personalInfo*);

int main() {
  personalInfo *info;
  
  getUserData(info);
  printUserData(info);
  
  return 0;
}




void getUserData(personalInfo *data) {
  printf("Dê-me o nome: ");
  fgets(data->name, MAX, stdin);
  
  printf("Data de nascimento.\n");
  printf("Dê-me o dia: ");
  scanf("%d", &data->birthday.day);
  
  printf("Dê-me o mês: ");
  scanf("%d", &data->birthday.month);
  
  printf("Dê-me o ano: ");
  scanf("%d", &data->birthday.year);
  
  printf("Dê-me o CPF: ");
  scanf("%d", &data->id);
  
  return;
}


void printUserData(personalInfo *data) {
  
  printf("\n\n---Dados---\n");
  
  printf("Nome: %s", data->name);
  printf("Data de nascimento.\nDia: %d\nMês: %d\nAno: %d\n", data->birthday.day, data->birthday.month, data->birthday.year);
  printf("Cadastro de Pessoa Física: %d\n", data->id);
  
  return;
}