#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev,*next;
    int data;
}node;
node *delete(node *head,int n);
node *creat();
int main()
{
    printf("input a list\n");
    node *list=creat(),*p;
    int n;
    printf("input a number:");
    scanf("%d",&n);
    list=delete(list,n);
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
    node *new,*head,*p;
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
node *delete(node *head,int n)
{
    node *p;
    p=head->next;
    while(p->data!=n&&p!=head)
    p=p->next;
    if(p==head->next)
    {
        head->next=p->next;
        p->next->prev=head;
        free(p);
        return head;
    }
    else if(p==head->prev)
    {
        head->prev=p->prev;
        p->prev->next=head;
        free(p);
        return head;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
    return head;
}