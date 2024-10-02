#include <stdio.h>
#include <stdlib.h>


// AVL tree structure and prototypes

typedef struct AVLNode {
  int key;
  int treeHeight;
  struct AVLNode *leftChild;
  struct AVLNode *rightChild;
} TypeAVLNode;


int emptyTree(TypeAVLNode*);
TypeAVLNode* initializeTree();
TypeAVLNode* destroyTree(TypeAVLNode*);
TypeAVLNode* newNode(int);
TypeAVLNode* removeNode(TypeAVLNode*, int);
TypeAVLNode* findSuccesor(TypeAVLNode*);
TypeAVLNode* searchInTree(TypeAVLNode*, int);
TypeAVLNode* insertIntoAVLTree(TypeAVLNode*, int, int*);
TypeAVLNode* leftRotate(TypeAVLNode*);
TypeAVLNode* rightRotate(TypeAVLNode*);

int getBalanceFactor(TypeAVLNode*);
int getLargestHeight(int, int);
int getTreeHeight(TypeAVLNode*);

void printTreeLevel(TypeAVLNode*, int);
void printTreeInOrder(TypeAVLNode*);


// Red-black tree structure and prototypes

typedef struct RBNode {
  int key;
  int color;
  struct RBNode* parent;
  struct RBNode* rightChild;
  struct RBNode* leftChild;
} TypeRBNode;
 
TypeRBNode* root = NULL;

TypeRBNode* initializeRBTree();
TypeRBNode* destroyRBTree(TypeRBNode*);
TypeRBNode* createNode(int);
TypeRBNode* insertIntoRBTree(TypeRBNode*, TypeRBNode*);
void rightRotateRB(TypeRBNode*);
void leftRotateRB(TypeRBNode*);
void fixRBTree(TypeRBNode*, TypeRBNode*, int*, int*);
int findRBTreeHeight(TypeRBNode*);
int findBlackHeight(TypeRBNode*, int*);




int main() {
  TypeRBNode *pAux;
  int RBTreeHeight, RBLeftTreeHeight, RBRightTreeHeight,
      blackHeight;
  
  TypeAVLNode *tree, *foundNode;
  int key;
  int i, treeHeight, leftTreeHeight, rightTreeHeight;
  
  int AVLRotations = 0, RBChangeColor = 0, RBRotations = 0;
  
  tree = initializeTree();
  
  
  scanf("%d", &key);
  
  while (key >= 0) {
    // Inserting into AVL tree.
    tree = insertIntoAVLTree(tree, key, &AVLRotations);
    
    
    // Inserting into red-black tree
    pAux = createNode(key);
    
    root = insertIntoRBTree(root, pAux);
    
    fixRBTree(root, pAux, &RBRotations, &RBChangeColor);
    
    root->color = 0;
    
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
  
  
  RBTreeHeight = findRBTreeHeight(root);
  RBLeftTreeHeight = findRBTreeHeight(root->leftChild);
  RBRightTreeHeight = findRBTreeHeight(root->rightChild);
  
  findBlackHeight(root, &blackHeight);
  
  printf("%d, %d, %d\n", treeHeight, leftTreeHeight, rightTreeHeight);
  printf("%d, %d, %d\n", RBTreeHeight - 1, RBLeftTreeHeight, RBRightTreeHeight);
  printf("%d\n", blackHeight);
  printf("%d, %d, %d", RBChangeColor, RBRotations, AVLRotations);
  
  tree = destroyTree(tree);
  root = destroyRBTree(root);
  
  return 0;
}




TypeAVLNode* initializeTree() {
  return NULL;
}


int emptyTree(TypeAVLNode *tree){
  return tree == NULL;
}


// build a node to insert into the tree.
TypeAVLNode* newNode(int key) {
  TypeAVLNode *node = (TypeAVLNode*) malloc(sizeof(TypeAVLNode));
  
  node->key = key;
  node->leftChild = NULL;
  node->rightChild = NULL;
  node->treeHeight = 1;
  
  return node;
}


TypeAVLNode* rightRotate(TypeAVLNode *node) {
  TypeAVLNode *pAux1 = node->leftChild;
  TypeAVLNode *pAux2 = pAux1->rightChild;
  
  pAux1->rightChild = node;
  node->leftChild = pAux2;
  
  node->treeHeight = getLargestHeight(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild)) + 1;
  pAux1->treeHeight = getLargestHeight(getTreeHeight(pAux1->leftChild), getTreeHeight(pAux1->rightChild)) + 1;
  
  return pAux1;
}


