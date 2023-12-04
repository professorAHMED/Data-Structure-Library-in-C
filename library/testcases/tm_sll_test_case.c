#include<stdio.h>
#include<tm_sll.h>
int main()
{
SinglyLinkedList *list1,*list2;
SinglyLinkedListIterator iter;
int *x;
int i1,i2,i3,i4,i5,i6,y,j1,j2,j3,j4;
bool succ;
list1=createSinglyLinkedList(&succ);
list2=createSinglyLinkedList(&succ);
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
j1=89;
j2=97;
j3=56;
j4=123;
addToSinglyLinkedList(list1,(void *)&i1,&succ);
addToSinglyLinkedList(list1,(void *)&i2,&succ);
addToSinglyLinkedList(list1,(void *)&i3,&succ);
printf("List 1\n");
iter=getSinglyLinkedListIterator(list1,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iter))
{
x=(int *)getNextElementFromSinglyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
insertIntoSinglyLinkedList(list1,0,(void *)&j1,&succ);
insertIntoSinglyLinkedList(list1,3,(void *)&j2,&succ);
printf("List 1 After Insertion at 0 and 3\n");
iter=getSinglyLinkedListIterator(list1,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iter))
{
x=(int *)getNextElementFromSinglyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
addToSinglyLinkedList(list2,(void *)&i4,&succ);
addToSinglyLinkedList(list2,(void *)&i5,&succ);
addToSinglyLinkedList(list2,(void *)&i6,&succ);
printf("List 2\n");
iter=getSinglyLinkedListIterator(list2,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iter))
{
x=(int *)getNextElementFromSinglyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
insertIntoSinglyLinkedList(list2,2,(void *)&j4,&succ);
insertIntoSinglyLinkedList(list2,4,(void *)&j3,&succ);
printf("List 2 After Insertion at 2 and 4\n");
iter=getSinglyLinkedListIterator(list2,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iter))
{
x=(int *)getNextElementFromSinglyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
appendToSinglyLinkedList(list1,list2,&succ);
printf("List 1 after Appended\n");
iter=getSinglyLinkedListIterator(list1,&succ);
if(succ)
{
while(hasNextInSinglyLinkedList(&iter))
{
x=(int *)getNextElementFromSinglyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
destroySinglyLinkedList(list1);
return 0;
}