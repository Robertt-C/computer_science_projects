#include <stdio.h>
#include <string.h>


int main() {
  char string[3] = {"AAA"};
  char string1[3] = {"AAA"};
  
  if (string == string1) {
    printf("Ok");
  }
  
  return 0;
}