#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct BTreeNode {
  int *page;
  struct BTreeNode **child;
  int pagesNumber;
  bool leaf;
} TypeBTree;

TypeBTree *initializeBTree(TypeBTree *);
TypeBTree *createNode(bool, int);
void childSplit(TypeBTree *, int, TypeBTree *, int);
void insertIntoBTree(TypeBTree **, int, int);
void insertIntoBTree_(TypeBTree *, int, int);
TypeBTree *BTreeSearch(TypeBTree *, int);




int main() {
  TypeBTree *tree, *result;
  int treeOrder, num, toSearch, i;

  tree = initializeBTree(tree);
  scanf("%d", &treeOrder);

  scanf("%d", &num);

  while (num >= 0) {
    insertIntoBTree(&tree, num, treeOrder);
    scanf("%d", &num);
  }

  scanf("%d", &toSearch);
  result = BTreeSearch(tree, toSearch);
  printf("%d\n", tree->pagesNumber);

  if (result != NULL) {
    
    printf("%d\n", result->pagesNumber);
    
    for (i = 0; i < 2 * treeOrder; i++) {
      if (result->page[i] > 0) {
        printf("%d ", result->page[i]);
      }
    }
    
  } else {
    printf("Valor nao encontrado\n");
  }
  
  return 0;
}




//--- Btree functions
TypeBTree *initializeBTree(TypeBTree *tree) {
  return NULL;
}


TypeBTree *createNode(bool leaf, int w) {
  TypeBTree *newNode = malloc(sizeof(TypeBTree));
  newNode->page = malloc(((2 * w) - 1) * sizeof(int));
  newNode->child = (TypeBTree**) malloc(2 * w * sizeof(TypeBTree*));
  newNode->leaf = leaf;
  newNode->pagesNumber = -1;
  
  return newNode;
}


void childSplit(TypeBTree *fatherNode, int index, TypeBTree *childNode, int w) {
  TypeBTree *newNode = createNode(childNode->leaf, w);
  newNode->pagesNumber = w - 1;
  int i;
  
  for (i = 0; i < w - 1; i++) {
    newNode->page[i] = childNode->page[i + w];
  }

  if (!childNode->leaf) {
    for (i = 0; i < w; i++) {
      newNode->child[i] = childNode->child[i + w];
    }
  }

  childNode->pagesNumber = w - 1;

  for (i = fatherNode->pagesNumber; i > index; i--) {
    fatherNode->child[i + 1] = fatherNode->child[i];
  }

  fatherNode->child[index + 1] = newNode;

  for (i = fatherNode->pagesNumber - 1; i >= index; i--) {
    fatherNode->page[i + 1] = fatherNode->page[i];
  }

  fatherNode->page[index] = childNode->page[w - 1];
  fatherNode->pagesNumber++;
}


void insertIntoBTree(TypeBTree **tree, int page, int w) {
  TypeBTree *node = *tree;

  if (node == NULL) {
    TypeBTree *newNode = createNode(true, w);
    newNode->page[0] = page;
    newNode->pagesNumber = 1;
    *tree = newNode;
    return;
  }

  if (node->pagesNumber == ((2 * w) - 1)) {
    TypeBTree *newNode = createNode(false, w);
    newNode->child[0] = node;
    *tree = newNode;
    childSplit(newNode, 0, node, w);
    insertIntoBTree_(newNode, page, w);
  } else {
    insertIntoBTree_(node, page, w);
  }
}


void insertIntoBTree_(TypeBTree *node, int page, int w) {
  int i = node->pagesNumber - 1;

  if (node->leaf) {
    while (i >= 0 && page < node->page[i]) {
      node->page[i + 1] = node->page[i];
      i--;
    }
    node->page[i + 1] = page;
    node->pagesNumber++;
  } else {
    while (i >= 0 && page < node->page[i]) {
      i--;
    }
    i++;
    if (node->child[i]->pagesNumber == ((2 * w) - 1)) {
      childSplit(node, i, node->child[i], w);
      if (page > node->page[i]) {
        i++;
      }
    }
    insertIntoBTree_(node->child[i], page, w);
  }
}

TypeBTree *BTreeSearch(TypeBTree *tree, int page) {
  int i = 0;
  while (i < tree->pagesNumber && page > tree->page[i]) {
    i++;
  }
  
  if (tree->page[i] == page) {
    return tree;
  }
  if (tree->leaf == true) {
    return NULL;
  }
  return BTreeSearch(tree->child[i], page);
}