#ifndef LIST
#include <stdlib.h>
#define LIST

// Dynamic sized array like Python list or Java arraylist
typedef struct list_type {
   int *vals;
   int cur_size; // amount of memory currently used
   int max_size; // amount of memory currently allocated
} list;



// Initializes a list with a single value v
list* list__init(int v) {
  list* new_list = malloc(sizeof(list));

  new_list->vals = malloc(sizeof(int));
  new_list->vals[0] = v;

  new_list->cur_size = 1;
  new_list->max_size = 1;

  return new_list;
}



// Appends a value v to a list
void list__append(list* my_list, int v) {
  int cur_size = my_list->cur_size;
  int max_size = my_list->max_size;
  int* vals    = my_list->vals;

  // Enough memory: can just add the new value
  if (cur_size < max_size) {
    printf("good for now!");
    my_list->vals[cur_size] = v;
    my_list->cur_size = cur_size + 1;
  }

  // Need to allocate more memory
  else {
    printf("allocating more memory");
    int* new_vals = malloc(2 * max_size * sizeof(int));

    for (int i=0; i<cur_size; i++) {
      new_vals[i] = my_list->vals[i];
    }
    new_vals[cur_size] = v;

    free(my_list->vals);
    my_list->vals = new_vals;
    my_list->cur_size = cur_size + 1;
    my_list->max_size = 2 * max_size;
  }

  return;
}




// Appends a value v to a list
void list__remove_last(list* my_list) {
  // Currently don't deallocate any memory for this operation
  // Doing that might be good, depending on how it's used
  my_list->cur_size -= 1;
  return;
}



// Prints a list
void list__print(list* my_list) {
  printf("[");

  for (int i=0; i<my_list->cur_size-1; i++) {
    printf("%d, ", my_list->vals[i]);
  }

  printf("%d]\n", my_list->vals[my_list->cur_size - 1]);

}



// Frees the list
void list__free(list* my_list) {
  free(my_list->vals);
  free(my_list);
}



// Returns value at a given index
int list__index(list* my_list, int index) {
  if (index < 0 || my_list->cur_size <= index) {
    printf("Index %d out of bounds: should be between 0 and %d\n", index, my_list->cur_size-1);
    return -1;
  }

  else {
    return my_list->vals[index];
  }
}



// Returns the length of the list
int list__len(list* my_list) {
  return my_list->cur_size;
}


#endif
