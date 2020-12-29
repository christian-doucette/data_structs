#ifndef HEAP
#define HEAP

#include <stdlib.h>


// Heap Data Structure


// I am starting at index 1, so for index i:
// - Parent is i/2
// - Left child is 2i
// - Right child is 2i+1


typedef struct {
   int *data;
   int cur_size;  // current size of the heap
   int max_size; // maximum size of the heap
} heap;


// Efficiently calculates is if x is a positive power of 2 (2, 4, 8, 16, etc.) using bits
int is_power_2(int x) {
  if (x <= 1) return 0;
  else return !((x & -x) ^ x);
}



// Initializes an empty heap
heap* heap__init(int size) {
  heap* new_heap = malloc(sizeof(heap));

  new_heap->data = malloc((1 + size) * sizeof(int));
  new_heap->cur_size = 0;
  new_heap->max_size = size;

  return new_heap;
}



int heap__is_empty(heap* my_heap) {
  return (my_heap->cur_size == 0);
}



int heap__is_full(heap* my_heap) {
  return (my_heap->cur_size == my_heap->max_size);
}




// Inserts a value v into the heap
void heap__insert(heap* my_heap, int v) {

  if (heap__is_full(my_heap)) {
    printf("This heap is full.\n");
  }

  else {
    my_heap->cur_size += 1;
    my_heap->data[my_heap->cur_size] = v;
    // Add percolate up here
  }
}




// Removes the minimum value in the heap
int heap__extract(heap* my_heap) {

  if (heap__is_empty(my_heap)) {
    printf("This heap is empty.\n");
    return -1;
  }

  else {
    int root = my_heap->data[1];
    my_heap->cur_size -= 1;

    if (my_heap->cur_size > 0) {
      my_heap->data[1] = my_heap->data[my_heap->cur_size + 1];
      // add percolate down here
    }
    return root;
  }
}



/*
// Returns the value at the top of the heap
int heap__peek(heap* my_heap) {
  if (heap__is_empty(my_heap)) {
    printf("heap is empty");
    return -1;
  }

  else return my_heap->data[my_heap->top];
}*/






// Prints the heap
void heap__print(heap* my_heap) {
  printf("------Heap------\n");

  for (int i = 1; i <= my_heap->cur_size; i++) {
    printf("%d ", my_heap->data[i]);
    if (is_power_2(i+1)) printf("\n");
  }

  printf("\n----------------\n\n");

}



// Frees the heap
void heap__free(heap* my_heap) {
  free(my_heap->data);
  free(my_heap);
}





#endif
