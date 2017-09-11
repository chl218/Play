#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define DEBUG 1

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
// insert(tree, value):
//    insert value into tree
//==============================================================================
Node* insert(Node *root, int32_t value) {
   if(root == NULL) {
      Node *node  = (Node*)malloc(sizeof(Node));
      node->left  = node->right = NULL;
      node->value = value;
      return node;
   }

   if(root->value == value) {
      return root;
   }

   if(value > root->value) {
      root->right = insert(root->right, value);
   }
   else {
      root->left  = insert(root->left, value);
   }

   return root;
}


//==============================================================================
// remove(tree, value):
//    remove value from tree'
//==============================================================================
Node* remove(Node *root, int32_t value) {

   if(root == NULL) {
      return NULL;
   }

   if(value > root->value) {
      root->right = remove(root->right, value);
   }
   else if(value < root->value) {
      root->left = remove(root->left, value);
   }
   else {
      if(root->right == NULL && root->left == NULL) {
         free(root);
         return NULL;
      }

      if(root->left == NULL) {
         Node *tmp = root->right;
         free(root);
         return tmp;
      }

      if(root->right == NULL) {
         Node *tmp = root->left;
         free(root);
         return tmp;
      }


      Node *top = root;

      root = root->right;
      while(root->left != NULL) {
         root = root->left;
      }

      top->value = root->value;
      top->right = remove(top->right, top->value);

      return top;
   }

   return root;
}

//==============================================================================
// exist(tree, value):
//    search if value in tree
//==============================================================================
bool contains(Node *root, int32_t value) {
   if(root == NULL) {
      return false;
   }

   if(value > root->value) {
      return contains(root->right, value);
   }
   else {
      return contains(root->left, value);
   }

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
// generateBST():
//    generate binary search tree with nodeAmount of nodes with values between
//    min to max
//==============================================================================
Node* generateBST(uint32_t nodeAmount, int32_t min, int32_t max) {
   if(nodeAmount < 0 || min > max) {
      return NULL;
   }

   Node *tree = NULL;
   
   while(nodeAmount--) {
      int32_t value = (rand() % (max-min)) + min;
      if(DEBUG) {
         printf("Insert: %3d\t Tree: ", value);
         inOrderTraversal(tree);
         printf("\n");
      }
      tree = insert(tree, value);
   }
   return tree;
}


//==============================================================================
// main():
//    tree test bench
//==============================================================================

#define MK_AMT 15
#define RM_AMT 5

#define MIN -50
#define MAX  50


int main() {

   srand(time(NULL));      // ONLY CALLED ONCE!

   Node *tree = generateBST(MK_AMT, MIN, MAX);

   printf("In-Order:   ");
   inOrderTraversal(tree);
   printf("\n");

   printf("Pre-Order:  ");
   preOrderTraversal(tree);
   printf("\n");
   
   printf("Post-Order: ");
   postOrderTraversal(tree);
   printf("\n");
   

   for(int i = 0; i < RM_AMT; i++) {
      int32_t value = (rand() % (MAX-MIN)) + MIN;
      printf("Remove: %3d\t Tree: ", value);
      tree = remove(tree, value);
      inOrderTraversal(tree);
      printf("\n");
   }


   return 0;
}