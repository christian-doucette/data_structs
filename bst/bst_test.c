#include <stdio.h>
#include "bst.h"

int main() {
  bst* my_bst = bst__init(15);

  bst__insert(my_bst, 6);
  bst__insert(my_bst, 16);
  bst__insert(my_bst, 3);
  bst__insert(my_bst, 7);
  bst__insert(my_bst, 100);

  bst__print(my_bst);
  printf("\n");



  printf("height: %d\n", bst__height(my_bst));
  printf("num nodes: %d\n", bst__num_nodes(my_bst));
  printf("min value: %d\n", bst__min(my_bst));
  printf("is 5 in tree?: %d\n", bst__search(my_bst, 5));
  printf("is 6 in tree?: %d\n", bst__search(my_bst, 6));
  printf("is 7 in tree?: %d\n", bst__search(my_bst, 7));




  bst__free(my_bst);
  return 0;
}
