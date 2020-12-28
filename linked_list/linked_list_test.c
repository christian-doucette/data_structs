#include <stdio.h>
#include "linked_list.h"

int main() {
  linked_list* my_ll = ll__init(3);
  ll__print(my_ll);

  ll__append(my_ll, 5);
  ll__print(my_ll);

  ll__append(my_ll, 100);
  ll__print(my_ll);

  printf("search_ll 4: %d\n", ll__search(my_ll, 4));
  printf("search_ll 5: %d\n", ll__search(my_ll, 5));
  printf("len: %d\n", ll__len(my_ll));



  ll__free(my_ll);
  return 0;
}
