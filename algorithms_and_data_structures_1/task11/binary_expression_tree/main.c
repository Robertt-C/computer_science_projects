#include "binary_expression_tree.h"

int main() {
  typeTreeStack root;
  typeInfixToPostfixStack infixToPostfixStack;
  char infixExpression[MAX], postfixExpression[MAX];
  int treeHeight, k;
  
  
  initializeTreeStack(&root);
  initializeInfixToPostfixStack(&infixToPostfixStack);
  
  printf("Dê-me a expressão (com espaços, e.g., ( A + B ))\n");
  printf("Expressao: ");
  
  while (gets(infixExpression) != EOF) {
    printf("\n");
    
    InfixToPostfix(&infixToPostfixStack, infixExpression, postfixExpression);
    
    buildExpressionTree(&root, postfixExpression);
    
    treeHeight = findTreeHeight(root.top);
    for (k = 0; k < treeHeight; k++) {
      printf("Nivel %d: ", k);
      printTreeLevel(root.top, k);
      printf("\n");
    }
    
    printf("\n");
    
    printf("Outra: ");
    
    destroyInfixToPostfixStack(&infixToPostfixStack);
    root.top = destroyTree(root.top);
    destroyTreeStack(&root);
  }
  return 0;
}