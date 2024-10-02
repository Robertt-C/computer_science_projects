#include "ticket_generator.h"


void initializeQueue(typeQueue *queue) {
  queue->queueCount = 0;
  queue->firstNode = NULL;
  queue->lastNode = NULL;
  
  return;
}


int isQueueEmpty(typeQueue *queue) {
  return queue->queueCount == 0;
}


int insertNode(typeQueue *queue, typeItem item) {
  typeNode *newNode;
  
  newNode = (typeNode*) malloc(sizeof(typeNode));
  
  if (newNode != NULL) {
    if (isQueueEmpty(queue)) {
      queue->firstNode = newNode;
    } else {
      queue->lastNode->nextNode = newNode;
    }
    
    newNode->info = item;
    newNode->nextNode = NULL;
    queue->lastNode = newNode;
    
    queue->queueCount++;
    return 1;
  }
  
  return 0;
}


int removeNode(typeQueue *queue, typeItem *item) {
  typeNode *aux;
  
  if (!isQueueEmpty(queue)) {
    aux = queue->firstNode;
    *item = aux->info;
    
    if (queue->firstNode == queue->lastNode) {
      queue->firstNode = NULL;
      queue->lastNode = NULL;
      
    } else {
      queue->firstNode = queue->firstNode->nextNode; //try with aux->nextNode
    }
    
    free(aux);
    queue->queueCount--;
    
    return 1;
  }
  
  return 0;
}


void printQueue(typeQueue *queue) {
  typeNode *aux;
  
  if (!isQueueEmpty(queue)) {
    aux = queue->firstNode;
    
    while(aux != NULL) {
      printItem(aux->info);
      aux = aux->nextNode;
    }
  }
  
  return;
}


void printItem(typeItem item) {
  printf("-----------------------------------------\n");
  printf("\nSua senha é: %d | Nome: %s\n\n", item.ticket, item.name);
  printf("-----------------------------------------\n");

  return;
}


void printAttended(typeItem item) {
  printf("Nome: %s | Senha: %d\n", item.name, item.ticket);
  
  return;
}


void getItem(typeQueue *queue, typeItem *item) {
  printf("\nDê-me seu primeiro nome: ");
  scanf("%s", item->name);
  
  item->ticket = queue->queueCount + 1;
  
  return;
}


    /*
       pI        pL  --->|    --->|
    i node node node newNode0 newNode1
    */