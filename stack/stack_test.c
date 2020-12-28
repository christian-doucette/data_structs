#include <stdio.h>
#include "stack.h"

int main() {
  stack* my_stack = stack__init();
  stack__print(my_stack);

  stack__push(my_stack, 5);
  stack__print(my_stack);

  stack__push(my_stack, 100);
  stack__print(my_stack);


  stack__push(my_stack, 105);
  stack__print(my_stack);

  stack__push(my_stack, 5);
  stack__print(my_stack);

  printf("Peeked val: %d\n",   stack__peek(my_stack));
  stack__print(my_stack);


  printf("Popped val: %d\n",   stack__pop(my_stack));
  stack__print(my_stack);

  printf("Popped val: %d\n",   stack__pop(my_stack));
  stack__print(my_stack);

  printf("Popped val: %d\n",   stack__pop(my_stack));
  stack__print(my_stack);

  printf("Popped val: %d\n",   stack__pop(my_stack));
  stack__print(my_stack);

  printf("Stack is empty?: %d\n", stack__is_empty(my_stack));


  stack__push(my_stack, 65);
  stack__push(my_stack, 66);
  stack__push(my_stack, 67);
  stack__push(my_stack, 68);
  stack__push(my_stack, 69);


  stack__print(my_stack);

  printf("Stack is empty?: %d\n", stack__is_empty(my_stack));






  return 0;
}
