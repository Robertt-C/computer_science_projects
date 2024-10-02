#include <stdio.h>

int main() {
  int i, j;
  
  for (i = 0; i <= 10; i++) {
    if (i == 10) {
      printf("Continua");
      continue;
    }
    
    printf("%d\n", i);
  }
  
  return 0;
}