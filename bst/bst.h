#ifndef BST
#include <stdlib.h>
#define BST

typedef struct bst_type {
   int val;
   struct bst_type* left;
   struct bst_type* right;
} bst;



// Initializes a single bst node with a value v
bst* bst__init(int v) {
  bst* new_bst = malloc(sizeof(bst));
  new_bst->val = v;
  new_bst->left  = NULL;
  new_bst->right = NULL;

  return new_bst;
}



// Inserts a value v to a bst
void bst__insert(bst* my_bst, int v) {
  // Doesn't handle duplicate values
  if (v == my_bst->val) {
    printf("Duplicates not allowed\n");
  }

  // if v should go in the left subtree
  else if (v < my_bst->val) {
    if (my_bst->left == NULL) {
      bst* new_bst = bst__init(v);
      my_bst->left = new_bst;
    }

    else {
      bst__insert(my_bst->left, v);
    }
  }

  // if v should go in the right subtree
  else if (v > my_bst->val) {
    if (my_bst->right == NULL) {
      bst* new_bst = bst__init(v);
      my_bst->right = new_bst;
    }

    else {
      bst__insert(my_bst->right, v);
    }
  }
}



// Prints a bst 
void bst__print(bst* my_bst) {

  printf("%d", my_bst->val);

  // Prints left subtree
  if (my_bst->left != NULL) {
    printf(" l(");
    bst__print(my_bst->left);
    printf(")");
  }

  // Prints right subtree
  if (my_bst->right != NULL) {
    printf(" r(");
    bst__print(my_bst->right);
    printf(")");
  }
}



// Frees all the nodes of a bst
void bst__free(bst* my_bst) {

  // Frees nodes in left subtree
  if (my_bst->left != NULL) {
    bst__free(my_bst->left);
  }

  // Frees nodes in right subtree
  if (my_bst->right != NULL) {
    bst__free(my_bst->right);
  }

  // Frees root node
  printf("Freeing %d\n", my_bst->val);
  free(my_bst);
}



// Returns 1 if a value v is in the bst, 0 if not
int bst__search(bst* my_bst, int v) {
  // Didn't find it
  if (my_bst == NULL) {
    return 0;
  }

  // Did find it
  else if (v == my_bst->val) {
    return 1;
  }

  // Search left subtree
  else if (v < my_bst->val) {
    return bst__search(my_bst->left, v);
  }

  // Search right subtree
  else {
    return bst__search(my_bst->right, v);
  }
}



// Returns the number of nodes in the bst
int bst__num_nodes(bst* my_bst) {
  if (my_bst == NULL) {
    return 0;
  }

  else {
    int num_l = bst__num_nodes(my_bst->left);
    int num_r = bst__num_nodes(my_bst->right);
    return 1 + num_l + num_r;
  }
}




// Returns the height of the bst
int bst__height(bst* my_bst) {
  if (my_bst == NULL) {
    return 0;
  }

  else {
    int height_l = bst__height(my_bst->left);
    int height_r = bst__height(my_bst->right);

    if (height_l < height_r) {
      return 1 + height_r;
    }

    else {
      return 1 + height_l;
    }
  }
}



#endif
