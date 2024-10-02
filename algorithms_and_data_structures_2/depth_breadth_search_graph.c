#include <stdio.h>
#include <stdlib.h>


struct node {
  int key; 
  int color;
  struct node *next;
};

typedef struct node *pNode;

struct graph {
  int verticesNumber;
  int edgesNumber;
  pNode *adjacentList;
};

typedef struct graph *pGraph;

typedef struct {
  int *array;
  int index;
} list;




void initializeList(list*, int);
void stack(list*, int);
int removeInitial(list*);
pGraph initializeGraph(int, int);
void insertEdge(pGraph, int, int);
void printNodeList(pNode);
void printGraph(pGraph);
void deleteNodeList(pNode);
void removeGraph(pGraph);
void depthSearchVisit(pGraph, pNode, list*);
void depthSearch(pGraph graph, int root, list*);
void breadthSearch(pGraph, int, list*);
void printList(list*);




int main() {
  int i, root, verticesNumber, edgesNumber, initial, last;
  pGraph graph;
  list depth, breadth;
  
  scanf("%d", &root);
  scanf("%d", &verticesNumber);
  scanf("%d", &edgesNumber);
  
  initializeList(&depth, verticesNumber);
  initializeList(&breadth, verticesNumber);
  
  graph = initializeGraph(verticesNumber, edgesNumber);
  
  for (i = 0; i < edgesNumber; i++) {
    scanf("%d", &initial);
    scanf("%d", &last);
    
    insertEdge(graph, initial, last);
  }
  
  breadthSearch(graph, root, &breadth);
  printList(&breadth);
  printf("\n");
  
  depthSearch(graph, root, &depth);
  printList(&depth);
  
  
  removeGraph(graph);
  free(depth.array);
  free(breadth.array);
  
  return 0;
}




void initializeList(list *pList, int num) {
  int i;
  
  pList->array = malloc(num * sizeof(int));
  pList->index = 0;
}


void stack(list *pList, int num) {
  pList->array[pList->index] = num;
  pList->index++;
}


int removeInitial(list *pList) {
  int aux = pList->array[0];
  
  for (int i = 0; i < pList->index - 1; i++) {
    pList->array[i] = pList->array[i+1];
  }
  
  pList->index--;
  
  return aux;
}


pGraph initializeGraph(int verticesNumber, int edgesNumber) {
  pGraph newGraph = malloc(sizeof(struct graph));
  int i;
  
  newGraph->verticesNumber = verticesNumber;
  newGraph->edgesNumber = edgesNumber;
  newGraph->adjacentList = malloc(verticesNumber * sizeof(pNode));
  
  for (i = 0; i < verticesNumber; i++) {
    newGraph->adjacentList[i] = malloc(sizeof(struct node));
    newGraph->adjacentList[i]->key = i;
    newGraph->adjacentList[i]->next = NULL;
  }
  
  return newGraph;
}


void insertEdge(pGraph graph, int initial, int last) {
  pNode newNode = malloc(sizeof(struct node));
  newNode->key = last;
  
  pNode aux = graph->adjacentList[initial];
  
  while (aux->next != NULL && aux->next->key < newNode->key) {
    aux = aux->next;
  }
  
  newNode->next = aux->next;
  aux->next = newNode;
}


void printNodeList(pNode node) {
  pNode aux = node;
  
  while (aux != NULL) {
    printf("%d ", aux->key);
    aux = aux->next;
  }
}


void printGraph(pGraph graph) {
  int i;
  
  for (i = 0; i < graph->verticesNumber; i++) {
    printNodeList(graph->adjacentList[i]);
    printf("\n");
  }
}


void deleteNodeList(pNode node) {
  pNode aux;
  
  while (node != NULL) {
    aux = node->next;
    free(node);
    node = aux;
  }
}


void removeGraph(pGraph graph) {
  int i;
  
  for (i = 0; i < graph->verticesNumber; i++) {
    deleteNodeList(graph->adjacentList[i]);
  }

  free(graph);
}


void depthSearchVisit(pGraph graph, pNode u, list *pList) {
  int i;
  
  stack(pList, u->key);
  u->color = 1;
  
  pNode aux = u;
  int num;
  
  while (aux->next != NULL) {
    aux = aux->next;
    
    num = aux->key;
    if (graph->adjacentList[num]->color == 0) {
      depthSearchVisit(graph, graph->adjacentList[num], pList); 
    }
  }
  
  u->color = 2;
}


void depthSearch(pGraph graph, int root, list *pList) {
  int i;
  
  for (i = 0; i < graph->verticesNumber; i++) {
    graph->adjacentList[i]->color = 0;
  }
  
  depthSearchVisit(graph, graph->adjacentList[root], pList);
  
  for (i = 0; i < graph->verticesNumber; i++) {
    if (graph->adjacentList[i]->color == 0) {
      depthSearchVisit(graph, graph->adjacentList[i], pList);
    }
  }
}


void breadthSearch(pGraph graph, int root, list *pList) {
  int i, num;
  pNode aux;
  list queue;
  
  for (i = 0; i < graph->verticesNumber; i++) {
    graph->adjacentList[i]->color = 0;
  }
  
  
  initializeList(&queue, graph->edgesNumber);
  
  stack(pList, root);
  graph->adjacentList[root]->color = 1;
  
  stack(&queue, root);
  
  while (queue.index > 0) {
    num = removeInitial(&queue);
    aux = graph->adjacentList[num];
    
    while (aux->next != NULL){
      aux = aux->next;
      
      if (graph->adjacentList[aux->key]->color == 0){
        graph->adjacentList[aux->key]->color = 1;
        stack(pList, aux->key);
        
        stack(&queue, aux->key);
      }
    }
    
    graph->adjacentList[num]->color = 3;
  }
  
}


void printList(list *pList){
  int i;
  
  for (i = 0; i < pList->index; i++){
    printf("%d ", pList->array[i]);
  }
}