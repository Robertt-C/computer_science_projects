#include <stdio.h>

int main() {
  int a, b, c;
  
  scanf("%d %d %d", &a, &b, &c);
  
  if (a + b < c || a + c < b || b + c < a) {
    printf("Não é possível formar um triângulo\n");
  }
  
  if (a + b > c && a + c > b && b + c > a) {
    if (a == b && b == c) {
      printf("O triângulo é equilátero\n");
    } else if (a != b && a != c && b != c) {
      printf("O triângulo é escaleno\n");
    } else {
      printf("O triângulo é isóceles\n");
    }
  }
  
  return 0;
}