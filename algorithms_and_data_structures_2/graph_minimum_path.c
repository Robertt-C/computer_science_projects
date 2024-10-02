#include <stdio.h>
#include <stdlib.h>

#define MAX 1215752192


struct node {
  int key; 
  int weight;
  struct node *predecessor;
  struct node *next;
};

typedef struct node *pNode;

struct graph {
  int verticesNumber;
  int edgesNumber;
  pNode *adjacentList;
};

typedef struct graph *pGraph;




pGraph initializeGraph(int, int);
void initializeRoot(pGraph, int);
void insertEdge(pGraph, int, int, int);
void deleteNodeList(pNode);
void removeGraph(pGraph);

void relax(pNode, pNode, int, int);
void BellmanFord(pGraph, int, int);

void printNodeList(pNode);
void printGraph(pGraph);
void printWeight(pGraph);




int main() {
  int i, root, verticesNumber, edgesNumber, initial, last, rule, weight;
  pGraph graph;
  
  scanf("%d", &root);
  
  scanf("%d", &rule);
  
  scanf("%d", &verticesNumber);
  scanf("%d", &edgesNumber);
  
  graph = initializeGraph(verticesNumber, edgesNumber);
  
  for (i = 1; i <= edgesNumber; i++) {
    scanf("%d", &initial);
    scanf("%d", &last);
    scanf("%d", &weight);
    
    insertEdge(graph, initial, last, weight);
  }
  
  BellmanFord(graph, root, rule);
  
  printWeight(graph);
  
  removeGraph(graph);
  
  return 0;
}




void initializeRoot(pGraph graph, int rootToSearch) {
  int i;
  
  for (i = 1; i <= graph->verticesNumber; i++) {
    graph->adjacentList[i - 1]->weight = MAX;
    graph->adjacentList[i - 1]->predecessor = graph->adjacentList[rootToSearch];
  }
  
  graph->adjacentList[rootToSearch]->weight = 0;
  graph->adjacentList[rootToSearch]->predecessor = NULL;
  
  return;
}


pGraph initializeGraph(int verticesNumber, int edgesNumber) {
  pGraph newGraph = (pGraph) malloc(sizeof(struct graph));
  int i;
  
  newGraph->verticesNumber = verticesNumber;
  newGraph->edgesNumber = edgesNumber;
  newGraph->adjacentList = (pNode*) malloc(verticesNumber * sizeof(pNode));
  
  for (i = 1; i <= verticesNumber; i++) {
    
    newGraph->adjacentList[i - 1] = (pNode) malloc(sizeof(struct node));
    newGraph->adjacentList[i - 1]->key = i;
    newGraph->adjacentList[i - 1]->weight = 0;
    newGraph->adjacentList[i - 1]->predecessor = NULL;
    newGraph->adjacentList[i - 1]->next = NULL;
    
  }
  
  return newGraph;
}


void insertEdge(pGraph graph, int initial, int last, int weight) {
  pNode newNode = (pNode) malloc(sizeof(struct node));
  newNode->key = last;
  newNode->weight = weight;
  
  pNode pAux = graph->adjacentList[initial];
  
  while (pAux->next != NULL && pAux->next->key < newNode->key) {
    pAux = pAux->next;
    
  }
  
  newNode->next = pAux->next;
  pAux->next = newNode;
  
  return;
}


void deleteNodeList(pNode node) {
  pNode pAux;
  
  while (node != NULL) {
    pAux = node->next;
    
    free(node);
    
    node = pAux;
  }
  
  return;
}


void removeGraph(pGraph graph) {
  int i;
  
  for (i = 1; i <= graph->verticesNumber; i++) {
    deleteNodeList(graph->adjacentList[i - 1]);
  }
  
  free(graph);
  
  return;
}


void relax(pNode uVertex, pNode vVertex, int edgeWeight, int rule) {
  
  if (uVertex->weight + edgeWeight < vVertex->weight && vVertex->predecessor != NULL && edgeWeight <= rule) {
    vVertex->predecessor = uVertex;
    vVertex->weight = uVertex->weight + edgeWeight;
  }
  
  return;
}


void BellmanFord(pGraph graph, int rootToSearch, int rule) {
  int i, j;
  
  initializeRoot(graph, rootToSearch);
  
  pNode pAux;
  for(i = 1; i <= graph->verticesNumber - 2; i++) {
    for(j = 1; j <= graph->verticesNumber; j++) {
      pAux = graph->adjacentList[j - 1];
      
      while (pAux->next != NULL) {
        pAux = pAux->next;
        
        relax(graph->adjacentList[j - 1], graph->adjacentList[pAux->key], pAux->weight, rule);
      }
    }
  }
  
  return;
}


void printNodeList(pNode node) {
  pNode pAux = node;
  
  while (pAux != NULL) {
    printf("%d ", pAux->key);
    pAux = pAux->next;
  }
  
  return;
}


void printGraph(pGraph graph) {
  int i;
  
  for (i = 1; i <= graph->verticesNumber; i++) {
    printNodeList(graph->adjacentList[i - 1]);
    
    printf("\n");
  }
  
  return;
}


void printWeight(pGraph graph) {
  int i;
  
  for (i = 1; i <= graph->verticesNumber; i++) {
    printf("%d ", graph->adjacentList[i - 1]->weight);
  }
  
  return;
}