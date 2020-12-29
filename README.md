# Data Structs

Implementation of common data structures in C. Currently includes:
1. [Linked List](#linked-list-code)
2. [Binary Search Tree](#binary-search-tree-code)
3. [List](#list-code)
4. [Stack](#stack-code)
5. [Hash Table](#hash-table-code)


## Motivation
The motivation of this project is to gain experience with:
1. Common data structures and their associated methods
2. Creating time/memory efficient implementations of these
3. Dynamic memory allocation and handling in C

Additionally, since C's standard library does not include many important data structures, I wanted to have a nice data structure library to use on future projects in C.

## Details
Each data structures include a init(), print(), and free() method. Below, I describe the additional methods for each data structure. I also include the average-case time complexity for my implementations.


### Linked List ([code](https://github.com/christian-doucette/data_structs/blob/master/linked_list/linked_list.h))
My linked list is a singly linked list that stores integer values. It also includes a header that tracks the head and tail of the linked list.

Methods:
1. Append - O(1): appends a value onto the end of a linked list
3. Search - O(n): checks if a value is in the linked list  


### Binary Search Tree ([code](https://github.com/christian-doucette/data_structs/blob/master/bst/bst.h))
My binary search tree is a standard BST that stores integers. Currently it does not rebalance. So, as insert, search, and min depend on the height of the tree, their abosolute worst case complexities are O(n) - however, average case is O(log(n))

Methods:
1. Insert - O(log(n)): Inserts a value into the BST
2. Search - O(log(n)): Checks if the BST contains a specific value
3. Min - O(log(n)): Returns the minimum value in the BST
4. Num Nodes - O(n): Returns the number of nodes in the BST
5. Height - O(n): Returns the height of the BST  


### List ([code](https://github.com/christian-doucette/data_structs/blob/master/list/list.h))
My list is a dynamically-sized array, like Python lists or Java Arraylists. It works by doubling the size of the array whenver more space is needed. Also, if the array ever reaches a quarter of its max size, it halves the array size. For both append and remove, since the costly reallocation only occurs rarely, amortized time complexity is O(1).

Methods:
1. Append - O(1): Appends a value v to the list
2. Remove Last - O(1): Removes the last value of the list
3. Index - O(1): Returns value at a given index
4. Len - O(1): Returns current length of the list  


## Stack ([code](https://github.com/christian-doucette/data_structs/blob/master/stack/stack.h))
My stack takes in size as an argument to its init() function.

Methods:
1. Is Empty - O(1): Checks if the stack is empty
2. Is Full - O(1): Checks if the stack is full
3. Push - O(1): Pushes a value onto the top of the stack
4. Pop - O(1): Removes a value from the top of the stack and returns it
5. Peek - O(1): Returns the value at the top of the stack  


## Hash Table ([code](https://github.com/christian-doucette/data_structs/blob/master/hash_table/hash_table.h))
My hash table is a closed address hash table that uses my [linked lists](#linked-list-code) to resolve collisions. It takes the size of the table as a argument to init().

Methods:
Insert - O(1): Inserts a value into the hash table
Search - O(1): Checks if a value is in the hash table
