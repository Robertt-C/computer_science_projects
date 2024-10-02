#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {
  int key;
  int treeHeight;
  struct treeNode *leftChild;
  struct treeNode *rightChild;
} TypeTreeNode;


int emptyTree(TypeTreeNode*);
TypeTreeNode* initializeTree();
TypeTreeNode* destroyTree(TypeTreeNode*);
TypeTreeNode* newNode(int);
TypeTreeNode* removeNode(TypeTreeNode*, int);
TypeTreeNode* findSuccesor(TypeTreeNode*);
TypeTreeNode* searchInTree(TypeTreeNode*, int);
TypeTreeNode* insertIntoAVLTree(TypeTreeNode*, int);
TypeTreeNode* leftRotate(TypeTreeNode*);
TypeTreeNode* rightRotate(TypeTreeNode*);

int getBalanceFactor(TypeTreeNode*);
int getLargestHeight(int, int);
int getTreeHeight(TypeTreeNode*);

void printTreeLevel(TypeTreeNode*, int);
void printTreeInOrder(TypeTreeNode*);



int main() {
  TypeTreeNode *tree, *foundNode;
  int key;
  int i, treeHeight, leftTreeHeight, rightTreeHeight;
  
  tree = initializeTree();
  
  
  scanf("%d", &key);
  
  while (key >= 0) {
    
    tree = insertIntoAVLTree(tree, key);
    
    scanf("%d", &key);
  }
  
  // not falling in segmentation fault.
  if (tree != NULL) {
    treeHeight = tree->treeHeight - 1;
    if (tree->leftChild != NULL) {
      leftTreeHeight = tree->leftChild->treeHeight;
    } else {
      leftTreeHeight = 0;
    }
    
    if (tree->rightChild != NULL) {
      rightTreeHeight = tree->rightChild->treeHeight;
    } else {
      rightTreeHeight = 0;
    }
  }
  
  /*
  for (i = 0; i < treeHeight; i++) {
    printf("Tree Level: [%d]\n", i);
    printTreeLevel(tree, i);
    printf("\n\n");
  }
  */
  
  // Second input: if the key is already in the tree, remove it, if it's not, add it to the tree.
  scanf("%d", &key);
  
  while (key >= 0) {
    
    if (searchInTree(tree, key) != NULL) {
      tree = removeNode(tree, key);
    } else {
      tree = insertIntoAVLTree(tree, key);
    }
    
    scanf("%d", &key);
  }
  
  
  // Searching for a node in the AVL tree.
  scanf("%d", &key);
  foundNode = searchInTree(tree, key);
  
  printf("%d, %d, %d\n", treeHeight, leftTreeHeight, rightTreeHeight);
  
  // not falling in segmentation fault.
  if (foundNode != NULL) {
    if (foundNode->leftChild != NULL && foundNode->rightChild != NULL) {
      printf("%d, %d, %d\n", foundNode->treeHeight - 1, foundNode->leftChild->treeHeight, foundNode->rightChild->treeHeight);
      
    } else if (foundNode->leftChild != NULL) {
      printf("%d, %d, %d\n", foundNode->treeHeight - 1, foundNode->leftChild->treeHeight, 0);
      
    } else if (foundNode->rightChild != NULL) {
      printf("%d, %d, %d\n", foundNode->treeHeight - 1, 0, foundNode->rightChild->treeHeight);
      
    } else {
      printf("%d, %d, %d\n", foundNode->treeHeight - 1, 0, 0);
    }
    
  } else {
    printf("Valor nao encontrado\n");
  }
  
  
  /*
  for (i = 0; i < treeHeight; i++) {
    printf("Tree Level: [%d]\n", i);
    printTreeLevel(tree, i);
    printf("\n\n");
  }
  */
    
  tree = destroyTree(tree);
  
  return 0;
}




TypeTreeNode* initializeTree() {
  return NULL;
}


int emptyTree(TypeTreeNode *tree){
  return tree == NULL;
}


// build a node to insert into the tree.
TypeTreeNode* newNode(int key) {
  TypeTreeNode *node = (TypeTreeNode*) malloc(sizeof(TypeTreeNode));
  
  node->key = key;
  node->leftChild = NULL;
  node->rightChild = NULL;
  node->treeHeight = 1;
  
  return node;
}


TypeTreeNode* rightRotate(TypeTreeNode *node) {
  TypeTreeNode *pAux1 = node->leftChild;
  TypeTreeNode *pAux2 = pAux1->rightChild;
  
  pAux1->rightChild = node;
  node->leftChild = pAux2;
  
  node->treeHeight = getLargestHeight(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild)) + 1;
  pAux1->treeHeight = getLargestHeight(getTreeHeight(pAux1->leftChild), getTreeHeight(pAux1->rightChild)) + 1;
  
  return pAux1;
}


TypeTreeNode* leftRotate(TypeTreeNode *node) {
  TypeTreeNode *pAux1 = node->rightChild;
  TypeTreeNode *pAux2 = pAux1->leftChild;
  
  pAux1->leftChild = node;
  node->rightChild = pAux2;
  
  node->treeHeight = getLargestHeight(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild)) + 1;
  pAux1->treeHeight = getLargestHeight(getTreeHeight(pAux1->leftChild), getTreeHeight(pAux1->rightChild)) + 1;
  
  return pAux1;
}


