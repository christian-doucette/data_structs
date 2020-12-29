#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>


//=====================//
//       Structs       //
//=====================//

// Node of a linked list

typedef struct node_type {
   int val;
   struct node_type* next;
} node;





// Header for a linked list -> this is what is directly interacted with

typedef struct linked_list_type {
   int len;
   node* head;
   node* tail;
} linked_list;






//=====================//
//       Methods       //
//=====================//



// Initializes an empty linked_list

linked_list* ll__init() {
  linked_list* new_ll = malloc(sizeof(linked_list));
  new_ll->len = 0;
  new_ll->head = NULL;
  new_ll->tail = NULL;

  return new_ll;
}






// Prints a linked list

void ll__print(linked_list* my_ll) {
  //printf("LL (len %d): ", my_ll->len);

  for (node* iterator = my_ll->head; iterator != NULL; iterator = iterator->next) {
    printf("%d -> ", iterator->val);
  }
  printf("NULL\n");
}






// Frees all the memory of a linked list

void ll__free(linked_list* my_ll) {
  node* iterator = my_ll->head;

  while (iterator != NULL) {
    node* prev_node = iterator;
    iterator = iterator->next;
    free(prev_node);
  }

  free(my_ll);
}






// Appends a value v to a linked list

void ll__append(linked_list* my_ll, int v) {

  // Initializes a new node
  node* new_node = malloc(sizeof(node));
  new_node->val = v;
  new_node->next = NULL;


  // If linked list is empty, sets head and tail to the new node
  if (my_ll->len == 0) {
    my_ll->head = new_node;
    my_ll->tail = new_node;
  }

  // If linked list is nonempty, appends to end of the list
  else {
    node* old_tail = my_ll->tail;
    old_tail->next = new_node;
    my_ll->tail = new_node;
  }

  my_ll->len += 1;
}






// Returns 1 if a value v is in the list, 0 if not

int ll__search(linked_list* my_ll, int v) {

  for (node* iterator = my_ll->head; iterator != NULL; iterator = iterator->next) {
    if (iterator->val == v) return 1;
  }
  return 0;
}





// Removes the head of the linked list, and returns its value

int ll__remove_head(linked_list* my_ll) {

  if (my_ll->head == NULL) {
    printf("The Linked List is empty");
    return -1;
  }

  else {
    node* old_head = my_ll->head;
    int old_head_val = old_head->val;

    my_ll->head = old_head->next;
    free(old_head);
    return old_head_val;
  }
}








#endif
