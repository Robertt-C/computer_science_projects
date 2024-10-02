#include "postfix_expression.h"

int main() {
  typeStack numberStack;
  char string[98] = {0};
  int i;
  
  
  printf("Dê-me a expressão posfixa: ");
  scanf("%s", string);
  
  resultStack(&numberStack, string);
  
  printf("Resultado = %d\n", numberStack.top->item);
  
  return 0;
}