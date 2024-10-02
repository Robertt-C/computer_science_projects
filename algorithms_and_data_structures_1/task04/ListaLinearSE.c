#include "ListaLinearSE.h"

int listaVaziaLLSE(ListaLinearSE *lista){
  return lista->ultimo==0;
}

int listaCheiaLLSE(ListaLinearSE *lista){
  return lista->ultimo==MAX;
}

void inicializaLLSE(ListaLinearSE *lista){
  lista->ultimo = 0;
}

void destroiListaLLSE(ListaLinearSE *lista){
  lista->ultimo = 0;
}

void imprimeListaLLSE(ListaLinearSE *lista){
  int i;

  for(i=0;i<lista->ultimo;i++){
    printf("%i %s\n",lista->itens[i].chave,lista->itens[i].nome);
  }
}


int insereNoFinalLLSE(ListaLinearSE *lista, TipoItem novoItem){
  int pos = lista->ultimo;

  if(!listaCheiaLLSE(lista)){
    lista->itens[pos] = novoItem;
    lista->ultimo++;
    return 1;
  }
  else
    return 0;
}

int insereNoInicioLLSE(ListaLinearSE *lista, TipoItem novoItem){
  int pos = lista->ultimo;
  int i;

  if(!listaCheiaLLSE(lista)){
    for(i=pos;i>0;i--)
      lista->itens[i] = lista->itens[i-1];
    lista->itens[0] = novoItem;
    lista->ultimo++;
    return 1;
  }
  else
    return 0;
}

int removeDoFinalLLSE(ListaLinearSE *lista,TipoItem *item){
  int pos = lista->ultimo;

  if(!listaVaziaLLSE(lista)){
    item->chave = lista->itens[pos-1].chave;
    strcpy(item->nome,lista->itens[pos-1].nome);
    lista->ultimo--;
    return 1;
  }
  else
    return 0;
}

int removeDoInicioLLSE(ListaLinearSE *lista, TipoItem *item){
  int pos = lista->ultimo;
  int i;
  
  if(!listaVaziaLLSE(lista)){
    item->chave = lista->itens[0].chave;
    strcpy(item->nome,lista->itens[0].nome);
    for(i=1;i<pos;i++){
      lista->itens[i-1] = lista->itens[i];
    }
    lista->ultimo--;
    return 1;
  }
  else
    return 0;
}



/*
int adicionaNaPosicao(ListaLinearSE *lista, TipoItem novoItem, int posicao) {
  int i, ultimo = lista->ultimo;
  
  if (listaVaziaLLSE(lista)) {
    insereNoInicioLLSE(lista, novoItem);
    return 1;
  } else if (listaCheiaLLSE(lista)) {
    return 0;
  } else {
    for (i = ultimo; i > posicao - 1; i--) {
      lista->itens[i] = lista->itens[i - 1];
    }
    lista->itens[posicao - 1] = novoItem;
    lista->ultimo++;
  }
  
  return 1;
}

*/

int adicionaNaPosicao(ListaLinearSE *lista, TipoItem novoItem, int posicao) {
  int i, j = 0, k = 1, ultimo = lista->ultimo;
  
  if (!listaVaziaLLSE(lista) && !listaCheiaLLSE(lista)) {
      for (i = posicao - 1; i < ultimo; i++, j--, k++) {
        lista->itens[ultimo+j] = lista->itens[ultimo-k];
      }
      
      lista->itens[posicao-1] = novoItem;
      lista->ultimo++;
      
      return 1;
    }
    
  return 0;
}


int retiraDaPosicao(ListaLinearSE *lista, TipoItem *item, int posicao) {
  int i, ultimo = lista->ultimo;
  
  item->chave = lista->itens[posicao-1].chave;
  strcpy(item->nome, lista->itens[posicao-1].nome);
  
  if (!listaVaziaLLSE(lista)) {
    for (i = posicao - 1; i < ultimo - 1; i++) {
      lista->itens[i] = lista->itens[i+1];
    }
    
    lista->ultimo--;
    
    return 1;
  }
  
  return 0;
}


int retiraEspecifico(ListaLinearSE *lista, TipoItem *item, char nome[50]) {
  int i, posicao, ultimo = lista->ultimo;
  
  for (i = 0; i < ultimo; i++) {
    if (strcmp(nome, lista->itens[i].nome) == 0) {
      posicao = i;
      break;
    }
  }
  
  item->chave = lista->itens[posicao].chave;
  strcpy(item->nome, lista->itens[posicao].nome);
  
  if (!listaVaziaLLSE(lista)) {
    for (i = posicao; i < ultimo - 1; i++) {
      lista->itens[i] = lista->itens[i+1];
    }
    
    lista->ultimo--;
    
    return 1;
  }
  
  return 0;
}



/* Lucas
int RetiraEspecifico(ListaLinearSE *lista, int chave, char nome) {
  int pos = lista->ultimo;
  int i, k;

  if (!listaVaziaLLSE(lista)) {
    for (k = 0; k < lista->ultimo; k++) {
      if (lista->itens[k].chave == chave) {
        if (strcmp(lista->itens[k].nome, &nome) == 0) {
          for (i = k; i < lista->ultimo; i++) {
            lista->itens[i - 1] = lista->itens[i];
          }
        }
        lista->ultimo--;
        break;
      }
      break;
      return 1;
    }
  } else {
    return 0;
  }
}


int RetiraDaPosicao(ListaLinearSE *lista, int posN) {
  int pos = lista->ultimo;
  int i;

  if (!listaVaziaLLSE(lista)) {
    for (i = posN; i < pos; i++) {
      lista->itens[i - 1] = lista->itens[i];
    }
    lista->ultimo--;
    return 1;
  } else {
    return 0;
  }
}
*/