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
typeTree removeTreeNode(typeTree, char);
typeTree searchInTree(typeTree, char);
void printTreePreOrder(typeTree);
void printTreeInOrder(typeTree);
void printTreePostOrder(typeTree);