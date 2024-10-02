#include <stdio.h>

int Receber_tamanho_matrizes(int tamanho){
  scanf("%d", &tamanho);
  return tamanho;
}

void Receber_matrizes(int l, int c, int tamanhoLinha, int tamanhoColuna, int mat[l][c]){
  for(l = 0; l < tamanhoLinha; l++){
    for(c = 0; c < tamanhoColuna; c++){
      scanf("%d", &mat[l][c]);
    }
  }
  return;
}

void Imprimir_matrizes(int l, int c, int tamanhoLinha, int tamanhoColuna, int mat[l][c]){
  printf("\nMatriz 1 (%dx%d)", l, c);
  for(l = 0; l < tamanhoLinha; l++){
    printf("\n");
    for(c = 0; c < tamanhoColuna; c++){
      printf("%d", mat[l][c]);
    }
  }
  return;
}

void Calculo_Matriz_Mult(int l1, int l2, int c1, int c2, int tamanhoLinha1, int tamanhoLinha2, int tamanhoColuna1, int tamanhoColuna2, int matA[l1][c1], int matB[l2][c2], int matC[l1][c2], int auxLinha2){
  int k;
  
  for (l1 = 0; l1 < tamanhoLinha1; l1++) {
    for (c2 = 0; c2 < tamanhoColuna2; c2++) {
      matC[l1][c2] = 0;
      for (k = 0; k < tamanhoLinha2; k++) {
        matC[l1][c2] += matA[l1][k]*matB[k][c2];
      }
    }
  }
  
  /*
  for(l1 = 0; l1 < tamanhoLinha1; l1++){
    for(c2 = 0; c2 < tamanhoColuna2; c2++){
      matC[l1][c2] += (matA[l1][c2])*(matB[l1][c2]);
      for(auxLinha2 = l1 + 1; auxLinha2 < tamanhoLinha2; auxLinha2++){
        matC[l1][c2] += (matA[l1][(c2)+1])*(matB[auxLinha2][c2]);
      }
    }
  }
  */
  
  return;
}

void Imprimir_Matriz_Mult(int l1, int auxlinhaC, int c2, int auxcolunaC, int matC[l1][c2]){
  printf("Matriz 1 * Matriz 2 (%dx%d)", l1, c2);
  for(l1 = 0; l1 < auxlinhaC; l1++){
    printf("\n");
    for(c2 = 0; c2 < auxcolunaC; c2++){
      printf("%d", matC[l1][c2]);
    }
  }
  return;
}

int main() {
  int m, n1, n2, o, tamanho;
  int matA[500][500] = {0}, matB[500][500] = {0}, matC[500][500] = {0};
  int l1, c1, l2, c2, auxlinhaB, auxlinhaC, auxcolunaC;

  m = Receber_tamanho_matrizes(tamanho);
  l1 = m;
  n1 = Receber_tamanho_matrizes(tamanho);
  c1 = n1;

  n2 = Receber_tamanho_matrizes(tamanho);
  l2 = n2;
  o = Receber_tamanho_matrizes(tamanho);
  c2 = o;

  if(n1 == n2){
    
    auxlinhaC = m;
    auxcolunaC = o;
    
    Receber_matrizes(m, n1, l1, c1, matA);
    Receber_matrizes(n1, o, l2, c2, matB);
    
    Imprimir_matrizes(m, n1, l1, c1, matA);
    Imprimir_matrizes(n2, o, l2, c2, matB);

    Calculo_Matriz_Mult(m, n2, n1, o, l1, l2, c1, c2, matA, matB, matC, auxlinhaB);

    Imprimir_Matriz_Mult(l1, auxlinhaC, c2, auxcolunaC, matC);
    
  }else{
    printf("Não é possível realizar a operação, pois as matrizes não seguem a regra MxN, NxO = MxO.");
  }

  return 0;
}