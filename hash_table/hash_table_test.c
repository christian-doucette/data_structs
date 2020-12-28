#include <stdio.h>
#include "hash_table.h"

int main() {
  hash_table* my_ht = ht__init();
  ht__print(my_ht);


  ht__insert(my_ht, 5);
  ht__insert(my_ht, 6);
  ht__insert(my_ht, 3);

  ht__print(my_ht);


  ht__free(my_ht);
  return 0;
}
