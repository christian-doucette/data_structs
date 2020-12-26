#ifndef LINKED_LIST
#include <stdlib.h>
#define LINKED_LIST

typedef struct linked_list_type {
   int val;
   struct linked_list_type* next;
} linked_list;



// Initializes a linked list with a single node with a value v
linked_list* init_ll(int v) {
  linked_list* new_ll = malloc(sizeof(linked_list));
  new_ll->val = v;
  new_ll->next = NULL;

  return new_ll;
}



// Appends a value v to a linked list
void append_ll(linked_list* my_ll, int v) {
  linked_list* new_node = init_ll(v);

  linked_list* lp = my_ll;
  while (lp->next) lp = lp->next;

  lp->next = new_node;
}



// Prints a linked list
void print_ll(linked_list* my_ll) {

  linked_list* lp = my_ll;
  for (linked_list* lp = my_ll; lp != NULL; lp = lp->next) {
    printf("%d -> ", lp->val);
  }
  printf("NULL\n");
}



// Frees all the nodes of a linked list
void free_ll(linked_list* my_ll) {
  if (my_ll->next != NULL) {
    free_ll(my_ll->next);
  }

  free(my_ll);
}



// Returns 1 if a value v is in the list, 0 if not
int search_ll(linked_list* my_ll, int v) {
  linked_list* lp = my_ll;

  while (lp != NULL) {
    if (lp->val == v) return 1;
    lp = lp->next;
  }

  return 0;
}



// Returns the length of the linked list
int len_ll(linked_list* my_ll) {
  int len = 0;
  for (linked_list* lp = my_ll; lp != NULL; lp = lp->next) {
    len++;
  }

  return len;

}


#endif
