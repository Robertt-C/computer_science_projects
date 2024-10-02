#include "ArvoreBinaria.h"

int arvoreVazia(TipoArvore arvore){
  return arvore==NULL;
}

TipoArvore inicializaArvore(){
  return NULL;
}

TipoArvore destroiArvore(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
    destroiArvore(arvore->subArvoreEsq);
    destroiArvore(arvore->subArvoreDir);
    free(arvore);
  }
  return NULL;
}

TipoArvore instanciaArvore(TipoArvore arvore,char dado){
  arvore = (TipoArvore) malloc(sizeof(TipoNohArvore));
  arvore->subArvoreEsq = NULL;
  arvore->subArvoreDir = NULL;
  arvore->dado = dado;
  return arvore;
}

TipoArvore insereSubArvoreEsq(TipoArvore raiz,TipoArvore subArvoreEsq){
  if(!arvoreVazia(raiz)){
    raiz->subArvoreEsq = subArvoreEsq;
    return raiz;
  }
  return NULL;
}

TipoArvore insereSubArvoreDir(TipoArvore raiz,TipoArvore subArvoreDir){
  if(!arvoreVazia(raiz)){
    raiz->subArvoreDir = subArvoreDir;
    return raiz;
  }
  return NULL;
}

TipoArvore montaArvore(TipoArvore raiz,TipoArvore subArvoreEsq,TipoArvore subArvoreDir){
  if(!arvoreVazia(raiz)){
    raiz->subArvoreEsq = subArvoreEsq;
    raiz->subArvoreDir = subArvoreDir;
    return raiz;
  }
  return NULL;
}




void imprimeArvorePreOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    printf("%c ", arvore->dado);
    imprimeArvorePreOrdem(arvore->subArvoreEsq);
    imprimeArvorePreOrdem(arvore->subArvoreDir);
  }
};


void imprimeArvoreEmOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvoreEmOrdem(arvore->subArvoreEsq);
    printf("%c ", arvore->dado);
    imprimeArvoreEmOrdem(arvore->subArvoreDir);
  }
}


void imprimeArvorePosOrdem(TipoArvore arvore) {
  if (!arvoreVazia(arvore)) {
    imprimeArvorePosOrdem(arvore->subArvoreEsq);
    imprimeArvorePosOrdem(arvore->subArvoreDir);
    printf("%c ", arvore->dado);
  }
}



/*
          A
       B     C
      D E   F G

 Pré-ordem: A B D E C F G

 Em ordem: D B E A F C G

 Pós-ordem: D E B F G C A
 
*/