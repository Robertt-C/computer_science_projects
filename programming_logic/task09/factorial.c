#include <stdio.h>

int Input() {
  int num;
  scanf("%d", &num);
  return num;
}

int Factorial(int num) {
  if (num == 0) {
    return 1;
  } else {
    return num * Factorial(num - 1);
  }
  
  return 0;
}

void Printer() {
  int num, factorial;
  
  num = Input();
  
  if (num >= 0) {
    printf("O fatorial de %d é: %d\n", num, Factorial(num));
  } else if (num < 0) {
    printf("Não existe fatorial de %d\n", num);
  }
  
  return;
}


int main() {
  
  Printer();
  
  return 0;
}