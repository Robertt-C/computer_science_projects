#include "postfix_to_infix.h"


int emptyStack(typeStack *stack) {
  return stack->top == NULL;
}


int stackNode(typeStack *stack, char item) {
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


char* createInfixExpression(typeStack *stack, char postfix[MAX]) {
  int i, count = 0, arrayCount = 0;
  char item, *infix;
  
  infix = (char*) malloc(strlen(postfix) * sizeof(char));
  
  for (i = 0; i < strlen(postfix); i++) {
    if (postfix[i] != '+' && postfix[i] != '*') {
      stackNode(stack, postfix[i]);
    } else if ((postfix[i] == '+' || postfix[i] == '*') && count == 0) {
      item = stack->top->item;
      infix[arrayCount] = item;
      arrayCount++;
      unstackNode(stack);
      
      infix[arrayCount] = postfix[i];
      arrayCount++;
      
      item = stack->top->item;
      infix[arrayCount] = item;
      arrayCount++;
      unstackNode(stack);
      
      
      count++;
    } else if ((postfix[i] == '+' || postfix[i] == '*') && count != 0) {
      infix[arrayCount] = postfix[i];
      arrayCount++;
      
      item = stack->top->item;
      infix[arrayCount] = item;
      arrayCount++;
      unstackNode(stack);
    }
  }
  
  return infix;
}


void printInfix(char *infix) {
  int i;
  
  for (i = strlen(infix); i > 0; i--) {
    printf("%c ", infix[i - 1]);
  }
  
  return;
}