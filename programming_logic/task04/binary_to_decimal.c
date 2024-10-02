#include <stdio.h>

int main() {
  int num, binary_num, decimal_num = 0, base = 1, rem;
  
  scanf ("%d", &num);
  
  binary_num = num;
  
  while (num > 0) {
    rem = num % 10;
    decimal_num = decimal_num + (rem * base);
    num = num / 10;
    base = base * 2;
  }
  printf("Binário:%d Decimal:%d\n", binary_num, decimal_num);
}

/*1010 101 resto 0 dec_num = 0 + 0 * 1 = 0
101 10 resto 1 dec_num = 0 + 1 * 2 = 2
10 1 resto 0 dec_num = 2 + 0 * 4 = 8*/