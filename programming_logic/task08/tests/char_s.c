#include <stdio.h>

int main() {
  char string[100] = {"Arroz       "};
  
  //printf("Arroz %s Arroz Arroz %s Arroz", string, string);
  
  printf("Length: %lu\n", strlen(string));
  
  return 0;
}