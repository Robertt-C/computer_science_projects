#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaLinearSE.h"

int main(){
  ListaLinearSE lista;
  TipoItem item;
  int i, posicao, n;
  char string[50];
  
  inicializaLLSE(&lista);
  
  printf("Número de itens a serem inseridos: ");
  scanf("%i",&n);
  for(i=0;i<n;i++){
    printf("Item %i\n",i+1);
    printf("Chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("Nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    item.nome[strlen(item.nome)-1] = '\0';
    if(!insereNoInicioLLSE(&lista,item)){
      printf("Erro! Tamanho limite excedido!\n");
      break;
    }
  }
  
  if(!listaVaziaLLSE(&lista)){
    printf("\nItens na lista:\n");
    imprimeListaLLSE(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }
  
  if(!removeDoFinalLLSE(&lista,&item)){
    printf("Erro! Lista Vazia!\n");
  }
  printf("\nItem removido: %i %s",item.chave,item.nome);

  if(!listaVaziaLLSE(&lista)){
    printf("\nItens na lista:\n");
    imprimeListaLLSE(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }
  
  if(!removeDoInicioLLSE(&lista,&item)){
    printf("Erro! Lista Vazia!\n");
  }
  printf("\nItem removido: %i %s",item.chave,item.nome);

  if(!listaVaziaLLSE(&lista)){
    printf("\nItens na lista:\n");
    imprimeListaLLSE(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }






  printf("Dê-me a posição a inserir: ");
  scanf("%d", &posicao);
  printf("Chave: ");
  scanf("%d", &item.chave);
  getchar();
  printf("Nome: ");
  fgets(item.nome,sizeof(item.nome),stdin);
  item.nome[strlen(item.nome)-1] = '\0';
  
  if (!adicionaNaPosicao(&lista, item, posicao)) {
    printf("Erro na inserção!\n");
  }
  
  if(!listaVaziaLLSE(&lista)){
    printf("\nItens na lista:\n");
    imprimeListaLLSE(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }
  
  
  printf("Dê-me a posição a retirar: ");
  scanf("%d", &posicao);
  if (!retiraDaPosicao(&lista, &item, posicao)) {
    printf("Erro na remoção!\n");
  }
  printf("Item %s removido da posição: %d\n", item.nome, item.chave);

  
  if(!listaVaziaLLSE(&lista)){
    printf("\nItens na lista:\n");
    imprimeListaLLSE(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }
  
  
  printf("Dê-me o nome do item a remover: ");
  scanf("%s", string);
  
  if (!retiraEspecifico(&lista, &item, string)) {
    printf("Erro na remoção!\n");
  }
  printf("Item %s removido da posição: %d\n", item.nome, item.chave);
  
  if(!listaVaziaLLSE(&lista)){
    printf("\nItens na lista:\n");
    imprimeListaLLSE(&lista);  
  }
  else{
    printf("\nLista Vazia.\n");
  }
  
  
  
  /*
  for (i = 0; i < 12; i++) {
    printf("Chave: %d, Item: %s\n", lista.itens[i].chave, lista.itens[i].nome);
  }
  
  printf("ultimo = %d\n", lista.ultimo);
  */
  
  return 0;
}