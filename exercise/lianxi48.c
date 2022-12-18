#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *deleteLink_1(struct node *head,int n);
struct node *creatLeftLink_1();
int main()
{
    struct node *list,*p;
    printf("input a list:\n");
    list=creatLeftLink_1();
    int n;
    printf("input a number:");
    scanf("%d",&n);
    list=deleteLink_1(list,n);
    p=list;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}
struct node *creatLeftLink_1()
{
    struct node*head,*new;
    int n;
    head=NULL;
    scanf("%d",&n);
    while(n!=-1)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->data=n;
        new->next=head;
        head=new;
        scanf("%d",&n);
    }
    return head;
}
struct node *deleteLink_1(struct node *head,int n)
{
    struct node *current,*p;
    current=head;
    while (current->data!=n&&current->next!=NULL)
    {
        p=current;
        current=current->next;
    }
    if(current->data==n)
    {
        if(current==head)
        head=current->next;
        else
        p->next=current->next;
        free(current);
    }
    return head;
}