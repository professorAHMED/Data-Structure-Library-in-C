#include<stdio.h>
#include<stdlib.h>
#include<tm_avl_tree.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
int ch,num;
AVLTree *tree;
AVLTreeInOrderIterator iterator;
int success;
int *x;
tree=createAVLTree(&success,myComparator);
if(tree==NULL)
{
printf("Unable to Create tree\n");
return 0;
}
while(1)
{
printf("1. Insert Into AVL Tree\n");
printf("2. InOrder Traversal\n");
printf("3. Exit\n");
printf("Enter Your Choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter a Number to Insert : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,(void *)x,&success);
if(success) printf("Successfully Inserted\n");
}
if(ch==2)
{
iterator=getAVLTreeInOrderIterator(tree,&success);
if(success)
{
while(hasNextInOrderElementInAVLTree(&iterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&iterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==3) break;
}
destroyAVLTree(tree);
return 0;
}