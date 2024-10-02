#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
  int item;
  struct node *next;
} typeNode;

typedef struct {
  typeNode *top;
} typeStack;

void startStack(typeStack*);
int emptyStack(typeStack*);
int stackNode(typeStack*, int);
int unstackNode(typeStack*);
void destroyStack(typeStack*);
int fillStack(typeStack*, int);
int checkStackSequence(typeStack*);
int doTheMove(typeStack*, typeStack*, typeStack*, int, int);
int towerTop(typeStack*);