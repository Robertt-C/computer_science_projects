#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100


typedef struct node {
  char item;
  struct node *next;
} typeNode;

typedef struct {
  typeNode *top;
} typeStack;


int emptyStack(typeStack*);
int stackNode(typeStack*, char);
int unstackNode(typeStack*);
char* createInfixExpression(typeStack*, char*);
void printInfix(char*);