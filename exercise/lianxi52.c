#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev,*next;
    int data;
}node;
node *creat();
node *insertnode(node* head,int n);
int main()
{
    printf("input a list\n");
    node *link=creat(),*p;
    p=link->next;
    printf("sort list is\n");
    while(p!=link)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}
node *creat()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    head->next=head;
    head->prev=head;
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        head=insertnode(head,n);
        scanf("%d",&n);
    }
    return head;
}
node *insertnode(node* head,int n)
{
    node *new,*p,*marker;
    new=(node*)malloc(sizeof(node));
    new->data=n;
    new->next=new->prev=NULL;
    p=head->next;
    while(p!=head&&p->data<n)
    {
        marker=p;
        p=p->next;
    }
    if(p==head->next)
    {
        new->next=head->next;
        new->prev=head;
        head->next->prev=new;
        head->next=new;
    }
    else
    {
        new->prev=marker;
        new->next=p;
        marker->next=new;
        p->prev=new;
    }
    return head;
}                                                                                                