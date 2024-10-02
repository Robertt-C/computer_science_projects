#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define PRIORITY 4

typedef struct {
  char name[MAX];
  int ticket;
  char priority[PRIORITY];
} typeItem;

typedef struct node {
  typeItem info;
  struct node *nextNode;
} typeNode;

typedef struct {
  int queueCount;
  typeNode *firstNode;
  typeNode *lastNode;
} typeQueue;


void initializeQueue(typeQueue*);
int isQueueEmpty(typeQueue*);
int insertNode(typeQueue*, typeItem);
int removeNode(typeQueue*, typeItem*);
void printQueue(typeQueue*);
void printItem(typeItem);
void printAttended(typeItem);
void getItem(typeQueue*, typeItem*);