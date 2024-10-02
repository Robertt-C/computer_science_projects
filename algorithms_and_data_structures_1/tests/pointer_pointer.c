#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int *pA, **pB, ***pC, A = 1, B = 2, C = 3;
  
  pC = &pB;
  pB = &pA;
  pA = &A;
  
  printf("pA: %d\npB: %d\npC: %d\n", *pA, **pB, ***pC);
  printf("Address of pA: %p\nAddress of pB: %p\nAddress of pC: %p\n", pA, pB, pC);
  
  return 0;
}