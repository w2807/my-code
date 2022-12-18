#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prior,*next;
}DNode;
void reverse(DNode *L)
{
    DNode *p,*q;
    p=L;
    do
    {
        q=p->next;  
        p->next=p->prior;
        p->prior=q;
        p=q;
    }while(p!=L);
}
int main()
{
    int i;
    DNode *L;
    DNode *s,*r,*p;
    L=(DNode*)malloc(sizeof(DNode));
    r=L;
    for(i=0;i<10;i++)
    {
        s=(DNode*)malloc(sizeof(DNode));
        s->data=i;
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=L;
    L->prior=r;
    p=L->next;
    while(p!=L)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
    reverse(L);
    p=L->next;
    while(p!=L)
    {
        printf("%d",p->data);
        p=p->next;
    }
}