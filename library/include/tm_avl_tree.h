#ifndef __TM_AVL_TREE__H
#define __TM_AVL_TREE__H 123
#include<tm_common.h>
#include<tm_stack.h>
#include<tm_queue.h>
typedef struct __$_tm_avl_tree_node
{
struct __$_tm_avl_tree_node *left;
struct __$_tm_avl_tree_node *right;
void *ptr;
}AVLTreeNode;
typedef struct __$_tm_avl_tree
{
int size;
struct __$_tm_avl_tree_node *start;
int(*predicate)(void *,void *);
}AVLTree;
typedef struct __$_tm_avl_tree_in_order_iterator
{
Stack *stack;
AVLTreeNode *node;
}AVLTreeInOrderIterator;
typedef struct __$_tm_avl_tree_pre_order_iterator
{
Stack *stack;
AVLTreeNode *node;
}AVLTreePreOrderIterator;
typedef struct __$_tm_avl_tree_post_order_iterator
{
Stack *stack;
AVLTreeNode *node;
}AVLTreePostOrderIterator;
AVLTree * createAVLTree(bool *success,int(*predicate)(void *,void*));
void destroyAVLTree(AVLTree *avlTree);
void clearAVLTree(AVLTree *avlTree);
int getSizeOfAVLTree(AVLTree *avlTree);
void insertIntoAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void * removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void * getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator);
void * getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success);
AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator);
void * getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success);
AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator);
void * getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success);
#endif