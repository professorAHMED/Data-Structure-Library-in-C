#include<stdio.h>
#include<stdlib.h>
#include<tm_queue.h>
int main()
{
Queue *queue;
bool succ;
int *x;
int x1,x2,x3,x4;
x1=100;
x2=200;
x3=300;
x4=400;
queue=createQueue(&succ);
addToQueue(queue,(void *)&x1,&succ);
if(succ) printf("%d Added\n",x1);
else printf("%d Not Added\n",x1);

addToQueue(queue,(void *)&x2,&succ);
if(succ) printf("%d Added\n",x2);
else printf("%d Not Added\n",x2);

addToQueue(queue,(void *)&x3,&succ);
if(succ) printf("%d Added\n",x3);
else printf("%d Not Added\n",x3);

addToQueue(queue,(void *)&x4,&succ);
if(succ) printf("%d Added\n",x4);
else printf("%d Not Added\n",x4);

printf("Size of Queue %d\n",getSizeOfQueue(queue));
x=(int *)elementAtTopOfQueue(queue,&succ);
printf("Element At Top %d\n",*x);
printf("Now Removing From Queue\n");
while(!isQueueEmpty(queue))
{
x=(int *)removeFromQueue(queue,&succ);
printf("%d\n",*x);
}
clearQueue(queue);
destroyQueue(queue);
return 0;
}