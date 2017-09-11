#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


//==============================================================================
// Node:
//    struct for tree node
//==============================================================================
typedef struct Node {
   int32_t value;
   Node *left;
   Node *right;
} Node;

//==============================================================================
// generateNode():
//    generate a tree node with random integer value between min and max
//==============================================================================
Node* generateNode(int32_t min, int32_t max) {
   if(min > max) {
      return NULL;
   }
   
   Node *node = (Node*) malloc(sizeof(Node));
   node->left = node->right = NULL;
   node->value = (rand() % (max-min)) + min;

   return node;
}

//==============================================================================
// insert():
//    insert node into root; no duplications
//==============================================================================
Node* insert(Node *root, Node *node) {
   if(root == NULL) {
      return node;
   }
   if(node == NULL) {
      return root;
   }
   if(node->value == root->value) {
      return root;
   }

   if(node->value > root->value) {
      root->right = insert(root->right, node);
   }
   else {
      root->left  = insert(root->left, node);
   }

   return root;
}

//==============================================================================
// generateBST():
//    generate binary search tree with nodeAmount of nodes with values between
//    min to max
//==============================================================================
Node* generateBST(uint32_t nodeAmount, int32_t min, int32_t max) {
   if(nodeAmount < 0 || min > max) {
      return NULL;
   }

   Node *tree = generateNode(min, max);
   nodeAmount--;

   while(nodeAmount--) {
      Node *node = generateNode(min, max);
      tree = insert(tree, node);
   }
   return tree;
}


//==============================================================================
// visit():
//    print tree node's value
//==============================================================================
void visit(Node *n) {
   printf("%4d ", n->value);
}

//==============================================================================
// inOrderTraversal():
//    visit left, current, right
//==============================================================================
void inOrderTraversal(Node *node) {
   if(node) {
      inOrderTraversal(node->left);
      visit(node);
      inOrderTraversal(node->right);
   }
}

//==============================================================================
// preOrderTraversal():
//    visit current, left, right
//==============================================================================
void preOrderTraversal(Node *node) {
   if(node) {
      visit(node);
      preOrderTraversal(node->left);
      preOrderTraversal(node->right);
   }
}

//==============================================================================
// postOrderTraversal():
//    visit left, right, current
//==============================================================================
void postOrderTraversal(Node *node) {
   if(node) {
      postOrderTraversal(node->left);
      postOrderTraversal(node->right);
      visit(node);          
   }
}


//==============================================================================
// main():
//    tree test bench
//==============================================================================
int main() {

   srand(time(NULL));      // ONLY CALLED ONCE!

   Node *tree = generateBST(15, -50, 50);

   inOrderTraversal(tree);
   printf("\n");

   preOrderTraversal(tree);
   printf("\n");

   postOrderTraversal(tree);
   printf("\n");
   
   return 0;
}