TypeAVLNode* leftRotate(TypeAVLNode *node) {
  TypeAVLNode *pAux1 = node->rightChild;
  TypeAVLNode *pAux2 = pAux1->leftChild;
  
  pAux1->leftChild = node;
  node->rightChild = pAux2;
  
  node->treeHeight = getLargestHeight(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild)) + 1;
  pAux1->treeHeight = getLargestHeight(getTreeHeight(pAux1->leftChild), getTreeHeight(pAux1->rightChild)) + 1;
  
  return pAux1;
}


int getBalanceFactor(TypeAVLNode *tree) {
  if (tree == NULL) {
    return 0;
  }
  
  return getTreeHeight(tree->leftChild) - getTreeHeight(tree->rightChild);
}


TypeAVLNode* insertIntoAVLTree(TypeAVLNode *node, int key, int *rotationsNumber) {
  if (node == NULL) {
    return newNode(key);
  }
  
  if (key < node->key) {
    node->leftChild  = insertIntoAVLTree(node->leftChild, key, rotationsNumber);
  } else if (key > node->key) {
    node->rightChild = insertIntoAVLTree(node->rightChild, key, rotationsNumber);
  } else {
    return node;
  }
  
  node->treeHeight = 1 + getLargestHeight(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild));
  
  int balanceFactor = getBalanceFactor(node);
  
  // LL
  if (balanceFactor > 1 && key < node->leftChild->key) {
    (*rotationsNumber)++;
    return rightRotate(node);
  }
  // RR
  if (balanceFactor < -1 && key > node->rightChild->key) {
    (*rotationsNumber)++;
    return leftRotate(node);
  }
  // LR
  if (balanceFactor > 1 && key > node->leftChild->key) {
    (*rotationsNumber)++;
    node->leftChild =  leftRotate(node->leftChild);
    return rightRotate(node);
  }
  
  // RL
  if (balanceFactor < -1 && key < node->rightChild->key) {
    (*rotationsNumber)++;
    node->rightChild = rightRotate(node->rightChild);
    return leftRotate(node);
  }
  
  return node;
}


TypeAVLNode* findSuccesor(TypeAVLNode *node) {
  TypeAVLNode *current = node;
  
  while (current->leftChild != NULL) {
    current = current->leftChild;
  }
  
  return current;
}


