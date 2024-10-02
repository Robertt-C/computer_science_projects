#include <stdio.h>

int main() {
  float money;
  int minus;
  
  scanf("%f", &money);
  
  minus = (int)money;
  
  printf("%d\n", minus);
  
  money = money / 100;
  minus = minus % 100;
  printf("%d nota(s) de R$ 100,00\n", (int)money);
  money = minus / 50;
  minus = minus % 50;
  printf("%d nota(s) de R$ 50,00\n", (int)money);
  money = minus / 20;
  minus = minus % 20;
  printf("%d nota(s) de R$ 20,00\n", (int)money);
  money = minus / 10;
  minus = minus % 10;
  printf("%d nota(s) de R$ 10,00\n", (int)money);
  money = minus / 5;
  minus = minus % 5;
  printf("%d nota(s) de R$ 5,00\n", (int)money);
  money = minus / 2;
  minus = minus % 2;
  printf("%d nota(s) de R$ 2,00\n", (int)money);
  money = minus / 1;
  minus = minus % 1;
  printf("%d nota(s) de R$ 1,00\n", (int)money);
  
  return 0;
}