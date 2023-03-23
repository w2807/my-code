#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}node;
typedef node* list;

list creatSortList();
list mergeList(list head1, list head2);
void printList(list head);

int main()
{
    list head1, head2;
    printf("input two list,and end with -1\n");
    head1 = creatSortList();
    head2 = creatSortList();
    printf("the list after merging is\n");
    printList(mergeList(head1, head2));
    return 0;
}

list creatSortList()
{
    list head, marker, p;
    head = NULL;
    int n;
    scanf("%d", &n);
    while(n != -1)
    {
        list new = (list)malloc(sizeof(node));
        new->val = n;
        p = head;
        while(p && p->val < n)
        {
            marker = p;
            p = p->next;
        }
        if(p == head)
        {
            new->next = head;
            head = new;
        }
        else
        {
            new->next = p;
            marker->next = new;
        }
        scanf("%d", &n);
    }
    return head;
}

list mergeList(list head1, list head2)
{
    list head = (list)malloc(sizeof(node)), p1 = head1, p2 = head2;
    list p = head;
    while(p1 && p2)
    {
        list new = (list)malloc(sizeof(node));
        if(p1->val <= p2->val)
        {
            new->val = p1->val;
            p1 = p1->next;
        }
        else
        {
            new->val = p2->val;
            p2 = p2->next;
        }
        p->next = new;
        p = p->next;
    }
    while(p1)
    {
        list new = (list)malloc(sizeof(node));
        new->val = p1->val;
        p->next = new;
        p1 = p1->next;
        p = new;
    }
    while(p2)
    {
        list new = (list)malloc(sizeof(node));
        new->val = p2->val;
        p->next = new;
        p2 = p2->next;
        p = new;
    }
    return head;
}

void printList(list head)
{
    list p = head;
    while(p)
    {
        printf("%d", p->val);
        p = p->next;
    }
}