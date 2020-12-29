#include <stdio.h>
#include "linked_list.h"

int main() {
  linked_list* my_ll = ll__init();
  ll__print(my_ll);

  ll__append(my_ll, 5);
  ll__append(my_ll, 6);
  ll__append(my_ll, 7);
  ll__append(my_ll, 57);
  ll__append(my_ll, 58);
  ll__append(my_ll, 59);

  ll__print(my_ll);

  printf("Removed head: %d\n", ll__remove_head(my_ll));
  
  ll__print(my_ll);



  ll__append(my_ll, 100);
  ll__print(my_ll);

  printf("search_ll 59: %d\n", ll__search(my_ll, 59));
  printf("search_ll 55: %d\n", ll__search(my_ll, 55));



  ll__free(my_ll);
  return 0;
}
