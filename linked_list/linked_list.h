#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>

//=========================//
//   Linked List Struct    //
//=========================//

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






//==========================//
//    Linked List Methods   //
//==========================//



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






// Checks if the linked list is empty
int ll__is_empty(linked_list* my_ll) {
  return (my_ll->head == NULL);
}







// Appends a value v to a linked list
void ll__append(linked_list* my_ll, int v) {

  // Initializes a new node
  node* new_node = malloc(sizeof(node));
  new_node->val = v;
  new_node->next = NULL;


  // If linked list is empty, sets head and tail to the new node
  if (ll__is_empty(my_ll)) {
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

  if (ll__is_empty(my_ll)) {
    printf("The Linked List is empty\n");
    return -1;
  }

  else {
    node* old_head = my_ll->head;
    int old_head_val = old_head->val;

    my_ll->head = old_head->next;
    if (my_ll->head == NULL) my_ll->tail = NULL;

    free(old_head);
    my_ll->len -= 1;
    return old_head_val;

  }
}





// Removes the first instance of a value from a linked list - returns 0 if something was removed, 1 otherwise
int ll__remove_val(linked_list* my_ll, int val) {

  // If the linked list is empty
  if (ll__is_empty(my_ll)) {
    return 1;
  }


  // If the value is in the head node, removes head
  else if (my_ll->head->val == val) {
    ll__remove_head(my_ll);
    return 0;
  }

  // Otherwise, checks the rest of the linked list
  else {
    for (node* iterator = my_ll->head; iterator->next != NULL; iterator = iterator->next) {

      // If the next node is the value to be removed
      if (iterator->next->val == val) {
        node* node_to_free = iterator->next;
        iterator->next = node_to_free->next;

        free(node_to_free);

        // If the freed node was the tail, sets tails to its new value
        if (iterator->next == NULL) {
          my_ll->tail = iterator;
        }


        my_ll->len -= 1;
        return 0;
      }
    }

    // If the value was not found
    return 1;
  }

}







#endif
