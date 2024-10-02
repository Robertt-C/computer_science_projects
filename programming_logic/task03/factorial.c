#include <stdio.h>

int main() {
  int num, count, factorial;
  
  scanf("%d", &num);
  count = 1;
  factorial = 1;
  if (num > 0) {
    while (count <= num) {
      factorial *= count;
      count++;
    }
    printf("O fatorial de %d é: %d\n", num, factorial);
  } else if (num == 0 || num == 1) {
    printf("O fatorial de %d é: 1\n", num);
  } else if (num < 0) {
    printf("Não existe fatorial de %d\n", num);
  }
  
  return 0;
}