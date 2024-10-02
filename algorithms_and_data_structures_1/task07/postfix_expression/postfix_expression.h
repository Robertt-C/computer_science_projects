#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100


typedef struct node {
  int item;
  struct node *next;
} typeNode;

typedef struct {
  typeNode *top;
} typeStack;


int stackNode(typeStack*, int);
int unstackNode(typeStack*);
int resultStack(typeStack*, char*);