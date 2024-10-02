#include <stdio.h>

int main() {
  int num, i, result = 0;
  
  scanf("%d", &num);
    
  i = 2;
  while (i <= num / 2) {
    if (num % i == 0) {
      result++;
      break;
    }
    i++;
  }
  
  if (num == 0 || num == 1) {
    printf("O número %d não é primo!\n", num);
  } else if (result == 0) {
    printf("O número %d é primo!\n", num);
  } else {
    printf("O número %d não é primo!\n", num);
  }
    
   return 0;
}

  /* wrong tentative
  int num, divider, warn;
  
  scanf("%d", &num);
  
  warn = 0;
  divider = 1;
  
  while (num) {
    warn = num%divider;
    divider++;
    if (num%divider == 0) {
      printf("O número %d não é primo!\n", num);
    } else if (num%divider == 1) {
      printf("O número %d é primo!\n", num);
    }
  }
  
  if (num%2 == 1) {
    printf("O número %d é primo!\n", num);
  } else ("O número %d não é primo!\n", num);
  
  if (num == 2) {
    printf("O número %d é primo!\n", num);
  } else if (num == 0 || num == 1) {
    printf("O número %d não é primo!\n", num);
  }
  
  return 0;
}

*/