#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev,*next;
    int data;
}node;
void reverse(node *head);
node *creat();
int main()
{
    node *list,*p;
    printf("input a list\n");
    list=creat();
    reverse(list);
    p=list->next;
    while(p!=list)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}
node *creat()
{
    node *head,*new,*p;
    int n;
    head=(node*)malloc(sizeof(node));
    head->next=head;
    head->prev=head;
    p=head;
    scanf("%d",&n);
    while(n!=-1)
    {
        new=(node*)malloc(sizeof(node));
        new->data=n;
        new->prev=p;
        new->next=p->next;
        p->next=new;
        head->prev=new;
        p=new;
        scanf("%d",&n);
    }
    return head;
}
void reverse(node *head)
{
    node *p1,*p2;
    p1=head;
    do
    {
        p2=p1->next;  
        p1->next=p1->prev;
        p1->prev=p2;
        p1=p2;
    }while(p1!=head);
}