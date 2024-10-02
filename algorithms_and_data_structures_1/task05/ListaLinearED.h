#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  int RA;
  char nome[30];
  float notas[3];
  int freq;
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  TipoNoh *inicioLista;
  int ultimo;
} ListaLinearED;


int listaVaziaLLED(ListaLinearED*);
void inicializaListaLLED(ListaLinearED*);
void destroiListaLLED(ListaLinearED*);
void imprimeItemLLED(TipoItem);
void imprimeListaLLED(ListaLinearED*);
int insereNoFinalLLED(ListaLinearED*,TipoItem);
int insereNoInicioLLED(ListaLinearED*,TipoItem);
int removeDoFinalLLED(ListaLinearED*,TipoItem*);
int removeDoInicioLLED(ListaLinearED*,TipoItem*);
int buscaItemNaListaLLED(ListaLinearED*,int,TipoItem*,int*);
int verificaIgualdade(TipoItem,int);

void leDadosAluno(TipoItem*);
int adicionaNaPosicao(ListaLinearED*, TipoItem, int);
int retiraDaPosicao(ListaLinearED*, TipoItem*, int);
int retiraEspecifico(ListaLinearED*,TipoItem*, int);