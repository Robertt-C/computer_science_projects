#include <stdio.h>
#include <string.h>

int main() {
  char string[1000];
  int i;
  
  fgets(string, 1000, stdin);
  
  for (i = 0; i < strlen(string); i++) {
    printf("%c ", string[i]);
    printf("%d\n", string[i]);
  }
  
  printf("\n");
  
  scanf("%s", string);
  
  for (i = 0; i < strlen(string); i++) {
    printf("%c ", string[i]);
    printf("%d\n", string[i]);
  }
  
  
  return 0;
}