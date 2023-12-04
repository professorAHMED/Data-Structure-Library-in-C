#ifndef __TM_AVL_TREE__C
#define __TM_AVL_TREE__C 123
#include<stdlib.h>
#include<tm_avl_tree.h>
AVLTree * createAVLTree(bool *success,int(*predicate)(void *,void*))
{
AVLTree *avlTree;
if(success) *success=false;
avlTree=(AVLTree *)malloc(sizeof(AVLTree));
if(avlTree==NULL || predicate==NULL) return NULL;
avlTree->start=NULL;
avlTree->predicate=predicate;
avlTree->size=0;
if(success) *success=true;
return avlTree;
}
void destroyAVLTree(AVLTree *avlTree)
{
if(avlTree==NULL) return;
clearAVLTree(avlTree);
free(avlTree);
}
void clearAVLTree(AVLTree *avlTree)
{}
int getSizeOfAVLTree(AVLTree *avlTree)
{
if(avlTree==NULL) return 0;
return avlTree->size;
}
void insertIntoAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
AVLTreeNode *t,*j;
int succ;
int weight;
if(success) *success=false;
if(avlTree==NULL) return;
if(avlTree->start==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
avlTree->start=t;
avlTree->size++;
if(success) *success=true;
return;
}
j=avlTree->start;
while(1)
{
weight=avlTree->predicate(ptr,j->ptr);
if(weight==0) return;
if(weight<0)
{
if(j->left==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
avlTree->size++;
if(success) *success=true;
}
void * removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{}
void * getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{}

AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreeInOrderIterator avlTreeInOrderIterator;
AVLTreeNode *t;
int succ;
avlTreeInOrderIterator.stack=NULL;
avlTreeInOrderIterator.node=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreeInOrderIterator;
if(avlTree->start==NULL)
{
if(success) *success=true;
return avlTreeInOrderIterator;
}
avlTreeInOrderIterator.stack=createStack(&succ);
if(avlTreeInOrderIterator.stack==NULL) return avlTreeInOrderIterator;
t=avlTree->start;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator.stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator.stack);
avlTreeInOrderIterator.stack=NULL;
avlTreeInOrderIterator.node=NULL;
return avlTreeInOrderIterator;
}
t=t->left;
}
avlTreeInOrderIterator.node=popFromStack(avlTreeInOrderIterator.stack,&succ);
if(succ==false) return avlTreeInOrderIterator;
if(success) *success=true;
return avlTreeInOrderIterator;
}
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator)
{
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL) return false;
return true;
}
void * getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
int succ;
if(success) *success=false;
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL) return NULL;
j=avlTreeInOrderIterator->node;
t=j->right;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack=NULL;
avlTreeInOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
t=t->left;
}
if(isStackEmpty(avlTreeInOrderIterator->stack))
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack=NULL;
avlTreeInOrderIterator->node=NULL;
}
else
{
avlTreeInOrderIterator->node=popFromStack(avlTreeInOrderIterator->stack,&succ);
}
if(success) *success=true;
return j->ptr;
}
#endif