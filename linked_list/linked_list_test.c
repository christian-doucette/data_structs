#include <stdio.h>
#include "linked_list.h"

int main() {
  linked_list* my_ll = ll__init();
  ll__print(my_ll);


  printf("Is empty?: %d\n", ll__is_empty(my_ll));
  printf("Removing 5: %d\n", ll__remove_val(my_ll, 5));



  ll__append(my_ll, 5);
  ll__append(my_ll, 6);
  ll__append(my_ll, 7);
  ll__append(my_ll, 57);
  ll__append(my_ll, 58);
  ll__append(my_ll, 59);



  ll__print(my_ll);
  printf("Current length: %d\n", my_ll->len);
  printf("Is empty?: %d\n", ll__is_empty(my_ll));
  //printf("Removing 5: %d\n", ll__remove_val(my_ll, 5));
  //ll__print(my_ll);

  //printf("Removing 60: %d\n", ll__remove_val(my_ll, 60));
  //ll__print(my_ll);



  printf("Removing 59: %d\n", ll__remove_val(my_ll, 59));
  ll__print(my_ll);
  printf("Current length: %d\n", my_ll->len);

  printf("Removing 57: %d\n", ll__remove_val(my_ll, 57));
  ll__print(my_ll);
  printf("Current length: %d\n", my_ll->len);






  printf("Removing 590: %d\n", ll__remove_val(my_ll, 590));
  ll__print(my_ll);
  printf("Current length: %d\n", my_ll->len);





  printf("Removed head: %d\n", ll__remove_head(my_ll));
  ll__print(my_ll);
  printf("Current length: %d\n", my_ll->len);



  ll__append(my_ll, 100);
  ll__print(my_ll);
  printf("Current length: %d\n", my_ll->len);



  printf("Searching for 59: %d\n", ll__search(my_ll, 59));
  printf("Searching for 58: %d\n", ll__search(my_ll, 58));



  ll__free(my_ll);
  return 0;
}
