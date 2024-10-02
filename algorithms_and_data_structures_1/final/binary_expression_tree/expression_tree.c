#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 300


// infix to postfix structure.
typedef struct node {
  char info;
  struct node *next;
} typeInfixToPostfixNode;

typedef struct {
  typeInfixToPostfixNode *top;
} typeInfixToPostfixStack;


void initializeInfixToPostfixStack(typeInfixToPostfixStack*);
int emptyInfixToPostfixStack(typeInfixToPostfixStack*);
int pushToInfixToPostfixStack(typeInfixToPostfixStack*, char);
char unstackInfixToPostfixNode(typeInfixToPostfixStack*);
void destroyInfixToPostfixStack(typeInfixToPostfixStack*);

int isOperator(char);
int operatorPrecedence(char);
void InfixToPostfix(typeInfixToPostfixStack*, char array1[], char array2[]);




// tree on a stack structure.
typedef struct treeNode {
  char info;
  struct treeNode* leftTree;
  struct treeNode* rightTree;
  struct treeNode* next;
} typeTreeNode;

typedef struct treeStack {
  typeTreeNode *top;
} typeTreeStack;


void initializeTreeStack(typeTreeStack*);
int emptyTree(typeTreeNode*);
int emptyStack(typeTreeStack*);
typeTreeNode* createNewNode(char);
typeTreeNode* unstackTreeNode(typeTreeStack*);
void stackTreeNode(typeTreeStack*, typeTreeNode*);
void buildExpressionTree(typeTreeStack*, char array[]);
void destroyTreeStack(typeTreeStack*);
typeTreeNode* destroyTree(typeTreeNode*);
int findTreeHeight(typeTreeNode*);
void printTreeLevel(typeTreeNode*, int);




int main() {
  typeTreeStack root;
  typeInfixToPostfixStack infixToPostfixStack;
  char infixExpression[MAX], postfixExpression[MAX];
  int treeHeight, k;
  
  
  initializeTreeStack(&root);
  initializeInfixToPostfixStack(&infixToPostfixStack);
  
  while (gets(infixExpression) != EOF) {
    
    InfixToPostfix(&infixToPostfixStack, infixExpression, postfixExpression);
    
    buildExpressionTree(&root, postfixExpression);
    
    treeHeight = findTreeHeight(root.top);
    for (k = 0; k < treeHeight; k++) {
      printf("Nivel %d: ", k);
      printTreeLevel(root.top, k);
      printf("\n");
    }
    
    printf("\n");
    
    destroyInfixToPostfixStack(&infixToPostfixStack);
    root.top = destroyTree(root.top);
    destroyTreeStack(&root);
  }
  return 0;
}




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
    free(nodeToRemove);
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
    printf("%c", root->info);
  } else if (root != NULL) {
    printTreeLevel(root->leftTree, treeLevel - 1);
    printTreeLevel(root->rightTree, treeLevel - 1);
  }
}