#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 52

struct treeNode {
  char info;
  struct treeNode *leftChildTree;
  struct treeNode *rightChildTree;
};

typedef struct treeNode typeTreeNode;

typedef typeTreeNode *typeTree;

int emptyTree(typeTree);
typeTree initializeTree();
typeTree destroyTree(typeTree tree);
typeTree createTreeNode(char info);
int searchIndex(char*, int, int, char);
typeTree buildTree(char*, char*, int, int);
void printTreePostOrder(typeTree);

int preOrderIndex;




int main() {
  typeTree root;
  char preOrder[MAX], inOrder[MAX];
  int casesNumber, nodesNumber;
  int initialTreeIndex = 0, lastTreeIndex;
  
  root = initializeTree();
  
  scanf("%d", &casesNumber);
  
  while (casesNumber > 0) {
    preOrderIndex = 0;
    
    scanf("%d %s %s", &nodesNumber, preOrder, inOrder);
    
    lastTreeIndex = strlen(inOrder) - 1;
    
    root = buildTree(inOrder, preOrder, initialTreeIndex, lastTreeIndex);
    
    printTreePostOrder(root);
    printf("\n");
    
    root = destroyTree(root);
    
    casesNumber--;
  }
  
  return 0;
}




typeTree initializeTree() {
  return NULL;
}


int emptyTree(typeTree tree) {
  return tree == NULL;
}


typeTree destroyTree(typeTree tree) {
  if(!emptyTree(tree)){
    destroyTree(tree->leftChildTree);
    destroyTree(tree->rightChildTree);
    free(tree);
  }
  return NULL;
}


typeTree createTreeNode(char info) {
  typeTree newTreeNode;
  
  newTreeNode = (typeTree) malloc(sizeof(typeTreeNode));
  newTreeNode->leftChildTree = NULL;
  newTreeNode->rightChildTree = NULL;
  newTreeNode->info = info;
  
  return newTreeNode;
}


int searchIndex(char inOrder[], int treeStart, int treeEnd, char info) {
  int i;
  
  for (i = treeStart; i <= treeEnd; i++) {
    if (inOrder[i] == info)
      return i;
  }
  
  return 0;
}


typeTree buildTree(char inOrder[], char preOrder[], int initialTreeIndex, int lastTreeIndex) {
  typeTree tree;
  int inOrderIndex;
  
  if (initialTreeIndex > lastTreeIndex) {
    return NULL;
  } else {
    tree = createTreeNode(preOrder[preOrderIndex++]);
  }
  
  if (initialTreeIndex == lastTreeIndex) {
    return tree;
  }
  
  inOrderIndex = searchIndex(inOrder, initialTreeIndex, lastTreeIndex, tree->info);
  
  tree->leftChildTree = buildTree(inOrder, preOrder, initialTreeIndex, inOrderIndex - 1);
  tree->rightChildTree = buildTree(inOrder, preOrder, inOrderIndex + 1, lastTreeIndex);
  
  return tree;
}


void printTreePostOrder(typeTree tree) {
  if (!emptyTree(tree)) {
    printTreePostOrder(tree->leftChildTree);
    printTreePostOrder(tree->rightChildTree);
    printf("%c", tree->info);
  }
}