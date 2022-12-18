#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insertSort(struct node *head,int n);
struct node *creatSortLink(struct node *head);
int main()
{
    struct node *list=(struct node*)malloc(sizeof(struct node)),*p;
    printf("input a list");
    list=creatSortLink(list);
    p=list;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}
struct node *insertSort(struct node *head,int n)
{
    struct node *new,*p,*marker;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=n;
    p=head;
    while(p!=NULL&&p->data<n)
    {
        marker=p;
        p=p->next;
    }
    if(p==head)
    {
        new->next=head;
        head=new;
    }
    else
    {
        new->next=p;
        marker->next=new;
    }
    return head;
}
struct node *creatSortLink(struct node *head)
{
    int n;
    head=NULL;
    scanf("%d",&n);
    while(n!=-1)
    {
        head=insertSort(head,n);
        scanf("%d",&n);
    }
    return head;
}