#include <stdio.h>

/*
int Imprime_Caminho(int atual, int parada) {
  printf("<entrei> Imprime_Caminho(atual:%d,parada:%d);\n", atual, parada);
  if(atual == parada) {
    printf("Cheguei no caso base!\n");
    printf("Na função recursiva - Atual:%d Parada:%d\n", atual, parada);
    return atual;
  }
  else {
    printf("Na função recursiva - Atual:%d Parada:%d\n", atual, parada);
    Imprime_Caminho(atual+1, parada);
  }
  return 0;
}
*/

int Imprime_Caminho_Inverso(int atual, int parada) {
  printf("<entrei> Imprime_Caminho_Inverso(atual:%d,parada:%d);\n", atual, parada);
  if(atual == parada) {
    printf("Cheguei no caso base!\n");
    printf("\\\\\\\\\\\\\\\n");
    printf("Na função recursiva - Atual:%d Parada:%d\n", atual, parada);
    return -1; //atual;
  } else {
    Imprime_Caminho_Inverso(atual+1, parada);
    printf("////////\n");
    printf("Na função recursiva - Atual:%d Parada:%d\n", atual, parada);
  }
  return 0;
}



int main() {
  int atual,
  parada,
  ultimo = 0,
  ultimob = 0;

  printf("Iniciar as chamadas da função recursiva.\n");
  atual = 1;
  parada = 10;
  
/*
  ultimo = Imprime_Caminho(atual, parada);
  printf("De volta na função main - Atual:%d Parada:%d\n", ultimo, parada);
*/

  ultimob = Imprime_Caminho_Inverso(atual, parada);
  printf("De volta na função main - Atual:%d Parada:%d\n", ultimob, parada);

  return 0;
}