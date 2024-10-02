#include <stdio.h>

int main() {
  int decimal, num, rem, base = 1, binary = 0;
  
  scanf("%d", &decimal);
  
  num = decimal;
  
  while (num != 0) {
    rem = num % 2;
    binary += (rem * base);
    num /= 2;
    base *= 10;
  }
  printf("Decimal:%d Binário:%d\n", decimal, binary);
  
  return 0;
}

/*12 / 2 resto 0 binary = 0 + 0 * 1 = 0
6 / 2 resto 0 binary = 0 + 0 * 10 = 0
3 / 2 resto 1 binary = 0 + 1 * 100 = 100
1 / 2 resto 1 binary = 100 + 1 * 1000*/

/*10 / 2 resto 0 binary = 0 + 0 * 1 = 0 
5 / 2 resto 1 binary = 0 + 1 * 10 = 10 
2 / 2 resto 0 binary = 10 + 0 * 100 = 10 
1 / 2 resto 1 binary = 10 + 1 * 1000 = 1010*/
