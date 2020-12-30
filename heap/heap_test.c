#include <stdio.h>
#include "heap.h"

int main() {
  heap* my_heap = heap__init(15);
  heap__print(my_heap);
  printf("heap is empty?: %d\n", heap__is_empty(my_heap));


  heap__insert(my_heap, 5);
  heap__print(my_heap);

  heap__insert(my_heap, 100);
  heap__print(my_heap);


  heap__insert(my_heap, 105);
  heap__print(my_heap);


  heap__insert(my_heap, 7);
  heap__print(my_heap);


  heap__insert(my_heap, 8);
  heap__print(my_heap);


  heap__insert(my_heap, 9);
  heap__print(my_heap);


  heap__insert(my_heap, 10);
  heap__print(my_heap);

  heap__insert(my_heap, 11);
  heap__print(my_heap);

  heap__insert(my_heap, 2);
  heap__print(my_heap);

  heap__insert(my_heap, 3);
  heap__print(my_heap);

  heap__insert(my_heap, 1000);
  heap__print(my_heap);

  heap__insert(my_heap, 1);
  heap__print(my_heap);





  printf("min val: %d\n",   heap__min(my_heap));
  heap__print(my_heap);

  printf("extracted min: %d\n",   heap__extract_min(my_heap));
  heap__print(my_heap);

  printf("extracted min: %d\n",   heap__extract_min(my_heap));
  heap__print(my_heap);

  printf("extracted min: %d\n",   heap__extract_min(my_heap));
  heap__print(my_heap);

  printf("extracted min: %d\n",   heap__extract_min(my_heap));
  heap__print(my_heap);

  printf("heap is empty?: %d\n", heap__is_empty(my_heap));


  heap__insert(my_heap, 65);
  heap__insert(my_heap, 66);
  heap__insert(my_heap, 67);
  heap__insert(my_heap, 68);


  heap__print(my_heap);

  printf("heap is empty?: %d\n", heap__is_empty(my_heap));

  heap__free(my_heap);






  return 0;
}
