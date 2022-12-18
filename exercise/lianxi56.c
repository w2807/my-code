#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev,*next;
    int data;
}node;
node *creat(int a[],int n);
node *he(node *head1,node *head2,int n);
int main()
{
    int n;
    scanf("%d",&n);
    int a1[n],a2[n],i;
    for(i=0;i<n;i++)
    scanf("%d",&a1[i]);
    for(i=0;i<n;i++)
    scanf("%d",&a2[i]);
    node *list1=creat(a1,n),*list2=creat(a2,n);
    node *list=he(list1,list2,n);
    node *p=list->next;
    while(p!=list)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}
node *creat(int a[],int n)
{
    node *new,*head,*p;
    int i;
    head=(node*)malloc(sizeof(node));
    head->next=head;
    head->prev=head;
    p=head;
    for(i=0;i<n;i++)
    {
        new=(node*)malloc(sizeof(node));
        new->data=a[i];
        new->prev=p;
        new->next=p->next;
        p->next=new;
        head->prev=new;
        p=new;
    }
    return head;
}
node *he(node *head1,node *head2,int n)
{
    node *p1,*p2;
    p1=head1->next;
    p2=head2->next;
    while(p1!=head1&&p2!=head2)
    {
        p2->data+=p1->data;
        p1=p1->next;
        p2=p2->next;
    }
    return head2;
}