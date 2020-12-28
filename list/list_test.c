#include <stdio.h>
#include "list.h"

int main() {
  list* my_list = list__init(3);
  list__print(my_list);

  list__append(my_list, 5);
  list__print(my_list);

  list__append(my_list, 100);
  list__print(my_list);


  list__append(my_list, 105);
  list__print(my_list);

  list__append(my_list, 5);
  list__print(my_list);

  list__remove_last(my_list);
  list__print(my_list);

  list__remove_last(my_list);
  list__print(my_list);

  list__remove_last(my_list);
  list__print(my_list);

  list__remove_last(my_list);
  list__print(my_list);

  list__remove_last(my_list);
  list__print(my_list);

  list__remove_last(my_list);
  list__print(my_list);

  list__append(my_list, 65);
  list__append(my_list, 66);
  list__append(my_list, 67);
  list__append(my_list, 68);
  list__append(my_list, 69);


  list__print(my_list);


  printf("%d\n", list__index(my_list, 0));
  printf("%d\n", list__index(my_list, 10));




  //printf("search_list 4: %d\n", search_list(my_list, 4));
  //printf("search_list 5: %d\n", search_list(my_list, 5));
  //printf("len: %d\n", len_list(my_list));



  list__free(my_list);
  return 0;
}
