#include <stdio.h>
#include "heap.h"

int main() {
  heap* my_heap = heap__init(8);

  heap__insert(my_heap, 5);

  heap__insert(my_heap, 100);

  heap__insert(my_heap, 105);

  heap__insert(my_heap, 7);

  heap__insert(my_heap, 8);

  heap__insert(my_heap, 9);

  heap__insert(my_heap, 10);

  heap__print(my_heap);





  printf("extractped val: %d\n",   heap__extract(my_heap));
  heap__print(my_heap);

  printf("extractped val: %d\n",   heap__extract(my_heap));
  heap__print(my_heap);

  printf("extractped val: %d\n",   heap__extract(my_heap));
  heap__print(my_heap);

  printf("extractped val: %d\n",   heap__extract(my_heap));
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
