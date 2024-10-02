#include <stdio.h>
#include <string.h>

struct pessoa {
  char nome [50];
  char sexo;
  int idade;
};

int main() {
  struct pessoa alunos[66];

  sprintf(alunos[1].nome, "Giovane");
  
  printf("%s\n", alunos[1].nome);
  
  return 0;
}
