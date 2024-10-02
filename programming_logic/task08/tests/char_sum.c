#include <stdio.h>
#include <string.h>

int main() {
  int i, sum = 0;
  char string[100] = {" "};
  
  //printf("%s\n", string); 558
  
  for (i = 0; i < strlen(string); i++) {
    sum += string[i];
    printf("%d\n", i);
  }
  
  printf("%d\n", sum);
  
  return 0;
}