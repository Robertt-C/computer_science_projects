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

int emptyTree(typeTree);
typeTree initializeTree();
typeTree destroyTree(typeTree);
typeTree insertOnBinarySearchTree(typeTree, int);
typeTree removeTreeNode(typeTree, int);
typeTree searchInTree(typeTree, int);
void printTreePreOrder(typeTree);
void printTreeInOrder(typeTree);
void printTreePostOrder(typeTree);
void printItem(typeTree, int);

int z;




int main() {
  typeTree tree, searchItem;
  char option[7];
  int infoToInsert, infoToSearch, infoToRemove;
  
  tree = initializeTree();
  
  while (scanf("%s", option) != EOF) {
    
    z = 1;
    
    if (!(strcmp("I", option))) {
      scanf("%d", &infoToInsert);
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
      scanf("%d", &infoToSearch);
      searchItem = searchInTree(tree, infoToSearch);
      printItem(searchItem, infoToSearch);
      printf("\n");
    } else if (!(strcmp(option, "R"))) {
      scanf("%d", &infoToRemove);
      
      if (searchInTree(tree, infoToRemove) != NULL) {
        tree = removeTreeNode(tree, infoToRemove);
      }
      
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


typeTree searchInTree(typeTree tree, int info) {
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


typeTree removeTreeNode(typeTree tree, int infoToRemove) {
  typeTree auxTree, father, auxFather; 
  
  if (tree == NULL) {
    return NULL;
  } else if (infoToRemove < tree->info) {
    tree->leftChildTree = removeTreeNode(tree->leftChildTree, infoToRemove);
  } else if (tree->info < infoToRemove) {
    tree->rightChildTree = removeTreeNode(tree->rightChildTree, infoToRemove);
  } else {
    if (tree->leftChildTree==NULL && tree->rightChildTree==NULL) {
      free (tree);
      tree = NULL;
    } else if (tree->leftChildTree == NULL) {
      auxTree = tree;
      tree = tree->rightChildTree; 
      free (auxTree);
    } else if (tree->rightChildTree == NULL) {
      auxTree = tree; 
      tree = tree->leftChildTree; 
      free (auxTree);
    } else {
      father = tree; 
      auxFather = tree->leftChildTree;
      
      while (auxFather->rightChildTree != NULL) {
        father = auxFather;
        auxFather = auxFather->rightChildTree;
      }
      
      tree->info = auxFather->info;
      
      if (father == tree) {
        father->leftChildTree = auxFather->leftChildTree;
      } else {
        father->rightChildTree = auxFather->leftChildTree;
      }
      
      free(auxFather);
    }
  }
  return tree;
}


void printTreePreOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    
    if (!z) {
      printf(" %d", tree->info);
    } else {
      printf("%d", tree->info);
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
      printf(" %d", tree->info);
    } else {
      printf("%d", tree->info);
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
      printf(" %d", tree->info);
    } else {
      printf("%d", tree->info);
      z = 0;
    }
  }
}


void printItem(typeTree treeNode, int infoToSearch) {
  if (!emptyTree(treeNode)) {
    printf("%d existe", infoToSearch);
  } else {
    printf("%d nao existe", infoToSearch);
  }
}