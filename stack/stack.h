#ifndef STACK
#include <stdlib.h>
#define STACK

// Stack Data Structure
typedef struct {
   int *data;
   int top;  // current top of the stack
   int size; // size of the stack
} stack;



// Initializes an empty stack
stack* stack__init(int size) {
  stack* new_stack = malloc(sizeof(stack));

  new_stack->data = malloc(size * sizeof(int));
  new_stack->top = -1;
  new_stack->size = size;

  return new_stack;
}



int stack__is_empty(stack* my_stack) {
  return (my_stack->top == -1);
}



int stack__is_full(stack* my_stack) {
  return (my_stack->top == my_stack->size - 1);
}




// Pushes a value v to the top of the stack
void stack__push(stack* my_stack, int v) {

  if (stack__is_full(my_stack)) {
    printf("Stack is full\n");
  }

  else {
    my_stack->top += 1;
    my_stack->data[my_stack->top] = v;
  }
}




// Pops the value at the top of the stack
int stack__pop(stack* my_stack) {

  if (stack__is_empty(my_stack)) {
    printf("This stack is empty.\n");
    return -1;
  }

  else {
    int popped_val = my_stack->data[my_stack->top];
    my_stack->top -= 1;
    return popped_val;
  }
}




// Returns the value at the top of the stack
int stack__peek(stack* my_stack) {
  if (stack__is_empty(my_stack)) {
    printf("Stack is empty");
    return -1;
  }

  else return my_stack->data[my_stack->top];
}






// Prints the stack
void stack__print(stack* my_stack) {
  printf("|");

  for (int i = 0; i <= my_stack->top; i++) {
    printf(" %d |", my_stack->data[i]);
  }

  printf("->\n");

}



// Frees the stack
void stack__free(stack* my_stack) {
  free(my_stack->data);
  free(my_stack);
}





#endif
