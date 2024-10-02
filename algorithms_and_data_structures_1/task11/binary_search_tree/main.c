#include "binary_search_tree.h"

int main() {
  typeTree tree;
  int i, j, num, casesNumber, numberQuantity;
  
  tree = initializeTree();
  printf("Quantos casos quer: ");
  scanf("%d", &casesNumber);
  
  for (i = 0; i < casesNumber; i++) {
    printf("Quantos números usará: ");
    scanf("%d", &numberQuantity);
    for (j = 0; j < numberQuantity; j++) {
      printf("Numero[%d]: ", j + 1);
      scanf("%d", &num);
      tree = insertOnBinarySearchTree(tree, num);
    }
    
    printf("\nPré-ordem: ");
    printTreePreOrder(tree);
    printf("\nEm ordem: ");
    printTreeInOrder(tree);
    printf("\nPós-ordem: ");
    printTreePostOrder(tree);
    printf("\n");
    
    tree = destroyTree(tree);
  }
  
  return 0;
}