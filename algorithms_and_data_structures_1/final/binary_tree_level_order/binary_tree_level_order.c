#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode {
  int info;
  struct treeNode *leftChildTree;
  struct treeNode *rightChildTree;
};

typedef struct treeNode typeTreeNode;

typedef typeTreeNode *typeTree;

typeTree initializeTree();
int emptyTree(typeTree);
typeTree insertOnBinarySearchTree(typeTree, int);
int findTreeHeight(typeTree);
void printTreeLevel(typeTree, int);
typeTree destroyTree(typeTree);

int z;


int main() {
  typeTree tree;
  int i, j, k, number, casesNumber, numberQuantity, lastTreeLevel;
  
  tree = initializeTree();
  scanf("%d", &casesNumber);
  
  for (i = 0; i < casesNumber; i++) {
    z = 1;
    scanf("%d", &numberQuantity);
    for (j = 0; j < numberQuantity; j++) {
      scanf("%d", &number);
      tree = insertOnBinarySearchTree(tree, number);
    }
    
    lastTreeLevel = findTreeHeight(tree);
    printf("Case %d:\n", i + 1);
    for (k = 0; k < lastTreeLevel; k++) {
      printTreeLevel(tree, k);
    }
    printf("\n\n");
    
    tree = destroyTree(tree);
  }
  
  return 0;
}




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
  typeTree newNode;
  
  if (emptyTree(tree)) {
    newNode = (typeTree) malloc(sizeof(typeTreeNode)); 
    newNode->leftChildTree = NULL;
    newNode->rightChildTree = NULL;
    newNode->info = info;
    
    return newNode;
  } else if (info < tree->info) {
    tree->leftChildTree = insertOnBinarySearchTree(tree->leftChildTree, info);
  } else {
    tree->rightChildTree = insertOnBinarySearchTree(tree->rightChildTree, info); 
  }
  
  return tree;
}


int findTreeHeight(typeTree tree) {
  int leftTreeHeight, rightTreeHeight;
  
  if (tree == NULL) {
    return 0;
  } else {
    leftTreeHeight = findTreeHeight(tree->leftChildTree);
    rightTreeHeight = findTreeHeight(tree->rightChildTree);
    
    if (leftTreeHeight >= rightTreeHeight) {
      return leftTreeHeight + 1;
    } else {
      return rightTreeHeight + 1;
    }
  }
}


void printTreeLevel(typeTree tree, int treeLevel) {
  if (tree != NULL && treeLevel == 0) {
    if (!z) {
    printf(" %d", tree->info);
    } else {
      printf("%d", tree->info);
      z = 0;
    }
  } else if (tree != NULL) {
    printTreeLevel(tree->leftChildTree, treeLevel - 1);
    printTreeLevel(tree->rightChildTree, treeLevel - 1);
  }
}