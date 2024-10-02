#include "postfix_to_infix.h"

int main() {
  typeStack postfixStack;
  char postfixExpression[MAX], *infixExpression;
  
  printf("Dê-me a expressão pós-fixa: ");
  scanf("%s", postfixExpression);
  
  infixExpression = createInfixExpression(&postfixStack, postfixExpression);
  
  if (infixExpression != NULL) {
    printInfix(infixExpression);
  }
  
  return 0;
}