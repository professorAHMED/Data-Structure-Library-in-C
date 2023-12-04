#include<stdio.h>
#include<stdlib.h>
#include<tm_stack.h>
int main()
{
Stack *stack;
bool succ;
int *x;
int x1,x2,x3,x4;
x1=100;
x2=200;
x3=300;
x4=400;
stack=createStack(&succ);
pushOnStack(stack,(void *)&x1,&succ);
if(succ) printf("%d Pushed\n",x1);
else printf("%d Not Pushed\n",x1);

pushOnStack(stack,(void *)&x2,&succ);
if(succ) printf("%d Pushed\n",x2);
else printf("%d Not Pushed\n",x2);

pushOnStack(stack,(void *)&x3,&succ);
if(succ) printf("%d Pushed\n",x3);
else printf("%d Not Pushed\n",x3);

pushOnStack(stack,(void *)&x4,&succ);
if(succ) printf("%d Pushed\n",x4);
else printf("%d Not Pushed\n",x4);

printf("Size of Stack %d\n",getSizeOfStack(stack));
x=(int *)elementAtTopOfStack(stack,&succ);
printf("Element At Top %d\n",*x);
printf("Now Popping From Stack\n");
while(!isStackEmpty(stack))
{
x=(int *)popFromStack(stack,&succ);
printf("%d\n",*x);
}
clearStack(stack);
destroyStack(stack);
return 0;
}