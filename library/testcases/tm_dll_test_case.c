#include<stdio.h>
#include<tm_dll.h>
int main()
{
DoublyLinkedList *list1,*list2;
DoublyLinkedListIterator iter;
DoublyLinkedListReverseIterator iterator;
bool succ;
int *x;
int j1,j2,j3,i1,i2,i3,i4,i5,i6,y;
list1=createDoublyLinkedList(&succ);
list2=createDoublyLinkedList(&succ);
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
j1=111;
j2=222;
j3=333;
addToDoublyLinkedList(list1,(void *)&i1,&succ);
addToDoublyLinkedList(list1,(void *)&i2,&succ);
addToDoublyLinkedList(list1,(void *)&i3,&succ);
addToDoublyLinkedList(list1,(void *)&i4,&succ);
addToDoublyLinkedList(list2,(void *)&i5,&succ);
addToDoublyLinkedList(list2,(void *)&i6,&succ);
iter=getDoublyLinkedListIterator(list1,&succ);
if(succ)
{
printf("Up to Down\n");
while(hasNextInDoublyLinkedList(&iter))
{
x=(int *)getNextElementFromDoublyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
insertIntoDoublyLinkedList(list1,2,(void *)&j1,&succ);
insertIntoDoublyLinkedList(list2,0,(void *)&j2,&succ);
insertIntoDoublyLinkedList(list2,1,(void *)&j3,&succ);
printf("After Insertion\n");
iter=getDoublyLinkedListIterator(list1,&succ);
if(succ)
{
printf("Up to Down\n");
while(hasNextInDoublyLinkedList(&iter))
{
x=(int *)getNextElementFromDoublyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
appendToDoublyLinkedList(list1,list2,&succ);
printf("Appended\n");
iter=getDoublyLinkedListIterator(list1,&succ);
if(succ)
{
printf("Up to Down\n");
while(hasNextInDoublyLinkedList(&iter))
{
x=(int *)getNextElementFromDoublyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
printf("Size of List 1 is %d\n",getSizeOfDoublyLinkedList(list1));
x=(int *)getFromDoublyLinkedList(list1,3,&succ);
printf("%d is at index 3\n",*x);
x=(int *)removeFromDoublyLinkedList(list1,3,&succ);
printf("%d is Removed From index 3\n",*x);
printf("After Removel\n");
iter=getDoublyLinkedListIterator(list1,&succ);
if(succ)
{
printf("Up to Down\n");
while(hasNextInDoublyLinkedList(&iter))
{
x=(int *)getNextElementFromDoublyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}

iterator=getDoublyLinkedListReverseIterator(list1,&succ);
if(succ)
{
while(hasPreviousInDoublyLinkedList(&iterator))
{
x=(int *)getPreviousFromDoublyLinkedList(&iterator,&succ);
printf("%d\n",*x);
y++;
}
}

destroyDoublyLinkedList(list1);
return 0;
}