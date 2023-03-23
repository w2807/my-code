#include <stdio.h>
#include <stdlib.h>

void push(int i, int * stack);
int pop(int * stack);
int* creatStack();

int main()
{
    int *stack = creatStack();
    int i;
    scanf("%d", &i);
    while(i != -1)
    push(i, stack);
    int a;

}