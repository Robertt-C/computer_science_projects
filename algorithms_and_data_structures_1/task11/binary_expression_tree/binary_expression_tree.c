#include "binary_expression_tree.h"

//--- Functions to handle the infix to postfix expression. ---//
void initializeInfixToPostfixStack(typeInfixToPostfixStack *stack) {
  stack->top = NULL;
  return;
}


int emptyInfixToPostfixStack(typeInfixToPostfixStack *stack) {
  return stack->top == NULL;
}


int pushToInfixToPostfixStack(typeInfixToPostfixStack *stack, char info) {
  typeInfixToPostfixNode *newNode;
  
  newNode = (typeInfixToPostfixNode*) malloc(sizeof(typeInfixToPostfixNode));
  
  if (newNode != NULL) {
    newNode->info = info;
    newNode->next = stack->top;
    stack->top = newNode;
    
    return 1;
  }
  
  return 0;
}


char unstackInfixToPostfixNode(typeInfixToPostfixStack *stack) {
  typeInfixToPostfixNode *pAux;
  
  if (!emptyInfixToPostfixStack(stack)) {
    pAux = stack->top;
    stack->top = pAux->next;
    
    free(pAux);
    
    return pAux->info;
  }
  
  return 0;
}


void destroyInfixToPostfixStack(typeInfixToPostfixStack *stack) {
  typeInfixToPostfixNode *pAux;
  
  if (!emptyInfixToPostfixStack(stack)) {
    pAux = stack->top;
    while (pAux != NULL) {
      stack->top = pAux->next;
      free(pAux);
      pAux = stack->top;
    }
  }
  
  return;
}


int isOperator(char symbol) {
  if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
    return 1;
  } else {
    return 0;
  }
}


int operatorPrecedence(char symbol) {
  if (symbol == '^') {
    return 3;
  } else if (symbol == '*' || symbol == '/') {
    return 2;
  } else if (symbol == '+' || symbol == '-') {
    return 1;
  } else {
    return 0;
  }
}


void InfixToPostfix(typeInfixToPostfixStack *stack, char infixExpression[], char postfixExpression[]) { 
  int i = 0, j = 0;
  char item, auxUnstack;
  
  pushToInfixToPostfixStack(stack, '(');
  strcat(infixExpression, " )");
  
  item = infixExpression[i];
  
  while (item != '\0') {
    if (item == '(') {
      pushToInfixToPostfixStack(stack, item);
      
    } else if (item != '+' && item != '-' && item != '*' && item != '/' && item != '^' && item != ')') {
      postfixExpression[j] = item;
      j++;
      
    } else if (isOperator(item) == 1) {
      auxUnstack = unstackInfixToPostfixNode(stack);
      
      while (isOperator(auxUnstack) == 1 && operatorPrecedence(auxUnstack) >= operatorPrecedence(item)) {
        postfixExpression[j] = auxUnstack;
        j++;
        auxUnstack = unstackInfixToPostfixNode(stack);
      }
      
      pushToInfixToPostfixStack(stack, auxUnstack);
      pushToInfixToPostfixStack(stack, item);
      
    } else if (item == ')') {
      auxUnstack = unstackInfixToPostfixNode(stack);
      
      while (auxUnstack != '(') {
        postfixExpression[j] = auxUnstack;
        j++;
        auxUnstack = unstackInfixToPostfixNode(stack);
      }
      
    }
    
    i += 2;
    item = infixExpression[i];
  }
  
  postfixExpression[j] = '\0';
}




//--- Functions to handle the stack/tree structure.
void initializeTreeStack(typeTreeStack *root) {
  root->top = NULL;
}


int emptyStack(typeTreeStack *stack) {
  return stack->top == NULL;
}


int emptyTree(typeTreeNode *root){
  return root == NULL;
}


struct treeNode* createNewNode(char info) {
  struct treeNode *newNode;
  
  newNode = (struct treeNode*) malloc(sizeof(struct treeNode));
  newNode->info = info;
  newNode->leftTree = NULL;
  newNode->rightTree = NULL;
  newNode->next = NULL;
  
  return newNode;
}


void stackTreeNode(typeTreeStack *root, struct treeNode *nodeToAdd) {
  
  if (root == NULL) {
    root->top = nodeToAdd;
  } else {
    nodeToAdd->next = root->top;
    root->top = nodeToAdd;
  }
  return;
}


typeTreeNode* unstackTreeNode(typeTreeStack *root) {
  struct treeNode *nodeToRemove;
  if (!emptyStack(root)) {
    nodeToRemove = root->top;
    root->top = nodeToRemove->next;
    return nodeToRemove;
  }
  return NULL;
}


typeTreeNode* destroyTree(typeTreeNode *root) {
  if(!emptyTree(root)){
    destroyTree(root->leftTree);
    destroyTree(root->rightTree);
    free(root);
  }
  return NULL;
}


void destroyTreeStack(typeTreeStack *stack){
  typeTreeNode *auxP;
  
  if (!emptyStack(stack)) {
    auxP = stack->top;
    while (auxP != NULL) {
      stack->top = auxP->next;
      free(auxP);
      auxP = stack->top;
    }
  }
}


void buildExpressionTree(typeTreeStack *root, char postfixExpression[]) {
  struct treeNode *auxRightTree, *auxLeftTree, *auxTree;
  int length = strlen(postfixExpression), i;
  
  for (i = 0; i < length; i++) {
    if (postfixExpression[i] == '+' || postfixExpression[i] == '-' || postfixExpression[i] == '*' || postfixExpression[i] == '/' || postfixExpression[i] == '^') {
      auxTree = createNewNode(postfixExpression[i]);
      auxRightTree = unstackTreeNode(root);
      auxLeftTree = unstackTreeNode(root);
      auxTree->leftTree = auxLeftTree;
      auxTree->rightTree = auxRightTree;
      stackTreeNode(root, auxTree);
    } else {
      auxTree = createNewNode(postfixExpression[i]);
      stackTreeNode(root, auxTree);
    }
  }
  return;
}


int findTreeHeight(struct treeNode *root) {
  int leftTreeHeight, rightTreeHeight;
  
  if (root == NULL) {
    return 0;
  } else {
    leftTreeHeight = findTreeHeight(root->leftTree);
    rightTreeHeight = findTreeHeight(root->rightTree);
    
    if (leftTreeHeight >= rightTreeHeight) {
      return leftTreeHeight + 1;
    } else {
      return rightTreeHeight + 1;
    }
  }
}


void printTreeLevel(struct treeNode* root, int treeLevel) {
  if (root != NULL && treeLevel == 0) {
    printf("%c ", root->info);
  } else if (root != NULL) {
    printTreeLevel(root->leftTree, treeLevel - 1);
    printTreeLevel(root->rightTree, treeLevel - 1);
  }
}