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



// Initializes an empty heap
heap* heap__init(int size) {
  heap* new_heap = malloc(sizeof(heap));

  new_heap->data = malloc((1 + size) * sizeof(int));
  new_heap->cur_size = 0;
  new_heap->max_size = size;

  return new_heap;
}




// Prints the heap
void heap__print(heap* my_heap) {
  printf("< ");

  for (int i = 1; i <= my_heap->cur_size; i++) {
    printf("%d ", my_heap->data[i]);
  }

  printf(">\n");

}





// Frees the heap
void heap__free(heap* my_heap) {
  free(my_heap->data);
  free(my_heap);
}






// Checks if the heap is empty
int heap__is_empty(heap* my_heap) {
  return (my_heap->cur_size == 0);
}




// Checks if the heap is full
int heap__is_full(heap* my_heap) {
  return (my_heap->cur_size == my_heap->max_size);
}





// Returns the minimum value in the heap
int heap__min(heap* my_heap) {
  if (heap__is_empty(my_heap)) {
    printf("This heap is empty.\n");
    return -1;
  }

  else {
    return my_heap->data[1];
  }
}





// Inserts a value v into the heap
void heap__insert(heap* my_heap, int v) {

  if (heap__is_full(my_heap)) {
    printf("This heap is full.\n");
  }

  else {
    my_heap->cur_size += 1;
    my_heap->data[my_heap->cur_size] = v;

    // Percolates up to maintain heap property
    int index = my_heap->cur_size;
    // If needs to swap with parent
    while (index > 1 && my_heap->data[index] < my_heap->data[index/2]) {
      int temp = my_heap->data[index];
      my_heap->data[index] = my_heap->data[index/2];
      my_heap->data[index/2] = temp;

      index = index/2;
    }
  }
}




// Removes the minimum value in the heap
int heap__extract_min(heap* my_heap) {

  if (heap__is_empty(my_heap)) {
    printf("This heap is empty.\n");
    return -1;
  }

  else {
    int min_val = my_heap->data[1];
    my_heap->cur_size -= 1;

    if (my_heap->cur_size > 0) {
      my_heap->data[1] = my_heap->data[my_heap->cur_size + 1];

      // Percolates down to maintain heap property
      int index = 1;
      // If should swap with left or right child
      while ((2*index <= my_heap->cur_size && my_heap->data[index] > my_heap->data[2*index])
      || (2*index + 1 <= my_heap->cur_size && my_heap->data[index] > my_heap->data[2*index + 1])) {

        // Swapping with right child
        int index_to_swap;
        if (2*index + 1 <= my_heap->cur_size &&  my_heap->data[2*index + 1] <  my_heap->data[2 * index]) {
          index_to_swap = 2*index + 1;
        }
        // Swapping with left child
        else {
          index_to_swap = 2*index;
        }

        int temp = my_heap->data[index];
        my_heap->data[index] = my_heap->data[index_to_swap];
        my_heap->data[index_to_swap] = temp;

        index = index_to_swap;



      }
    }
    return min_val;
  }
}






#endif
