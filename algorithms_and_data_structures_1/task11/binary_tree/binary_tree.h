#include <stdio.h>
#include <stdlib.h>

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
typeTree createTreeNode(typeTree,char);
typeTree insertLeftChild(typeTree,typeTree);
typeTree insertRightChild(typeTree,typeTree);
typeTree buildTree(typeTree,typeTree,typeTree);
void printTreePreOrder(typeTree);
void printTreeInOrder(typeTree);
void printTreePostOrder(typeTree);