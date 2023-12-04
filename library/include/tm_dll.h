#ifndef __TM_DLL__H
#define __TM_DLL__H 123
#include<tm_common.h>
typedef struct __$_tm_dll_node
{
void *ptr;
struct __$_tm_dll_node *previous;
struct __$_tm_dll_node *next;
}DoublyLinkedListNode;
typedef struct __$_tm_dll
{
int size;
struct __$_tm_dll_node *start;
struct __$_tm_dll_node *end;
}DoublyLinkedList;
typedef struct __$_tm_dll_itrator
{
struct __$_tm_dll_node *node;
}DoublyLinkedListIterator;
typedef struct __$_tm_dll_reverse_itrator
{
struct __$_tm_dll_node *node;
}DoublyLinkedListReverseIterator;
DoublyLinkedList * createDoublyLinkedList(bool *success);
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success);
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success);
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success);
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator);
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success);
DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator);
void * getPreviousFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success);
#endif