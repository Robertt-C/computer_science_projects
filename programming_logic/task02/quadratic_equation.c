#include <math.h>
#include <stdio.h>

int main() {
  float a, b, c, delta, firstDegree;
  
  scanf("%f%f%f", &a, &b, &c);
  
  delta = pow(b, 2) - 4 * a * c;
  firstDegree = -c/b;
  
  if (a == 0) {
    printf("Raiz: %.2f\n", firstDegree);
  } else if (delta > 0) {
    printf("Raiz 1: %.2f\n", ((-b + sqrt(delta)) / (2 * a)));
    printf("Raiz 2: %.2f\n", ((-b - sqrt(delta)) / (2 * a)));
  } else if (delta == 0) {
    printf("Raiz: %.2f\n", ((-b + sqrt(delta)) / (2 * a)));
  } else {
    printf("Não existem raízes reais\n");
  }
  
  return 0;
}