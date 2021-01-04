#include <stdio.h>
#include "hash_table.h"

int main() {
  hash_table* my_ht = ht__init(41);
  ht__print(my_ht);

  for (int i=0; i<32; i++) {
    ht__insert(my_ht, i);
  }



  ht__print(my_ht);

  printf("30 in the table?: %d\n", ht__search(my_ht, 30));
  printf("33 in the table?: %d\n", ht__search(my_ht, 33));

  printf("Removing 18 from hash table: %d\n", ht__remove_key(my_ht, 18));
  printf("Removing 5 from hash table: %d\n", ht__remove_key(my_ht, 5));
  printf("Removing 4 from hash table: %d\n", ht__remove_key(my_ht, 4));
  printf("Removing 100 from hash table: %d\n", ht__remove_key(my_ht, 100));
  printf("Removing 4 from hash table: %d\n", ht__remove_key(my_ht, 14));


  ht__print(my_ht);



  ht__free(my_ht);
  return 0;
}
