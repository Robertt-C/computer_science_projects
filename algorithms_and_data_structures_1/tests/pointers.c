#include <stdio.h>

void sumPointer() {
  /*
  int *p = 2000;
  
  *p++;
  
  printf("%d\n", *p);
  */
  return;
}


void arrayAccess() {
  int vetor[100],*p, i;
  
  for(i=0; i<100; i++)
    vetor[i] = i*2;
  for(i=0, p=vetor; i<100; i++, p++)
    printf("%d: %d\n",i,*p); 
   //*p => equivalente a acessar vetor[i]
  p = vetor + 10;
  printf("%d\n",*p); //*p => equivalente a acessar vetor[10]
  
  return;
}



int main() {
  
  arrayAccess();
  
  return 0;
}