#include <stdio.h>

int Flag(int i, int j) {
  if (i != j) {
    return 0;
  }
  return 0;
}

int main() {
  int i = 10, j = 20;
  
  if (Flag(i, j)) {
    printf("Não\n");
    return 0;
  }
}