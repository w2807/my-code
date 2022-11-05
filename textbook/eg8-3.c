#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
void push(int i);
int pop(void);
int *tos,*p1,stack[SIZE];
int main()
{
    int value;
    tos=stack;
    p1=stack;
    while(value!=-1)
    {
        printf("input a number:");
        scanf("%d",&value);
        if(value!=0)
        push(value);
        else
        printf("number out of stack is %d\n",pop());
    }
    return 0;
}
void push(int i)
{
    p1++;
    if(p1==(tos+SIZE))
    {
        printf("the stack is full");
        system("pause");
        exit(1);
    }
    *p1=i;
}
int pop(void)
{
    if(p1==tos)
    {
        printf("the stack is empty\n");
        system("pause");
        exit(1);
    }
    p1--;
    return *(p1+1);
}