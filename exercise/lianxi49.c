#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *creat();
struct node *concatenate(struct node *head1,struct node *head2);
void print(struct node *head);
int main()
{
    struct node *list1,*list2,*list;
    printf("input a list:\n");
    list1=creat();
    printf("input another list:\n");
    list2=creat();
    list=concatenate(list1,list2);
    print(list);
    return 0;
}
struct node *creat()
{
    struct node *new,*head,*tail;
    int n;
    head=NULL;
    scanf("%d",&n);
    while(n!=-1)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->data=n;
        new->next=NULL;
        if(head==NULL)
        head=new;
        else
        tail->next=new;
        tail=new;
        scanf("%d",&n);
    }
    return head;
}
struct node *concatenate(struct node *head1,struct node *head2)
{
    struct node *p1,*tail,*current;
    p1=head1;
    while(p1)
    {
        current=p1;
        p1=p1->next;
    }
    tail=current;
    tail->next=head2;
    return head1;
}
void print(struct node *head)
{
    struct node *p;
    p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}