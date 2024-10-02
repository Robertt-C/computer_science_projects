#include <stdio.h>
#include <stdlib.h>

struct treeNode {
  int info;
  struct treeNode *leftChildTree;
  struct treeNode *rightChildTree;
};

typedef struct treeNode typeTreeNode;

typedef typeTreeNode *typeTree;

int emptyTree(typeTree);
typeTree initializeTree();
typeTree destroyTree(typeTree);
typeTree insertOnBinarySearchTree(typeTree, int);
void printTreePreOrder(typeTree);
void printTreeInOrder(typeTree);
void printTreePostOrder(typeTree);




int main() {
  typeTree tree;
  int i, j, num, casesNumber, numberQuantity;
  
  tree = initializeTree();
  
  scanf("%d", &casesNumber);
  
  for (i = 0; i < casesNumber; i++) {
    scanf("%d", &numberQuantity);
    for (j = 0; j < numberQuantity; j++) {
      scanf("%d", &num);
      tree = insertOnBinarySearchTree(tree, num);
    }
    
    printf("Case %d:\n", i + 1);
    printf("Pre.:");
    printTreePreOrder(tree);
    printf("\n");
    printf("In..:");
    printTreeInOrder(tree);
    printf("\n");
    printf("Post:");
    printTreePostOrder(tree);
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


void printTreePreOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printf(" %d", tree->info);
    printTreePreOrder(tree->leftChildTree);
    printTreePreOrder(tree->rightChildTree);
  }
};


void printTreeInOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreeInOrder(tree->leftChildTree);
    printf(" %d", tree->info);
    printTreeInOrder(tree->rightChildTree);
  }
}


void printTreePostOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreePostOrder(tree->leftChildTree);
    printTreePostOrder(tree->rightChildTree);
    printf(" %d", tree->info);
  }
}