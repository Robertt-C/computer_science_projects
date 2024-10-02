#include <stdio.h>

int main() {
  int i, num, count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

/*
  Pedimos um número e em cada caso somamos 1 para o contador do
  respectivo caso.
*/
  while (num != 0) {
    scanf("%d", &num);
    
    switch (num) {
      case 1:
        count[0]++;
        break;
      case 2:
        count[1]++;
        break;
      case 3:
        count[2]++;
        break;
      case 4:
        count[3]++;
        break;
      case 5:
        count[4]++;
        break;
      case 6:
        count[5]++;
        break;
      case 7:
        count[6]++;
        break;
      case 8:
        count[7]++;
        break;
      case 9:
        count[8]++;
        break;
    }
  }
  
  printf("O histograma é: %d %d %d %d %d %d %d %d %d\n", count[0], count[1], count[2], count[3], count[4], count[5], count[6], count[7], count[8]);  
}
