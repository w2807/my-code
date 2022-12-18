#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev,*next;
    int data;
}node;
node *creat();
node *hebing(node *haed1,node *head2);
int main()
{
    node *list1,*list2;
    printf("input a list\n");
    list1=creat();
    printf("input another list\n");
    list2=creat();
    node *list=hebing(list1,list2);
    node *p;
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
    head=(node*)malloc(sizeof(node));
    head->next=head;
    head->prev=head;
    p=head;
    int n;
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
node *hebing(node *head1,node *head2)
{
    node *tail1,*tail2;
    tail1=head1->next;
    while(tail1->next!=head1)
    tail1=tail1->next;
    while(tail2->next!=head2)
    tail2=tail2->next;
    tail1->next=head2->next;
    head2->next->prev=tail1;
    tail2->next=head1;
    head1->prev=tail2;
    return head1;
}