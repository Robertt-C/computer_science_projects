/*
1 Crie um tipo de registro que contenha os seguintes
campos: Nome, RA, nota e frequencia;

2 Crie um vetor de variaveis deste registro;

3 Faca um programa que permita inserir remover, visualizar
e buscar elementos do registro pelo RA.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 30
#define MAX 100

struct data {
  int dia;
  int mes;
  int ano;
};

struct info {
  char nome[NAME_MAX];
  struct data dataNascimento;
  int ra;
  float notas[3];
  int frequencia;
};


int checarAluno(struct info turma[]) {
  char vazio[1] = {""};
  int i;
  
  for (i = 0; i < MAX; i++) {
    if (turma[i].ra == 0 && strcmp(turma[i].nome, vazio) == 0) {
      return i;
    }
  }
  return 0;
}


int pegarRa() {
  int ra;
  
  printf("\nDê-me o RA: \n");
  scanf("%d", &ra);
  
  return ra;
}


void exibirInformacoesAluno(struct info turma[], int indice) {
  int i, length = 40;
  
  for (i = 0; i < length; i++) {
    if (i == 0) {
      printf("\n");
    }
    
    printf("-");
  }

  printf("\nNome: %s\n", turma[indice].nome);
  printf("Data de nascimento: %d/%d/%d\n", turma[indice].dataNascimento.dia, turma[indice].dataNascimento.mes, turma[indice].dataNascimento.ano);
  printf("RA: %d\n", turma[indice].ra);
  for (i = 0; i < 3; i++) {
    printf("Nota[%d]: %.2f\n", i + 1, turma[indice].notas[i]);
  }
  printf("Frequência: %d\n", turma[indice].frequencia);
  
  for (i = 0; i < length; i++) {
    printf("-");
    
    if (i == length - 1) {
      printf("\n");
    }
  }
  
  return;
}

//==============================================================================
//==============================================================================

void pegarInfoAluno(struct info turma[]) {
  int i, indice = checarAluno(turma);
  
  if (indice >= 0) {
    getchar();
    printf("\nInsira o nome do Aluno: \n");
    fgets(turma[indice].nome, sizeof(turma[indice].nome), stdin);
    turma[indice].nome[strlen(turma[indice].nome) - 1] = '\0';
    //scanf("%s", turma[indice].nome);
    
    printf("\nInsira a data de nascimento: \n");
    
    printf("Dia: \n");
    scanf("%d", &turma[indice].dataNascimento.dia);
    
    printf("Mês: \n");
    scanf("%d", &turma[indice].dataNascimento.mes);
    
    printf("Ano: \n");
    scanf("%d", &turma[indice].dataNascimento.ano);
    
    printf("Insira o RA do Aluno: \n");
    scanf("%d", &turma[indice].ra);
    
    for (i = 0; i < 3; i++) {
      printf("Insira a nota %d do Aluno: \n", i + 1);
      scanf("%f", &turma[indice].notas[i]);
    }
    
    printf("Insira a frequência do Aluno: \n");
    scanf("%d", &turma[indice].frequencia);
  }
  return;
}


void removerAluno(struct info turma[]) {
  char vazio[1] = {""};
  int indice, ra = pegarRa();
  
  for (indice = 0; indice < MAX; indice++) {
    if (turma[indice].ra == ra) {
      strcpy(turma[indice].nome, vazio);
      turma[indice].ra = 0;
      turma[indice].notas[0] = 0.0;
      turma[indice].notas[1] = 0.0;
      turma[indice].notas[2] = 0.0;
      turma[indice].frequencia = 0;
      
      printf("\nAluno removido com sucesso.\n");
      
      break;
    } else if (indice == MAX - 1 && turma[indice].ra != ra) {
      printf("\nAluno não removido, esse não está nesta lista.\n");
    }
  }
  return;
}


void listarAlunos(struct info turma[]) {
  int i, cont = 0;
  
  for (i = 0; i < MAX; i++) {
    if (turma[i].ra != 0) {
      exibirInformacoesAluno(turma, i);
      cont++;
    } else if (cont == 0 && i == MAX - 1) {
      printf("\nA lista está vazia!\n");
    }
  }
  return;
}


void buscarAluno(struct info turma[]) {
  int i, ra = pegarRa();
  
  for (i = 0; i < MAX; i++) {
    if (turma[i].ra == ra) {
      exibirInformacoesAluno(turma, i);
      break;
    } else {
      printf("\nAluno não encontrado no sistema.\n");
      break;
    }
  }
  return;
}


void sair() {
  printf("Obrigado.\n");
  
  return;
}


void mostrarMenu(){
  int i, length = 20;
  
  for (i = 0; i < length; i++ ) {
    if (i == 0) {
      printf("\n");
    }
    printf("-");
  }
  
  printf("\n1 - Inserir Aluno. |");
  printf("\n2 - Remover Aluno. |");
  printf("\n3 - Listar Alunos. |");
  printf("\n4 - Buscar Aluno.  |");
  printf("\n5 - Sair.          |\n");
  
  for (i = 0; i < length; i++ ) {
    printf("-");
    
    if (i == length - 1) {
      printf("\n");
    }
  }
  
  return;
}




int main() {
  struct info turma[MAX] = {0};
  int opcao;
  
  do {
    mostrarMenu();
    
    printf("\nOpção: \n");
    scanf("%d", &opcao);
    
    switch (opcao) {
      case 1:
        pegarInfoAluno(turma);
        break;
      case 2:
        removerAluno(turma);
        break;
      case 3:
        listarAlunos(turma);
        break;
      case 4:
        buscarAluno(turma);
        break;
      case 5:
        sair();
        break;
      default:
        printf("\nOpção Inválida.\n---------------\n");
        break;
    }
  } while (opcao != 5);
  
  return 0;
}