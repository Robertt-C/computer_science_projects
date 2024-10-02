#include "binary_tree.h"


int emptyTree(typeTree tree) {
  return tree == NULL;
}

typeTree initializeTree() {
  return NULL;
}

typeTree destroyTree(typeTree tree) {
  if(!emptyTree(tree)){
    destroyTree(tree->leftChildTree);
    destroyTree(tree->rightChildTree);
    free(tree);
  }
  return NULL;
}

typeTree createTreeNode(typeTree tree, char info) {
  tree = (typeTree) malloc(sizeof(typeTreeNode));
  tree->leftChildTree = NULL;
  tree->rightChildTree = NULL;
  tree->info = info;
  return tree;
}

typeTree insertLeftChild(typeTree root, typeTree leftChildTree) {
  if(!emptyTree(root)){
    root->leftChildTree = leftChildTree;
    return root;
  }
  return NULL;
}

typeTree insertRightChild(typeTree root, typeTree rightChildTree) {
  if(!emptyTree(root)){
    root->rightChildTree = rightChildTree;
    return root;
  }
  return NULL;
}

typeTree buildTree(typeTree root, typeTree leftChildTree, typeTree rightChildTree) {
  if(!emptyTree(root)){
    root->leftChildTree = leftChildTree;
    root->rightChildTree = rightChildTree;
    return root;
  }
  return NULL;
}


void printTreePreOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printf("%c ", tree->info);
    printTreePreOrder(tree->leftChildTree);
    printTreePreOrder(tree->rightChildTree);
  }
};


void printTreeInOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreeInOrder(tree->leftChildTree);
    printf("%c ", tree->info);
    printTreeInOrder(tree->rightChildTree);
  }
}


void printTreePostOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreePostOrder(tree->leftChildTree);
    printTreePostOrder(tree->rightChildTree);
    printf("%c ", tree->info);
  }
}



/*
          A
       B     C
      D E   F G

 Pré-ordem: A B D E C F G

 Em ordem: D B E A F C G

 Pós-ordem: D E B F G C A
 
*/