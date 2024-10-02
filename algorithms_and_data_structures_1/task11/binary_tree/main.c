#include "binary_tree.h"

int main(){
  typeTree root, father, leftChild, rightChild;
  
  root = initializeTree();
  father = initializeTree();
  leftChild = initializeTree();
  rightChild = initializeTree();
  
  root = createTreeNode(root, 'A');
  
  father = createTreeNode(father, 'B');
  leftChild = createTreeNode(leftChild, 'D');
  rightChild = createTreeNode(rightChild, 'E');
  
  father = buildTree(father, leftChild, rightChild);
  
  root = insertLeftChild(root, father);
  
  
  father = createTreeNode(father, 'C');
  leftChild = createTreeNode(leftChild, 'F');
  rightChild = createTreeNode(rightChild, 'G');
  
  father = buildTree(father, leftChild, rightChild);
  
  root = insertRightChild(root, father);
  
  printf("\n");
  printf("Pré-ordem: ");
  printTreePreOrder(root);
  printf("\n");
  
  printf("\n");
  printf("Em ordem: ");
  printTreeInOrder(root);
  printf("\n");
  
  printf("\n");
  printf("Pós-ordem: ");
  printTreePostOrder(root);
  printf("\n");
  
  
  root = destroyTree(root);
  
  return 0;
}

/*
          A
       B     C
      D E   F G
*/