TypeAVLNode* removeNode(TypeAVLNode *root, int key) {
  if (root == NULL) {
    return root;
  }
  
  if (key < root->key) {
    root->leftChild = removeNode(root->leftChild, key);
  } else if ( key > root->key ) {
    root->rightChild = removeNode(root->rightChild, key);
  } else {
    if ((root->leftChild == NULL) || (root->rightChild == NULL)) {
      TypeAVLNode *pAux = root->leftChild ? root->leftChild : root->rightChild;
      
      if (pAux == NULL) {
        pAux = root;
        root = NULL;
      } else {
        *root = *pAux;
      }
      
      free(pAux);
    } else {
      TypeAVLNode *pAux = findSuccesor(root->rightChild);
      
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
TypeAVLNode* searchInTree(TypeAVLNode *tree, int info) {
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
int getTreeHeight(TypeAVLNode *tree) {
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


TypeAVLNode* destroyTree(TypeAVLNode *tree){
  if(!emptyTree(tree)){
    destroyTree(tree->leftChild);
    destroyTree(tree->rightChild);
    free(tree);
  }
  return NULL;
}


void preOrder(TypeAVLNode *root) {
  if(root != NULL) {
    printf("%d ", root->key);
    preOrder(root->leftChild);
    preOrder(root->rightChild);
  }
}


void printTreeLevel(TypeAVLNode *tree, int treeLevel) {
  if (tree != NULL && treeLevel == 0) {
    
    printf("%d ", tree->key);
    
  } else if (tree != NULL) {
    printTreeLevel(tree->leftChild, treeLevel - 1);
    printTreeLevel(tree->rightChild, treeLevel - 1);
  }
  
  return;
}


void printTreeInOrder(TypeAVLNode *tree) {
  if (!emptyTree(tree)) {
    printTreeInOrder(tree->leftChild);
    
    printf("%d ", tree->key);
    
    printTreeInOrder(tree->rightChild);
  }
}








//----------------------------------------------------

// Red-black tree functions.

TypeRBNode* createNode(int key) {
  TypeRBNode* temp = (TypeRBNode*) malloc(sizeof(TypeRBNode));
  
  temp->rightChild = NULL;
  temp->leftChild = NULL;
  temp->parent = NULL;
  temp->key = key;
  temp->color = 1;
  
  return temp;
}


TypeRBNode* insertIntoRBTree(TypeRBNode *trav, TypeRBNode *temp) {
  if (trav == NULL) {
    return temp;
  }
  
  if (temp->key < trav->key) {
    trav->leftChild = insertIntoRBTree(trav->leftChild, temp);
    trav->leftChild->parent = trav;
  } else if (temp->key > trav->key) {
    trav->rightChild = insertIntoRBTree(trav->rightChild, temp);
    trav->rightChild->parent = trav;
  }
  
  return trav;
}


void rightRotateRB(TypeRBNode *temp) {
  TypeRBNode *left = temp->leftChild;
  temp->leftChild = left->rightChild;
  
  if (temp->leftChild) {
    temp->leftChild->parent = temp;
  }
  left->parent = temp->parent;
  
  if (!temp->parent) {
    root = left;
  } else if (temp == temp->parent->leftChild) {
    temp->parent->leftChild = left;
  } else {
    temp->parent->rightChild = left;
  }
  
  left->rightChild = temp;
  temp->parent = left;
}


void leftRotateRB(TypeRBNode* temp) {
  TypeRBNode* right = temp->rightChild;
  temp->rightChild = right->leftChild;
  
  if (temp->rightChild) {
    temp->rightChild->parent = temp;
  }
  right->parent = temp->parent;
  
  if (!temp->parent) {
    root = right;
  } else if (temp == temp->parent->leftChild) {
    temp->parent->leftChild = right;
  } else {
    temp->parent->rightChild = right;
  }
  right->leftChild = temp;
  temp->parent = right;
}


void fixRBTree(TypeRBNode* root, TypeRBNode* parent, int *rotationsNumber, int *changeColorsNumber) {
  TypeRBNode* ptParent = NULL;
  TypeRBNode* ptGrandParent = NULL;
  
  
  while ((parent != root) && (parent->color != 0) && (parent->parent->color == 1)) {
    ptParent = parent->parent;
    ptGrandParent = parent->parent->parent;
    
    // A Parent's parent is left child of Grand-parent of parent
    if (ptParent == ptGrandParent->leftChild) {
      TypeRBNode* ptUncle = ptGrandParent->rightChild;
      // Parent's uncle is red
      if (ptUncle != NULL && ptUncle->color == 1) {
        (*changeColorsNumber)++;
        ptGrandParent->color = 1;
        (*changeColorsNumber)++;
        ptParent->color = 0;
        (*changeColorsNumber)++;
        ptUncle->color = 0;
        parent = ptGrandParent;
      } else {
        // Parent is right child of parent
        if (parent == ptParent->rightChild) {
          (*rotationsNumber)++;
          leftRotateRB(ptParent);
          parent = ptParent;
          ptParent = parent->parent;
        }
        
        (*rotationsNumber)++;
        rightRotateRB(ptGrandParent);
        int auxColor = ptParent->color;
        (*changeColorsNumber)++;
        ptParent->color = ptGrandParent->color;
        (*changeColorsNumber)++;
        ptGrandParent->color = auxColor;
        parent = ptParent;
      }
    } else {
      // Parent's parent is right child of Grand-parent of parent
      TypeRBNode* ptUncle = ptGrandParent->leftChild;
      // Parent's uncle is red
      if ((ptUncle != NULL) && (ptUncle->color == 1)) {
        (*changeColorsNumber)++;
        ptGrandParent->color = 1;
        (*changeColorsNumber)++;
        ptParent->color = 0;
        (*changeColorsNumber)++;
        ptUncle->color = 0;
        parent = ptGrandParent;
      } else {
        // Parent is left child of parent
        if (parent == ptParent->leftChild) {
          (*rotationsNumber)++;
          rightRotateRB(ptParent);
          parent = ptParent;
          ptParent = parent->parent;
        }
        // Parent is right child of parent 
        (*rotationsNumber)++;
        leftRotateRB(ptGrandParent);
        int auxColor = ptParent->color;
        (*changeColorsNumber)++;
        ptParent->color = ptGrandParent->color;
        (*changeColorsNumber)++;
        ptGrandParent->color = auxColor;
        parent = ptParent;
      }
    }
  }
}


TypeRBNode* destroyRBTree(TypeRBNode *tree){
  if(tree != NULL){
    destroyRBTree(tree->leftChild);
    destroyRBTree(tree->rightChild);
    free(tree);
  }
  return NULL;
}


TypeRBNode* initializeRBTree() {
  return NULL;
}


int findRBTreeHeight(TypeRBNode *tree) {
  int leftTreeHeight, rightTreeHeight;
  
  if (tree == NULL) {
    return 0;
  } else {
    leftTreeHeight = findRBTreeHeight(tree->leftChild);
    rightTreeHeight = findRBTreeHeight(tree->rightChild);
    
    if (leftTreeHeight >= rightTreeHeight) {
      return leftTreeHeight + 1;
    } else {
      return rightTreeHeight + 1;
    }
  }
}


int findBlackHeight(TypeRBNode *tree, int *blackHeight){
  if (tree == NULL) {
    return 0;
  }
  if (tree->color == 0) {
   (*blackHeight)++;
  }
  findBlackHeight(tree->leftChild , blackHeight);
  
  return 0;
}