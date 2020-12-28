#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdlib.h>
#include "../linked_list/linked_list.h"

#define HT_SIZE 5

// Hash Table Data Structure (using closed address with linked lists)
typedef struct {
   linked_list* table[HT_SIZE];
   int size;
} hash_table;



// Using identity as hash function for now
int hash(int x) {
  return x;
}



// Initializes an empty hash_table
hash_table* ht__init() {

  hash_table* new_ht = malloc(sizeof(hash_table));

  new_ht->size = HT_SIZE;

  for (int i=0; i<HT_SIZE; i++) {
    new_ht->table[i] = NULL;
  }

  return new_ht;
}



// Adds a key to a hash_table
void ht__insert(hash_table* my_ht, int key) {
  int hashed_key = hash(key) % HT_SIZE;
  ll__append(my_ht->table[hashed_key], key);
}


// Checks if a key exists in the table
int ht__search(hash_table* my_ht, int key) {
  int hashed_key = hash(key) % HT_SIZE;
  return ll__search(my_ht->table[hashed_key], key);
}






// Prints a hash_table
void ht__print(hash_table* my_ht) {
  printf("====Hash Table====\n");

  for (int i=0; i<HT_SIZE; i++) {
    printf("%d: ", i);
    ll__print(my_ht->table[i]);
  }
}



// Frees the hash_table
void ht__free(hash_table* my_ht) {
  for (int i=0; i<HT_SIZE; i++) {
    linked_list* this_ll = my_ht->table[i];

    if (this_ll != NULL) {
      ll__free(this_ll);
    }
  }
  free(my_ht);
}





// Returns the size of the hash_table
int ht__size(hash_table* my_ht) {
  return my_ht->size;
}


#endif
