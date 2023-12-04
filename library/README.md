# C-DS-Library
# Data Structures Library Documentation
Welcome to the Data Structures Library documentation. This comprehensive guide will walk you through the various data structures provided by the library, along with their available methods and usage instructions.

##Table of Contents

- [Introduction](#introduction)
- [Singly Linked List](#singly-linked-list)
- [Doubly Linked List](#doubly-linked-list)
- [Stack](#stack)
- [Queue](#queue)
- [AVL Tree](#avl-tree)
- [Conclusion](#conclusion)

##Introduction

The Data Structures Library is a collection of C implementations of fundamental data structures. These data structures are designed to provide efficient storage, retrieval, and manipulation of data elements.

##Singly Linked List

###Description

A Singly Linked List is a linear data structure where each node contains data and a pointer to the next node.

###Methods

- 'createSinglyLinkedList(bool *success)': Create an empty Singly Linked List.
- 'destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)': Free the memory occupied by the list.
- 'clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList)': Remove all elements from the list.
- 'addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList, void *ptr, bool *success)': Add an element to the end of the list.
- 'insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, void *ptr, bool *success)': Insert an element at a specified index.
- 'getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList)': Get the number of elements in the list.
- 'getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, bool *success)': Get the element at a specified index.
- 'removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, bool *success)': Remove the element at a specified index.
- 'appendToSinglyLinkedList(SinglyLinkedList *target, SinglyLinkedList *source, bool *success)': Append elements of the source list to the target list.
- 'getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList, bool *success)': Get an iterator for traversing the list.
- 'hasNextInSinglyLinkedList(SinglyLinkedListIterator *iterator)': Check if there are more elements in the list.
- 'getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *iterator, bool *success)': Get the next element from the iterator.

###Usage

'''c
#include <tm_sll.h>
#include <tm_common.h>

bool success = false;
SinglyLinkedList *list = createSinglyLinkedList(&success);
if (success) {
    // Perform operations on the list
    // ...

    destroySinglyLinkedList(list);
}
'''

Doubly Linked List
Description
A Doubly Linked List is a linear data structure where each node contains data and two pointers, one pointing to the previous node and another to the next node.

Methods
createDoublyLinkedList(bool *success): Create an empty Doubly Linked List.
destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList): Free the memory occupied by the list.
clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList): Remove all elements from the list.
addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList, void *ptr, bool *success): Add an element to the end of the list.
insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, void *ptr, bool *success): Insert an element at a specified index.
getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList): Get the number of elements in the list.
getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, bool *success): Get the element at a specified index.
removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int index, bool *success): Remove the element at a specified index.
appendToDoublyLinkedList(DoublyLinkedList *target, DoublyLinkedList *source, bool *success): Append elements of the source list to the target list.
getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList, bool *success): Get an iterator for traversing the list.
hasNextInDoublyLinkedList(DoublyLinkedListIterator *iterator): Check if there are more elements in the list.
getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *iterator, bool *success): Get the next element from the iterator.
Usage
c
Copy code
#include <tm_dll.h>
#include <tm_common.h>

bool success = false;
DoublyLinkedList *list = createDoublyLinkedList(&success);
if (success) {
    // Perform operations on the list
    // ...

    destroyDoublyLinkedList(list);
}
Stack
Description
A Stack is a Last-In-First-Out (LIFO) data structure where elements are added and removed from the top.

Methods
createStack(bool *success): Create an empty stack.
pushOnStack(Stack *stack, void *ptr, bool *success): Push an element onto the stack.
popFromStack(Stack *stack, bool *success): Pop the top element from the stack.
getSizeOfStack(Stack *stack): Get the number of elements in the stack.
isStackEmpty(Stack *stack): Check if the stack is empty.
elementAtTopOfStack(Stack *stack, bool *success): Get the element at the top of the stack.
clearStack(Stack *stack): Remove all elements from the stack.
destroyStack(Stack *stack): Free the memory occupied by the stack.
Usage
c
Copy code
#include <tm_stack.h>
#include <tm_common.h>

bool success = false;
Stack *stack = createStack(&success);
if (success) {
    // Perform operations on the stack
    // ...

    destroyStack(stack);
}
Queue
Description
A Queue is a First-In-First-Out (FIFO) data structure where elements are added to the rear and removed from the front.

Methods
createQueue(bool *success): Create an empty queue.
addToQueue(Queue *queue, void *ptr, bool *success): Enqueue an element into the queue.
removeFromQueue(Queue *queue, bool *success): Dequeue the front element from the queue.
getSizeOfQueue(Queue *queue): Get the number of elements in the queue.
isQueueEmpty(Queue *queue): Check if the queue is empty.
elementAtTopOfQueue(Queue *queue, bool *success): Get the element at the front of the queue.
clearQueue(Queue *queue): Remove all elements from the queue.
destroyQueue(Queue *queue): Free the memory occupied by the queue.
Usage
c
Copy code
#include <tm_queue.h>
#include <tm_common.h>

bool success = false;
Queue *queue = createQueue(&success);
if (success) {
    // Perform operations on the queue
    // ...

    destroyQueue(queue);
}
AVL Tree
Description
An AVL Tree is a self-balancing binary search tree that maintains its balance during insertion and deletion operations.

Methods
createAVLTree(bool *success, int(*predicate)(void *, void *)): Create an empty AVL tree.
destroyAVLTree(AVLTree *avlTree): Free the memory occupied by the tree.
clearAVLTree(AVLTree *avlTree): Remove all elements from the tree.
getSizeOfAVLTree(AVLTree *avlTree): Get the number of elements in the tree.
insertIntoAVLTree(AVLTree *avlTree, void *ptr, bool *success): Insert an element into the tree.
removeFromAVLTree(AVLTree *avlTree, void *ptr, bool *success): Remove an element from the tree.
getFromAVLTree(AVLTree *avlTree, void *ptr, bool *success): Get an element from the tree.
getAVLTreeInOrderIterator(AVLTree *avlTree, bool *success): Get an iterator for in-order traversal.
getAVLTreePreOrderIterator(AVLTree *avlTree, bool *success): Get an iterator for pre-order traversal.
getAVLTreePostOrderIterator(AVLTree *avlTree, bool *success): Get an iterator for post-order traversal.
Usage
c
Copy code
#include <tm_avl_tree.h>
#include <tm_common.h>

bool success = false;
int compare(void *a, void *b) {
    // Define your comparison logic here
}

AVLTree *tree = createAVLTree(&success, compare);
if (success) {
    // Perform operations on the AVL tree
    // ...

    destroyAVLTree(tree);
}
Conclusion
The Data Structures Library offers a collection of essential data structures for efficient data storage and manipulation. By integrating these data structures into your projects, you can enhance performance and improve code organization.

For detailed information on function usage and examples, refer to the individual header files and source files provided in the library.
