#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdlib.h>
#include "../linked_list/linked_list.h"



//=========================//
//    Hash Table Struct    //
//=========================//

// Hash Table Data Structure
// Using Closed Addressing  with Linked Lists to resolve collision

typedef struct {
   linked_list** table;
   int size;
} hash_table;





//=========================//
//      Hash Function      //
//=========================//

// Using 32-bit integer hash function from here: https://stackoverflow.com/a/12996028/14056167
int hash(int x) {
  x = ((x >> 16) ^ x) * 0x45D9F3B;
  x = ((x >> 16) ^ x) * 0X45D9F3B;
  x = (x >> 16) ^ x;
  return x;
}







//=========================//
//    Hash Table Methods   //
//=========================//

// Initializes an empty hash_table
hash_table* ht__init(int size) {

  hash_table* new_ht = malloc(sizeof(hash_table));

  linked_list** ll_pointers_list = malloc(size * sizeof(linked_list*));

  for (int i=0; i<size; i++) {
    ll_pointers_list[i] = ll__init();
  }

  new_ht->size = size;
  new_ht->table = ll_pointers_list;
  return new_ht;
}





// Prints a hash_table
void ht__print(hash_table* my_ht) {
  printf("====Hash Table====\n");

  for (int i = 0; i < (my_ht->size); i++) {
    printf("%d: ", i);
    ll__print(my_ht->table[i]);
  }
  printf("==================\n\n");
}






// Frees the hash_table
void ht__free(hash_table* my_ht) {
  for (int i = 0; i < (my_ht->size); i++) {
    linked_list* this_ll = my_ht->table[i];

    if (this_ll != NULL) {
      ll__free(this_ll);
    }
  }
  free(my_ht->table);
  free(my_ht);
}





// Adds a key to a hash_table
void ht__insert(hash_table* my_ht, int key) {
  int hashed_key = hash(key) % (my_ht->size);
  ll__append(my_ht->table[hashed_key], key);
}




// Removes a key from a hash_table - returns 0 if it was found, 0 otherwise
int ht__remove_key(hash_table* my_ht, int key) {
  int hashed_key = hash(key) % (my_ht->size);
  return ll__remove_val(my_ht->table[hashed_key], key);
}




// Checks if a key exists in the table
int ht__search(hash_table* my_ht, int key) {
  int hashed_key = hash(key) % (my_ht->size);
  return ll__search(my_ht->table[hashed_key], key);
}





// Returns the size of the hash_table
int ht__size(hash_table* my_ht) {
  return my_ht->size;
}


#endif
