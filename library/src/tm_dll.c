#ifndef __TM_DLL__C
#define __TM_DLL__C 123
#include<tm_dll.h>
#include<stdlib.h>
DoublyLinkedList * createDoublyLinkedList(bool *success)
{
DoublyLinkedList * doublyLinkedList;
if(success) *success=false;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL) return NULL;
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success) *success=true;
return doublyLinkedList;
}
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return;
clearDoublyLinkedList(doublyLinkedList);
free(doublyLinkedList);
}
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL) return;
while(doublyLinkedList->start!=NULL)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node);
}
}
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)
{
DoublyLinkedListNode *node;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->previous=NULL;
node->next=NULL;
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
node->previous=doublyLinkedList->end;
doublyLinkedList->end->next=node;
doublyLinkedList->end=node;
}
doublyLinkedList->size++;
if(success) *success=true;
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return 0;
return doublyLinkedList->size;
}
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)
{
DoublyLinkedListNode *node,*p1;
int x;
if(doublyLinkedList==NULL) return;
if(index<0 || index>doublyLinkedList->size) return;
if(index==doublyLinkedList->size)
{
addToDoublyLinkedList(doublyLinkedList,ptr,success);
if(success) *success=true;
return;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->previous=NULL;
node->next=NULL;
if(index==0)
{
node->next=doublyLinkedList->start;
doublyLinkedList->start->previous=node;
doublyLinkedList->start=node;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
x=0;
p1=doublyLinkedList->start;
while(x<index)
{
p1=p1->next;
x++;
}
p1->previous->next=node;
node->previous=p1->previous;
p1->previous=node;
node->next=p1;
doublyLinkedList->size++;
if(success) *success=true;
}
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success)
{
DoublyLinkedListNode *node,*t,*s,*e;
bool done;
if(success) *success=false;
if(targetDoublyLinkedList==NULL) return;
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->start==NULL)
{
if(success) *success=true;
return;
}
s=NULL;
e=NULL;
t=sourceDoublyLinkedList->start;
done=true;
while(t!=NULL)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->previous=NULL;
node->next=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
node->previous=e;
e->next=node;
e=node;
}
t=t->next;
}
if(done==false)
{
while(s!=NULL)
{
node=s;
s=s->next;
free(node);
}
return;
}
if(targetDoublyLinkedList->start==NULL)
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
}
else
{
targetDoublyLinkedList->end->next=s;
s->previous=targetDoublyLinkedList->end;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
if(success) *success=true;
}
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *node;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL) return NULL;
if(index<0 || index>=doublyLinkedList->size) return NULL;
node=doublyLinkedList->start;
x=0;
while(x<index)
{
node=node->next;
x++;
}
if(success) *success=true;
return node->ptr;
}
void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *node;
void *ptr=NULL;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL) return ptr;
if(index<0 || index>=doublyLinkedList->size) return ptr;
node=doublyLinkedList->start;
x=0;
while(x<index)
{
node=node->next;
x++;
}
ptr=node->ptr;
if(doublyLinkedList->start==node && doublyLinkedList->end==node)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end==NULL;
}else if(doublyLinkedList->start==node)
{
doublyLinkedList->start=doublyLinkedList->start->next;
doublyLinkedList->start->previous=NULL;
}else if(doublyLinkedList->end==node)
{
doublyLinkedList->end=node->previous;
doublyLinkedList->end->next=NULL;
}else
{
node->previous->next=node->next;
node->next->previous=node->previous;
}
doublyLinkedList->size--;
if(success) *success=true;
return ptr;
}
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListIterator doublyLinkedListIterator;
doublyLinkedListIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListIterator;
doublyLinkedListIterator.node=doublyLinkedList->start;
if(success) *success=true;
return doublyLinkedListIterator;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)
{
if(doublyLinkedListIterator==NULL) return false;
if(doublyLinkedListIterator->node==NULL) return false;
return true;
}
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success)
{
void *ptr=NULL;
if(success) *success=false;
if(doublyLinkedListIterator==NULL || doublyLinkedListIterator->node==NULL) return ptr;
ptr=doublyLinkedListIterator->node->ptr;
doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;
if(success) *success=true;
return ptr;
}
DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListReverseIterator doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=doublyLinkedList->end;
if(success) *success=true;
return doublyLinkedListReverseIterator;
}
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator)
{
if(doublyLinkedListReverseIterator==NULL) return false;
if(doublyLinkedListReverseIterator->node==NULL) return false;
return true;
}
void * getPreviousFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success)
{
void *ptr=NULL;
if(success) *success=false;
if(doublyLinkedListReverseIterator==NULL || doublyLinkedListReverseIterator->node==NULL) return ptr;
ptr=doublyLinkedListReverseIterator->node->ptr;
doublyLinkedListReverseIterator->node=doublyLinkedListReverseIterator->node->previous;
if(success) *success=true;
return ptr;
}
#endif