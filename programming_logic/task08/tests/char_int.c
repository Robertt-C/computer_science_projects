#include <stdio.h>
#include <string.h>

/*
char Receiver() {
  char character;
  
  scanf("%c", &character);
  
  return character;
}
*/

void Hash() {
  char string0[50], string1[100];
  
  fgets(string0, 50, stdin);
  
  //fputs(string0, stdout);
  
  printf("%s\n", string0);
  
  
  printf("%c\n", string0[3]);
  return;
}


int main() {
  Hash();
  
  return 0;
}