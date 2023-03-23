#include <stdio.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node, *LinkList;

void createList(LinkList L, int n);
void printList(LinkList L);
LinkList sub(LinkList L1, LinkList L2);

int main()
{
    LinkList L1, L2, L3;
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    createList(L1, n);
    createList(L2, n);
    L3 = sub(L1, L2);
    printList(L3);
    return 0;
}

void createList(LinkList L,int n)
{
    
}