#include <stdio.h>
#include "bst.h"

int main() {
  bst* my_bst = init_bst(15);

  add_bst(my_bst, 6);
  add_bst(my_bst, 16);
  add_bst(my_bst, 3);
  add_bst(my_bst, 7);
  add_bst(my_bst, 1);

  print_bst(my_bst);
  printf("\n");



  printf("height: %d\n", height_bst(my_bst));
  printf("num nodes: %d\n", num_nodes_bst(my_bst));


  free_bst(my_bst);
  return 0;
}
