#include "hanoi.h"

void startStack(typeStack *stack) {
  stack->top = NULL;
  return;
}


int towerTop(typeStack *stack) {
  if (!emptyStack(stack)) {
    return stack->top->item == 1;
  }
  
  return 0;
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
    stack->top = pAux->next;
    
    free(pAux);
    
    return 1;
  }
  
  return 0;
}


void destroyStack(typeStack *stack) {
  typeNode *pAux;
  
  if (!emptyStack(stack)) {
    pAux = stack->top;
    while (pAux != NULL) {
      stack->top = pAux->next;
      free(pAux);
      pAux = stack->top;
    }
  }
  
  return;
}


int fillStack(typeStack *stack, int disksNumber) {
  int i;
  
  if (emptyStack(stack)) {
    for (i = disksNumber; i > 0; i--) {
      stackNode(stack, i);
    }
  }
  
  return 0;
}


int checkStackSequence(typeStack *stack) {
  typeNode *aux1, *aux2;
  
  if (!emptyStack(stack)) {
    aux1 = stack->top;
    aux2 = aux1->next;
    
    while (aux2 != NULL) {
      
      if (aux1->item > aux2->item) {
        return 0;
      }
      
      aux1 = aux1->next;
      aux2 = aux1->next;
    }
    /*
    if (aux1->item > aux2->item) {
      return 0;
    }
    */
  }
  
  return 1;
}


int doTheMove(typeStack *stack1, typeStack *stack2, typeStack *stack3, int fromTower, int toTower) {
  int item;
  
  if (fromTower == 1 && toTower == 2) {
    if (!emptyStack(stack1)) {
      item = stack1->top->item;
      stackNode(stack2, item);
      unstackNode(stack1);
    } else {
      return 0;
    }
  } else if (fromTower == 1 && toTower == 3) {
    if (!emptyStack(stack1)) {
      item = stack1->top->item;
      stackNode(stack3, item);
      unstackNode(stack1);
    } else {
      return 0;
    }
  } else if (fromTower == 2 && toTower == 1) {
    if (!emptyStack(stack2)) {
      item = stack2->top->item;
      stackNode(stack1, item);
      unstackNode(stack2);
    } else {
      return 0;
    }
  } else if (fromTower == 2 && toTower == 3) {
    if (!emptyStack(stack2)) {
      item = stack2->top->item;
      stackNode(stack3, item);
      unstackNode(stack2);
    } else {
      return 0;
    }
  } else if (fromTower == 3 && toTower == 1) {
    if (!emptyStack(stack3)) {
      item = stack3->top->item;
      stackNode(stack1, item);
      unstackNode(stack3);
    } else {
      return 0;
    }
  } else if (fromTower == 3 && toTower == 2) {
    if (!emptyStack(stack3)) {
      item = stack3->top->item;
      stackNode(stack2, item);
      unstackNode(stack3);
    } else {
      return 0;
    }
  }
  
  return 1;
}