#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>


typedef struct linked_list_type {
   int val;
   struct linked_list_type* next;
} linked_list;



// Initializes a linked list with a single node with a value v
linked_list* ll__init(int v) {
  linked_list* new_ll = malloc(sizeof(linked_list));
  new_ll->val = v;
  new_ll->next = NULL;

  return new_ll;
}



// Appends a value v to a linked list
void ll__append(linked_list* my_ll, int v) {
  linked_list* new_node = ll__init(v);

  linked_list* lp = my_ll;
  while (lp->next) lp = lp->next;

  lp->next = new_node;
}



// Prints a linked list
void ll__print(linked_list* my_ll) {

  linked_list* lp = my_ll;
  for (linked_list* lp = my_ll; lp != NULL; lp = lp->next) {
    printf("%d -> ", lp->val);
  }
  printf("NULL\n");
}



// Frees all the nodes of a linked list
void ll__free(linked_list* my_ll) {
  if (my_ll->next != NULL) {
    ll__free(my_ll->next);
  }

  free(my_ll);
}



// Returns 1 if a value v is in the list, 0 if not
int ll__search(linked_list* my_ll, int v) {
  linked_list* lp = my_ll;

  while (lp != NULL) {
    if (lp->val == v) return 1;
    lp = lp->next;
  }

  return 0;
}



// Returns the length of the linked list
int ll__len(linked_list* my_ll) {
  int len = 0;
  for (linked_list* lp = my_ll; lp != NULL; lp = lp->next) {
    len++;
  }

  return len;

}


#endif
