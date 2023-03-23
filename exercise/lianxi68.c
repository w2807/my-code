#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int val;
    struct node *next;
} node;
typedef node* list;

list creat();
void printList(list head);
list deleteNode(list head);

int main()
{
    list head;
    head = creat();
    printf("before deleting:");
    printList(head);
    head = deleteNode(head);
    printf("after deleting:");
    printList(head);
    return 0;
}

list creat()
{
    list head = NULL, post = head;
    int i;
    scanf("%d", &i);
    while (i != -1)
    {
        list new = (list)malloc(sizeof(node));
        new->val = i;
        new->next = NULL;
        if (head == NULL)
        head = new;
        else
        post->next = new;
        post = new;
        scanf("%d", &i);
    }
    return head;
}

void printList(list head)
{
    list p = head;
    while (p)
    {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("\n");
}

list deleteNode(list head)
{
    list p = head;
    while (p->next)
    {
        if (p->val == p->next->val)
        p->next = p->next->next;
        else
        p = p->next;
    }
    return head;
}