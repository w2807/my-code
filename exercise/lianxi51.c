#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;
node *creat1();
node *creat2();
int main()
{
    node *link1,*link2,*p1,*p2;
    printf("input two links:\n");
    link1=creat1();
    link2=creat2();
    p1=link1->next;
    p2=link2->next;
    printf("left link is:\n");
    while(p1!=link1)
    {
        printf("%d ",p1->data);
        p1=p1->next;
    }
    printf("\nright link is:\n");
    while(p2!=link2)
    {
        printf("%d ",p2->data);
        p2=p2->next;
    }
    return 0;
}
node *creat1()
{
    node *new,*head;
    int n;
    head=(node*)malloc(sizeof(node));
    head->next=head;
    head->prev=head;
    scanf("%d",&n);
    while (n!=-1)
    {
        new=(node*)malloc(sizeof(node));
        new->data=n;
        new->next=head->next;
        new->prev=head;
        head->next->prev=new;
        head->next=new;
        scanf("%d",&n);
    }
    return head;
}
node *creat2()
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