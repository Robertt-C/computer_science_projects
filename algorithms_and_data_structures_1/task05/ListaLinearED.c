#include "ListaLinearED.h"

int listaVaziaLLED(ListaLinearED *lista){
  return lista->ultimo==0;
}

void inicializaListaLLED(ListaLinearED *lista){
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void destroiListaLLED(ListaLinearED* lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void imprimeItemLLED(TipoItem item){
  int i;
  printf("\nRa: %i",item.RA);
  printf("\nNome: %s",item.nome);
  for(i=0;i<3;i++){
    printf("\nNota %i: %.1f",i+1,item.notas[i]);
  }
  printf("\nFrequencia: %i\n",item.freq);
}

void imprimeListaLLED(ListaLinearED *lista){
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    while(ptrAux != NULL){
      imprimeItemLLED(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
  }
}
/*
int insereNoFinalLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh, *ptrAux;
  
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    
    if(!listaVaziaLLED(lista)){
      while(ptrAux->prox != NULL)
        ptrAux = ptrAux->prox;
      ptrAux->prox = novoNoh;
    }
    else{
      lista->inicioLista = novoNoh;
    }
    
    novoNoh->item = item;
    novoNoh->prox = NULL;
    lista->ultimo++;
    return 1;
  }
  return 0;
}
*/




int insereNoFinalLLED(ListaLinearED *lista,TipoItem item) {
  TipoNoh *ptrAux, *novoNoh;
  
  if (listaVaziaLLED(lista)) {
    insereNoInicioLLED(lista, item);
    return 1;
  } else {
    novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
    
    ptrAux = lista->inicioLista;
    
    if (novoNoh != NULL) {
      while (ptrAux->prox != NULL) {
        ptrAux = ptrAux->prox;
      }
      
      ptrAux->prox = novoNoh;
      novoNoh->prox = NULL;
      novoNoh->item = item;
      lista->ultimo++;
    }
    
    return 1;
  }
  
  return 0;
}




int insereNoInicioLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh;

  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  
  if(novoNoh != NULL){
    novoNoh->item = item;
    novoNoh->prox = lista->inicioLista;
    lista->inicioLista = novoNoh;
    lista->ultimo++;
    return 1;
  }
  return 0;
}


int removeDoFinalLLED(ListaLinearED *lista,TipoItem *item){
  TipoNoh *ptrAux1, *ptrAux2;
  
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL){
      lista->inicioLista = NULL;
      *item = ptrAux1->item;
      free(ptrAux1);
    } else {
      while(ptrAux2->prox != NULL){
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      ptrAux1->prox = NULL;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    lista->ultimo--;
    return 1;
  }
  return 0;
}


/* ////==== erro embaixo 
int removeDoFinalLLED(ListaLinearED *lista,TipoItem *item) {
  TipoNoh *ptrAux1, *ptrAux2;
  
  if (!listaVaziaLLED(lista)) {
    ptrAux1 = lista->inicioLista;
    ptrAux2 = lista->inicioLista->prox;
    
    while (ptrAux2 != NULL) {
      ptrAux1 = ptrAux1->prox;
      ptrAux2 = ptrAux2->prox;
    }
    
    free(ptrAux1);
    ptrAux1->prox = NULL;
    lista->ultimo--;
    *item = ptrAux1->item;
    
    return 1;
  }
  
  return 0;
}
*/


/*
int removeDoInicioLLED(ListaLinearED *lista, TipoItem *item){
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    *item = ptrAux->item;
    lista->inicioLista = ptrAux->prox;
    free(ptrAux);
    lista->ultimo--;
    return 1;
  }
  return 0;
}*/




int removeDoInicioLLED(ListaLinearED *lista, TipoItem *item) {
  TipoNoh *ptrAux;
  
  if (!listaVaziaLLED(lista)) {
    *item = lista->inicioLista->item;
    
    ptrAux = lista->inicioLista;
    lista->inicioLista = lista->inicioLista->prox;
    
    free(ptrAux);
    lista->ultimo--;
    
    return 1;
  }
  
  return 0;
}




int buscaItemNaListaLLED(ListaLinearED *lista,int info,TipoItem *item,int *pos){
  TipoNoh *ptrAux;
  int cont=1;
  
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    while(ptrAux!=NULL){
      if(verificaIgualdade(ptrAux->item,info)){
        *item = ptrAux->item;
        *pos = cont;
        return 1;
      }
      cont++;
      ptrAux = ptrAux->prox;
    }
  }
  return 0;
}

int verificaIgualdade(TipoItem item,int info){
  if(item.RA==info)
    return 1;
  return 0;
}






void leDadosAluno(TipoItem *item){
  int i;
  printf("\nRA: ");
  scanf("%i",&item->RA);
  getchar();
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
  for(i=0;i<3;i++){
    printf("Nota %i: ", i+1);
    scanf("%f",&item->notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&item->freq);
  
  return;
}


int adicionaNaPosicao(ListaLinearED *lista, TipoItem item, int posicao) {
  TipoNoh *novoNoh, *ptrAux;
  int i;
  
  if (posicao > lista->ultimo) {
    posicao = lista->ultimo + 1;
  }
  
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  
  ptrAux = lista->inicioLista;
  
  if (novoNoh != NULL && posicao == 1) {
    insereNoInicioLLED(lista, item);
    
  } else if (novoNoh != NULL && posicao == lista->ultimo + 1) {
    insereNoFinalLLED(lista, item);
    
  } else if (novoNoh != NULL) {
    for (i = 2; i < posicao; i++) {
      if (ptrAux != NULL) {
        ptrAux = ptrAux->prox;
      }
    }
    
    novoNoh->prox = ptrAux->prox;
    ptrAux->prox = novoNoh;
    
    lista->ultimo++;
    return 1;
  }
  return 0;
}

/*
int retiraDaPosicao(ListaLinearED *lista, TipoItem *item, int posicao) {
  TipoNoh *ptrAux1, *ptrAux2;
  int i;
  
  if (posicao > lista->ultimo) {
    posicao = lista->ultimo;
    removeDoFinalLLED(lista, item);
    return 1;
  } else if (posicao == 1) {
    removeDoInicioLLED(lista, item);
    return 1;
  }
  
  
  ptrAux1 = lista->inicioLista;
  
  if (!listaVaziaLLED(lista)) {
    for (i = 2; i < posicao; i++) {
      ptrAux1 = ptrAux1->prox;
    }
    
    ptrAux2 = ptrAux1->prox;
    *item = ptrAux2->item;
    free(ptrAux2);
    
    ptrAux1->prox = ptrAux1->prox->prox;
    
    lista->ultimo--;
    return 1;
  }
  return 0;
}
*/



int retiraDaPosicao(ListaLinearED *lista, TipoItem *item, int posicao) {
  TipoNoh *ptrAux1, *ptrAux2;
  int i;
  
  if (!listaVaziaLLED(lista)) {
    ptrAux1 = lista->inicioLista;
    
    for (i = 0; i < posicao - 2; i++) {
      ptrAux1 = ptrAux1->prox;
    }
    
    ptrAux2 = ptrAux1->prox;
    ptrAux1->prox = ptrAux1->prox->prox;
    
    *item = ptrAux2->item;
    
    free(ptrAux2);
    lista->ultimo--;
    
    return 1;
  }
  
  return 0;
}
     p1    p2
     1     2     3     4
i -> |p -> |p -> |p -> |p -> null



int retiraEspecifico(ListaLinearED *lista, TipoItem *item, int RA) {
  TipoNoh *ptrAux1;
  int i, cont, ultimo = lista->ultimo;
  
  ptrAux1 = lista->inicioLista;
  
  for (i = 0; i < ultimo; i++) {
    if (ptrAux1->item.RA == RA) {
      cont = i + 1;
      break;
    }
    ptrAux1 = ptrAux1->prox;
  }
  
  
  if (retiraDaPosicao(lista, item, cont)) {
    return 1;
  }
  
  return 0;
}