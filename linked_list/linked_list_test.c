#include <stdio.h>
#include "linked_list.h"

int main() {
  linked_list* my_ll = init_ll(3);
  print_ll(my_ll);

  append_ll(my_ll, 5);
  print_ll(my_ll);

  append_ll(my_ll, 100);
  print_ll(my_ll);

  printf("search_ll 4: %d\n", search_ll(my_ll, 4));
  printf("search_ll 5: %d\n", search_ll(my_ll, 5));
  printf("len: %d\n", len_ll(my_ll));



  free_ll(my_ll);
  return 0;
}
