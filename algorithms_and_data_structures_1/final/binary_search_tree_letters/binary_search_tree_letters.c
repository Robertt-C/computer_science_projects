#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode {
  char info;
  struct treeNode *leftChildTree;
  struct treeNode *rightChildTree;
};

typedef struct treeNode typeTreeNode;

typedef typeTreeNode *typeTree;

int emptyTree(typeTree);
typeTree initializeTree();
typeTree destroyTree(typeTree);
typeTree insertOnBinarySearchTree(typeTree, char);
typeTree searchInTree(typeTree, char);
void printTreePreOrder(typeTree);
void printTreeInOrder(typeTree);
void printTreePostOrder(typeTree);
void printItem(typeTree, char);

int z;




int main() {
  typeTree tree, searchItem;
  char infoToInsert, infoToSearch, option[7];
  
  tree = initializeTree();
  
  while (scanf("%s", option) != EOF) {
    
    z = 1;
    
    if (!(strcmp("I", option))) {
      getchar();
      scanf("%c", &infoToInsert);
      tree = insertOnBinarySearchTree(tree, infoToInsert);
    } else if (!(strcmp(option, "PREFIXA"))) {
      printTreePreOrder(tree);
      printf("\n");
    } else if (!(strcmp(option, "INFIXA"))) {
      printTreeInOrder(tree);
      printf("\n");
    } else if (!(strcmp(option, "POSFIXA"))) {
      printTreePostOrder(tree);
      printf("\n");
    } else if (!(strcmp(option, "P"))) {
      getchar();
      scanf("%c", &infoToSearch);
      searchItem = searchInTree(tree, infoToSearch);
      printItem(searchItem, infoToSearch);
      printf("\n");
    }
  }
  
  tree = destroyTree(tree);
  
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


typeTree insertOnBinarySearchTree(typeTree tree, char info) {
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


void printTreePreOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    
    if (!z) {
      printf(" %c", tree->info);
    } else {
      printf("%c", tree->info);
      z = 0;
    }
    
    printTreePreOrder(tree->leftChildTree);
    printTreePreOrder(tree->rightChildTree);
  }
};


void printTreeInOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreeInOrder(tree->leftChildTree);
    
    if (!z) {
      printf(" %c", tree->info);
    } else {
      printf("%c", tree->info);
      z = 0;
    }
    
    printTreeInOrder(tree->rightChildTree);
  }
}


void printTreePostOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreePostOrder(tree->leftChildTree);
    printTreePostOrder(tree->rightChildTree);
    
    if (!z) {
      printf(" %c", tree->info);
    } else {
      printf("%c", tree->info);
      z = 0;
    }
  }
}


void printItem(typeTree treeNode, char infoToSearch) {
  if (!emptyTree(treeNode)) {
    printf("%c existe", infoToSearch);
  } else {
    printf("%c nao existe", infoToSearch);
  }
}