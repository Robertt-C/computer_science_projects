#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 202


// infix to postfix structure.
typedef struct node {
  char info;
  struct node *next;
} typeInfixToPostfixNode;

typedef struct {
  typeInfixToPostfixNode *top;
} typeInfixToPostfixStack;


void initializeInfixToPostfixStack(typeInfixToPostfixStack*);
int emptyInfixToPostfixStack(typeInfixToPostfixStack*);
int pushToInfixToPostfixStack(typeInfixToPostfixStack*, char);
char unstackInfixToPostfixNode(typeInfixToPostfixStack*);
void destroyInfixToPostfixStack(typeInfixToPostfixStack*);

int isOperator(char);
int operatorPrecedence(char);
void InfixToPostfix(typeInfixToPostfixStack*, char array1[], char array2[]);




// tree on a stack structured.
typedef struct treeNode {
  char info;
  struct treeNode* leftTree;
  struct treeNode* rightTree;
  struct treeNode* next;
} typeTreeNode;

typedef struct treeStack {
  typeTreeNode *top;
} typeTreeStack;


void initializeTreeStack(typeTreeStack*);
int emptyTree(typeTreeNode*);
int emptyStack(typeTreeStack*);
typeTreeNode* createNewNode(char);
typeTreeNode* unstackTreeNode(typeTreeStack*);
void stackTreeNode(typeTreeStack*, typeTreeNode*);
void buildExpressionTree(typeTreeStack*, char array[]);
void destroyTreeStack(typeTreeStack*);
typeTreeNode* destroyTree(typeTreeNode*);
int findTreeHeight(typeTreeNode*);
void printTreeLevel(typeTreeNode*, int);