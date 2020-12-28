#ifndef STACK
#include <stdlib.h>
#define STACK

// Stack data Structure (using dynamic array)
typedef struct {
   int *vals;
   int cur_size; // amount of memory currently used
   int max_size; // amount of memory currently allocated
} stack;



// Initializes an empty stack
stack* stack__init() {
  stack* new_stack = malloc(sizeof(stack));

  new_stack->vals = malloc(4 * sizeof(int));

  new_stack->cur_size = 0;
  new_stack->max_size = 4;

  return new_stack;
}



// Appends a value v to a stack
void stack__push(stack* my_stack, int v) {
  int cur_size = my_stack->cur_size;
  int max_size = my_stack->max_size;
  int* vals    = my_stack->vals;

  // Enough memory: can just add the new value
  if (cur_size < max_size) {
    //printf("good for now!\n");
    my_stack->vals[cur_size] = v;
    my_stack->cur_size = cur_size + 1;
  }

  // Need to allocate more memory
  else {
    //printf("allocating more memory\n");
    int* new_vals = malloc(2 * max_size * sizeof(int));

    for (int i=0; i<cur_size; i++) {
      new_vals[i] = my_stack->vals[i];
    }
    new_vals[cur_size] = v;

    free(my_stack->vals);
    my_stack->vals = new_vals;
    my_stack->cur_size = cur_size + 1;
    my_stack->max_size = 2 * max_size;
  }

  return;
}




// Appends a value v to a stack
int stack__pop(stack* my_stack) {
  // If stack is empty, notifies and does nothing
  if (my_stack->cur_size == 0) {
    printf("This stack is empty.\n");
    return -1;
  }


  my_stack->cur_size -= 1;
  int cur_size = my_stack->cur_size;
  int popped_val = my_stack->vals[cur_size];


  // Deallocating half the memory if it is a quarter of max size (with a minimum size of 4)
  if (4 * cur_size <= my_stack->max_size && 4 < my_stack->max_size) {
    //printf("Deallocating some memory: cur_size: %d, new max_size: %d, old max_size: %d\n", cur_size, 2*cur_size, my_stack->max_size);
    int* new_vals = malloc(2 * cur_size * sizeof(int));

    for (int i=0; i<cur_size; i++) {
      new_vals[i] = my_stack->vals[i];
    }

    free(my_stack->vals);
    my_stack->vals = new_vals;

    my_stack->max_size = 2 * cur_size;
  }

  return popped_val;
}




int stack__peek(stack* my_stack) {
  int top_index = my_stack->cur_size - 1;

  if (top_index == -1) {
    printf("Stack is empty");
    return -1;
  }

  else return my_stack->vals[top_index];
}




int stack__is_empty(stack* my_stack) {
  return my_stack->cur_size == 0;
}




// Prints a stack
void stack__print(stack* my_stack) {
  printf("Bottom -> ");

  for (int i=0; i<my_stack->cur_size; i++) {
    printf("%d ", my_stack->vals[i]);
  }

  printf("<- Top\n");

}



// Frees the stack
void stack__free(stack* my_stack) {
  free(my_stack->vals);
  free(my_stack);
}





// Returns the length of the stack
int stack__size(stack* my_stack) {
  return my_stack->cur_size;
}


#endif