int getBalanceFactor(TypeTreeNode *tree) {
  if (tree == NULL) {
    return 0;
  }
  
  return getTreeHeight(tree->leftChild) - getTreeHeight(tree->rightChild);
}


TypeTreeNode* insertIntoAVLTree(TypeTreeNode *node, int key) {
  if (node == NULL) {
    return newNode(key);
  }
  
  if (key < node->key) {
    node->leftChild  = insertIntoAVLTree(node->leftChild, key);
  } else if (key > node->key) {
    node->rightChild = insertIntoAVLTree(node->rightChild, key);
  } else {
    return node;
  }
  
  node->treeHeight = 1 + getLargestHeight(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild));
  
  int balanceFactor = getBalanceFactor(node);
  
  // LL
  if (balanceFactor > 1 && key < node->leftChild->key) {
    return rightRotate(node);
  }
  // RR
  if (balanceFactor < -1 && key > node->rightChild->key) {
    return leftRotate(node);
  }
  // LR
  if (balanceFactor > 1 && key > node->leftChild->key) {
    node->leftChild =  leftRotate(node->leftChild);
    return rightRotate(node);
  }
  
  // RL
  if (balanceFactor < -1 && key < node->rightChild->key) {
    node->rightChild = rightRotate(node->rightChild);
    return leftRotate(node);
  }
  
  return node;
}


TypeTreeNode* findSuccesor(TypeTreeNode *node) {
  TypeTreeNode *current = node;
  
  while (current->leftChild != NULL) {
    current = current->leftChild;
  }
  
  return current;
}


TypeTreeNode* removeNode(TypeTreeNode *root, int key) {
  if (root == NULL) {
    return root;
  }
  
  if (key < root->key) {
    root->leftChild = removeNode(root->leftChild, key);
  } else if ( key > root->key ) {
    root->rightChild = removeNode(root->rightChild, key);
  } else {
    if ((root->leftChild == NULL) || (root->rightChild == NULL)) {
      TypeTreeNode *pAux = root->leftChild ? root->leftChild : root->rightChild;
      
      if (pAux == NULL) {
        pAux = root;
        root = NULL;
      } else {
        *root = *pAux;
      }
      
      free(pAux);
    } else {
      TypeTreeNode *pAux = findSuccesor(root->rightChild);
      
      root->key = pAux->key;
      
      root->rightChild = removeNode(root->rightChild, pAux->key);
    }
  }
  
  if (root == NULL) {
    return root;
  }
  
  root->treeHeight = 1 + getLargestHeight(getTreeHeight(root->leftChild), getTreeHeight(root->rightChild));
  
  int balanceFactor = getBalanceFactor(root);
  
  // LL
  if (balanceFactor > 1 && getBalanceFactor(root->leftChild) >= 0) {
    return rightRotate(root);
  }
  // LR
  if (balanceFactor > 1 && getBalanceFactor(root->leftChild) < 0) {
    root->leftChild =  leftRotate(root->leftChild);
    return rightRotate(root);
  }
  
  // RR
  if (balanceFactor < -1 && getBalanceFactor(root->rightChild) <= 0) {
    return leftRotate(root);
  }
  
  // RL
  if (balanceFactor < -1 && getBalanceFactor(root->rightChild) > 0) {
    root->rightChild = rightRotate(root->rightChild);
    return leftRotate(root);
  }

  return root;
}

// Search node in the tree.
TypeTreeNode* searchInTree(TypeTreeNode *tree, int info) {
  if (!emptyTree(tree)) {
    if (tree->key > info) {
      return searchInTree(tree->leftChild, info);
    } else if (tree->key < info) {
      return searchInTree(tree->rightChild, info);
    } else {
      return tree;
    }
  }
  
  return NULL;
}


// Returns a specific tree height.
int getTreeHeight(TypeTreeNode *tree) {
  if (tree == NULL) {
    return 0;
  }
  
  return tree->treeHeight;
}


// Function to compare tree heights.
int getLargestHeight(int height1, int height2) {
  if (height1 > height2) {
    return height1;
  } else {
    return height2;
  }
}


TypeTreeNode* destroyTree(TypeTreeNode *tree){
  if(!emptyTree(tree)){
    destroyTree(tree->leftChild);
    destroyTree(tree->rightChild);
    free(tree);
  }
  return NULL;
}


void preOrder(TypeTreeNode *root) {
  if(root != NULL) {
    printf("%d ", root->key);
    preOrder(root->leftChild);
    preOrder(root->rightChild);
  }
}


void printTreeLevel(TypeTreeNode *tree, int treeLevel) {
  if (tree != NULL && treeLevel == 0) {
    
    printf("%d ", tree->key);
    
  } else if (tree != NULL) {
    printTreeLevel(tree->leftChild, treeLevel - 1);
    printTreeLevel(tree->rightChild, treeLevel - 1);
  }
  
  return;
}


void printTreeInOrder(TypeTreeNode *tree) {
  if (!emptyTree(tree)) {
    printTreeInOrder(tree->leftChild);
    
    printf("%d ", tree->key);
    
    printTreeInOrder(tree->rightChild);
  }
}