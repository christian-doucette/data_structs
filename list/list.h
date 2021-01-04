#ifndef LIST
#define LIST

#include <stdlib.h>


//=========================//
//       List Struct       //
//=========================//

// Dynamic sized array like Python list or Java arraylist
// It doubles the memory each time it is filled
// And when it reaches a quarter of full capacity, halfs the capacity

typedef struct {
   int *vals;
   int cur_size; // amount of memory currently used
   int max_size; // amount of memory currently allocated
} list;




//=========================//
//      List Methods       //
//=========================//

// Initializes a list with a single value v
list* list__init(int v) {
  list* new_list = malloc(sizeof(list));

  new_list->vals = malloc(4 * sizeof(int));
  new_list->vals[0] = v;

  new_list->cur_size = 1;
  new_list->max_size = 4;

  return new_list;
}





// Prints a list
void list__print(list* my_list) {
  printf("[");

  for (int i=0; i<my_list->cur_size; i++) {
    printf(" %d ", my_list->vals[i]);
  }

  printf("]\n");

}




// Frees the list
void list__free(list* my_list) {
  free(my_list->vals);
  free(my_list);
}






// Appends a value v to a list
void list__append(list* my_list, int v) {
  int cur_size = my_list->cur_size;
  int max_size = my_list->max_size;
  int* vals    = my_list->vals;

  // Enough memory: can just add the new value
  if (cur_size < max_size) {
    my_list->vals[cur_size] = v;
    my_list->cur_size = cur_size + 1;
  }

  // Need to allocate more memory
  else {
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





// Removes the last value of a list
void list__remove_last(list* my_list) {
  // If list is empty, notifies and does nothing
  if (my_list->cur_size == 0) {
    printf("This list is empty.\n");
    return;
  }

  my_list->cur_size -= 1;
  int cur_size = my_list->cur_size;

  // Deallocating half the memory if it is a quarter of max size (with a minimum size of 4)
  if (4 * cur_size <= my_list->max_size && 1 < cur_size) {
    int* new_vals = malloc(2 * cur_size * sizeof(int));

    for (int i=0; i<cur_size; i++) {
      new_vals[i] = my_list->vals[i];
    }

    free(my_list->vals);
    my_list->vals = new_vals;

    my_list->max_size = 2 * cur_size;
  }

  return;
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
