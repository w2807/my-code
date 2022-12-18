#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *creatLeftLink_1();
int creatLeftLink_2(struct node **phead);
int main()
{
    printf("input a list");
    struct node *list1=creatLeftLink_1();
    struct node *list,**list2=&list;
    int a;
    printf("input a list");
    a=creatLeftLink_2(list2);
    printf("%d\n",a);
    struct node *p;
    p=list1;
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
int creatLeftLink_2(struct node **phead)
{
    struct node *new;
    int n,k=0;
    *phead=NULL;
    scanf("%d",&n);
    while(n!=-1)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->data=n;
        new->next=*phead;
        *phead=new;
        scanf("%d",&n);
        k++;
    }
    return k;
}