#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node, *List;

List createList(int n);
int findMax(List L);
int findMin(List L);
void printList(List L);
int *fun(List L);

int main()
{
    srand((unsigned)time(NULL));
    int n;
    List L;
    printf("Enter the list's length: ");
    scanf("%d", &n);
    L = createList(n);
    printf("the list is \n");
    printList(L);
    int *p = fun(L);
    printf("\nthe numbers are ");
    for (int i = 0 ;i < 2; i++)
        printf("%d ", p[i]);
    printf("\nthe list is \n");
    printList(L);
    system("pause");
    return 0;
}

List createList(int n)
{
    List L = (List)malloc(sizeof(Node));
    L->next = NULL;
    List r = L, s;
    for (int i = 0; i < n; i++)
    {
        s = (List)malloc(sizeof(Node));
        s->data = rand();
        r->next = s;
        r = s;
    }
    s->next = NULL;
    return L;
}

int findMax(List L)
{
    List p = L->next;
    int max = p->data;
    while (p)
    {
        if (p->data > max)
        max = p->data;
        p = p->next;
    }
    return max;
}

int findMin(List L)
{
    List p = L->next;
    int min = p->data;
    while (p)
    {
        if (p->data < min)
        min = p->data;
        p = p->next;
    }
    return min;
}

void printList(List L)
{
    List p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int *fun(List L)
{
    if (L->next == NULL)
    {
        printf("The list is empty");
        exit(1);
    }
    int *returnp = (int *)malloc(sizeof(int) * 2);
    List p = L->next;
    int max = findMax(L), min = findMin(L);
    while (p->data != min)
        p = p->next;
    p->data = max;
    returnp[0] = min;
    returnp[1] = max;
    return returnp;
}