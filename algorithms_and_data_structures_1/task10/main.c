#include "ArvoreBinaria.h"

int main(){
  TipoArvore raiz, pai, filhoEsquerdo, filhoDireito;
  
  raiz = inicializaArvore();
  pai = inicializaArvore();
  filhoEsquerdo = inicializaArvore();
  filhoDireito = inicializaArvore();
  
  raiz = instanciaArvore(raiz, 'A');
  
  pai = instanciaArvore(pai, 'B');
  filhoEsquerdo = instanciaArvore(filhoEsquerdo, 'D');
  filhoDireito = instanciaArvore(filhoDireito, 'E');
  
  pai = montaArvore(pai, filhoEsquerdo, filhoDireito);
  
  raiz = insereSubArvoreEsq(raiz, pai);
  
  
  pai = instanciaArvore(pai, 'C');
  filhoEsquerdo = instanciaArvore(filhoEsquerdo, 'F');
  filhoDireito = instanciaArvore(filhoDireito, 'G');
  
  pai = montaArvore(pai, filhoEsquerdo, filhoDireito);
  
  raiz = insereSubArvoreDir(raiz, pai);
  
  printf("\n");
  printf("Pré-ordem: ");
  imprimeArvorePreOrdem(raiz);
  printf("\n");
  
  printf("\n");
  printf("Em ordem: ");
  imprimeArvoreEmOrdem(raiz);
  printf("\n");
  
  printf("\n");
  printf("Pós-ordem: ");
  imprimeArvorePosOrdem(raiz);
  printf("\n");
  
  
  raiz = destroiArvore(raiz);
  
  return 0;
}

/*
          A
       B     C
      D E   F G
*/