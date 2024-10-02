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


int rearrangeQueue(typeQueue *queue) {
  typeNode *aux1, *aux2;
  char priority[PRIORITY] = "Sim", notPriority[PRIORITY] = "Não";
  int limit = 2, count = 0;
  
  if (!isQueueEmpty(queue)) {
    aux1 = queue->firstNode;
    
    while (aux1 != NULL) {
      if (strcmp(aux1->info.priority, priority) == 0 ) {
        
      }
      aux1 = aux1->nextNode;
    }
  }
  
  aux1  
  i --> p --> p --> p --> p --> p --> p
        0     0     1     1     0     1
        
  i --> p --> p --> p --> p --> p --> p
        1     1     0     1     0     0
  
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
  printf("\nNome: %s | Sua senha é: %d | Prioridade: %s\n\n", item.name, item.ticket, item.priority);
  printf("-----------------------------------------\n");
    
  return;
}


void printAttended(typeItem item) {
  printf("Nome: %s | Senha: %d | Prioridade: %s\n", item.name, item.ticket, item.priority);
  
  return;
}


void getItem(typeQueue *queue, typeItem *item) {
  char priority[PRIORITY] = "Sim", notPriority[PRIORITY] = "Não";
  int priorityNum;
  
  
  printf("\nDê-me seu primeiro nome: ");
  scanf("%s", item->name);
  
  printf("Preferencial: 1 || Não preferencial: 0\nDigite: ");
  scanf("%d", &priorityNum);
  
  if (priorityNum == 1) {
    strcpy(item->priority, priority);
  } else {
    strcpy(item->priority, notPriority);
  }
  
  item->ticket = queue->queueCount + 1;
  
  return;
}


    /*
       pI        pL  --->|    --->|
    i node node node newNode0 newNode1
    */