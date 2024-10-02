#include "binary_search_tree.h"

int emptyTree(typeTree tree){
  return tree == NULL;
}


typeTree initializeTree(){
  return NULL;
}


typeTree destroyTree(typeTree tree){
  if(!emptyTree(tree)){
    destroyTree(tree->leftChildTree);
    destroyTree(tree->rightChildTree);
    free(tree);
  }
  return NULL;
}


typeTree insertOnBinarySearchTree(typeTree tree, int info) {
  typeTree new;
  
  if (emptyTree(tree)) {
    new = (typeTree) malloc(sizeof(typeTreeNode)); 
    new->leftChildTree = NULL;
    new->rightChildTree = NULL;
    new->info = info;
    
    return new;
  } else if (info < tree->info) {
    tree->leftChildTree = insertOnBinarySearchTree(tree->leftChildTree, info);
  } else {
    tree->rightChildTree = insertOnBinarySearchTree(tree->rightChildTree, info); 
  }
  
  return tree;
}


typeTree searchInTree(typeTree tree, char info) {
  if (!emptyTree(tree)) {
    if (tree->info > info) {
      return searchInTree(tree->leftChildTree, info);
    } else if (tree->info < info) {
      return searchInTree(tree->rightChildTree, info);
    } else {
      return tree;
    }
  }
  
  return NULL;
}


typeTree removeTreeNode(typeTree tree, char info) {
  return NULL;
}




void printTreePreOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printf("%d ", tree->info);
    printTreePreOrder(tree->leftChildTree);
    printTreePreOrder(tree->rightChildTree);
  }
};


void printTreeInOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreeInOrder(tree->leftChildTree);
    printf("%d ", tree->info);
    printTreeInOrder(tree->rightChildTree);
  }
}


void printTreePostOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreePostOrder(tree->leftChildTree);
    printTreePostOrder(tree->rightChildTree);
    printf("%d ", tree->info);
  }
}