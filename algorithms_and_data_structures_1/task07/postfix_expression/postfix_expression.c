#include "postfix_expression.h"


int startStack(typeStack *stack) {
  stack->top = NULL;
  
  return 1;
}


int emptyStack(typeStack *stack) {
  return stack->top == NULL;
}


int stackNode(typeStack *stack, int item) {
  typeNode *newNode;
  
  newNode = (typeNode*) malloc(sizeof(typeNode));
  
  if (newNode != NULL) {
    newNode->item = item;
    newNode->next = stack->top;
    stack->top = newNode;
    
    return 1;
  }
  
  return 0;
}


int unstackNode(typeStack *stack) {
  typeNode *pAux;
  
  if (!emptyStack(stack)) {
    pAux = stack->top;
    stack->top = stack->top->next;
    
    free(pAux);
    
    return 1;
  }
  
  return 0;
}

/* 
 Desempilhando dois números e um operador,
 depois empilha o resultado e volta a desempilhar como no início.
*/
int resultStack(typeStack *numberStack, char string[MAX]) {
  int i, item;
  
  for (i = 0; i < strlen(string); i++) {
    if (string[i] != '+' && string[i] != '*') {
      item = string[i] - '0';
      stackNode(numberStack, item);
    } else if (string[i] == '+') {
      item = numberStack->top->item + numberStack->top->next->item;
      
      unstackNode(numberStack);
      unstackNode(numberStack);
      stackNode(numberStack, item);
    } else if (string[i] == '*') {
      item = numberStack->top->item * numberStack->top->next->item;
      
      unstackNode(numberStack);
      unstackNode(numberStack);
      stackNode(numberStack, item);
    }
  }
  
  return 0;
}